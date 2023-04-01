package juc.syncup;

import org.openjdk.jol.info.ClassLayout;

import java.awt.*;

public class SynchronizedUpDemo {
    public static void main(String[] args) {
//        nolock();

//轻量锁
        Object o = new Object();
        new Thread(() -> {
            synchronized (o)
            {
                System.out.println(Thread.currentThread().getName());
                System.out.println(ClassLayout.parseInstance(o).toPrintable());
            }
        },"a").start();
        new Thread(() -> {
            synchronized (o)
            {
                System.out.println(Thread.currentThread().getName());
                System.out.println(ClassLayout.parseInstance(o).toPrintable());
            }
        },"b").start();
        new Thread(() -> {
            synchronized (o)
            {
                System.out.println(Thread.currentThread().getName());
                System.out.println(ClassLayout.parseInstance(o).toPrintable());
            }
        },"c").start();

    }

    private static void biasedlock()
    {
        //        注意偏向锁如果不设置启动时间为0，会直接跳到轻量级锁
//        或者让线程睡眠4秒以上，偏向锁就开启了
//        注意，如果线程没有加锁，那么即便标志位变了，指针还是没记录线程id。这里是主线程main调用
        Object o = new Object();
        synchronized (o)
        {
            System.out.println(Thread.currentThread().getName());
            System.out.println(ClassLayout.parseInstance(o).toPrintable());
        }
    }

    private static void nolock()
    {
        Object o = new Object();

        System.out.println("10进制"+o.hashCode());
        System.out.println("16进制"+Integer.toHexString(o.hashCode()));
        System.out.println("2进制"+Integer.toBinaryString(o.hashCode()));

        System.out.println("输出对象内存布局"+ ClassLayout.parseInstance(o).toPrintable());

    }
}
//输出从右下到左上看
