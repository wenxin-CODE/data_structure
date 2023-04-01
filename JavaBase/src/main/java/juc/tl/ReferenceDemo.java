package juc.tl;

import java.lang.ref.*;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

class MyObject
{
    @Override
    protected void finalize() throws Throwable
    {
//        对象被丢弃前执行的操作,但由于并发性，可能显示在回收之后
        System.out.println("-------不要了-----");
    }
}

public class ReferenceDemo {
    public static void main(String[] args) {
        MyObject myObject = new MyObject();
        ReferenceQueue<MyObject> objectReferenceQueue = new ReferenceQueue<>();
        PhantomReference<MyObject> myObjectPhantomReference = new PhantomReference<>(myObject, objectReferenceQueue);
        List<byte[]> list = new ArrayList<>();

//        先设置内存10MB
        new Thread(()-> {
            while (true)
            {
                list.add(new byte[1*1024*1024]);
                try {
                    TimeUnit.MILLISECONDS.sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println(myObjectPhantomReference.get()+" list add ok");
            }
        },"t1").start();

        new Thread(()->{
            while (true){
                Reference<? extends MyObject> poll = objectReferenceQueue.poll();
                if(poll!=null){
                    System.out.println("回收了虚对象到队列");
                    break;
                }
            }
        },"t2").start();
    }

    private static void weakReference() {
        WeakReference<MyObject> myObjectWeakReference = new WeakReference<>(new MyObject());
        System.out.println("内存够用"+myObjectWeakReference.get());
        System.gc();
        System.out.println("内存够用"+myObjectWeakReference.get());
    }

    private static void softReference() {
        SoftReference<MyObject> myObjectSoftReference = new SoftReference<>(new MyObject());

        System.gc();//其实这个内存不够时是自动执行的
        System.out.println("内存够用"+myObjectSoftReference.get());

//        设置内存仅10MB
        try {
            byte[] bytes = new byte[20*1024*1024];
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            System.out.println("内存不够"+myObjectSoftReference.get());
        }
    }

    private static void strongReference() {
        MyObject myObject = new MyObject();
        System.out.println("gc before:"+myObject);

//        强引用设为null，才会回收
        myObject=null;
        System.gc();
        try {
            TimeUnit.MILLISECONDS.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("gc after:"+myObject);
    }
}
