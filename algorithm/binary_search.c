#include <stdio.h>
// 递归算法——二分查找
//实现二分查找算法，ele 表示要查找的目标元素，[p,q] 指定查找区域
int binary_search(int *arr,int p,int q,int ele) {
    int mid = 0;
    //如果[p,q] 不存在，返回 -1
    if (p > q) {
        return -1;
    }
    // 找到中间元素所在的位置
    mid = p + (q - p) / 2;
    //递归的出口
    if (ele == arr[mid]) {
        return mid;
    }
    //比较 ele 和 arr[mid] 的值，缩小 ele 可能存在的区域
    if (ele < arr[mid]) {
        //新的搜索区域为 [p,mid-1]
        return binary_search(arr, p, mid - 1, ele);
    }
    else {
        //新的搜索区域为 [mid+1,q]
        return binary_search(arr, mid + 1, q, ele);
    }
}

int main()
{
    int arr[10] = { 10,14,19,26,27,31,33,35,42,44 };
    //输出二叉查找元素 31 所在位置的下标
    printf("%d", binary_search(arr, 0, 9, 31));
    return 0;
}