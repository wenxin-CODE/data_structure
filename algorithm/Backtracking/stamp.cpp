#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iostream>

// https://blog.csdn.net/yangshucheng2018/article/details/105123037

#define INF 2147483647
const int MAXN = 2000;
using namespace std;
int m, n;
int ans[MAXN], maxStampVal, stampVal[MAXN], maxVal[MAXN], y[MAXN];
bool occur[MAXN];
void search(int cur){//搜索前cur种邮票的最大连续邮资
    if(cur > n){
        if(maxVal[cur-1] > maxStampVal){
            maxStampVal = maxVal[cur-1];
            memcpy(ans, stampVal, sizeof(stampVal));
        }
        return ;
    }
    int tmp[MAXN];//tmp存储当前y数组,为接下来回溯后返回用
    memcpy(tmp, y, sizeof(y));
    for(int i = stampVal[cur - 1] + 1; i <= maxVal[cur - 1] + 1; ++i){
        //对第cur种面额的可取值范围进行最大连续面额的搜索
        stampVal[cur] = i;//第cur个邮票面值为 i
        // 关键步骤，利用了动态规划的思想
        //设不超过m张面值为x[1:i]的邮票贴出邮资j所需的最少邮票数为y[j]
        //y贴出的邮资为0~（第cur-1种邮票）*m
        for(int j = 0; j < stampVal[cur - 1] * m; ++j){
            if(y[j] < m){//不超过m张的时候
            for(int num = 1; num <= m - y[j]; ++num){
            //num为可以贴上面额为i的邮票的数量
//如果最少邮票数y[j]添加num张邮票时的张数（y[j] + num）
//小于 y[j]再添加num张邮票时的邮资 的张数（y[j + i * num]）时，
//说明邮资为j + i * num时耗费的张数应该是更小的y[j] + num
                if(y[j] + num < y[j + i * num] && (j + i * num < MAXN))
                    y[j + i * num] = y[j] + num;
            }
            }
        }
        int r = maxVal[cur - 1];//最大连续邮资为r
        while(y[r + 1] < INF) r++;//当y[r+1]有进行动态规划得到的值时，说明最大连续邮资可以到r+1
        maxVal[cur] = r;//当前的最大连续邮资为r
        search(cur + 1);//搜索cur+1时的情况
        memcpy(y, tmp, sizeof(tmp));//回溯y
    }
}
int main(){
    //n邮票面额种类数,m单种邮票最大张数
    while(scanf("%d %d", &n, &m)!=EOF){
        stampVal[1] = 1;//第一张邮票必须是1
        maxVal[1] = m;//用m张面值为1的邮票组成的最大连续面额为m
        int i=0;
        for(i = 0; i <= m; ++i)
            y[i] = i;//只有一张面值为1的邮票时，y[i]=i
        while(i < MAXN) y[i++] = INF;//其他y[i+1~MAXN]必须最大,方便之后选更小的
        maxStampVal = -1;
        search(2);
        for(i = 1; i <= n; ++i)
            printf("%3d", ans[i]);
        printf(" ->%3d\n", maxStampVal);
    }
    return 0;
}
