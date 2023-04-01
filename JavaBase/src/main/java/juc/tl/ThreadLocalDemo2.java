package juc.tl;

import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class MyData
{
    ThreadLocal<Integer> threadLocal = ThreadLocal.withInitial(() -> 0);
    public void add()
    {
        threadLocal.set(1+threadLocal.get());
    }
}

public class ThreadLocalDemo2 {
    public static void main(String[] args) {
        MyData myData = new MyData();
        ExecutorService executorService = Executors.newFixedThreadPool(3);

        try {
            for (int i = 0; i < 10; i++) {
                executorService.submit(() -> {
                    try {
                        Integer before = myData.threadLocal.get();
                        myData.add();
                        Integer after4 = myData.threadLocal.get();
                        System.out.println(Thread.currentThread().getName()+"\t"+before+"\t"+after4);
                    } finally {
//                        线程池用完之后一定要删除，不然后面用会保留前面的结果继续操作
                        myData.threadLocal.remove();
                    }

                });
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            executorService.shutdown();
        }
    }
}
