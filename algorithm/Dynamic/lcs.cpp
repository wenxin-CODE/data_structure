#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 动态规划——最长公共子序列，不用保证连续
// 二位列表中看对应位置字符是否相同
// 若不相同，找相邻位置较大的写下来
// 若相同，找较大的加一写下来
// 这个就是法则，要变得就是‘若’后面的条件
void LCS(string s1,string s2)
{
    int m=s1.length()+1;
    int n=s2.length()+1;
    int **c;
    int **b;
    c=new int* [m];
    b=new int* [m];
    for(int i=0;i<m;i++)
    {
        c[i]=new int [n];
        b[i]=new int [n];
        for(int j=0;j<n;j++)
            b[i][j]=0;
    }
    for(int i=0;i<m;i++)
        c[i][0]=0;
    for(int i=0;i<n;i++)
        c[0][i]=0;
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(s1[i]==s2[j])
            {
                c[i+1][j+1]=c[i][j]+1;
                b[i+1][j+1]=1;          //1表示箭头为  左上
            }
            else if(c[i][j+1]>=c[i+1][j])
            {
                c[i+1][j+1]=c[i][j+1];
                b[i+1][j+1]=2;          //2表示箭头向  上
            }
            else
            {
                c[i+1][j+1]=c[i+1][j];
                b[i+1][j+1]=3;          //3表示箭头向  左
            }
        }
    }
    for(int i=0;i<m;i++)                //输出c数组
    {
        for(int j=0;j<n;j++)
        {
            cout<<c[i][j]<<' ';
        }
        cout<<endl;
    }
    stack<char> same;                   //存LCS字符
    stack<int> same1,same2;             //存LCS字符在字符串1和字符串2中对应的下标，方便显示出来
    for(int i = m-1,j = n-1;i >= 0 && j >= 0; )
    {
        if(b[i][j] == 1)
        {
            i--;
            j--;
            same.push(s1[i]);
            same1.push(i);
            same2.push(j);
        }
        else if(b[i][j] == 2)
                i--;
             else
                j--;
    }
    cout<<s1<<endl;                     //输出字符串1
    for(int i=0;i<m && !same1.empty();i++)      //输出字符串1的标记
    {
        if(i==same1.top())
        {
            cout<<1;
            same1.pop();
        }
        else
            cout<<' ';
    }
    cout<<endl<<s2<<endl;                //输出字符串2
    for(int i=0;i<n && !same2.empty();i++)      //输出字符串2的标记
    {
        if(i==same2.top())
        {
            cout<<1;
            same2.pop();
        }
        else
            cout<<' ';
    }
    cout<<endl<<"最长公共子序列为：";
    while(!same.empty())
    {
        cout<<same.top();
        same.pop();
    }
    cout<<endl<<"长度为："<<c[m-1][n-1]<<endl;
    for (int i = 0; i<m; i++)
    {
        delete [] c[i];
        delete [] b[i];
    }
    delete []c;
    delete []b;
}
int main()
{
    string s1="ABCPDSFJGODIHJOFDIUSHGD";
    string s2="OSDIHGKODGHBLKSJBHKAGHI";
    LCS(s1,s2);
    return 0;
}