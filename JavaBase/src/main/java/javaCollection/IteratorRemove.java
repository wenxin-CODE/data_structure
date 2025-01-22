package javaCollection;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class IteratorRemove {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);
        list.add(6);
        Iterator<Integer> iterator = list.iterator();
        while(iterator.hasNext()){
            int val = iterator.next();
            if(val == 3){
                // list.remove(val);//Exception in thread "main" java.util.ConcurrentModificationException
                //不能直接在list中删除元素，否则会报异常
                iterator.remove();
            }
        }
        for (Integer integer : list) {
            System.out.println(integer);
        }
    }
}
