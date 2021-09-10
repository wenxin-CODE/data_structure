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