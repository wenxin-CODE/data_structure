package juc.AQS;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class AQSDemo {
    public static void main(String[] args) {
        Lock lock = new ReentrantLock();//参数默认为false，非公平锁

        lock.lock();
        try{

        }finally {
            lock.unlock();
        }
    }
}
