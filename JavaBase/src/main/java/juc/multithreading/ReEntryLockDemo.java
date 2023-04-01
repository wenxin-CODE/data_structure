package juc.multithreading;

public class ReEntryLockDemo {

//    //隐式可重入锁，不用手动释放，执行完了，自动释放。就不会出现阻塞

//    同步方法
    public synchronized void m1()
    {
        System.out.println(Thread.currentThread().getName()+"\t---m1 come in");
        m2();
        System.out.println(Thread.currentThread().getName()+"\t---m1 come out");
    }
    public synchronized void m2()
    {
        System.out.println(Thread.currentThread().getName()+"\t---m2 come in");
        m3();
        System.out.println(Thread.currentThread().getName()+"\t---m2 come out");
    }public synchronized void m3()
    {
        System.out.println(Thread.currentThread().getName()+"\t---m3 come in");
//        m2();
        System.out.println(Thread.currentThread().getName()+"\t---m3 come out");
    }


    public static void main(String[] args) {
        ReEntryLockDemo reEntryLockDemo = new ReEntryLockDemo();

        new Thread(() -> {
            reEntryLockDemo.m1();
        },"t1").start();
    }

//    同步代码块
    private static void ReEntryLock1() {
        final Object o = new Object();
        new Thread(() -> {
            synchronized (o){
                System.out.println(Thread.currentThread().getName()+"\t----外层调用");
                synchronized (o){
                    System.out.println(Thread.currentThread().getName()+"\t----中层调用");
                    synchronized (o){
                        System.out.println(Thread.currentThread().getName()+"\t----内层调用");
                    }
                }
            }
        },"t1").start();
    }
}
