#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TElemType int
int top=-1;//top变量时刻表示栈顶元素所在位置

//构造结点的结构体
typedef struct BiTNode{
    TElemType data;//数据域
    struct BiTNode *lchild,*rchild;//左右孩子指针
}BiTNode,*BiTree;

//初始化树的函数
void CreateBiTree(BiTree *T){
    *T=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data=1;
    (*T)->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->data=2;
    (*T)->lchild->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data=5;
    (*T)->lchild->rchild->lchild=NULL;
    (*T)->lchild->rchild->rchild=NULL;
    (*T)->rchild->data=3;
    (*T)->rchild->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data=6;
    (*T)->rchild->lchild->lchild=NULL;
    (*T)->rchild->lchild->rchild=NULL;
    (*T)->rchild->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data=7;
    (*T)->rchild->rchild->lchild=NULL;
    (*T)->rchild->rchild->rchild=NULL;
    (*T)->lchild->lchild->data=4;
    (*T)->lchild->lchild->lchild=NULL;
    (*T)->lchild->lchild->rchild=NULL;
}

//弹栈函数
void pop( ){
    if (top==-1) {
        return ;
    }
    top--;
}

//模拟操作结点元素的函数，输出结点本身的数值
void displayElem(BiTNode* elem){
    printf("%d ",elem->data);
}

//后序遍历非递归算法
typedef struct SNode{
    BiTree p;
    int tag;
}SNode;

//后序遍历使用的进栈函数
void postpush(SNode *a,SNode sdata){
    a[++top]=sdata;
}

//后序遍历函数
void PostOrderTraverse(BiTree Tree){
    SNode a[20];
    BiTNode *p;
    int tag;
    SNode sdata;
    p=Tree;
    while (p||top!=-1){
        while(p){
            sdata.p=p;
            sdata.tag=0;
            postpush(a,sdata);
            p=p->lchild;
        }
        sdata=a[top];
        pop();
        p=sdata.p;
        tag=sdata.tag;

        if(tag==0){
            sdata.p=p;
            sdata.tag=1;
            postpush(a,sdata);
            p=p->rchild;
        }else{
            displayElem(p);
            p=NULL;
        }
    }
}

int main(){
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("后序遍历: \n");
    PostOrderTraverse(Tree);
}