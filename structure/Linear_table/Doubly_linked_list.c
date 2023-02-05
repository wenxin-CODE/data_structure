#include<stdio.h>
#include<stdlib.h>

typedef struct line{
    struct line *prior;
    int data;
    struct line *next;
}line;

line *initLine(line *head){
    head = (line*)malloc(sizeof(line));
    head->data=1;
    head->next=NULL;
    head->prior=NULL;
    line *list=head;

    for(int i=2;i<5;i++){
        line *body = (line*)malloc(sizeof(line));
        body->data=i;
        body->next=NULL;
        body->prior=NULL;

        list->next=body;
        body->prior=list;
        list=list->next;
    }

    return head;
}

line *insertLine(line *head,int data,int add){
    line *body = (line*)malloc(sizeof(line));
    body->data=data;
    body->next=NULL;
    body->prior=NULL;

    if(add == 1){
        body->next=head;
        head->prior=body;
        head=body;
    }else{
        line *temp=head;
        for (int i = 1; i < add-1; i++)
        {
            /* code */
            temp=temp->next;
        }
        if (temp->next==NULL)
        {
            /* code */
            temp->next=body;
            body->prior=temp;
        }else
        {
            temp->next->prior=body;
            body->next=temp->next;
            temp->next=body;
            body->prior=temp;
        }
    }
    return head;
}

line *delLine(line *head,int data){
    line *temp=head;
    while (temp)
    {
        if(temp->data==data){
            temp->prior->next=temp->next;
            temp->next->prior=temp->prior;
            free(temp);
            return head;
        }
        temp=temp->next;
    }
    printf("链表中午该元素");
    return head;
}

int selElem(line *head,int elem){
    line *t=head;
    int i=1;
    while(t){
        if (t->data==elem)
        {
            return i;
        }
        i++;
        t=t->next;
    }
    return -1;
}

line *renameElem(line *p,int add,int newElem){
    line *t=p;
    for (int i = 1; i < add; i++)
    {
        /* code */
        t=t->next;
    }
    t->data=newElem;
    return p;
}

void display(line *head){
    // line *temp = head;
    // while(temp){
    //     printf("%d\n",temp->data);
    //     temp = temp->next;
    // }
    line * temp=head;
    while (temp) {
        if (temp->next==NULL) {
            printf("%d\n",temp->data);
        }else{
            printf("%d->",temp->data);
        }
        temp=temp->next;
    }
}

int main() {
    line * head=NULL;
    printf("创建双链表:");
    head=initLine(head);
    display(head);
    printf("在表中第 3 的位置插入元素 7:");
    head=insertLine(head, 7, 3);
    display(head);
    printf("表中删除元素 2:");
    head=delLine(head, 2);
    display(head);
    printf("元素 3 的位置是：%d\n",selElem(head,3));
    printf("表中第 3 个节点中的数据改为存储 6:");
    head = renameElem(head,3,6);
    display(head);
    return 0;
}