#include<iostream>
using namespace std;
#include<stdlib.h>
// https://blog.csdn.net/pigpig_fly/article/details/53510852
static int *x;  //用x数组来存放解向量
static int sum; //用sum变量来记录有几个解
int check(int k){  //查看k皇后是否满足约束条件 
    for(int i=0;i<k;i++)
        if (x[i]==x[k] || abs(x[i]-x[k]) ==abs(i-k))  //满足不在同一条斜线和同一列 
           return 1;

        return 0;

} 
void queen(int n){
// 有冲突就回溯，一直到第一个，所以不会重复
// 一直回溯到第一个皇后到8号格子。这是K就减到-1，退出
     int k = 0;            //从 皇后0 开始放
     sum = 0;

    while(k>=0){
        x[k]++;           //摆放第k个皇后（第一次摆放皇后0）,++是为了把-1变成0 
        while(x[k]<n && check(k) == 1)     //对皇后k进行检测，直到不发生冲突或x[k]越界 
          x[k]++;    //检测下一列 

        if(x[k]<n && k == n-1)//皇后都摆完了
        {

          for(int i =0;i<n;i++)
          {
            cout<<x[i]+1<<" ";//0格子没算，所以要加一
          }
          cout<<endl;
          sum++; 

        }
        if(x[k]<n && k<n-1)     //若皇后还没有摆放完，就摆放下一个皇后k = k+1 
           k++;
        else                    //否则就是发生了越界，要进行回溯 
        { 
           x[k]=-1;         
           k--;  
        }

    }  
    if(sum == 0) 
        cout<<"无解"<<endl;
} 
int main(){

    int n =8; 
    x = new int[n+1];
    for(int i=0;i<n;i++){
        x[i] = -1;//还没放皇后
    }

    queen(n);
    cout<<"一共解的个数为 ："<<sum<<endl;
    return 0;
}
