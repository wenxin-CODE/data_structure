package juc.multithreading;

import java.util.concurrent.CompletableFuture;

public class CompletableFutureAPITest3 {
    public static void main(String[] args) {
//        对计算结果进行消费，无返回值
//        CompletableFuture.supplyAsync(()->{
//            return 3;
//        }).thenApply(r->{
//            return r*8;
//        }).thenApply(r->{
//            return r/2;
//        }).thenAccept(r-> System.out.println(r));

//        三种处理方式对比
        System.out.println(CompletableFuture.supplyAsync(()->"6666").thenRun(()->{}).join());
        System.out.println(CompletableFuture.supplyAsync(()->"6666").thenAccept(r-> System.out.println(r)).join());
        System.out.println(CompletableFuture.supplyAsync(()->"6666").thenApply(r->r+"9999").join());
    }
}

