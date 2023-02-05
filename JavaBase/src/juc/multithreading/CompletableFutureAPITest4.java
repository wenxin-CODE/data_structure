package juc.multithreading;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.TimeUnit;

//选择速度快的 & 结果合并
public class CompletableFutureAPITest4 {
    public static void main(String[] args) {
        CompletableFuture<String> first = CompletableFuture.supplyAsync(() -> {
            try {
                TimeUnit.SECONDS.sleep(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return "1号选手";
        });
        CompletableFuture<String> second = CompletableFuture.supplyAsync(() -> {
            try {
                TimeUnit.SECONDS.sleep(2);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return "2号选手";
        });
        CompletableFuture<String> result = first.applyToEither(second, r -> r + "is winner");
        CompletableFuture<String> res = first.thenCombine(second, (x, y) -> {
            return x +'和'+ y;
        });
        System.out.println(result.join());
        System.out.println("=========================");
        System.out.println(res.join());
    }
}

