package javaCollection;

import java.util.HashMap;
import java.util.Map;

public class MapExercise {
    public static void main(String[] args) {
        Map hashMap = new HashMap();
        hashMap.put(1,new Emp("aa",1000,1));
        hashMap.put(2,new Emp("bb",2000,2));
        hashMap.put(3,new Emp("cc",3000,3));
        hashMap.put(4,"long");

        for (Object o : hashMap.keySet()) {
            if(hashMap.get(o) instanceof Emp){
                Emp jj = (Emp) hashMap.get(o);
                if(jj.getSal()>1500){
                    System.out.println(jj);
                }
            }
        }


    }
}

class Emp{
    private String name;
    private int sal;
    private int id;

    public Emp(String name, int sal, int id) {
        this.name = name;
        this.sal = sal;
        this.id = id;
    }

    @Override
    public String toString() {
        return "Emp{" +
                "name='" + name + '\'' +
                ", sal=" + sal +
                ", id=" + id +
                '}';
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getSal() {
        return sal;
    }

    public void setSal(int sal) {
        this.sal = sal;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
}
