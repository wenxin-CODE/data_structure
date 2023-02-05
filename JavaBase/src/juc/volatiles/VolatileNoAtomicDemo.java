package juc.volatiles;

import java.util.concurrent.TimeUnit;

class MyNumber
{
    volatile int value;

//volatile没有原子性，要用锁实现
//    如果不加锁，会造成++操作无效，从而使结果小于10000
    public synchronized void addPlusPlus()
    {
        value++;
    }
}

public class VolatileNoAtomicDemo {
    public static void main(String[] args) {
        MyNumber myNumber = new MyNumber();

        for (int i = 1; i <=10 ; i++) {
            new Thread(() -> {
                for (int j = 1; j <=1000; j++) {
                    myNumber.addPlusPlus();
                }
            },String.valueOf(i)).start();
        }

        try {
            TimeUnit.SECONDS.sleep(2);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println(myNumber.value);
    }
}
