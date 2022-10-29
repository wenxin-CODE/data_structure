#include <stdio.h>
 
//  https://blog.csdn.net/laoniu_c/article/details/38455255
#define M	65535 //无穷大
#define N	5 //顶点数
 
//贪心算法——Dijkstra算法函数，求给定顶点到其余各点的最短路径
//参数：邻接矩阵、出发点的下标、结果数组、路径前一点记录
void Dijkstra(int Cost[][N], int v0, int Distance[], int prev[])
{
    int s[N];
    int mindis,dis;
    int i, j, u;
    //初始化
    for(i=0; i<N; i++)
    {
        Distance[i] = Cost[v0][i];
        s[i] = 0;
        if(Distance[i] == M)
			prev[i] = -1;
        else
			prev[i] = v0;
    }
    Distance[v0] = 0;
    s[v0] = 1; //标记v0
    //在当前还未找到最短路径的顶点中，
    //寻找具有最短距离的顶点
    for(i=1; i < N; i++)
    {//每循环一次，求得一个最短路径
        mindis = M;
        u = v0;

		//求离出发点最近的顶点
        for (j=0; j < N; j++) 
			if(s[j]==0 && Distance[j]<mindis)
			{
				mindis = Distance [j];
				u = j;
			} // if语句体结束，j循环结束

        s[u] = 1;//后续这个最近点就失效了

		// 利用最近的点修改递增路径序列（集合）
        for(j=0; j<N; j++) 
			if(s[j]==0 && Cost[u][j]<M)
			{ //对还未求得最短路径的顶点
				//求出由最近的顶点 直达各顶点的距离
				dis = Distance[u] +Cost[u][j];
				// 如果新的路径更短，就替换掉原路径
	
				if(Distance[j] > dis)
				{
					Distance[j] = dis;
					prev[j] = u;
				}
			} // if 语句体结束，j循环结束
    } // i循环结束
}
// 输出最短路径
// prev是确定的，他代表每个结点的前一步是谁，就是该节点所有前驱里面距离最短的那个
// 参数：路径前一点记录、出发点的下标、到达点下标
void PrintPrev(int prev[],int v0,int vn)
{
    int tmp = vn;
    int i, j;
    //临时存路径
    int tmpprv[N];
    //初始化数组
    for(i=0; i < N; i++)
		tmpprv[i] = 0;
 
    //记录到达点下标
    tmpprv[0] = vn+1;
    //中间点用循环记录
    for(i =0, j=1; j < N ;j++)
    {
        if(prev[tmp]!=-1 && tmp!=0)
        {
            tmpprv[i] = prev[tmp]+1;
            tmp = prev[tmp];
            i++;
        }
        else break;
    }
 
    //输出路径，数组逆向输出
    for(i=N-1; i >= 0; i--)
    {
        if(tmpprv[i] != 0)
        { //排除0元素
            printf("V%d", tmpprv[i]);
            if(i)  //不是最后一个输出符号 
                printf("-->");
        }
    }
	printf("-->V%d", vn+1);
}
//主函数
int main()
{
    //给出有向网的顶点数组
    char *Vertex[N]={"V1", "V2", "V3", "V4", "V5"};
    //给出有向网的邻接矩阵
    int Cost[N][N]={
		{0, 10, M, 30, 100},
        {M, 0, 50, M, M},
        {M, M, 0, M, 10},
        {M, M, 20, 0, 60},
        {M, M, M, M, 0},
    };
    int Distance[N]; //存放求得的最短路径长度
    int prev[N];  //存放求得的最短路径
	int i;
    //调用Dijkstra算法函数，求顶点V1到其余各点的最短路径
    
    Dijkstra(Cost, 0, Distance, prev);
    for(i=0; i < N; i++)
    {
        //输出最短路径长度
        printf("%s-->%s:%d\t", Vertex[0], Vertex[i], Distance[i]);
        //输出最短路径
        PrintPrev(prev, 0, i);
        printf("\n");
    }
 
    return 0;
}