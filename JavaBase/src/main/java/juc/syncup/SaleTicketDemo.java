package juc.syncup;

class Ticket
{
    private int num = 50;
    Object object = new Object();
    public void sale()
    {
        synchronized (object)
        {
            if(num>0)
            {
                System.out.println(Thread.currentThread().getName()+"卖出第"+(num--)+"还剩"+num);
            }
        }
    }
}

public class SaleTicketDemo {
    public static void main(String[] args) {
        Ticket ticket = new Ticket();
//        直接使用重量级锁
//        像这个程序，实际上大多数时候都是同一个线程抢到，每次都要切换用户/内核状态，费时间——这时候适合偏向锁
        new Thread(() -> {
            for (int i = 0; i < 55; i++) {
                ticket.sale();
            }
        },"a").start();
        new Thread(() -> {
            for (int i = 0; i < 55; i++) {
                ticket.sale();
            }
        },"b").start();
        new Thread(() -> {
            for (int i = 0; i < 55; i++) {
                ticket.sale();
            }
        },"c").start();
    }
}
