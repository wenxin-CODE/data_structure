package javaCollection;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class JavaMap {
    public static void main(String[] args) {

        Map hashMap = new HashMap();
        hashMap.put("no.1","dby");
        hashMap.put("no.2","dxy");
        hashMap.put("no.3","dwy");

        Set set = hashMap.entrySet();//EntrySet<Entry<k,v>>
        System.out.println(set.getClass());
        for (Object obj:
             set) {
            System.out.println(obj.getClass());
//            Node实现了Entry接口，上转为Entry
            Map.Entry entry = (Map.Entry) obj;
//            entry的两个方法
            System.out.println(entry.getKey()+"--"+entry.getValue());
        }

//        通过所有的key遍历:增强for、迭代器
        Set set1 = hashMap.keySet();
        for (Object obj:set1) {
            System.out.println(hashMap.get(obj));
        }

//        直接取出value
        Collection values = hashMap.values();
//        通过collection遍历 方法

    }
}
