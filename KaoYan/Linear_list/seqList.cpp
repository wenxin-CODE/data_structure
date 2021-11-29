#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define InitSize 5
typedef struct 
{
    int *data;
    int MaxSize;
    int length;
    /* data */
}Seqlist;

void InitList(Seqlist &L){
    L.data = (int *)malloc(InitSize*sizeof(int));
    // 对分配的空间强制类型转换
    L.length = 0;
    L.MaxSize = InitSize;
    printf("你好世界\n");
    // 会存在脏数据，最好初始为0
}

void IncreaseSize(Seqlist &L,int len){
    int *p = L.data;
    L.data = (int *)malloc(InitSize*sizeof(int));
    // 这里就是直接往L.data后面追加
    for (int i = 0; i < L.length; i++){
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize+len;
    // free(p);
    printf("扩容成功\n");
}

bool ListInsert(Seqlist &L,int i,int e){
    if(i<0||i>L.length+1)
        return false;
    if (L.length>L.MaxSize)
    {
        /* code */
        return false;
    }
    for (int j = L.length; j>=i;j--){
        L.data[j] = L.data[j-1];
        // 插入时，要先从后往前移
    } 
    L.data[i-1] = e;
    L.length++;
    return true;
}

bool DeleteElement(Seqlist &L,int i,int &e){
    if(i<0||i>L.length){
        return false;
    }
    e = L.data[i-1];
    // 位序和下标
    for(int j = i;j<L.length;j++){
        L.data[j-1]=L.data[j];
        // 删除后，要从前往后移
    }
    L.length--;
    return true;
}

int LocalElement(Seqlist L,int e){
    int i;
    for(i=0;i<L.length;i++){
        if(L.data[i]==e){
            // 自定义数据类型，不能用==，要编写判断程序
            return i+1;
        }
    }
    return 0;
}

void ChangeElement(Seqlist &L,int oldData,int newData){
    int i;
    for(i=0;i<L.length;i++){
        if(L.data[i]==oldData){
            // 自定义数据类型，不能用==，要编写判断程序
            L.data[i]=newData;
            return ;
        }
    }
    printf("没这个元素");
}

void PrintElement(Seqlist L){
    printf("顺序输出元素");
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
}

// 2.2.3.8
// 2.2.3.10
void Reverse(Seqlist A,int left,int right,int arraysize){
    if(left>=right||right>=arraysize){
        return;
    }
    int mid = (left+right)/2;
    for(int i=0;i<=mid-left;i++){
        int temp = A.data[left+i];
        A.data[left+i]=A.data[right-i];
        A.data[right-i]=temp;
    }
}

void ExChange(Seqlist A,int m,int n,int arraysize){
    Reverse(A,0,m+n-1,arraysize);
    Reverse(A,0,n-1,arraysize);
    Reverse(A,n,m+n-1,arraysize);
    PrintElement(A);
}

// 2.2.3.11
int M_search(Seqlist A,Seqlist B,int n){
    int s1=0,d1=n-1,m1,s2=0,d2=n-1,m2;
    while (s1!=d1||s2!=d2)
    {
        m1=(s1+d1)/2;
        m2=(s2+d2)/2;
        if (A.data[m1]==B.data[m2])
        {
            return A.data[m1];
        }
        if (A.data[m2]<B.data[m2])
        {
            /* code */
            if ((s1+d1)%2==0)
            // 元素个数为奇数
            {
                /* code */
                s1=m1;
                d2=m2;
            }else{
                s1=m1+1;
                d2=m2;
            }
        }else{
            if ((s2+d2)%2==0)
            // 元素个数为奇数
            {
                /* code */
                s2=m2;
                d1=m1;
            }else{
                s2=m2+1;
                d1=m1;
            }
        }
        
    }
    return A.data[s1]<B.data[s2]?A.data[s1]:B.data[s2];
    
}

int main(){
    Seqlist L;
    InitList(L);
    ListInsert(L,1,1);
    ListInsert(L,2,2);
    ListInsert(L,3,3);
    ListInsert(L,4,4);
    ListInsert(L,5,5);
    ListInsert(L,6,6);
    // IncreaseSize(L,10);
    ListInsert(L,7,7);
    ListInsert(L,8,8);
    ListInsert(L,9,9);
    ListInsert(L,10,10);
    printf("%d\n",L.data[7]);
    // IncreaseSize(L,10);
    // printf("%d\n",sizeof(L.data)/sizeof(int));
    // ListInsert(L,1,1);
    // ListInsert(L,2,2);
    // ListInsert(L,3,3);
    // ListInsert(L,4,4);
    // ListInsert(L,5,5);
    // Seqlist K;
    // InitList(K);
    // ListInsert(K,6,6);
    // ListInsert(K,7,7);
    // ListInsert(K,8,8);
    // ListInsert(K,9,9);
    // ListInsert(K,10,10);
    // printf("中位数是%d",M_search(L,K,L.length));
    // ListInsert(L,5,5);
    // PrintElement(L);
    // int a = 0;
    // DeleteElement(L,1,a);
    // PrintElement(L);
    // printf("删除的是%d\n",a);
    // IncreaseSize(L,5);
    // printf("现在长度为 %d\n",L.length);
    // printf("现在大小为 %d\n",L.MaxSize);
    // int local = LocalElement(L,6);
    // printf("6的位置是%d\n",local);
    // ChangeElement(L,3,10);
    // PrintElement(L);
    // 获取元素要用L.data[]
}