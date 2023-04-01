package jvm;

public class Car {
    private int age;

    public static void main(String[] args) {
        Car car1 = new Car();
        Car car2 = new Car();
        Car car3 = new Car();

//        System.out.println(car1.hashCode());
//        System.out.println(car2.hashCode());
//        System.out.println(car3.hashCode());

        Class<? extends Car> aClass1 = car1.getClass();
//        Class<? extends Car> aClass2 = car2.getClass();
//        Class<? extends Car> aClass3 = car3.getClass();
//
//        System.out.println(aClass1.hashCode());
//        System.out.println(aClass2.hashCode());
//        System.out.println(aClass3.hashCode());

//        ========================================================
        ClassLoader classLoader = aClass1.getClassLoader();
        System.out.println(classLoader);//AppClassLoader用户类加载器
        System.out.println(classLoader.getParent());//ExtClassLoader扩展类加载器
        System.out.println(classLoader.getParent().getParent());//值为null，要么不存在；要么是C编写的，获取不到

    }
}
