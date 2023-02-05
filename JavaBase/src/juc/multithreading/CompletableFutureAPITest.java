package juc.multithreading;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

public class CompletableFutureAPITest {

    public static void main(String[] args) throws ExecutionException, InterruptedException, TimeoutException {
        CompletableFuture<String> completableFuture = CompletableFuture.supplyAsync(() -> {
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return "hello CompletableFuture";
        });

//        System.out.println(completableFuture.getNow("心急吃不了热豆腐"));
//        System.out.println(completableFuture.get());
//        System.out.println(completableFuture.get(1500, TimeUnit.MILLISECONDS));
//        System.out.println(completableFuture.join());
        try{ TimeUnit.SECONDS.sleep(1);} catch (InterruptedException e){e.printStackTrace();}
        System.out.println(completableFuture.complete("未雨绸缪")+"\t"+completableFuture.join());

    }
}

