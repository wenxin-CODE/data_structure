package juc.multithreading;

import java.util.concurrent.*;

public class TestThread extends Thread{
    public static void main(String[] args) throws ExecutionException, InterruptedException, TimeoutException {
        ExecutorService executorService = Executors.newFixedThreadPool(3);
        long start = System.currentTimeMillis();
        FutureTask<String> task2 = new FutureTask<>(() -> {
            TimeUnit.SECONDS.sleep(2);
            return "2";
        });
        FutureTask<String> task1 = new FutureTask<>(() -> {
            TimeUnit.SECONDS.sleep(1);
            return "1";
        });
        FutureTask<String> task3 = new FutureTask<>(() -> {
            TimeUnit.SECONDS.sleep(3);
            return "3";
        });
        executorService.submit(task1);
        executorService.submit(task2);
        executorService.submit(task3);
        System.out.println(task1.get());
        System.out.println(task2.get(3,TimeUnit.SECONDS));
        while (true){
            if(task3.isDone()){
                System.out.println(task3.get());
                break;
            }else {
                TimeUnit.MILLISECONDS.sleep(200);
            }
        }
        System.out.println("执行耗时："+(System.currentTimeMillis()-start));
        executorService.shutdown();
    }
}

class Demo{
    public void xxx(){
        for (int i = 0; i < 20; i++) {
            System.out.println("我在学习"+i);
        }
    }
}
