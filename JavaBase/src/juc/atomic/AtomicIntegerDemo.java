package juc.atomic;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.atomic.AtomicInteger;

class MyNumber
{
    AtomicInteger atomicInteger = new AtomicInteger();
    public void addPlusPlus(){
        atomicInteger.getAndIncrement();
    }
}

public class AtomicIntegerDemo {
    public static final int SIZE = 50;
    public static void main(String[] args) throws InterruptedException {
        MyNumber myNumber = new MyNumber();
//        保证线程执行完毕
        CountDownLatch countDownLatch = new CountDownLatch(SIZE);

        for (int i = 0; i < SIZE; i++) {
            new Thread(()->{
                try{
                    for (int j = 0; j < 1000; j++) {
                        myNumber.addPlusPlus();
                    }
                }finally {
//                    执行完，size-1
                    countDownLatch.countDown();
                }
            },String.valueOf(i)).start();
        }

//        确保SIZE减为0
        countDownLatch.await();

        //        此时查看结果，50个线程不一定执行完毕了
//        可以睡眠两秒，再查看。但实际操作中，你不知道要等多久
        System.out.println(Thread.currentThread().getName()+" result:"+myNumber.atomicInteger.get());
    }
}
