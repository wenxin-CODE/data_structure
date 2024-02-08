package javaCollection;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class JavaMap {
    public static void main(String[] args) {

        Map hashMap = new HashMap();
        hashMap.put("no.1","dby");
        hashMap.put("no.2","dxy");
        hashMap.put("no.3","dwy");

        Set set = hashMap.entrySet();
        System.out.println(set.getClass());
        for (Object obj:
             set) {
            System.out.println(obj.getClass());
            Map.Entry entry = (Map.Entry) obj;
            System.out.println(entry.getKey()+"--"+entry.getValue());
        }

    }
}
