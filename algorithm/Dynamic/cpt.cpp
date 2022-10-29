#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;

// https://blog.csdn.net/Jayphone17/article/details/102581362
//  权值用二维数组记录
// 动态规划——凸多边形最优三角分割

const int M =1111;
int n; //顶点数
int s[M][M];//记录最优策略二维数组
double m[M][M];//记录最优值二维数组
double g[M][M];//记录各顶点之间权值的二维数组
 
void convex_Polygon_Triangulation()
{
    for (int i=1;i<=n;i++) //初始化
    {
        m[i][i]=0;
        s[i][i]=0;
    }
    for(int d=2;d<=n;d++)//d为问题规模，d=2实际上有三个点
    {
        for (int i=1;i<=n-d+1;i++)//控制i值
        {
            int j=i+d-1; //j值
            m[i][j]=m[i+1][j]+g[i-1][i]+g[i][j]+g[i-1][j];
            //策略为k=i的情况
            s[i][j]=i;
            for (int k=i+1;k<j;k++) //枚举划分点i到j所有情况
            {
                double temp=m[i][k]+m[k+1][j]+g[i-1][k]+g[k][j]+g[i-1][j];
                if(m[i][j]>temp)
                {
                    m[i][j]=temp;
                    s[i][j]=k;
                }
            }
        }
    }
}
 
void print (int i,int j)  //递归求解所有子问题的弦。
{
    if(i==j)
        return ;
    if(s[i][j]>i)
    {
        cout << "{v" << i-1 << "v" << s[i][j] << "}" << endl;
    }
    if(s[i][j]+1<j)
    {
        cout << "{v" << s[i][j] << "v" << j << "}" << endl;
    }
    print(i,s[i][j]);
    print(s[i][j]+1,j);
}
 
int main()
{
    int i;
    int j;
    cout << "请输入顶点个数n："<< endl;
    cin >> n;
    n--;
    cout << "请依次输入各顶点的连接权值：" << endl;
    for (i=0;i<=n;++i)
    {
        for (j=0;j<=n;++j)
        {
            cin >> g[i][j];
        }
    }
    convex_Polygon_Triangulation();
    cout << "最优三角剖分的权值和是:" << endl;
    cout << m[1][n]<< endl;
    cout << "顶点的集合是："<< endl;
    print(1,n);
    return 0;
}