#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
using namespace std;

// https://blog.csdn.net/qq_43599985/article/details/102926683
/********************/
struct state
{
	int a[3][3];
	int zx,zy;
	int integer;//map->9位数
	int useful;//若0位置越界或节点重复，则为无效节点 
};
state start;
queue<state> q;
map<int,int> used;
map<int,int> step;
int walk[4][2]=
{
	0,-1,//left
	+1,0,//down
	0,+1,//right
	-1,0//up
};
/*******************/
int bfs();
int setinteger(state n);
state move(state now,int i);
/******************/
void init()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			cin>>start.a[i][j];
			if(start.a[i][j]==0)
			{
				start.zx=i;
				start.zy=j;
			}
		}
	start.integer=setinteger(start);
	used[start.integer]=1;
	step[start.integer]=0;
	q.push(start);
}
 
//  为每种情况赋一个值
int setinteger(state n)
{
	n.integer=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			n.integer*=10;
			n.integer+=n.a[i][j];
		}
//	cout<<n.integer<<endl;
	return n.integer;
}
 
int bfs()
{
	state now,next;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			next=move(now,i);
			if(next.useful)
			{
				if(next.integer==123456780)
					return step[next.integer];
				else
					q.push(next);
			}
		}
	}
	return -1;
}
 
//  移动0的位置
state move(state now,int i)
{
	int newx,newy;
	state next;
	next.useful=0;
	for(int j=0;j<3;j++)
		for(int k=0;k<3;k++)
		{
			next.a[j][k]=now.a[j][k];
			cout<<next.a[j][k]<<endl;
		}	
	newx=now.zx+walk[i][0];
	newy=now.zy+walk[i][1];
	cout<<newx<<newy<<endl;
	if(newx>=0 && newx<3 && newy>=0 && newy<3)
	{
		swap(next.a[now.zx][now.zy],next.a[newx][newy]);
		next.zx=newx;
		next.zy=newy;
		next.integer=setinteger(next);
		if(!used.count(next.integer))//查看这种情况出现过没
		{
			used[next.integer]=1;
			step[next.integer]=step[now.integer]+1;
			next.useful=1;
		}
	}
	cout<<next.integer<<endl;
	return next;
}
	
int main()
{
	init();
	cout<<bfs()<<endl;
	return 0;
} 


// 样例输入
// 1 2 3
// 4 0 6
// 7 5 8