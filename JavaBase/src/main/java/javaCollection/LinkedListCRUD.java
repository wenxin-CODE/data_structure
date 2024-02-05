package javaCollection;

import java.util.Iterator;
import java.util.LinkedList;

public class LinkedListCRUD {
    public static void main(String[] args) {
//        无参构造
        LinkedList linkedList = new LinkedList();
        linkedList.add(1);
        linkedList.add(2);
        linkedList.add(3);
        linkedList.add(null);
        linkedList.add(null);
//        执行linklast方法：创建新节点存储数据，然后将last指针指向新创建的节点
        System.out.println(linkedList);
        linkedList.set(1,999);
        System.out.println(linkedList);
//        链表的删除步骤
        linkedList.remove(2);
        System.out.println(linkedList);

        System.out.println("================================");
        Iterator iterator = linkedList.iterator();
        while (iterator.hasNext()){
            Object next = iterator.next();
            System.out.println("next="+next);
        }

    }
}
