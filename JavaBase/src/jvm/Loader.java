package jvm;

public class Loader {
    public static void main(String[] args) {
        Integer a = 1;
        System.out.println(a.getClass().getClassLoader());
    }
}
