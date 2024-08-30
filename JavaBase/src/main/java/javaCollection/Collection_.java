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
        System.out.println("鍙嶈浆锛�"+ arrayList);
        Collections.shuffle(arrayList);
        System.out.println("娲楃墝锛�"+ arrayList);
        Collections.sort(arrayList);
//        涔熷彲鑷畾涔夋帓搴忚鍒檚ort(List, Comparator)
        System.out.println("鎺掑簭锛�"+ arrayList);
//        涔熷彲鑷畾涔夋帓搴忚鍒檓ax(List, Comparator)
        System.out.println("鑷劧鎺掑簭鐨勬渶澶у厓绱狅細"+ Collections.max(arrayList));
        Collections.swap(arrayList,0,2);
        System.out.println("璋冩崲锛�"+ arrayList);
        System.out.println("aa鍑虹幇鐨勯鐜囷細"+Collections.frequency(arrayList,"aa"));
        ArrayList arrayList1 = new ArrayList();
        for (int i = 0; i < 5; i++) {
            arrayList1.add("");
        }
        Collections.copy(arrayList1,arrayList);
//        娉ㄦ剰澶嶅埗瀵硅薄涓嶈兘涓虹┖锛屼笖瀹瑰繀椤诲ぇ浜庣瓑浜庤澶嶅埗瀵硅薄
        System.out.println("澶嶅埗锛�"+arrayList1);
        Collections.replaceAll(arrayList,"aa","AA");
        System.out.println("鏇挎崲锛�"+ arrayList);


    }
}
