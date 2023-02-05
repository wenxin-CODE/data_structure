package juc.volatiles;

import java.util.concurrent.TimeUnit;

public class VolatileSeeDemo {

    static volatile boolean flag = true;
    public static void main(String[] args) {
        new Thread(() -> {
            System.out.println(Thread.currentThread().getName()+"=======come in");
            while (flag)//每次都到主内存里面取变量
            {
//业务代码----------
            }
            System.out.println(Thread.currentThread().getName()+"，flag设为false，程序停止");
        },"t1").start();

        try {
            TimeUnit.SECONDS.sleep(2);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        flag = false;

        System.out.println(Thread.currentThread().getName()+"修改完成");
    }
}
