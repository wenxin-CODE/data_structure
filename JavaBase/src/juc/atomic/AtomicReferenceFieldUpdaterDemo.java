package juc.atomic;

import java.util.concurrent.atomic.AtomicReferenceFieldUpdater;

public class AtomicReferenceFieldUpdaterDemo {
    public static void main(String[] args) {
        Fish fish = new Fish();
        for (int i = 0; i < 5; i++) {
            new Thread(() -> {
                fish.init();
            }).start();
        }
    }

    static class Fish {
        volatile Boolean isLive = Boolean.FALSE;
        AtomicReferenceFieldUpdater<Fish, Boolean> updater = AtomicReferenceFieldUpdater.newUpdater(Fish.class, Boolean.class, "isLive");

        public void init() {
            if (updater.compareAndSet(this, Boolean.FALSE, Boolean.TRUE)) {
                System.out.println("初始化的线程：" + Thread.currentThread().getName());
            } else {
                System.out.println("==========已被其他线程初始化============="+Thread.currentThread().getName());
            }
        }
    }

}
