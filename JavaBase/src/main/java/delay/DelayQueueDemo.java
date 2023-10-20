package delay;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.DelayQueue;
import java.util.concurrent.TimeUnit;


//延迟队列的两个方法
//Poll()：获取并移除队列的超时元素，没有则返回空
//take()：获取并移除队列的超时元素，如果没有则wait当前线程，直到有元素满足超时条件，返回结果
public class DelayQueueDemo {     
     public static void main(String[] args) {              
            // TODO Auto-generated method stub              
            List<String> list = new ArrayList<String>();              
            list.add("00000001");              
            list.add("00000002");              
            list.add("00000003");              
            list.add("00000004");              
            list.add("00000005");             
            DelayQueue<OrderDelay> queue = new DelayQueue<OrderDelay>();
            long start = System.currentTimeMillis();              
            for(int i = 0;i<5;i++){                  
                //延迟三秒取出                
                queue.put(new OrderDelay(list.get(i),                          
                        TimeUnit.NANOSECONDS.convert(3,TimeUnit.SECONDS)));                      
                    try {                           
                        queue.take().print();                           
                        System.out.println("After " +                                   
                                (System.currentTimeMillis()-start) + " MilliSeconds");                  
                } catch (InterruptedException e) {                      
                    // TODO Auto-generated catch block                     
                    e.printStackTrace();                 
                }             
            }        
     }      
}