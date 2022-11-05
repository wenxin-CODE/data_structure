#include<iostream>
#include<stack>//由于问题中的包是需要进行后进先出的操作，因此考虑到使用栈这种数据结构（后进先出）
using namespace std;

// https://blog.csdn.net/hanmo22357/article/details/124371395

int maxValue(int w[], int v[], const unsigned& length, const unsigned& capacity)
{
    stack<int> Bag;//首先构造出一个空的背包
    int max = 0;//不同装入情况中背包中物品最大的价值
    int weight = 0;//当前背包中物品的总重量
    int value = 0;//当前背包中物品的总价值
    int i;

    for (i = 0; ; i++)
    {
        if (weight + w[i] <= capacity)//第一种情况：背包装入该物品后不会超重
        {
            Bag.push(i);//将该物品装入背包中
            weight += w[i];//装入物品后背包重量增加
            value += v[i];//装入物品后背包中物品的价值增加
        }
        else//第二种情况：装入该物品后背包超重，则不能将该物品装入包中，相当于什么也不做
        {
            //此处用else语句只是方便理解这是另外一种情况，可以省略
        }

        //当从第一个物品考虑到了最后一个物品时，就确定了一个可以满足条件的装包方法（一个方法就是确定了一个规定每一个物品是否装进包里的策略）
        if (i == length - 1)
        {
            //接下来将本次装包物品价值与当前最高的装包物品价值进行比较，保留较大的一个
            if (max < value)
            {
                max = value;
            }
            //此时取出最后装进包里的一件物品并对其下一件物品进行考虑（这就是算法的重点：回溯的过程！）
            {
                i = Bag.top();//取出上一件装入的东西（这就是回溯的过程）
                Bag.pop();
                weight -= w[i];//取出东西后背包重量减轻
                value -= v[i];//取出物品后背包总价值也会降低
                if (i == length - 1)//特殊情况：如果最后装进包里的物品本来在就是编号最大的物品，那么它后面就没有其他物品了，循环必定终止
                {
                    if (Bag.empty())break;//当所有物品都被从包中拿出来后，这是说明已经遍历完所有情况，查找结束（相当于解空间树中最右边的子树已经走完了）
                    i = Bag.top();//取出上一件装入的东西（这就是回溯的过程）
                    Bag.pop();
                    weight -= w[i];//取出东西后背包重量减轻
                    value -= v[i];//取出物品后背包总价值也会降低
                }
            }
        }
    }
    return max;
}

int main(void)
{
    unsigned num, capacity;
    cout << "请输入物品的个数：";
    cin >> num;
    int* weights = new int[num];
    int* values = new int[num];
    cout << "请输入每件物品的重量：";
    for (unsigned i = 0; i < num; i++)
    {
        cin>>weights[i];
    }
    cout << "请输入每件物品的价值：";
    for (unsigned i = 0; i < num; i++)
    {
        cin >> values[i];
    }
    cout << "请输入包的最大承重：";
    cin >> capacity;
    cout << "该问题的最优解为：" << maxValue(weights, values, num, capacity);
    return 0;
} 
