package javaCollection;

import java.util.ArrayList;
import java.util.Collections;

public class Collection_ {
    public static void main(String[] args) {
        ArrayList arrayList = new ArrayList();
        arrayList.add("aa");
        arrayList.add("bb");
        arrayList.add("cc");
        arrayList.add("aa");

        Collections.reverse(arrayList);
        System.out.println("反转："+ arrayList);
        Collections.shuffle(arrayList);
        System.out.println("洗牌："+ arrayList);
        Collections.sort(arrayList);
//        也可自定义排序规则sort(List, Comparator)
        System.out.println("排序："+ arrayList);
//        也可自定义排序规则max(List, Comparator)
        System.out.println("自然排序的最大元素："+ Collections.max(arrayList));
        Collections.swap(arrayList,0,2);
        System.out.println("调换："+ arrayList);
        System.out.println("aa出现的频率："+Collections.frequency(arrayList,"aa"));
        ArrayList arrayList1 = new ArrayList();
        for (int i = 0; i < 4; i++) {
            arrayList1.add("");
        }
        Collections.copy(arrayList1,arrayList);
//        注意复制对象不能为空，且容必须大于等于被复制对象
        System.out.println("复制："+arrayList1);
        Collections.replaceAll(arrayList,"aa","AA");
        System.out.println("替换："+ arrayList);


    }
}
