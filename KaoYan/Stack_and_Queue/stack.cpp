#include "stdio.h"
#include "stdlib.h"

using namespace std;
#define MaxSize 10
typedef int Elemtype ;

typedef struct{
    Elemtype data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &K){
    K.top = -1;
}

bool IsEmpty(SqStack S){
    if(S.top == -1)
        return true;
    else
        return false;
}

bool push(SqStack &S,Elemtype e){
    if(MaxSize-1==S.top)
        return false;
    else
    {
        S.data[++S.top]=e;
        return true;
    }
}

int pop(SqStack &S,Elemtype &e){
    if(S.top==-1)
        return -9999;
    else
    {
        e=S.data[S.top--];
        return e;
    }
}

int GetElem(SqStack S,Elemtype &e){
    if(S.top == -1)
        return -9999;
    e=S.data[S.top];
    return e;
}

/*
//3.1.4.5共享栈
#define maxsize 100
#define elemtp int

typedef struct{
    elemtp stack[maxsize];
    int top[2];
}stk;

int push(stk &s,int i,elemtp x){
    // i表示站号，=0是1号站，=1是2号站
    if(i<0||i>1)
        exit(0);
    if(s.top[1]-s.top[0]==1)
        return 0;
    switch(i){
        case 0: s.stack[++s.top[0]]=x;
                return 1;
                break;
        case 1: s.stack[--s.top[1]]=x;
                return 1;
    }
}

elemtp pop(stk &s,int &i){
    if(i<0||i>1)
        exit(0);
    switch(i){
        case 0: 
        if(s.top[0]==-1){
            printf("栈空\n");
            return -1;
        }else{
            return s.stack[s.top[0]--];
        }
        case 1: 
         if(s.top[1]==maxsize){
            printf("栈空\n");
            return -1;
        }else{
            return s.stack[s.top[1]++];
        }
    }
}
*/

int main(){
    SqStack S;
    InitStack(S);
    push(S,1);
    push(S,2);
    push(S,3);
    push(S,4);
    push(S,5);
    int outdata;
    pop(S,outdata);
    printf("%d\n",S.top);
    printf("%d\n",outdata);
    int nowdata;
    printf("%d\n",S.top);
    printf("%d",GetElem(S,nowdata));
}

