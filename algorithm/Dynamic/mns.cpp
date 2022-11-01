#include <iostream>
using namespace std;

// 动态规划——电路连线
// https://www.cnblogs.com/wkfvawl/p/11660698.html#:~:text=%E7%94%B5%E8%B7%AF%E5%B8%83%E7%BA%BF%E9%97%AE%E9%A2%98%E8%A6%81%E7%A1%AE%E5%AE%9A%E5%B0%86%E5%93%AA%E4%BA%9B%E8%BF%9E%E7%BA%BF%E5%AE%89%E6%8E%92%E5%9C%A8%E7%AC%AC%E4%B8%80%E5%B1%82%E4%B8%8A%EF%BC%8C%E4%BD%BF%E5%BE%97%E8%AF%A5%E5%B1%82%E4%B8%8A%E6%9C%89%E5%B0%BD%E5%8F%AF%E8%83%BD%E5%A4%9A%E7%9A%84%E8%BF%9E%E7%BA%BF%E3%80%82%20%E6%8D%A2%E5%8F%A5%E8%AF%9D%E8%AF%B4%EF%BC%8C%20%E8%AF%A5%E9%97%AE%E9%A2%98%E8%A6%81%E6%B1%82%E7%A1%AE%E5%AE%9A%E5%AF%BC%E7%BA%BF%E9%9B%86Nets%20%3D%20%7B%20%EF%BC%88i%2C%CF%80%20%28i%29%EF%BC%89%EF%BC%8C1%3C%3Di%3C%3Dn%20%7D%E7%9A%84%E6%9C%80%E5%A4%A7%E4%B8%8D%E7%9B%B8%E4%BA%A4%E5%AD%90%E9%9B%86%E3%80%82,%28i%2Cj%29%E8%A1%A8%E7%A4%BA%E7%9A%84%E9%83%BD%E6%98%AF%E9%9B%86%E5%90%88%EF%BC%81%20%EF%BC%81%20%E5%86%85%E5%AD%98%E5%82%A8%E7%9A%84%E6%98%AF%E8%BF%9E%E7%BA%BF%EF%BC%8CSize%20%28i%2Cj%29%E5%AD%98%E5%82%A8%E7%9A%84%E6%89%8D%E6%98%AF%E6%9C%80%E5%A4%A7%E4%B8%8D%E7%9B%B8%E4%BA%A4%E8%BF%9E%E7%BA%BF%E7%9A%84%E4%B8%AA%E6%95%B0%EF%BC%81%20%EF%BC%81%202%E3%80%81%E9%80%92%E5%BD%92%E8%AE%A1%E7%AE%97%E6%9C%80%E4%BC%98%E5%80%BC%20%E5%BD%93i%3D1%E7%9A%84%E6%97%B6%E5%80%99%E5%BE%88%E5%A5%BD%E7%90%86%E8%A7%A3%E3%80%82%20%E5%BD%93i%3E1%E6%97%B6%EF%BC%8C%E6%88%91%E4%BB%AC%E8%BF%98%E6%98%AF%E7%9C%8B%E4%B8%8A%E9%9D%A2%E7%9A%84%E9%82%A3%E4%B8%AA%E8%BF%9E%E7%BA%BF%E5%9B%BE%E3%80%82
// 动态规划——要么是前面的最优解，要么是前面的加现在的一个
const int N = 10;

void MNS(int C[],int n,int **size);
void Traceback(int C[],int **size,int n,int Net[],int& m);

int main()
{
    int c[] = {0,8,7,4,2,5,1,9,3,10,6};//下标从1开始
    int **size = new int *[N+1];

    for(int i=0; i<=N; i++)
    {
        size[i] = new int[N+1];
    }

    MNS(c,N,size);

    cout<<"电路布线最大不相交连线数目为："<<size[N][N]<<endl;

    int Net[N],m;
    Traceback(c,size,N,Net,m);

    cout<<"最大不相交连线分别为："<<endl;
    for(int i=m-1; i>=0; i--)
    {
        cout<<"("<<Net[i]<<","<<c[Net[i]]<<") ";
    }
    cout<<endl;
    return 0;
}

// // **指向指针的指针
void MNS(int C[],int n,int **size)
{
    for(int j=0;j<C[1];j++)
    {
        size[1][j]=0;
    }

    for(int j=C[1]; j<=n; j++)
    {
        size[1][j]=1;
    }//这两个for填充第一行，对应公式一

    for(int i=2; i<n; i++)
    {
        for(int j=0; j<C[i]; j++)
        {
            size[i][j]=size[i-1][j];//当i<c[i]的情形
        }
        for(int j=C[i]; j<=n; j++)
        {
            //当j>=c[i]时，考虑(i，c[i])是否属于MNS(i,j)的两种情况
            size[i][j]=max(size[i-1][j],size[i-1][C[i]-1]+1);
            //第一项代表交叉了，第二项代表没交差
        }
    }//这个for对应那个公式

    // 上面的for有=，就不用这句
    size[n][n]=max(size[n-1][n],size[n-1][C[n]-1]+1);
}

void Traceback(int C[],int **size,int n,int Net[],int& m)
{
    int j=n;
    m=0;
    for(int i=n;i>1;i--)
    {
        if(size[i][j]!=size[i-1][j])//此时，（i,c[i])是最大不相交子集的一条边
        {
            Net[m++]=i;
            j=C[i]-1;//更新扩展连线柱区间
        }
    }
    if(j>=C[1])//处理i=1的情形
    {
        Net[m++]=1;
    }
}