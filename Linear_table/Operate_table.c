#include <stdio.h>
#include <stdlib.h>
#define Size 5

typedef struct Table{
    int * head;
    int length;
    int size;
}table;

table initTable(){
    table t;
    t.head=(int*)malloc(Size*sizeof(int));
    if (!t.head)
    {
        printf("初始化失败\n");
        exit(0);
    }
    t.length=0;
    t.size=Size;
    return t;
}

table addTable(table t,int elem,int add)
{
    if (add>t.length+1||add<1) {
        printf("插入位置有问题\n");
        return t;
    }
    if (t.length>=t.size) {
        t.head=(int *)realloc(t.head, (t.size+1)*sizeof(int));
        if (!t.head) {
            printf("存储分配失败\n");
        }
        t.size+=1;
    }
    for (int i=t.length-1; i>=add-1; i--) {
        t.head[i+1]=t.head[i];
    }
    t.head[add-1]=elem;
    t.length++;
    return t;
}

table delTable(table t,int add){
    if (add>t.length || add<1) {
        printf("被删除元素的位置有误\n");
        return t;
    }
    for (int i=add; i<t.length; i++) {
        t.head[i-1]=t.head[i];
    }
    t.length--;
    return t;
}

int selectTable(table t,int elem){
    for (int i=0; i<t.length; i++) {
        if (t.head[i]==elem) {
            return i+1;
        }
    }
    return -1;
}

table amendTable(table t,int elem,int newElem){
    int add=selectTable(t, elem);
    t.head[add-1]=newElem;
    return t;
}

void displayTable(table t){
    for (int i=0;i<t.length;i++) {
        printf("%d ",t.head[i]);
    }
    printf("\n");
}

int main(){
    table t1=initTable();
    for (int i=1; i<=Size; i++) {
        t1.head[i-1]=i;
        t1.length++;
    }
    printf("原顺序表：\n");
    displayTable(t1);
  
    printf("删除元素1:\n");
    t1=delTable(t1, 1);
    displayTable(t1);
  
    printf("在第2的位置插入元素5:\n");
    t1=addTable(t1, 5, 2);
    displayTable(t1);
  
    printf("查找元素3的位置:\n");
    int add=selectTable(t1, 3);
    printf("%d\n",add);
  
    printf("将元素3改为6:\n");
    t1=amendTable(t1, 3, 6);
    displayTable(t1);
    return 0;
}