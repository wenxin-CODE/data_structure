#include <iostream>
#include <vector>
using namespace std;

// https://blog.csdn.net/weixin_47487155/article/details/115328155
void dfs(int depth, int n, const int a[20][20], vector<vector<int>>& v, vector<int>&path)
//depth为递归层数，n为图节点数，二维数组a[20][20]存放图的邻接矩阵，二维向量v记录哈密顿回路
//一维向量path[i]存放前往的第i个城市(结点）为path[i]，path[0]=1(出发点始终为第一个节点）
{
	if (depth == n )//递归出口
	{
        if(a[(path[depth - 1] - 1)][0] == 1)//能返回出发城市（出发点）才是哈密顿回路
	        // 尾部添加元素
			v.push_back(path); 
	    path.resize(n, 1);//清除上一条哈密顿回路痕迹的干扰
	}
	else
	{
		for (int j = 1; j <= n; j++)//枚举下一个结点的各种可能
		{
			path[depth] = j;
			bool flag = true;
			for (int i = 0; i < depth; i++)
                if ((a[(path[depth-1]-1)][j - 1] == 0) || (a[(path[depth - 1]-1)][j - 1] == 1 && path[i]== j))//path[i]=j表示之前来过,对应第21行代码
                //减枝函数，减去当前不可前往的结点和之前已前往的结点
				{
					flag = false;
						break;
						// 跳出当前循环
				}
			    if (flag) 
                    dfs(depth + 1, n, a, v, path);//若满足约束条件和限界函数，递归下一层
		}
	}
}
int main()
{
	int n;
	int a[20][20];
	//测试用例： a[5][5]={{0,1,0,1,0},{1,0,1,0,1},{0,1,0,1,1},{1,0,1,0,1},{0,1,1,1,0}}
	cout << "图的节点个数为：";
	cin >> n;
	cout << "请输入图的邻接矩阵" << endl;//以出发点为第一个节点
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	// 动态数组，大小不固定
	vector<vector<int>>v;//记录每一条路径
	vector<int> path;
	// cout<<path[0]<<endl;
	path.resize(n, 1);//全部赋值为1
	dfs(1, n, a, v, path);
	int count = v.size();
	if (count == 0)
		cout << "该图不存在哈密顿回路";
	else {
		cout << "该图存在" << count << "个哈密顿回路," << "分别是：" << endl;
		for (auto it = v.begin(); it != v.end(); it++)
		{
			for (auto z = (*it).begin(); z != (*it).end(); z++)
				cout << *z<<" ";
			cout << endl;
		}
	}
}

