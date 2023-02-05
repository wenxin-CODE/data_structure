package juc.multithreading;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class CompletableFutureAPITest2 {
    public static void main(String[] args) {
//        存在依赖关系，串行执行

//        使用默认的线程池，会随主程序的结束而结束
        ExecutorService executorService = Executors.newFixedThreadPool(2);
        CompletableFuture<Integer> completableFuture = CompletableFuture.supplyAsync(() -> {
            try {
                TimeUnit.SECONDS.sleep(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return 6;
        },executorService).thenApply((r)-> {
//            int i=2/0;
            return r * 5;
        }).thenApply((r)-> {
            System.out.println(r);
            return r - 2;
        }).whenComplete((v, e) -> {
            System.out.println("计算结果："+v);
        }).exceptionally(e -> {
            System.out.println(e.getMessage());
            System.out.println(e);
            return null;
        });
        System.out.println("============主线程==========");
        executorService.shutdown();
    }
}

//thenapply也可以用handle代替

