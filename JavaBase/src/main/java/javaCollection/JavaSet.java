package javaCollection;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class JavaSet {
    public static void main(String[] args) {
        Set hashSet = new HashSet();
        hashSet.add("tom");
        hashSet.add("mike");
        hashSet.add("alice");
        hashSet.add("daved");
        hashSet.add(null);

//        输出顺序是固定的
        for (int i = 0; i < 10; i++) {
            Iterator iterator = hashSet.iterator();
            while (iterator.hasNext()){
                Object o = iterator.next();
                System.out.print(o+" ");
            }
            System.out.println();
        }


    }
}
