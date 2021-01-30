#include <stdio.h>
#include <string.h>
#include<stdlib.h>
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

//模拟操作结点元素的函数，输出结点本身的数值
void displayElem(BiTNode* elem){
    printf("%d ",elem->data);
}

//跟左右访问顺序，先把跟存起来
void push(BiTNode** a,BiTNode* elem){
    a[++top]=elem;
}

void pop(){
    if(top==-1){
        return ;
    }
    top--;
}

BiTNode* getTop(BiTNode**a){
    return a[top];
}

void PreOrderTraverses(BiTree Tree){
    BiTNode* a[20];
    BiTNode *p;
    push(a,Tree);
    while(top!=-1){
        p=getTop(a);
        pop();
        while(p){
            displayElem(p);
            if(p->rchild){
                push(a,p->rchild);
            }
            p=p->lchild;
        }
    }
}

//先序遍历
void PreOrderTraverse(BiTree T){
    if (T) {
        //中序后序调换三步顺序
        displayElem(T);//调用操作结点数据的函数方法
        PreOrderTraverse(T->lchild);//访问该结点的左孩子
        PreOrderTraverse(T->rchild);//访问该结点的右孩子
    }
    //如果结点为空，返回上一层
    return;
}

int main() {
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("递归先序遍历: \n");
    PreOrderTraverse(Tree);
    printf("\n非递归先序遍历: \n");
    PreOrderTraverses(Tree);
}

