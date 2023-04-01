package juc.tl;

import java.util.Random;
import java.util.concurrent.TimeUnit;

class House
{
    int saleCount = 0;
    public synchronized void saleHouse()
    {
        ++saleCount;
    }

//    ThreadLocal<Integer> saleVolume = new ThreadLocal<Integer>(){
//        @Override
//        protected Integer initialValue()
//        {
//            return 0;
//        }
//    };
//    每个线程有专属的本地变量副本
    ThreadLocal<Integer> saleVolume = ThreadLocal.withInitial(() -> 0);
    public void saleVolumeByTL()
    {
        saleVolume.set(1+saleVolume.get());
    }

}

public class ThreadLocalDemo {
    public static void main(String[] args) {
        House house = new House();
        for (int i = 0; i < 5; i++) {
            new Thread(() -> {
                int size = new Random().nextInt(5)+1;
//                System.out.println(size);

                try {
                    for (int j = 0; j < size; j++) {
    //                    统计总共买了多少套
                        house.saleHouse();
    //                    统计每个线程买了多少套
                        house.saleVolumeByTL();
                    }
                    System.out.println(Thread.currentThread().getName()+"号买了"+house.saleVolume.get());
                } finally {
//                   用完及时清除
                    house.saleVolume.remove();
                }
            },String.valueOf(i)).start();
        }

        try {
            TimeUnit.MILLISECONDS.sleep(300);} catch (InterruptedException e) {e.printStackTrace();}

        System.out.println(Thread.currentThread().getName()+"共卖出"+house.saleCount);
    }
}
