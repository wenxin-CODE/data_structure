#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define linkNum 3//全局设置链表中节点存储数据的个数
typedef struct Link {
    char a[linkNum]; //数据域可存放 linkNum 个数据
    struct Link * next; //代表指针域，指向直接后继元素
}link; // nk为节点名，每个节点都是一个 link 结构体

link * initLink(link * head, char * str);
void displayLink(link * head);

int main()
{
    link * head = NULL;
    head = initLink(head, "data.biancheng.net");
    displayLink(head);
    return 0;
}

//初始化链表，其中head为头指针，str为存储的字符串
link * initLink(link * head, char * str) {
    int length = strlen(str);
    //根据字符串的长度，计算出链表中使用节点的个数
    int num = length/linkNum;
    if (length%linkNum) {
        num++;
    }
    //创建并初始化首元节点
    head = (link*)malloc(sizeof(link));
    head->next = NULL;
    link *temp = head;
    //初始化链表
    for (int i = 0; i<num; i++)
    {
        int j = 0;
        for (; j<linkNum; j++)
        {
            if (i*linkNum + j < length) {
                temp->a[j] = str[i*linkNum + j];
            }          
            else
                temp->a[j] = '#';
        }
        if (i*linkNum + j < length)
        {
            link * newlink = (link*)malloc(sizeof(link));
            newlink->next = NULL;
            temp->next = newlink;
            temp = newlink;
        }
    }
    return head;
}

// #include <stdio.h>
// #include <string.h>
// //串普通模式匹配算法的实现函数，其中 B是伪主串，A是伪子串
// int mate(char * B,char *A){
//     int i=0,j=0;
//     while (i<strlen(B) && j<strlen(A)) {
//         if (B[i]==A[j]) {
//             i++;
//             j++;
//         }else{
//             i=i-j+1;
//             j=0;
//         }
//     }
//     //跳出循环有两种可能，i=strlen(B)说明已经遍历完主串，匹配失败；j=strlen(A),说明子串遍历完成，在主串中成功匹配
//     if (j==strlen(A)) {
//         return i-strlen(A)+1;
//     }
//     //运行到此，为i==strlen(B)的情况
//     return 0;
// }
// int main() {
//     int number=mate("ababcabcacbab", "abcac");
//     printf("%d",number);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main()
// {
//     char * a1 = NULL;
//     char * a2 = NULL;
//     a1 = (char*)malloc(10 * sizeof(char));
//     strcpy(a1, "data.bian");//将字符串"data.bian"复制给a1
//     a2 = (char*)malloc(10 * sizeof(char));
//     strcpy(a2, "cheng.net");
//     int lengthA1 = strlen(a1);//a1串的长度
//     int lengthA2 = strlen(a2);//a2串的长度
//     //尝试将合并的串存储在 a1 中，如果 a1 空间不够，则用realloc动态申请
//     if (lengthA1 < lengthA1 + lengthA2) {
//         a1 = (char*)realloc(a1, (lengthA1 + lengthA2+1) * sizeof(char));
//     }
//     //合并两个串到 a1 中
//     for (int i = lengthA1; i < lengthA1 + lengthA2; i++) {
//         a1[i] = a2[i - lengthA1];
//     }
//     //串的末尾要添加 \0，避免出错
//     a1[lengthA1 + lengthA2] = '\0';
//     printf("%s", a1);
//     //用完动态数组要立即释放
//     free(a1);
//     free(a2);
//     return 0;
// }

//输出链表
void displayLink(link * head) {
    link * temp = head;
    while (temp) {
        for (int i = 0; i < linkNum; i++) {
            printf("%c", temp->a[i]);
        }
        temp = temp->next;
    }
}