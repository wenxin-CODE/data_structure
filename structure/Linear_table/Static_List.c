#include<stdio.h>
#include<stdlib.h>
#define maxSize 6
//通过 "数组+游标" 的方式存储具有线性关系数据的存储结构就是静态链表。

typedef struct {
    int data;//数据域
    int cur;//游标
}component;

//将结构体数组中所有分量链接到备用链表中
void reserveArr(component *array);
//初始化静态链表
int initArr(component *array);
//输出函数
void displayArr(component * array,int body);
//从备用链表上摘下空闲节点的函数
int mallocArr(component * array);

int main() {
    component array[maxSize];
    int body=initArr(array);
    printf("静态链表为：\n");
    displayArr(array, body);
    return 0;
}

//创建备用链表
void reserveArr(component *array){
    for (int i=0; i<maxSize; i++) {
        array[i].cur=i+1;//将每个数组分量链接到一起
        array[i].data=-1;
    }
    array[maxSize-1].cur=0;//链表最后一个结点的游标值为0
}

//提取分配空间
int mallocArr(component * array){
    //若备用链表非空，则返回分配的结点下标，否则返回 0（当分配最后一个结点时，该结点的游标值为 0）
    int i=array[0].cur;
    if (array[0].cur) {
        array[0].cur=array[i].cur;
    }
    return i;
}

//初始化静态链表
int initArr(component *array){
    reserveArr(array);
    int body=mallocArr(array);
    //声明一个变量，把它当指针使，指向链表的最后的一个结点，因为链表为空，所以和头结点重合
    int tempBody=body;
    for (int i=1; i<4; i++) {
        int j=mallocArr(array);//从备用链表中拿出空闲的分量
        array[tempBody].cur=j;//将申请的空闲分量链接在链表的最后一个结点后面
        array[j].data=i;//给新申请的分量的数据域初始化
        tempBody=j;//将指向链表最后一个结点的指针后移
    }
    array[tempBody].cur=0;//新的链表最后一个结点的指针设置为0
    return body;
}

void displayArr(component * array,int body){
    int tempBody=body;//tempBody准备做遍历使用
    while (array[tempBody].cur) {
        printf("%d,%d ",array[tempBody].data,array[tempBody].cur);
        tempBody=array[tempBody].cur;
    }
    printf("%d,%d\n",array[tempBody].data,array[tempBody].cur);
}
