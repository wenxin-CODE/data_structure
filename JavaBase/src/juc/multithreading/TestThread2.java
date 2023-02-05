package juc.multithreading;

public class TestThread2 implements Runnable{

    @Override
    public void run() {
        for (int i = 0; i < 20; i++) {
            System.out.println("运行runable方法");
        }
    }

    public static void main(String[] args) {
        TestThread2 testThread2 = new TestThread2();
        new Thread(testThread2).start();

        for (int i = 0; i < 200; i++) {
            System.out.println("主方法"+i);
        }
    }
}
