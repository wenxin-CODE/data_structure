package juc.atomic;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicIntegerFieldUpdater;

//——对象属性修改原子类：
//AtomicIntegerFieldUpdater是基于反射的应用程序，可对指定类的指定volatile int字段进行更新【long、reference一样】。以一种线程安全的方式操作非线程安全对象的某些字段

class BankAccount {
    String Name = "CCB";

//    更新属性必须是public volatile
    public volatile int money = 0;

    public void add()
    {
        money++;
    }

//    使用newUpdater()创建更新器，并设置要更新的类和属性
//    只对要修改的字段加锁，而不是对整个类
    AtomicIntegerFieldUpdater<BankAccount> fieldUpdater =
            AtomicIntegerFieldUpdater.newUpdater(BankAccount.class,"money");

    public void transMoney(BankAccount bankAccount)
    {
//        自增操作
        fieldUpdater.getAndIncrement(bankAccount);
    }
}

public class AtomicIntegerFiledUpdaterDemo
{
//    public static void main(String[] args) throws InterruptedException {
//        BankAccount bankAccount = new BankAccount();
//        CountDownLatch countDownLatch = new CountDownLatch(10);
//
//        for (int i = 1; i <= 10; i++) {
//            new Thread(() -> {
//                try
//                {
//                    for (int j = 1; j <= 1000; j++) {
////                        bankAccount.add();
//                        bankAccount.transMoney(bankAccount);
//                    }
//
//                } finally {
//                    countDownLatch.countDown();
//                }
//            },String.valueOf(i)).start();
//
//            countDownLatch.await();
//            System.out.println(Thread.currentThread().getName()+" result:"+bankAccount.money);
//
//        }
//    }

    public static void main(String[] args) {
        int size = 50;
        CountDownLatch latch = new CountDownLatch(size);
        Dog dog = new Dog();
        for (int i = 0; i < 50; i++) {
            new Thread(() -> {
                try {
                    for (int j = 0; j < 10000; j++) {
                        dog.add();
                    }
                } finally {
                    latch.countDown();
                }
            }, String.valueOf(i)).start();
        }
        try {
            latch.await(1, TimeUnit.SECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        if (latch.getCount() > 0) {
            System.out.println("============执行超时============");
            return;
        }
        System.out.println(dog.age);
    }

    static class Dog {
        private volatile int age;
        private String name;

        AtomicIntegerFieldUpdater<Dog> updater = AtomicIntegerFieldUpdater.newUpdater(Dog.class, "age");

        public void add() {
            updater.getAndIncrement(this);
        }
    }
}

