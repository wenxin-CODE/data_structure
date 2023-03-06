#include<iostream>
#include<math.h>
using namespace std;
// 格雷码问题
//字符串数组s用来保存2^n个字符序列
string s[1025];

void gray(int n) {
	//递归出口，即1位gray对应的0，1输出
	if (n == 1) {
		s[0] = "0";
		s[1] = "1";
		return;
	}
	
	//分治，把规模n的问题 变成 规模n-1的问题
	gray(n - 1);
	
	//对 i = pow(2, n-1) to pow(2, n-1)的 n-1位 即后一半2^(n-1)个码字用逆序书写
    // 对高位n进行前半段赋0，后半段赋1，然后逆序数写，保证相邻两位只差一个数字
	for (int i = pow(2, n - 1); i < pow(2, n); i++)
		s[i] = s[(int)(pow(2, n) - 1 - i)];
		
	//对高位n进行前半段赋0，后半段赋1
	for (int i = 0; i < pow(2, n); i++)
		if (i < pow(2, n - 1))s[i] = "0" + s[i];
		else s[i] = "1" + s[i];
}
int main() {
	int n;
	cout << "请输入一个正整数(n<=10):";
	cin >> n;
	try {
		if (n > 10)throw(n);
	}
	catch (int) { 
        cout << "n must <=10";
        return 0;
    }
	gray(n);
	for (int i = 0; i < pow(2, n); i++)
		cout << s[i] << endl;
    return 0;
}
