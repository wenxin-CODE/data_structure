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
        printf("初始化失败");
        exit(0);
    }
    t.length=0;
    t.size=Size;
    return t;
}

//输出顺序表中元素的函数
void displayTable(table t){
    for (int i=0;i<t.length;i++) {
        printf("%d ",t.head[i]);
    }
    printf("\n");
}

int main(){
    table t=initTable();
    //向顺序表中添加元素
    for (int i=1; i<=Size; i++) {
        t.head[i-1]=i;
        t.length++;
    }
    printf("顺序表中存储的元素分别是：\n");
    displayTable(t);
    return 0;
}