// https://www.luogu.com.cn/problem/U281314
// 改变矩阵访问方式才是王道，改变矩阵显得很蠢
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;    //n 表示矩阵大小; q 表示操作次数
    scanf("%d", &n);
    int m[n][n];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            int t;
            scanf("%d", &t);
            m[i][j] = t;
        }
    }
    scanf("%d", &q);
    bool flag = false;      //是否翻转的标志
    int row = 0, col = 0;   //row:移动几行；col:移动几列
    while (q--) {
        int q1, q2;
        scanf("%d", &q1);
        if (q1 == 1) flag = !flag;
        else if (q1 == 2) {
            scanf("%d", &q2);
            flag ? col -= q2 : row -= q2;   //跟顺序有关系，flag不能抵消
        } else {
            scanf("%d", &q2);
            flag ? row -= q2 : col -= q2;
        }
    }
    row = row % n + n;  //（-11）% 10 == (-1)
    col = col % n + n;  //保证两个在[0，n)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //以（row,col）为基准，出发去遍历
            int ret = flag ? m[(row + j) % n][(col + i) % n] : m[(row + 1) % n][(col + j) % n];
            printf("%d ", ret);
        }
        printf("\n");
    }
    return 0;
}