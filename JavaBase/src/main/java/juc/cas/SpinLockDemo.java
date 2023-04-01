package juc.cas;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicReference;

//借鉴CAS思想，实现自旋锁

public class SpinLockDemo {

    AtomicReference<Thread> atomicReference = new AtomicReference<>();

    public void lock(){
        Thread thread = Thread.currentThread();
        System.out.println(Thread.currentThread().getName()+"\t"+"---com in");
        while (!atomicReference.compareAndSet(null, thread)) {

        }
    }

    public void unlock(){
        Thread thread = Thread.currentThread();
        atomicReference.compareAndSet(thread,null);
        System.out.println(Thread.currentThread().getName()+"\t"+"---task over,unlock...");
    }

    public static void main(String[] args) {
        SpinLockDemo spinLockDemo = new SpinLockDemo();

        new Thread(()->{
            spinLockDemo.lock();
            try {
                TimeUnit.SECONDS.sleep(5);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            spinLockDemo.unlock();
        },"A").start();

        try {
            TimeUnit.SECONDS.sleep(2);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        new Thread(()->{
            spinLockDemo.lock();
            spinLockDemo.unlock();
        },"B").start();
    }
}
