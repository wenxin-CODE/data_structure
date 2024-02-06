package javaCollection;

import java.util.HashSet;

public class HashSetIncrement {
    public static void main(String[] args) {
        HashSet hashSet = new HashSet();
        //            初始table大小为16，加载因子为0.75，阈值为12，扩容二倍
//        for (int i = 0; i < 100; i++) {
//            hashSet.add(i);
//        }

//        满足两个条件时，Node就会变成TreeNode
        for (int i = 0; i < 12; i++) {
            hashSet.add(new A(i));
        }

        System.out.println("======");
    }
}

class A{
    private int a;

    public A(int a) {
        this.a = a;
    }

//    确保每次hashcode相同，加在同一个链表上
    @Override
    public int hashCode(){
        return 100;
    }
}
