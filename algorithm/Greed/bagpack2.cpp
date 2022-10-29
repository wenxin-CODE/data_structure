#include<bits/stdc++.h>//包含了目前c++所包含的所有头文件！！！！
using namespace std;
const int maxn = 1000;
float z[maxn];
 
//  贪心算法——部分背包
//  https://blog.csdn.net/doubleguy/article/details/102980460
void Sort(int n,float w[],float v[]){
	for(int i=0;i<n;i++)
		z[i]=v[i]/w[i];//用z[]存商品的单位重量价值 
	for(int i=0;i<n;i++){//此排序的策略是每次把 单位重量商品的价值最大 的商品放在前面 
		for(int j=i+1;j<n;j++){
			if(z[i]<z[j]){
				float temp = z[i];
				z[i] = z[j];
				z[j]=temp;
				float tempw = w[i];//这里不要忘记把商品的重量和价值同时放到最前面 
				w[i] = w[j];
				w[j] = tempw;
				float tempv = v[i];
				v[i] = v[j];
				v[j] = tempv; 
			}
		}
	}
}
 
void fire(int n,float w[],float v[],float x[],float carrymax){
	Sort(n,w,v);//根据单位重量商品的价值对商品进行排序 
	int i;
	for(i=0;i<n;i++){
		if(w[i]>carrymax)	
            break;
		x[i] = 1;	//x[]数组用来记录此次是否选择商品，1代表全部拿走，0代表不拿，小数代表部分拿 
		carrymax -= w[i];
	}
	if(i<=n-1)  x[i] = carrymax/w[i]; 
} 
 
 
int main(){
	int n;
	float carry=0; 
	float carrymax,v[maxn],w[maxn],x[maxn];//w[],每个商品的重量,v[]代表每个商品的价值,carrymax代表最大容量 
	memset(x,0,sizeof(x));
	cout<<"请输入最大容量：";
	cin>>carrymax;
	cout<<"请输入商品数量：";
	cin>>n;
	cout<<"请输入每个商品的重量和价值："<<endl;
	for(int i=0;i<n;i++){
		cin>>w[i]>>v[i];
	}
	fire(n,w,v,x,carrymax);
	for(int i=0;i<n;i++){
		if(x[i]==1){
			cout<<"商品重量为"<<w[i]<<" 价值为"<<v[i]<<"的商品全部拿走"<<endl;
			carry+=v[i];
		}
			
		else if(x[i]==0)
			cout<<"商品重量为"<<w[i]<<" 价值为"<<v[i]<<"的商品不拿走"<<endl;
		else{
			cout<<"商品重量为"<<w[i]<<" 价值为"<<v[i]<<"的商品拿走"<<x[i]<<endl;
			carry+=v[i]*x[i];
		}
	}
	cout<<"最终收获的商品价值为："<<carry<<endl;
	return 0;
}