#include <stdio.h>
//设置一个数组，数组的下标表示集合中的元素，所以数组只用下标为1，2，3的空间
int set[5];
//i代表数组下标，n表示集合中最大的元素值
void PowerSet(int i,int n){
    //当i>n时，说明集合中所有的元素都做了选择，开始判断
    if (i>n) {
        for (int j=1; j<=n; j++) {
            //如果树组中存放的是 1，说明在当初尝试时，选择取该元素，即对应的数组下标，所以，可以输出
            if (set[j]==1) {
                printf("%d ",j);
            }
        }
        printf("\n");
    }else{
        //如果选择要该元素，对应的数组单元中赋值为1；反之，赋值为0。然后继续向下探索
        set[i]=1;PowerSet(i+1, n);
        set[i]=0;PowerSet(i+1, n);
    }
}
int main() {
    int n=3;
    for (int i=0; i<5; i++) {
        set[i]=0;
    }
    PowerSet(1, n);
    return 0;
}