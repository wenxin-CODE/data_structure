#include<stdio.h>
#define MAXN 20

// 子集和问题
int n=4,W=31;
int w[]={0,11,13,24,7};  //存放所有整数，不要下标为0的元素 
int count=0;  //累计解个数
void dispsolution(int x[])
{
	int i;
	printf("第%d个解：\n",++count);
	for(int i=1;i<=n;i++)
	if(x[i]==1)
	printf("%d ",w[i]);
	printf("\n");
 } 

//  先看到没到叶节点
// 到了直接看和够不够要求
// 没到先看左子树还能不能装得下，装不下就剪枝
// 再看右子树下面都要够不够，不够就剪枝
 void dfs(int tw,int rw,int x[],int i) //求解子集和 
 {
 	//tw 考虑第i个整数时选取的整数和，rw为剩下的整数和
	 if(i>n)   //找到一个叶子结点
	 {
	 	if(tw==W)    //找到一个满足条件的解输出
		 dispsolution(x); 
	  } 
	  else    //尚未找完所有整数 
	  {
	  	if(tw+w[i]<=W)  //左孩子结点剪枝：选取满足条件的整数w[i]
	  	{
		  x[i]=1;  //选取第i个整数 
		  dfs(tw+w[i],rw-w[i],x,i+1); 
	   } 
	   if(tw+rw>W)  //右孩子结点剪枝：剪出不可能存在解的结点
	   {
	   	x[i]=0;  //不选取第i个整数，回溯 
	   	dfs(tw,rw-w[i],x,i+1);
		} 
    }
 }
int main(){
 	int x[MAXN];  //存放一个解向量
	 int rw=0;
	 for(int j=1;j<=n;j++)   //求所有整数和
	 rw+=w[j];   
	 dfs(0,rw,x,1);   //i从1开始 
 	
 }
  
