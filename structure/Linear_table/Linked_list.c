// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Link
// {
//     /* data */
//     char elem;//数据域
//     struct Link * next;//指针域
// }link;//节点名

// link *initLink(){
//     // link *p = NULL;//创建头指针
//     // link *temp = (link*)malloc(sizeof(link));//创建首元素结点
//     // //初始化首元素结点
//     // temp->elem=1;
//     // temp->next=NULL;
//     // p=temp;//头指针指向首元素结点
//     // for(int i=2;i<5;i++){
//     //     link *a=(link*)malloc(sizeof(link));
//     //     a->elem=i;
//     //     a->next=NULL;
//     //     temp->next=a;//建立逻辑关系
//     //     temp=temp->next;//指向最后一个节点
//     // }
//     // return p;

//     //包含头节点的方法
//     link * p=(link*)malloc(sizeof(link));//创建一个头结点
//     link * temp=p;//声明一个指针指向头结点，
//     //生成链表
//     for (int i=1; i<5; i++) {
//         link *a=(link*)malloc(sizeof(link));
//         a->elem=i;
//         a->next=NULL;
//         temp->next=a;
//         temp=temp->next;
//     }
//     return p;
// }

// void display(link *p){
//     // link *temp=p;
//     // while(temp){
//     //     printf("%d   ",temp->elem);
//     //     temp=temp->next;
//     // }
//     // printf("\n");

//     //带头结点的遍历
//     link* temp=p;//将temp指针重新指向头结点
//     //只要temp指针指向的结点的next不是Null，就执行输出语句。
//     while (temp->next) {
//         temp=temp->next;
//         printf("%d",temp->elem);
//     }
//     printf("\n");
// }

// link * insertELem(link *p,int elem,int add){
//     link *temp = p;
//     //找到要插入位置的上一个节点
//     for(int i=1;i<add;i++){
//         temp = temp->next;
//         if(temp == NULL){
//             printf("插入位置无效\n");
//             return p;
//         }
//     }
//     //创建插入节点
//     link *c = (link*)malloc(sizeof(link));
//     c->elem = elem;
//     c->next = temp->next;
//     //插入节点
//     temp->next=c;
//     return p;
// }

// link *delElem(link *p,int del){
//     link *temp = p;
//     //遍历到待删除节点的上一个
//     for(int i=1;i<del;i++){
//         temp = temp->next;
//         if(temp->next == NULL){
//             printf("没有该节点\n");
//             return p;
//         }
//     }
//     link *delet = temp->next;//保存待删除元素，后面释放
//     temp->next = temp->next->next;//修改指针
//     free(delet);
//     return p;
// }

// int selectELem(link *p,int elem){
//     link *t=p;
//     int i=1;
//     //有头节点，要用t->next
//     while(t->next){
//         if(t->elem == elem){
//             return i;
//             /* code */
//         }
//         i++;
//     }
//     //没有元素
//     return -1;
// }

// link *renameElem(link *p,int change,int newElem){
//     link *temp = p;
//     temp = temp->next;
//     for(int i=1;i<change;i++){
//         temp = temp->next;
//     }
//     temp->elem = newElem;
//     return p;
// }

// int main(){
//     printf("初始化链表 ：\n");
//     link *p = initLink();
//     // *p=*p->next;
//     // printf("%d",p->elem);
//     display(p);

//     // printf("在第4的位置插入元素5：\n");
//     // p = insertELem(p,5,4);
//     // display(p);
//     printf("删除元素3:\n");
//     p = delElem(p, 3);
//     display(p);
//     printf("查找元素2的位置为：\n");
//     int address = selectELem(p, 2);
//     if (address == -1) {
//         printf("没有该元素");
//     }
//     else {
//         printf("元素2的位置为：%d\n", address);
//     }
//     printf("更改第3的位置上的数据为7:\n");
//     p = renameElem(p, 3, 7);
//     display(p);
//     return 0;
// }


#include<stdio.h>
#include <stdlib.h>

typedef struct Link {
    int  elem;
    struct Link *next;
}link;
link * initLink();
//链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
link * insertElem(link * p, int elem, int add);
//删除结点的函数，p代表操作链表，add代表删除节点的位置
link * delElem(link * p, int add);
//查找结点的函数，elem为目标结点的数据域的值
int selectElem(link * p, int elem);
//更新结点的函数，newElem为新的数据域的值
link *amendElem(link * p, int add, int newElem);
void display(link *p);
link* reverseList(link *p);

int main() {
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    link *p = initLink();
    display(p);

    printf("反转链表");
    p = reverseList(p);
    display(p);

    printf("在第4的位置插入元素5：\n");
    p = insertElem(p, 5, 4);
    display(p);

    printf("删除元素3:\n");
    p = delElem(p, 3);
    display(p);

    printf("查找元素2的位置为：\n");
    int address = selectElem(p, 2);
    if (address == -1) {
        printf("没有该元素");
    }
    else {
        printf("元素2的位置为：%d\n", address);
    }
    printf("更改第3的位置上的数据为7:\n");
    p = amendElem(p, 3, 7);
    display(p);

    return 0;
}

link* reverseList(link* head) {
    link* pre = nullptr;
    link* cur = head;
    while(cur){
        link* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    link* p = (link*)malloc(sizeof(link));
    p->next = pre;
    // delElem(p,-1163005939);
    return p;
}

link * initLink() {
    link * p = (link*)malloc(sizeof(link));//创建一个头结点
    link * temp = p;//声明一个指针指向头结点，用于遍历链表
    //生成链表
    for (int i = 1; i < 5; i++) {
        link *a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}
link * insertElem(link * p, int elem, int add) {
    link * temp = p;//创建临时结点temp
    //首先找到要插入位置的上一个结点
    for (int i = 1; i < add; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("插入位置无效\n");
            return p;
        }
    }
    //创建插入结点c
    link * c = (link*)malloc(sizeof(link));
    c->elem = elem;
    //向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    return  p;
}

link * delElem(link * p, int add) {
    link * temp = p;
    //遍历到被删除结点的上一个结点
    for (int i = 1; i < add; i++) {
        temp = temp->next;
        if (temp->next == NULL) {
            printf("没有该结点\n");
            return p;
        }
    }
    link * del = temp->next;//单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
    free(del);//手动释放该结点，防止内存泄漏
    return p;
}
int selectElem(link * p, int elem) {
    link * t = p;
    int i = 1;
    while (t->next) {
        t = t->next;
        if (t->elem == elem) {
            return i;
        }
        i++;
    }
    return -1;
}
link *amendElem(link * p, int add, int newElem) {
    link * temp = p;
    temp = temp->next;//tamp指向首元结点
    //temp指向被删除结点
    for (int i = 1; i < add; i++) {
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}
void display(link *p) {
    link* temp = p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next) {
        temp = temp->next;
        printf("%d ", temp->elem);
    }
    printf("\n");
}