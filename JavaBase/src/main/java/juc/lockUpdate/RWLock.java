package juc.lockUpdate;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class RWLock {
//    private Logger logger = LoggerFactory.getLogger(RWLock.class);
    ReentrantReadWriteLock readWriteLock = new ReentrantReadWriteLock();
    ReentrantReadWriteLock.ReadLock readLock = readWriteLock.readLock();
    ReentrantReadWriteLock.WriteLock writeLock = readWriteLock.writeLock();

    /**
     *	这里仅仅是想知道锁重入的情况，是不是这个时候加入的锁会到等待队列里面排队。
     */
    public void queryData() {
        try {
            Thread.sleep(500);
            readLock.lock();
            System.out.println("查询数据完成.");
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            readLock.unlock();
        }

    }

    public void test3() throws Exception {
        // 开始锁降级
        writeLock.lock();
        System.out.println("主线程抢到写锁...");
        // 这里的休眠是为了让下面线程能在预想的情况下加入等待队列.
        Thread.sleep(500);
        // 这里就是假设等待队列里面排在前面的是读锁线程
        processReadLock(1); // 这里可以和下面processWriteLock对调

        processWriteLock(2);

        Thread.sleep(500);
        // 开始锁降级
        readLock.lock(); // A 降级开始
        // 锁降级完成
        writeLock.unlock();
        System.out.println("主线程释放写锁");
        queryData();
        readLock.unlock(); // A 降级结束
        System.out.println("主线程读锁释放");
        System.out.println("过程结束..");
    }

    private void processWriteLock(int threadIndex) {
        new Thread(() -> {
            System.out.println("线程" + threadIndex + " 写锁开始竞争,阻塞中.");
            writeLock.lock();
            System.out.println("线程" + threadIndex + " 写锁执行中..");
            writeLock.unlock();
            System.out.println("线程" + threadIndex + " 写锁释放..");
        }).start();
    }

    private void processReadLock(int threadIndex) {
        new Thread(() -> {
            System.out.println("线程" + threadIndex + " 读锁开始竞争,阻塞中.");
            readLock.lock();
            System.out.println("线程" + threadIndex + " 读锁执行中..");
            readLock.unlock();
            System.out.println("线程" + threadIndex + " 读锁释放..");
        }).start();
    }


    public static void main(String[] args) throws Exception {
        RWLock readWriteLockTest = new RWLock();
        readWriteLockTest.test3();
    }
}
