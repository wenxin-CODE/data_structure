package juc.interrupt;

public class InterruptDemo4 {
    public static void main(String[] args) {
        System.out.println(Thread.currentThread().getName()+Thread.interrupted());
        System.out.println(Thread.currentThread().getName()+Thread.interrupted());
        System.out.println("========1");
        Thread.currentThread().interrupt();
        System.out.println("=======2");
//        打出-====2表明第8行一定执行了
        System.out.println(Thread.currentThread().getName()+Thread.interrupted());
        System.out.println(Thread.currentThread().getName()+Thread.interrupted());

    }
}
