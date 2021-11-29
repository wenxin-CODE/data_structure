#include "stdio.h"
#include "stdlib.h"

using namespace std;

// =================================循环队列存储
#define MaxSize 10
typedef int ELement;
typedef struct{
    ELement data[MaxSize];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.front=Q.rear=0;
    // 这里都指向表头，也有其他方法
}

bool IsEmpty(SqQueue Q){
    // 判空操作依据定义的不同可以不同，例如使用size，或tag（表示插入还是删除）
    if(Q.front == Q.rear)
        return true;
    else
        return false;
}

bool EnQueue(SqQueue &Q,ELement i){
    if((Q.rear+1)%MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = i;
    Q.rear = (Q.rear+1)%MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q,ELement &i){
    if(Q.rear == Q.front)
        return false;
    i = Q.data[Q.front];
    Q.front = (Q.front+1)%MaxSize;
    return true;
}

ELement GetElem(SqQueue Q){
     if(Q.rear == Q.front)
        return false;
    ELement i = Q.data[Q.front];
    return i;
}
// ======================================================

// 队列链式存储===========================================
// typedef struct LinkNode{
//     ELement data;
//     struct LinkNode *next;
// }LinkNode;

// typedef struct{
//     LinkNode *front,*rear;
// }LinkQueue;

// void LInitQueue(LinkQueue &Q){
//     Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
//     Q.front->next=NULL;
// }

// bool IsEmpty(LinkQueue Q){
//     if(Q.front==Q.rear)
//         return true;
//     else
//         return false;
// }

// // 因为大小不受限，所以不用判断是否插入成功
// void LEnQueue(LinkQueue &Q,ELement i){
//     LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
//     s->data=i;
//     s->next=NULL;
//     // Q.rear->next=s;
//     Q.rear=s;
// }

int main(){
    // SqQueue Q;
    SqQueue Q;
    InitQueue(Q);
    for (int i = 10; i >= 0; i--)
    {
        EnQueue(Q,i);
    }
    int nowdata;
    DeQueue(Q,nowdata);
    printf("%d\n",nowdata);
    printf("%d",GetElem(Q));
}