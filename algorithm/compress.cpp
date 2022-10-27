// 6,5,7,5,245,180,28,28,19,22,25,20
// 没懂这个最优子结构
// 动态规划——图片压缩
#include<iostream> 
#include<cmath>  
#include<stack>
#include<algorithm>
using namespace std;   
  
const int N = 7;  
  
int length(int i);  
void Compress(int n,int p[],int s[],int l[],int b[]);  
int TraceBack(int n,int l[],int b[]);  //返回有多少个段
void Out(int m,int min_len,int l[],int b[]);
  
int main()  
{  
    //int p[] = {0,10,12,15,255,1,2};//图像灰度数组 下标从1开始计数  
      int p[] = {6,5,7,5,245,180,28,28,19,22,25,20};
    int s[N]={0},l[N]={0},b[N]={0};  
  
    cout<<"图像的灰度序列为："<<endl;  
  
    for(int i=1;i<N;i++)  
    {  
        cout<<p[i]<<" ";  
    }  
    cout<<endl;  
  
    Compress(N-1,p,s,l,b);  
    int m=TraceBack(N-1,l,b); 
    Out(m,s[N-1],l,b);
    return 0;  
}  
  
void Compress(int n,int p[],int s[],int l[],int b[])  
{  
    int Lmax = 256,header = 11;  
    s[0] = 0;  
    for(int i=1; i<=n; i++)  
    {  
        b[i] = length(p[i]);//计算像素点p需要的存储位数  
        int bmax = b[i];  
        s[i] = s[i-1] + bmax + header;  
        l[i] = 1;  
  
        for(int j=2; j<=i && j<=Lmax;j++)  //最后一段含有一个像素，两个像素，所有像素
        {  
            //if(bmax<b[i-j+1])   //最后一个b[i-j+1]有效，是前一段当中的最大值，并不是后一段中的最大值
            if(bmax<b[i-j+1]) 
            {  
                bmax = b[i-j+1];  
            }  
  
            if(s[i]>s[i-j]+j*bmax+header)  
            {  
                s[i] = s[i-j] + j*bmax+header;  
                l[i] = j;  
                //b[i] = bmax;  //我加，跟新当前组，所需的存储位数
            }  
        }  
    }  
}  
  
int length(int i)  
{   
    int k=1;  
    i = i/2;  
    while(i>0)  
    {  
        k++;  
        i=i/2;  
    }  
    return k;
   //return ceil(log(i+1)/log(2));  
}  

int TraceBack(int n,int l[],int b[]) //从后向前检查，因而之后对应段的，最后一个存储有效
{
    stack<int>ss;
    ss.push(l[n]);
    //ss.push(b[n]);
    while (n!=0)      //此时　ｌ[]，用来存储，第ｉ组中，元素个数  
    {
        n=n-l[n];
        ss.push(l[n]);  //l[0]=0,也被压入栈中
        //ss.push(b[n]);
    }
    int i=0;
    while (!ss.empty())
    {
        //b[i]=ss.top();
        //ss.pop(); 
        l[i]=ss.top(); //此时　ｌ[]，用来存储，第ｉ组中，元素个数
        ss.pop();
        i++;
    }
    i--;

    int m=i;//共分成ｍ段
    for(i=1;i<=m;i++)
        b[i]=*max_element(b+i,b+i+l[i]);  // 此时　ｂ[],用来存储，第ｉ组中，元素所需的存储位数
    
    return m;
}

void Out(int m,int min_len,int l[],int b[])
{
    int i=0;
    cout<<"最小长度："<<min_len<<endl;
    cout<<"共分成："<<m<<"段"<<endl;
    for(i=i+1;i<=m;i++)
    {
        cout<<"第一个段含有"<<l[i]<<"元素.   "<<"需要存储位数"<<b[i]<<endl;
    }
}
