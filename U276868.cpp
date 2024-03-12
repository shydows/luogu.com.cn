// https://www.luogu.com.cn/problem/U276868
#include<bits/stdc++.h>
using namespace std;
const int N = 2001, M = 8001, C = 801, Q = 1e5 + 1;
int v[N];
int dp[N][C];

int rd() {//scanf %d的函数，比scanf快
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = 0;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return f ? k : -k;
}
void wr(int x) {//printf %d的函数，比printf快
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar((x % 10) ^ '0');
}

int h[N], e[M], co[M], ne[M], idx = 1;
void add(int a, int b, int c) {
    e[idx] = b;
    co[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int DP(int i, int c) {
    if (!dp[i][c]) {
        for (int j = h[i]; j; j = ne[j]) {
            int t = e[j]; // t就是与i邻接的点
            int cost = co[j];
            if ((c >= cost) && (dp[i][c] < (DP(t, c - cost) + v[t])))
                dp[i][c] = DP(t, c - cost) + v[t];
        }
    }
    return dp[i][c];
}

int main() {
    int n = rd(); int m = rd(); int q = rd();

    for (int i = 1;i <= n;i++) {
        v[i] = rd();
    }

    for (int i = 1;i <= m;i++) {
        int x = rd(); int y = rd(); int z = rd();
        add(x, y, z);
    }

    while (q--) {
        int u = rd(); int c = rd();
        wr(DP(u, c) + v[u]);
        putchar('\n');
    }

    return 0;
}

// Answer
// #include <iostream>
// using namespace std;
// const int N = 2005, M = 8005, Q = 1e5 + 5, C = 805;

// struct Edge {
//     int t, w, ne;
// } e[M << 1];
// int h[N], idx;
// void add(int u, int v, int w) { e[++idx] = { v, w, h[u] }, h[u] = idx; }

// int n, m, q;
// int v[N];
// int dp[N][C];
// int main() {
//     scanf("%d%d%d", &n, &m, &q);
//     for (int i = 1; i <= n; i++)
//         scanf("%d", v + i);
//     for (int x, y, z; m--;)
//         scanf("%d%d%d", &x, &y, &z), add(x, y, z);
//     for (int c = 1; c < C; c++)
//         for (int u = 1; u <= n; u++)
//             for (int i = h[u]; i; i = e[i].ne)
//                 if (c >= e[i].w && dp[u][c] < dp[e[i].t][c - e[i].w] + v[e[i].t])
//                     dp[u][c] = dp[e[i].t][c - e[i].w] + v[e[i].t];
//     for (int u, c; q--;)
//         scanf("%d%d", &u, &c), printf("%d\n", dp[u][c] + v[u]);
// }