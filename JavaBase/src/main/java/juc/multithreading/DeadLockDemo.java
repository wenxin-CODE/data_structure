package juc.multithreading;

import java.util.concurrent.TimeUnit;

//死锁原因：
//1资源不足  2调用顺序有误  3分配不当

//查看死锁：
//1jps -l查看进程号  2jstack '进程号'   查看是否死锁
public class DeadLockDemo {

    public static void main(String[] args) {
        final Object oa = new Object();
        final Object ob = new Object();

        new Thread(() -> {
            synchronized (oa){
                System.out.println(Thread.currentThread().getName()+"\t---获得a，还要b");
                try{ TimeUnit.SECONDS.sleep(1); }catch (InterruptedException e){ e.printStackTrace(); }
                synchronized (ob){
                    System.out.println(Thread.currentThread().getName()+"\t---获得b");
                }
            }
        },"A").start();

        new Thread(() -> {
            synchronized (ob){
                System.out.println(Thread.currentThread().getName()+"\t---获得b，还要a");
                try{ TimeUnit.SECONDS.sleep(1); }catch (InterruptedException e){ e.printStackTrace(); }
                synchronized (oa){
                    System.out.println(Thread.currentThread().getName()+"\t---获得a");
                }
            }
        },"A").start();
    }
}
