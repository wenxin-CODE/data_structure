package juc.interrupt;

import java.util.concurrent.TimeUnit;

public class InterruptDemo3 {
    public static void main(String[] args) {
        Thread t1 = new Thread(() -> {
            while (true)
            {
                if(Thread.currentThread().isInterrupted())
                {
                    System.out.println(Thread.currentThread().getName()+
                            "中断标志"+Thread.currentThread().isInterrupted()+"停止程序");
                    break;
                }

                try {
                    Thread.sleep(200);
//                    调用了sleep，中断标志变为true
//                    此时调用interrupt，会唤醒线程，true变false
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
//                    解决这个sleep的方法就是加入上面这一句
//                    用了这一句，false就又变成true
                    e.printStackTrace();
                }
//                加入sleep，就无法中断线程，进入死循环

                System.out.println("====hello,业务逻辑");
            }
        },"t1");
        t1.start();

        try {
            TimeUnit.SECONDS.sleep(2);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        new Thread(() -> t1.interrupt(),"t2").start();
    }
}
