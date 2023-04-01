package juc.locksupport;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.LockSupport;
import java.util.concurrent.locks.ReentrantLock;

public class LockSupportDemo {
    public static void main(String[] args) {
        Thread t1 = new Thread(() -> {
//            先唤醒unpark后等待park也可以——此时park不会消耗一点时间，高效
            try {
                TimeUnit.SECONDS.sleep(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println(Thread.currentThread().getName()+"  come in");
            LockSupport.park();//阻塞
            System.out.println(Thread.currentThread().getName()+" 被唤醒");
        },"t1");
        t1.start();

//        try {
//            TimeUnit.SECONDS.sleep(1);
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }

        new Thread(() -> {
            LockSupport.unpark(t1);//阻塞
            System.out.println(Thread.currentThread().getName()+" 发出通知");
        },"t2").start();
    }

    private static void lockawaitsignal()
    {
        Lock lock = new ReentrantLock();
//        对同一个condition进行阻塞和唤醒
        Condition condition = lock.newCondition();
        new Thread(() -> {
            lock.lock();
//也要注意锁块的使用，lock和unlock
            try
            {
                System.out.println(Thread.currentThread().getName()+"  come in");
                condition.await();
                System.out.println(Thread.currentThread().getName()+" 被唤醒");
            }catch (InterruptedException e)
            {
                e.printStackTrace();
            }finally {
                lock.unlock();
            }
        },"t1").start();

        try {
            TimeUnit.SECONDS.sleep(1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        new Thread(() -> {
            lock.lock();

            try
            {
                condition.signal();
                System.out.println(Thread.currentThread().getName()+" 发出通知");
            }finally {
                lock.unlock();
            }
        },"t2").start();
    }

    private static void syncwaitnotify()
    {
        Object o = new Object();
        new Thread(() -> {
//            t1  t2使用的是同一把锁，这把锁属于对象o
            synchronized (o){
                System.out.println(Thread.currentThread().getName()+"  come in");
                try {
                    o.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println(Thread.currentThread().getName()+" 被唤醒");
            }
        },"t1").start();

        try {
            TimeUnit.SECONDS.sleep(2);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        new Thread(() -> {
            synchronized (o){
//                只用这里o的锁被唤醒了，才能执行t1的第二个sout
                o.notify();
                System.out.println(Thread.currentThread().getName()+" 发出通知");
            }
        },"t2").start();
    }
}
