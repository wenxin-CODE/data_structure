package juc.atomic;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.atomic.AtomicLong;
import java.util.concurrent.atomic.LongAccumulator;
import java.util.concurrent.atomic.LongAdder;

//可减少乐观锁重试次数。例如高并发统计点赞数，不可能完全同步，差距不大就行

class ClickNumber
{
    int number;
    public synchronized void clickBySync()
    {
        number++;
    }

    AtomicLong atomicLong = new AtomicLong(0);
    public void clickByAto()
    {
        atomicLong.getAndIncrement();
    }

    LongAdder longAdder = new LongAdder();
    public void clickByLongAdder()
    {
        longAdder.increment();
    }

    LongAccumulator longAccumulator = new LongAccumulator((x,y)->x+y,0);
    public void clickByLongAcc()
    {
        longAccumulator.accumulate(1);
    }

}

//longadder只能从零开始计算加法，longaccumulator灵活一些
public class LongAdderDemo {
    public static final int _1w = 10000;
    public static final int threadNumber = 50;
    public static void main(String[] args) throws InterruptedException {
//        LongAccumulator例子
//        LongAccumulator longAccumulator = new LongAccumulator((x, y) -> x + y, 0);
//        longAccumulator.accumulate(1); //0是初始值，x是1,相加之后y变成1
//        longAccumulator.accumulate(3); //y是1，x是3，相加之后y变成4
//        System.out.println(longAccumulator.get());

        ClickNumber clickNumber = new ClickNumber();
        long starttime;
        long endtime;

        CountDownLatch countDownLatch1 = new CountDownLatch(threadNumber);
        CountDownLatch countDownLatch2 = new CountDownLatch(threadNumber);
        CountDownLatch countDownLatch3 = new CountDownLatch(threadNumber);
        CountDownLatch countDownLatch4 = new CountDownLatch(threadNumber);

        starttime = System.currentTimeMillis();
        for (int i = 0; i < threadNumber; i++) {
            new Thread(()-> {
                try {
                    for (int j = 0; j < 100 * _1w; j++) {
                        clickNumber.clickBySync();
                    }
                }finally {
                    countDownLatch1.countDown();
                }
            },String.valueOf(i)).start();
        }
        countDownLatch1.await();
        endtime = System.currentTimeMillis();
        System.out.println("costtime---"+(endtime-starttime)+"---"+clickNumber.number);

        starttime = System.currentTimeMillis();
        for (int i = 0; i < threadNumber; i++) {
            new Thread(()-> {
                try {
                    for (int j = 0; j < 100 * _1w; j++) {
                        clickNumber.clickByAto();
                    }
                }finally {
                    countDownLatch2.countDown();
                }
            },String.valueOf(i)).start();
        }
        countDownLatch2.await();
        endtime = System.currentTimeMillis();
        System.out.println("costtime---"+(endtime-starttime)+"---"+clickNumber.atomicLong.get());

        starttime = System.currentTimeMillis();
        for (int i = 0; i < threadNumber; i++) {
            new Thread(()-> {
                try {
                    for (int j = 0; j < 100 * _1w; j++) {
                        clickNumber.clickByLongAdder();
                    }
                }finally {
                    countDownLatch3.countDown();
                }
            },String.valueOf(i)).start();
        }
        countDownLatch3.await();
        endtime = System.currentTimeMillis();
        System.out.println("costtime---"+(endtime-starttime)+"---"+clickNumber.longAdder.sum());

        starttime = System.currentTimeMillis();
        for (int i = 0; i < threadNumber; i++) {
            new Thread(()-> {
                try {
                    for (int j = 0; j < 100 * _1w; j++) {
                        clickNumber.clickByLongAcc();
                    }
                }finally {
                    countDownLatch4.countDown();
                }
            },String.valueOf(i)).start();
        }
        countDownLatch4.await();
        endtime = System.currentTimeMillis();
        System.out.println("costtime---"+(endtime-starttime)+"---"+clickNumber.longAccumulator.get());

    }
}


//longadder为什么快：分散热点——并发量低时只用base计数，一个CAS；并发量高时，新增窗口cell，形成多个CAS，最后统计求和result=base+cell[n]