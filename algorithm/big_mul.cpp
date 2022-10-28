#include<stdlib.h>
#include<cstring>
#include <iostream>
 
//  https://blog.csdn.net/qq_27437197/article/details/85739473
using namespace std;
#define M 100
char sa[1000];
char sb[1000];
typedef struct _Node {
    int s[M];
    int l;
    int c;
} Node, *pNode;
 
void cp(pNode src, pNode des, int st, int l) {
    int i, j;
    for (i = st, j = 0; i < st + l; i++, j++) {
        des->s[j] = src->s[i];
    }
    des->l = l;
    des->c = st + src->c;
}
 
void add(pNode pa, pNode pb, pNode ans) {
    int i, cc, k, palen, pblen, len;
    int ta, tb;
    pNode temp;
    //保证pa是高次幂
    if ((pa->c < pb->c)) {
        temp = pa;
        pa = pb;
        pb = temp;
    }
    ans->c = pb->c;  //结果的幂取最少的幂
    cc = 0;
    palen = pa->l + pa->c; //pa的长度
    pblen = pb->l + pb->c; //pb的长度
    //选取最长的长度
    if (palen > pblen)
        len = palen;
    else
        len = pblen;
    k = pa->c - pb->c; 
    //k是幂差，len是最长的位数
    for (i = 0; i < len - ans->c; i++) {
        if (i < k)
            ta = 0;
        else
            ta = pa->s[i - k];
        if (i < pb->l)
            tb = pb->s[i];
        else
            tb = 0;
        if (i >= pa->l + k)
            ta = 0;
        ans->s[i] = (ta + tb + cc) % 10;
        cc = (ta + tb + cc) / 10;
    }
    if (cc)
        ans->s[i++] = cc;
    ans->l = i;
}
 
void mul(pNode pa, pNode pb, pNode ans) {
    int i, cc, w;
    int ma = pa->l >> 1, mb = pb->l >> 1;
    Node ah, al, bh, bl;
    Node t1, t2, t3, t4, z;
    pNode temp;
    if (!ma || !mb) {
    //如果pa是一位数，则和pb交换
        if (!ma) {
            temp = pa;
            pa = pb;
            pb = temp;
        }
        ans->c = pa->c + pb->c;
        w = pb->s[0]; //pb必为一位数
        cc = 0;
        for (i = 0; i < pa->l; i++) {
            //pa必为2位数以上
            ans->s[i] = (w * pa->s[i] + cc) % 10;
            cc = (w * pa->s[i] + cc) / 10;
        }
        if (cc)
            ans->s[i++] = cc;
        ans->l = i;
        return;
    }
    cp(pa, &ah, ma, pa->l - ma); //高位升幂
    cp(pa, &al, 0, ma);           //低位幂不变
    cp(pb, &bh, mb, pb->l - mb);
    cp(pb, &bl, 0, mb);
 
    mul(&ah, &bh, &t1); 
    mul(&ah, &bl, &t2);
    mul(&al, &bh, &t3);
    mul(&al, &bl, &t4);
 
    add(&t3, &t4, ans);
    add(&t2, ans, &z);
    add(&t1, &z, ans);
}
 
 
int main() {
    Node ans, a, b;
    cout << "输入大整数 a：" << endl;
    cin >> sa;
    cout << "输入大整数 b：" << endl;
    cin >> sb;
    a.l = strlen(sa);
    b.l = strlen(sb);
    int z = 0, i;
    for (i = a.l - 1; i >= 0; i--)
        a.s[z++] = sa[i] - '0';
    a.c = 0;
    z = 0;
    for (i = b.l - 1; i >= 0; i--)
        b.s[z++] = sb[i] - '0';
    b.c = 0;
    mul(&a, &b, &ans);
    cout << "最终结果为：";
    for (i = ans.l - 1; i >= 0; i--)
        cout << ans.s[i];
    cout << endl;
    return 0;
}