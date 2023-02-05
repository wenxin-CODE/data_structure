package juc.cas;
//
//import lombok.AllArgsConstructor;
//import lombok.Data;
//import lombok.NoArgsConstructor;
//import lombok.ToString;

import java.util.concurrent.atomic.AtomicStampedReference;

class Cat{
     String name;
     int age;

    public Cat(int age, String name) {
        this.name = name;
        this.age = age;
    }
}

public class AtomicStampedDemo {
    public static void main(String[] args) {
        Cat cat1 = new Cat(1,"狸花");
        Cat cat2 = new Cat(2,"奶牛");
        Cat cat3 = new Cat(3,"大橘");
        AtomicStampedReference<Cat> reference = new AtomicStampedReference<>(cat1,1);
        new Thread(()->{
            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("线程A修改结果"+reference.compareAndSet(cat1, cat2, reference.getStamp(), reference.getStamp()+1)+",stamp:"+reference.getStamp());
            reference.compareAndSet(cat2,cat1,reference.getStamp(),reference.getStamp()+1);
        },"A").start();

        new Thread(()->{
            int stamp = reference.getStamp();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("线程B修改结果"+reference.compareAndSet(cat1, cat3, stamp, stamp + 1)+",stamp:"+reference.getStamp());
        },"B").start();
    }
}
