#include <stdio.h>
// arr 为待排序数组，[p,q] 用于指定排序区域
int partition(int* arr, int p, int q) {
    int temp = 0;
    // lo、hi分别表示指向首个元素和倒数第 2 个元素的指针
    int lo = p;
    int hi = q - 1;
    //pivot 表示选中的中间值
    int pivot = arr[q];
    while (1)
    {
        //lo从左往右遍历，直至找到一个不小于 pivot 的元素
        // pivot指向末尾元素
        while (arr[lo] < pivot) {
            lo++;
        };
        //hi从右往左遍历，直至找到一个不大于 pivot 的元素
        while (hi > 0 && arr[hi] > pivot) {
            hi--;
        }
        //如果 lo≥hi，退出循环
        if (lo >= hi)
        {
            break;
        }
        else {
            //交换 arr[lo] 和 arr[hi] 的值
            temp = arr[lo];
            arr[lo] = arr[hi];
            arr[hi] = temp;
            // lo 和 hi 都向前移动一个位置，准备继续遍历
            lo++;
            hi--;
        }
    }
    //交换 arr[lo] 和 arr[q] 的值
    temp = arr[lo];
    // 末尾元素赋值给lo，相当于分界点
    arr[lo] = pivot;
    // 这里再改变q为lo所指的元素
    arr[q] = temp;
    //返回中间值所在序列中的位置
    return lo;
}

void quick_sort(int* arr, int p, int q) {
    int par;
    //如果待排序序列不存在，或者仅包含 1 个元素，则不再进行分割
    if (q - p <= 0) {
        return;
    }
    else {
        //调用 partition() 函数，分割 [p,q] 区域
        // 完成后保证，par左边的都小，右边的都大
        par = partition(arr, p, q);
        //以 [p,par-1]作为新的待排序序列，继续分割
        quick_sort(arr, p, par - 1);
        //以[par+1,q]作为新的待排序序列，继续分割
        quick_sort(arr, par + 1, q);
    }
}

int main()
{
    int i = 0;
    int arr[10] = { 35,33,42,10,14,19,27,44,26,31 };
    //对于 arr 数组中所有元素进行快速排序
    quick_sort(arr, 0, 9);
    for (; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}