package juc.multithreading;

public class Race implements Runnable{

    public static String winner;

    @Override
    public void run() {
        for (int i = 0; i <= 100; i++) {


            if(Thread.currentThread().getName().equals("兔子") && i/10==5){
                try {
                    Thread.sleep(20);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            if (GameOver(i)){
                break;
            }

            System.out.println(Thread.currentThread().getName()+"跑到"+i+"步");
        }
    }

    public boolean GameOver(int step){
        if (winner!=null){
            return true;
        }
        if (step>=100){
            winner = Thread.currentThread().getName();
            System.out.println("获胜者事"+winner);
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Race race = new Race();

        new Thread(race,"兔子").start();
        new Thread(race,"乌龟").start();
    }
}
