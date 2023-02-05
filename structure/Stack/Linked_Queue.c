#include<stdio.h>
#include<stdlib.h>

typedef struct QNode{
    int data;
    struct QNode *next;
}QNode;

QNode *initQueue(){
    QNode *queue = (QNode*)malloc(sizeof(QNode));
    queue->next = NULL;
    return queue;
}

QNode *enQueue(QNode *rear,int data){
    QNode *elem = (QNode*)malloc(sizeof(QNode));
    elem->data = data;
    elem->next = NULL;
    rear->next = elem;
    rear = elem;
    return rear;
}

QNode *deQueue(QNode *top,QNode *rear){
    if(top->next == NULL){
        printf("\n队列已空\n");
        return rear;
    }
    QNode *p = top->next;
    printf("元素为：%d",p->data);
    //top = top->next;
    top->next = p->next;
    //用这个是为了保证top始终是起始的空结点
    if(rear == p){
        rear=top;
    }
    free(p);
    return top;
    //返回top或者rear没影响，因为top的next变了先行
}

int main(){
    QNode *queue,*top,*rear;
    queue=rear=top=initQueue();
    rear = enQueue(rear,1);
    rear = enQueue(rear,2);
    rear = enQueue(rear,3);
    rear = enQueue(rear,4);

    top = deQueue(top,rear);
    top = deQueue(top,rear);
    top = deQueue(top,rear);
    top = deQueue(top,rear);
    return 0;    
}