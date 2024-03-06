// https://www.luogu.com.cn/problem/U276530

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int N = n + 1, M = m + 1;
    int row[N], col[M], num[N][M], flag[N][M] = { 0 };//flag标记是否可补全
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i <= m; j++) {
            cin >> num[i][j];
        }
    }
    //row记录第几行的等差
    for (int i = 1; i <= n; i++) {
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
        if (A && B) row[i] = (b - a) / (B - A);
    }
    //col 列等差
    for (int j = 1; j <= m; j++) {
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
        if (A && B) col[j] = (b - a) / (B - A);
    }
    for (int i = 1; i <= n; i++) {
        if (!row[i]) continue;
        for (int j = 1; i <= m; j++) {
            if (num[i][j]) continue;

        }
    }
}