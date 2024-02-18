package javaCollection;

import java.util.HashMap;

public class JavaTreeMap {
    public static void main(String[] args) {
        HashMap hashMap = new HashMap();
        for (int i = 0; i < 15; i++) {
//            链表长度到8，table开始扩容；table容量达到64，链表树化
            hashMap.put(new AA(i),"hello"+i);
        }
        System.out.println(hashMap);
    }
}

class AA {
    private int num;

    public AA(int num) {
        this.num = num;
    }

    @Override
    public int hashCode() {
        return 100;
    }

    @Override
    public String toString() {
        return "A{" +
                "num=" + num +
                '}'+'\n';
    }
}
