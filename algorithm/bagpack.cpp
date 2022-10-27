#include<stdio.h>

// 动态规划——0/1背包问题
int V[200][200];//前i个物品装入容量为j的背包中获得的最大价值
int max(int a,int b)
{
   if(a>=b)
       return a;
   else return b;
}
 
int KnapSack(int n,int w[],int v[],int x[],int C)
{
    int i,j;
	//填表,其中第一行和第一列全为0
    for(i=0;i<=n;i++)
        V[i][0]=0;
    for(j=0;j<=C;j++)
        V[0][j]=0;
    for(i=1;i<=n;i++)
	{
		printf("%d  %d  %d  ",i,w[i-1],v[i-1]);
        for(j=1;j<=C;j++)
		{
            if(j<w[i-1])
			{
				V[i][j]=V[i-1][j];
				printf("[%d][%d]=%2d  ",i,j,V[i][j]);
			}
			
            else
			{
                V[i][j]=max(V[i-1][j],V[i-1][j-w[i-1]]+v[i-1]);
				printf("[%d][%d]=%2d  ",i,j,V[i][j]);
			}
		}
		printf("\n");
	}
	//判断哪些物品被选中
    j=C;
    for(i=n;i>=1;i--)
    {
        if(V[i][j]>V[i-1][j])
            {
                x[i]=1;
                j=j-w[i-1];
            }
        else
            x[i]=0;
    }
    printf("选中的物品是:\n");
    for(i=1;i<=n;i++)
        printf("%d ",x[i]);
    printf("\n");
    return V[n][C];
        
}
 
int main()
{
    int s;//获得的最大价值
    int w[15];//物品的重量
    int v[15];//物品的价值
    int x[15];//物品的选取状态
    int n,i;
    int C;//背包最大容量
    n=5;
    printf("请输入背包的最大容量:\n");
    scanf("%d",&C);
    
    printf("输入物品数:\n");
    scanf("%d",&n);
    printf("请分别输入物品的重量:\n");
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
 
    printf("请分别输入物品的价值:\n");
    for(i=0;i<n;i++)
        scanf("%d",&v[i]);
 
    s=KnapSack(n,w,v,x,C);
 
    printf("最大物品价值为:\n");
    printf("%d\n",s);
   
    return 0;
}