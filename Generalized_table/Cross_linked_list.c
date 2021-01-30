#include<stdio.h>
#include<stdlib.h>

typedef struct OLNode{
    int i,j,e;
    struct OLNode *right,*down;
}OLNode,*OLink;

typedef struct{
    OLink *rhead,*chead;//行列链表头指针
    int mu,nu,tu;
}CrossList;

CrossList CreateMatrix_OL(CrossList M){
    int m,n,t;
    int i,j,e;
    OLNode *p,*q;
    printf("输入矩阵行数，列数，非零元素个数");
    scanf("%d%d%d",&m,&n,&t);
    M.mu=m;
    M.nu=n;
    M.tu=t;
    if(!(M.rhead=(OLink*)malloc((m+1)*sizeof(OLink)))||!(M.chead=(OLink*)malloc((n+1)*sizeof(OLink)))){
        printf("初始化失败");
        exit(0);
    }
    for(i=1;i<=m;i++){
        M.rhead[i]=NULL;
    }
    for(j=1;j<=n;j++){
        M.chead[j]=NULL;
    }
    for(scanf("%d%d%d",&i,&j,&e);0!=i;scanf("%d%d%d",&i,&j,&e)){
        if(!(p=(OLNode*)malloc(sizeof(OLNode)))){
            printf("初始化失败");
            exit(0);
        }
        p->i=i;
        p->j=j;
        p->e=e;

        if(NULL==M.rhead[i]||M.rhead[i]->j>i){
            p->right=M.rhead[i];
            M.rhead[i]=p;
        }else
        {
            for(q=M.rhead[i];(q->right)&&q->right->j<j;q=q->right);
            p->right=q->right;
            q->right=p;
        }
        if(NULL==M.chead[j]||M.chead[j]->i>i){
            p->down=M.chead[j];
            M.chead[j]=p;
        }else
        {
            for(q=M.chead[j];(q->down)&&q->down->i<i;q=q->down);
            p->down=q->down;
            q->down=p;
        }
    }
    return M;
}

void display(CrossList M){
    for(int i=1;i<=M.nu;i++){
        if(NULL!=M.chead[i]){
            OLink p=M.chead[i];
            while(NULL!=p){
                printf("%d\t%d\t%d\n", p->i, p->j, p->e);
                p=p->down;
            }
        }
    }
}

int main()
{
    CrossList M;
    M.rhead = NULL;
    M.chead = NULL;
    M = CreateMatrix_OL(M);
    printf("输出矩阵M:\n");
    display(M);
    return 0;
}