package javaCollection;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class CollectionIterator {
    public static void main(String[] args) {
        final Book book1 = new Book("aaa", "xx", 10);
        final Book book2 = new Book("aaa", "xx", 10);
        final Book book3 = new Book("aaa", "xx", 10);
        List<Book> list1 = new ArrayList<Book>();
        list1.add(book1);
        list1.add(book2);
        list1.add(book3);

        Iterator iterator = list1.iterator();
        while(iterator.hasNext()){
            final Object next = iterator.next();
//            想要输出对象里面的内容，需实现tostring方法
            System.out.println("obj="+next);
        }
//        此时迭代器也到达collection底部，如果后面还想遍历，建议执行下面操作，不然会抛出异常
         iterator = list1.iterator();
        System.out.println("==============重置==================");
//        增强的for循环遍历，只适用于集合&数组，其底层仍使用的是迭代器，可以调试一下
        for(Object book:list1){
            System.out.println("obj="+book);
        }

    }
}

class Book{
    private String name;
    private String author;
    private int price;

    public Book(String name, String author, int price) {
        this.name = name;
        this.author = author;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public String getAuthor() {
        return author;
    }

    public int getPrice() {
        return price;
    }

    @Override
    public String toString() {
        return "Book{" +
                "name='" + name + '\'' +
                ", author='" + author + '\'' +
                ", price=" + price +
                '}';
    }
}
