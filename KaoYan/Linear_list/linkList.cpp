#include <stdio.h>
#include <stdlib.h>

using namespace std;
typedef int Elemtype;

typedef struct LNode{
    Elemtype data;
    struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    if(L==NULL)
        return false;
    L->next = NULL;
    return true;
}

bool InsertNextNode(LNode *p,Elemtype e){
    if (p==NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;//将节点s连接到p之后
    return true;
}

LinkList List_HeadInsert(LinkList &L){
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    printf("请输入一个信息");
    scanf("%D",&x);
    while (x!=9999)
    {
        /* code */
        InsertNextNode(L,x);
        printf("请输入一个信息");
        scanf("%D",&x);
    }
    return L;
}

LinkList List_tailInsert(LinkList &L){
    LNode *s,*r = L;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    printf("请输入一个信息");
    scanf("%D",&x);
    while (x!=9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        printf("请输入一个信息");
        scanf("%D",&x);
    }
    r->next = NULL;
    return L;
}

bool InsertPriorNode(LNode *p,Elemtype e){
    if(p==NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

bool ListDelete(LinkList &L,Elemtype i,Elemtype &e){
    if(i<1)
        return false;//按位序进行删除
    LNode *p;
    int j=0;
    p = L;
    while(p!=NULL && j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL)
        return false;
    if(p->next == NULL)
        return false;//后面没有了，没啥可删
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

bool LinkInsert(LinkList &L,int i,Elemtype e){
    if(i<1)
        return false;
    LNode *p;
    int j=0;
    p=L;
    while(p!=NULL && j<i-1){
        p=p->next;
        j++;
    }
    return InsertNextNode(p,e);
}

// 这里查询接受返回数据要用一个指针
LNode * GetElem(LinkList L,int i){
    if(i<0)
        return NULL;
    LNode *p;
    int j=0;
    p=L;
    while(p!=NULL && j<i){
        p=p->next;
        j++;
    }
    return p;
}

LNode * LocalElem(LinkList L,Elemtype e){
    LNode *p = L->next;
    while(p!=NULL && p->data !=e)
        p = p->next;
    return p;
}

void VisitElem(LinkList L){
    L = L->next;
    while (L!=NULL)
    {
        printf("%d ",L->data);
        L = L->next;
    }
    printf("\n");
}

int main(){
    LinkList L;
    InitList(L);
    printf("创建链表\n");
    List_HeadInsert(L);
    printf("遍历链表\n");
    VisitElem(L);
    printf("查找元素\n");
    printf("%d\n",GetElem(L,2)->data);
    printf("插入元素10\n");
    LinkInsert(L,2,10);
    printf("遍历链表\n");
    VisitElem(L);
    int a = 0;
    printf("删除3号元素\n");
    ListDelete(L,3,a);
    printf("遍历链表\n");
    VisitElem(L);
    printf("删除的是%d\n",a);
    LNode *k;
    printf("修改第5个元素\n");
    k = GetElem(L,5);
    k->data = 100;
    VisitElem(L);
    printf("Hello World!!!");
}