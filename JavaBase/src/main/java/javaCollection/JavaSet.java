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

        hashSet.remove("null");

//        输出顺序是固定的
        for (int i = 0; i < 10; i++) {
            Iterator iterator = hashSet.iterator();
            while (iterator.hasNext()){
                Object o = iterator.next();
                System.out.print(o+" ");
            }
            System.out.println();
        }

        HashSet hashSet1 = new HashSet();
        System.out.println(hashSet1.add("Alice"));
        System.out.println(hashSet1.add("Alice"));
        System.out.println(hashSet1.add(new Dog("Alice")));
        System.out.println(hashSet1.add(new Dog("Alice")));
        System.out.println(hashSet1.add(new String("Alice")));
        System.out.println(hashSet1.add(new String("Bob")));
        System.out.println(hashSet1.add(new String("Bob")));
        System.out.println(hashSet1.add(new Integer(12)));
        System.out.println(hashSet1.add(new Integer(12)));


    }
}

class Dog{
    public String name;

    Dog(String name){
        this.name=name;
    }

    @Override
    public String toString() {
        return "Dog{" +
                "name='" + name + '\'' +
                '}';
    }
}

