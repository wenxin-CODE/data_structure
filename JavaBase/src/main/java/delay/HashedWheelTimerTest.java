package delay;

import io.netty.util.HashedWheelTimer;
import io.netty.util.Timeout;
import io.netty.util.Timer;
import io.netty.util.TimerTask;
 
import java.util.concurrent.TimeUnit;

//https://mp.weixin.qq.com/s/kv8lHT7KuQhc3gMyiHYpaQ
//时间轮算法
//指定转盘有多少刻度刻度，每个刻度代表多长时间，然后旋转，到一定时间后，执行对应的任务
public class HashedWheelTimerTest {
    static class MyTimerTask implements TimerTask{
        boolean flag;
        public MyTimerTask(boolean flag){
            this.flag = flag;
        }
        public void run(Timeout timeout) throws Exception {
            // TODO Auto-generated method stub
             System.out.println("要去数据库删除订单了。。。。");
             this.flag =false;
        }
    }
    public static void main(String[] argv) {
        MyTimerTask timerTask = new MyTimerTask(true);
        Timer timer = new HashedWheelTimer();
        timer.newTimeout(timerTask, 5, TimeUnit.SECONDS);
        int i = 1;
        while(timerTask.flag){
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
            System.out.println(i+"秒过去了");
            i++;
        }
    }
}