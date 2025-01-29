package javaCollection;

import java.util.Comparator;
import java.util.TreeSet;


//TreeMap鍚岀悊

public class JavaTreeSet {
    public static void main(String[] args) {
        TreeSet treeSet = new TreeSet(new Comparator() {
            @Override
            public int compare(Object o1, Object o2) {
               return ((String) o1).compareTo((String) o2);//这种方式会返回PHP
                // return ((String) o1).length()-((String) o2).length();//这种方式不包含PHP
            }
        });


        treeSet.add("java");
        treeSet.add("python");
        treeSet.add("C++");
        treeSet.add("PHP");

        System.out.println("treeset= "+treeSet);
    }
}
