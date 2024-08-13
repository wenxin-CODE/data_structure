//package main.java.rules;
//
//import com.sun.org.apache.xalan.internal.xsltc.dom.SingletonIterator;
//
//import java.text.SimpleDateFormat;
//import java.util.Date;
//import java.util.concurrent.CountDownLatch;
//import java.util.concurrent.ExecutorService;
//import java.util.concurrent.Executors;
//
//class Concurrent{
//    public static void main(String[]args){
//
//        Singlenton s=new Singleton();
//        System.out.println(s.getInstance());
//
//    }
//}
//
////1、获取单例对象保证线程安全
//class Singleton {
//    private volatile static Singleton instance;
//
//    private Singleton() { }
//
//    public static Singleton getInstance() {
//        if (instance == null) {
//            synchronized (Singleton.class) {
//                if (instance == null) {
//                    instance = new Singleton();
//                }
//            }
//        }
//        return instance;
//    }
//}
//
////2、禁止自行创建线程。从线程池中获取【内存占用低，管理方便】
//class ThreadPoolExample {
//    public static void main(String[] args) {
//        // 创建固定大小的线程池
//        ExecutorService executor = Executors.newFixedThreadPool(5);
//
//        // 提交任务给线程池执行
//        for (int i = 0; i < 10; i++) {
//            Runnable task = new WorkerThread("Task " + i);
//            executor.execute(task);
//        }
//
//        // 关闭线程池
//        executor.shutdown();
//    }
//}
//
//class WorkerThread implements Runnable {
//    private String taskName;
//
//    public WorkerThread(String taskName) {
//        this.taskName = taskName;
//    }
//
//    @Override
//    public void run() {
//        System.out.println(Thread.currentThread().getName() + " executing " + taskName);
//        // 执行任务的具体逻辑
//    }
//}
//
////SImpleDataFormat线程不安全，定义为static要加锁
//class SafeDateFormatExample {
//    private static final Object lock = new Object();
//    private static final SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
//
//    public static void main(String[] args) {
//        Runnable task = () -> {
//            try {
//                parseAndPrintDate("2022-01-01 12:30:45");
//            } catch (ParseException e) {
//                e.printStackTrace();
//            }
//        };
//
//        // 启动多个线程来同时解析日期
//        for (int i = 0; i < 5; i++) {
//            new Thread(task).start();
//        }
//    }
//
//    private static void parseAndPrintDate(String dateString) throws ParseException {
//        synchronized (lock) {
//            Date date = sdf.parse(dateString);
//            System.out.println(Thread.currentThread().getName() + ": Parsed date: " + date);
//        }
//    }
//}
//
////线程池使用THreadPoolExecutor创建，Executor会出现OOM，请求堆积，线程太多
//class NewFixedTest {
//
//    public static void main(String[] args) {
//        ExecutorService executor = ThreadPoolExecutor.newFixedThreadPool(10);
//        for (int i = 0; i < Integer.MAX_VALUE; i++) {
//            executor.execute(() -> {
//                try {
//                    Thread.sleep(10000);
//                } catch (InterruptedException e) {
//                    //do nothing
//                }
//            });
//        }
//    }
//}
//
////高并发注意锁的粒度
////private void slowNotShare() {
////    try {
////        TimeUnit.MILLISECONDS.sleep(100);
////    } catch (InterruptedException e) {
////    }
////}
////
////public int right() {
////    long beginTime = System.currentTimeMillis();
////    IntStream.rangeClosed(1, 10000).parallel().forEach(i -> {
////        slowNotShare();//可以不加锁
////        //只对List这部分加锁
////        synchronized (data) {
////            data.add(i);
////        }
////    });
////    log.info("cosume time:{}", System.currentTimeMillis() - beginTime);
////    return data.size();
////}
////
//////错误的加锁方法
////public int wrong() {
////    long beginTime = System.currentTimeMillis();
////    IntStream.rangeClosed(1, 10000).parallel().forEach(i -> {
////        //加锁粒度太粗了，slowNotShare其实不涉及共享资源
////        synchronized (this) {
////            slowNotShare();
////            data.add(i);
////        }
////    });
////    log.info("cosume time:{}", System.currentTimeMillis() - beginTime);
////    return data.size();
////}
//
////使用 CountDownLatch 进行异步转同步操作，每个线程退出前必须调用 countDown方法。
//class AsyncToSyncExample {
//    public static void main(String[] args) throws InterruptedException {
//        int numThreads = 3; // 假设有3个线程
//
//        // 创建一个 CountDownLatch，计数器初始化为线程数量
//        CountDownLatch latch = new CountDownLatch(numThreads);
//
//        // 启动多个线程
//        for (int i = 0; i < numThreads; i++) {
//            Thread thread = new Thread(() -> {
//                try {
//                    // 线程执行的业务逻辑
//                    doSomeWork();
//                } catch (Exception e) {
//                    e.printStackTrace();
//                } finally {
//                    // 无论如何，都需要调用 countDown 方法
//                    latch.countDown();
//                }
//            });
//            thread.start();
//        }
//
//        // 等待所有线程完成，最多等待5秒（超时时间可以根据实际情况调整）
//        if (!latch.await(5000, java.util.concurrent.TimeUnit.MILLISECONDS)) {
//            // 超时处理逻辑
//            System.out.println("Timeout while waiting for threads to finish.");
//        } else {
//            // 所有线程执行完成后的逻辑
//            System.out.println("All threads have finished their work.");
//        }
//    }
//
//    private static void doSomeWork() {
//        // 模拟线程执行的业务逻辑
//        try {
//            Thread.sleep(2000);
//            System.out.println(Thread.currentThread().getName() + " has finished its work.");
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }
//    }
//}
//
//// 对多个资源、数据库表、对象同时加锁时，需要保持一致的加锁顺序，否则可能会造成死锁。
//class DeadlockExample {
//    private static final Object lockA = new Object();
//    private static final Object lockB = new Object();
//
//    public static void main(String[] args) {
//        Thread thread1 = new Thread(() -> {
//            synchronized (lockA) {
//                System.out.println("Thread 1 acquired lockA");
//                try {
//                    Thread.sleep(100);
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//
//                synchronized (lockB) {
//                    System.out.println("Thread 1 acquired lockB");
//                }
//            }
//        });
//
//        Thread thread2 = new Thread(() -> {
//            // 保持一致的加锁顺序，先尝试获取 lockA，再获取 lockB
//            synchronized (lockA) {
//                System.out.println("Thread 2 acquired lockA");
//                try {
//                    Thread.sleep(100);
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//
//                synchronized (lockB) {
//                    System.out.println("Thread 2 acquired lockB");
//                }
//            }
//        });
//
//        thread1.start();
//        thread2.start();
//    }
//}
