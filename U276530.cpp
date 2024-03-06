// https://www.luogu.com.cn/problem/U276530

//90分，不知道错哪里了
#include <bits/stdc++.h>
using namespace std;
vector<int> HNC, HNR;
const int MAX = 1002;
//num 矩阵；flag 补充的地方；row 每行行差；hrow 是否计算出行差
int num[MAX][MAX], flag[MAX][MAX], row[MAX], col[MAX], hrow[MAX], hcol[MAX];
//补全第i行
void bur(int i, int row, int m) {
    int j = 1;
    while (!num[i][j]) j++;
    int j1 = j;//向小的遍历
    while (j1-- > 1) {
        if (num[i][j1]) continue;
        num[i][j1] = num[i][j1 + 1] - row;
        flag[i][j1] = num[i][j1];
    }
    int j2 = j;//向大的遍历
    while (j2++ < m) {
        if (num[i][j2]) continue;
        num[i][j2] = num[i][j2 - 1] + row;
        flag[i][j2] = num[i][j2];
    }
}
//补全第j列
void buc(int j, int col, int n) {
    int i = 1;
    while (!num[i][j]) i++;
    int i1 = i - 1;//向小的遍历
    while (i1 >= 1) {
        if (num[i1][j]) {
            i1--; continue;
        }
        num[i1][j] = num[i1 + 1][j] - col;
        flag[i1][j] = num[i1][j];
        i1--;
    }
    int i2 = i + 1;//向大的遍历
    while (i2 <= n) {
        if (num[i2][j]) {
            i2++; continue;
        }
        num[i2][j] = num[i2 - 1][j] + col;
        flag[i2][j] = num[i2][j];
        i2++;
    }
}
//计算行等差
void cr(int m, int n, int* row) {
    for (int i = 1; i <= n; i++) {
        if (hrow[i]) continue;
        int j = 1, a, b, A = 0, B = 0;
        while (j <= m && !num[i][j]) j++;
        if (j <= m) {
            a = num[i][j];
            A = j;
            j++;
        }
        while (j <= m && !num[i][j]) j++;
        if (j <= m) {
            b = num[i][j];
            B = j;
        }
        if (A && B) {
            row[i] = (b - a) / (B - A);
            hrow[i] = 1;
            HNR.push_back(i);//计算出了新的行等差
        }

    }
}
//计算列等差
void cc(int m, int n, int* col) {
    for (int j = 1; j <= m; j++) {
        if (hcol[j]) continue;
        int i = 1, a, b, A = 0, B = 0;
        while (i <= n && !num[i][j]) i++;
        if (i <= n) {
            a = num[i][j];
            A = i;
            i++;
        }
        while (i <= m && !num[i][j]) i++;
        if (i <= m) {
            b = num[i][j];
            B = i;
        }
        if (A && B) {
            col[j] = (b - a) / (B - A);
            hcol[j] = 1;
            HNC.push_back(j);//计算出了新的列等差
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    memset(flag, 0, sizeof flag);
    memset(hrow, 0, sizeof hrow);
    memset(hcol, 0, sizeof hcol);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> num[i][j];
        }
    }
    cr(m, n, row);
    cc(m, n, col);
    while (!HNR.empty() || !HNC.empty()) {
        while (!HNR.empty()) {
            int i = HNR.back();
            HNR.pop_back();
            bur(i, row[i], m);
        }
        while (!HNC.empty()) {
            int j = HNC.back();
            HNC.pop_back();
            buc(j, col[j], n);
        }
        cr(m, n, row);
        cc(m, n, col);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (flag[i][j] <= 0) continue;
            cout << i << " " << j << " " << flag[i][j] << endl;
        }
    }
}
// #include <iostream>
// using namespace std;
// const int N = 1005;

// // g 为输入的矩阵，ans 为恢复后的矩阵
// int g[N][N], ans[N][N];
// // row、col 分别记录每行/列有多少个非 0 元素
// int row[N], col[N];
// int n, m;

// // 恢复函数，若成功恢复了元素，返回 true，否则返回 false
// bool fix() {
//     bool tag = false;
//     // 遍历每一行
//     for (int i = 1; i <= n; i++)
//         // 如果该行的非 0 元素个数大于 2，说明改行可以完整地恢复
//         if (row[i] >= 2) {
//             int a = 0, b = 0;
//             // 遍历每一列，找到这一行的前两个非 0 元素
//             for (int j = 1; j <= m && !(a && b); j++)
//                 if (ans[i][j])
//                     if (!a)
//                         a = j;
//                     else
//                         b = j;
//             // 计算该行的公差
//             int diff = (ans[i][b] - ans[i][a]) / (b - a);
//             ans[i][0] = ans[i][a] - diff * a;
//             for (int j = 1; j <= m; j++)
//                 if (!ans[i][j])
//                     // 记得更新对应列的情况
//                     col[j]++, ans[i][j] = ans[i][j - 1] + diff;
//             // 恢复完之后，将改行置 0，避免重复计算
//             row[i] = 0, tag = true;
//         }
//     // 遍历每一列，跟上面同理
//     for (int j = 1; j <= m; j++)
//         if (col[j] >= 2) {
//             int a = 0, b = 0;
//             for (int i = 1; i <= n && !(a && b); i++)
//                 if (ans[i][j])
//                     if (!a)
//                         a = i;
//                     else
//                         b = i;
//             int diff = (ans[b][j] - ans[a][j]) / (b - a);
//             ans[0][j] = ans[a][j] - diff * a;
//             for (int i = 1; i <= n; i++)
//                 if (!ans[i][j])
//                     row[i]++, ans[i][j] = ans[i - 1][j] + diff;
//             col[j] = 0, tag = true;
//         }
//     return tag;
// }

// int main() {
//     scanf("%d%d", &n, &m);
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             scanf("%d", &g[i][j]),
//             ans[i][j] = g[i][j],
//             row[i] += g[i][j] > 0,
//             col[j] += g[i][j] > 0;
//     // 每次恢复完之后，可能新恢复的数值可以帮助恢复其他信息
//     // 直到恢复不出东西，退出循环
//     while (fix())
//         ;
//     // 输出
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             if (ans[i][j] ^ g[i][j])
//                 printf("%d %d %d\n", i, j, ans[i][j]);
// }