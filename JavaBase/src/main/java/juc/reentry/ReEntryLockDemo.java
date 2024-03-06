package juc.reentry;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

//synchronized关键字使用的锁都是可重入锁，
public class ReEntryLockDemo {

    final Object o = new Object();

    public static void main(String[] args) {
        final ReEntryLockDemo reEntryLockDemo = new ReEntryLockDemo();
        reEntryLockDemo.entry03();
    }

//    同步代码块
    public void entry01(){

        new Thread(()->{
            synchronized (o){
                System.out.println(Thread.currentThread().getName()+"\t"+"外层调用");
                synchronized (o){
                    System.out.println(Thread.currentThread().getName()+"\t"+"中层调用");
                    synchronized (o){
                        System.out.println(Thread.currentThread().getName()+"\t"+"内层调用");
                    }
                }
            }
        },"t1").start();
    }

//    同步方法
    public void entry02(){
        m1();
    }

    private synchronized void m1() {
        System.out.println(Thread.currentThread().getName()+"\t"+"m1外层调用");
        m2();
    }

    private synchronized void m2() {
        System.out.println(Thread.currentThread().getName()+"\t"+"m2外层调用");
        m3();
    }

    private synchronized void m3() {
        System.out.println(Thread.currentThread().getName()+"\t"+"m3外层调用");

    }

    Lock lock = new ReentrantLock();
    public void entry03(){
        new Thread(()->{
            lock.lock();
            try {
                System.out.println(Thread.currentThread().getName()+"\t"+"外层调用");
                lock.lock();
                try {
                    System.out.println(Thread.currentThread().getName()+"\t"+"内层调用");
                }finally {
                    lock.unlock();
                }
            }finally {
//                每一个锁对象都有一个锁计数器和一个指向持有该锁的线程的指针
//                这里如果加锁和解锁的次数没对上，下面的线程就不能获得锁
                lock.unlock();
            }
        },"t2").start();

        try {
            TimeUnit.MILLISECONDS.sleep(20);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        new Thread(()->{
            lock.lock();
            try {
                System.out.println(Thread.currentThread().getName()+"\t"+"外层调用");
                lock.lock();
                try {
                    System.out.println(Thread.currentThread().getName()+"\t"+"内层调用");
                }finally {
                    lock.unlock();
                }
            }finally {
                lock.unlock();
            }
        },"t3").start();
    }
}
