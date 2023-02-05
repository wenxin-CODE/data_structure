package juc.multithreading;

import java.util.Arrays;
import java.util.List;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.TimeUnit;
import java.util.stream.Collectors;

public class CompletableFutureDemo {
    static List<NetMall> list = Arrays.asList(
            new NetMall("vip"),
            new NetMall("jd"),
            new NetMall("tb"),
            new NetMall("pdd")
    );
    public static void main(String[] args) {
        long cur1 = System.currentTimeMillis();
        getPrice("Phone").forEach(r-> System.out.println(r));
        System.out.println("getPrice耗时"+(System.currentTimeMillis()-cur1));
        long cur2 = System.currentTimeMillis();
        getPriceByCompletableFuture("Phone").forEach(r-> System.out.println(r));
        System.out.println("getPriceByCompletableFuture耗时"+(System.currentTimeMillis()-cur2));
    }

//    一家一家搜索
    private static List<String> getPrice(String productName){
//        流式计算
        return list.stream()
                .map(r->String.format(productName+" in %s price is %.2f",r.getName(),r.calcPrice(productName)))
                .collect(Collectors.toList());
    }

//    list<netMall>-->list<completablefuture<string>>-->list<string>
    private static List<String> getPriceByCompletableFuture(String productName){
        return list.stream()
                .map(r-> CompletableFuture.supplyAsync(()->String.format(productName+" in %s price is %.2f",r.getName(),r.calcPrice(productName))))
                .collect(Collectors.toList())
                .stream()
                .map(s->s.join())
                .collect(Collectors.toList());
    }
}
class NetMall{
    private String name;

    public double calcPrice(String productName){
        try {
            TimeUnit.SECONDS.sleep(1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return  ThreadLocalRandom.current().nextDouble(100000000)+productName.hashCode();
    }

    public NetMall(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
