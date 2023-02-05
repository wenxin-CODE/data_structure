#include<stdio.h>
#include<stdlib.h>

int enQueue(int *a,int rear,int data){
    a[rear] = data;
    rear++;
    return rear;
}

int deQueue(int *a,int front,int rear){
    if (front!=rear)
    {
        printf("出队元素：%d\n",a[front]);
        front++;
        return front;
    }else{
        printf("队已空");
        return -1;
    }
}

int main(){
    int a[100];
    int front,rear;
    front=rear=0;
    rear = enQueue(a,rear,1);
    rear = enQueue(a,rear,2);
    rear = enQueue(a,rear,3);
    rear = enQueue(a,rear,4);
    front = deQueue(a,front,rear);
    front = deQueue(a,front,rear);
    front = deQueue(a,front,rear);
    front = deQueue(a,front,rear);
    front = deQueue(a,front,rear);
    return 0;
}