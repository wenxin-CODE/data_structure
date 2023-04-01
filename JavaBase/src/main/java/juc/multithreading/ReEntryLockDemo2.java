package juc.multithreading;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

//显式锁：lock和unlock就近匹配，个数要对的上
public class ReEntryLockDemo2 {
    static Lock lock = new ReentrantLock();
    public static void main(String[] args) {
        new Thread(() -> {
            lock.lock();
            try
            {
                System.out.println(Thread.currentThread().getName()+"\t---外层调用");
                lock.lock();
                try{
                    System.out.println(Thread.currentThread().getName()+"\t---内层调用");
                }finally {
                    lock.unlock();
//                    如果这里注释掉一个unlock，下面的t2就跑不通
                }
            }finally {
                lock.unlock();
            }
        },"t1").start();

        new Thread(() -> {
            lock.lock();
            try
            {
                System.out.println(Thread.currentThread().getName()+"\t---外层调用");
            }finally {
                lock.unlock();
            }
        },"t2").start();
    }
}
