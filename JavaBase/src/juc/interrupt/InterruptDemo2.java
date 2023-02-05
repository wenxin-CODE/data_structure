package juc.interrupt;
import java.util.concurrent.TimeUnit;

public class InterruptDemo2 {
    public static void main(String[] args) {
//        interrupt只改变标志位，不会终止线程
        Thread t1 = new Thread(() -> {
            for (int i = 1; i <= 300; i++) {
                System.out.println("======" + i);
            }
            System.out.println("t1调用interrupt后标志位02是" + Thread.currentThread().isInterrupted());
        }, "t1");

        t1.start();
        System.out.println("t1默认标志位是" + t1.isInterrupted());//默认是false
        try {
            TimeUnit.MICROSECONDS.sleep(200);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        t1.interrupt();
        System.out.println("t1调用interrupt后标志位01是" +t1.isInterrupted());//此时为true
        try {
            TimeUnit.MICROSECONDS.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        t1.interrupt();
        System.out.println("t1调用interrupt后标志位03是" +t1.isInterrupted());//此时为false，因为t1已经停止，中断他没有效果
    }
}