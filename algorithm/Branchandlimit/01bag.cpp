#include <iostream>
#include <vector>
#include <queue>

// https://blog.csdn.net/weixin_42182525/article/details/99970790

using namespace std;

//物品
typedef struct goods {
	int item;		//物品名称
	int weight;		//重量
	int value;		//价值
	int ave;		//平均价值=价值/重量
};

//运算符重载，优先队列降序排列
typedef struct temp {
	bool operator()(goods a, goods b) {
		return a.ave < b.ave;
	}
};

priority_queue < goods, vector<goods>, temp> q;

void Knapsack(int W) {
	vector<bool> choose(q.size() + 1, false);	//物品是否选择放入背包
	int ub = q.top().ave*W;				//初始化上界
	int w = 0, v = 0;		//当前背包里的重量w，价值v
	while (!q.empty()){
		if (w + q.top().weight > W) {
			q.pop();
			if (!q.empty())
				ub = v + q.top().ave*(W - w);
			continue;
		}
		goods a = q.top();	//取出队首位置的物品
		q.pop();
		if (!q.empty()) {
			int yes = v + a.value + q.top().ave*(W - w - a.weight);	//放入物品
			int no = v + q.top().ave*(W - w);	//不放物品
			if (yes > no) {
				ub = yes;
				w += a.weight;
				v += a.value;
				choose[a.item] = true;
			}
			else 
				ub = no;
		}
		else {
			v += a.value;
			choose[a.item] = true;
		}
	} 
	
	cout << "背包最大价值为：" << v << endl;
	cout << "装入的物品编号为：";
	for (int i = 1; i < choose.size(); i++)
		if (choose[i])
			cout << i << " ";
	cout << endl;
}

int main() {
	int n, W;
	cout << "输入物品个数：";
	cin >> n;
	cout << "输入背包容量：";
	cin >> W;
	vector<goods> package(n);
	
	cout << "输入物品信息：（重量w 价值w）" << endl;
	for (int i = 0; i < n; i++) {
		package[i].item = i + 1;
		cin >> package[i].weight >> package[i].value;
		package[i].ave = package[i].value / package[i].weight;
		q.push(package[i]);		//存入信息入队
	}

	Knapsack(W);	//01背包

	system("pause");
	return 0;
}

/*
3 12
7 42
5 25
4 40
*/

