package juc.interrupt;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicBoolean;

public class InterruptDemo
{
//    volatile代表可见性
    static volatile boolean isStop = false;
//    原子布尔，自动带锁，不可分
    static AtomicBoolean atomicBoolean = new AtomicBoolean(false);

    public static void main(String[] args)
    {
        Thread t1 = new Thread(() -> {
            while(true)
            {
//                监听状态
                if(Thread.currentThread().isInterrupted())
                {
//                    自己停止自己
                    System.out.println(Thread.currentThread().getName()+"\t interrupt改为true");
                    break;
                }
                System.out.println("t1---hello juc.interrupt api");
            }
        },"t1");
        t1.start();

        try{ TimeUnit.MICROSECONDS.sleep(200); }catch (InterruptedException e){ e.printStackTrace(); }

        new Thread(() -> {
//            发送协商
            t1.interrupt();
        },"t2").start();
//        t1也可以自行中断
    }

    private static void m2_autobool()
    {
        new Thread(() -> {
            while(true)
            {
//                监听状态
                if(atomicBoolean.get())
                {
//                    自己停止自己
                    System.out.println(Thread.currentThread().getName()+"\t atomicBoolean改为true");
                    break;
                }
                System.out.println("t1---hello atomicBoolean");
            }
        },"t1").start();

        try{ TimeUnit.MICROSECONDS.sleep(200); }catch (InterruptedException e){ e.printStackTrace(); }

        new Thread(() -> {
//            发送协商
            atomicBoolean.set(true);
        },"t2").start();
    }

    private static void m1_volatile()
    {
        new Thread(() -> {
            while(true)
            {
//                监听状态
                if(isStop)
                {
//                    自己停止自己
                    System.out.println(Thread.currentThread().getName()+"\t stop改为true");
                    break;
                }
                System.out.println("t1---hello volatile");
            }
        },"t1").start();

        try{ TimeUnit.MICROSECONDS.sleep(200); }catch (InterruptedException e){ e.printStackTrace(); }

        new Thread(() -> {
//            发送协商
            isStop = true;
        },"t2").start();
    }
}

