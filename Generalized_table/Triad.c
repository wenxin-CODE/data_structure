#include<stdio.h>
#define number 3

typedef struct{
    int i,j;
    int data;
}triple;

typedef struct 
{
    triple data[number];
    int n,m,num;
}TSMatrix;

void display(TSMatrix M){
    for(int i=1;i<=M.n;i++){
        for(int j=1;j<=M.m;j++){
            int value = 0;
            for(int k=0;k<M.num;k++) {
                //判断并输出行列号对应的元素
                if(i==M.data[k].i&&j==M.data[k].j){
                    printf("%d ",M.data[k].data);
                    value = 1;
                    break;//跳出for循环
                }
            }
            if(value==0)
            printf("0 ");
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    TSMatrix M;
    M.m=3;
    M.n=3;
    M.num=3;

    M.data[0].i=1;
    M.data[0].j=1;
    M.data[0].data=1;
    M.data[1].i=2;
    M.data[1].j=3;
    M.data[1].data=5;
    M.data[2].i=3;
    M.data[2].j=1;
    M.data[2].data=3;
    display(M);
    return 0;
}
