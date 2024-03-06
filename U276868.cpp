// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2002, M = 8008, V = 10010;
// int v[V];
// map<int, int> From[M];
// int dp(int u, int c) {
//     if (c == 0) return v[u];
//     int pre = dp(u, c - 1);
//     map<int, int> Map = From[u];
//     for (auto i : Map) {
//         int to = i.first;
//         int z = i.second;
//         if (c >= z) {
//             pre = max(dp(to, c - z) + v[u], pre);
//         }
//     }
//     return pre;
// }
// int main() {
//     int n, m, q;
//     scanf("%d%d%d", &n, &m, &q);
//     for (int i = 1;i <= n;i++) {
//         scanf("%d", v + i);
//     }
//     for (int i = 1;i <= m;i++) {
//         int from, to, z;
//         scanf("%d%d%d", &from, &to, &z);
//         From[from][to] = z;
//     }
//     while (q--) {
//         int u, c;
//         scanf("%d%d", &u, &c);
//         printf("%d\n", dp(u, c));
//     }
// }

//想到用数组没错，但关键是怎么样构建数组，这种方式中不能确保顺序遍历数组
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2001, M = 8001, V = 10001;
// int v[V], DP[N][801];
// map<int, int> From[M];
// int main() {
//     int n, m, q;
//     scanf("%d%d%d", &n, &m, &q);
//     for (int i = 1;i <= n;i++) {
//         scanf("%d", v + i);
//     }
//     for (int i = 1;i <= m;i++) {
//         int from, to, z;
//         scanf("%d%d%d", &from, &to, &z);
//         From[from][to] = z;
//     }
//     for (int u = 1;u <= n;u++) {
//         DP[u][0] = v[u];
//     }
//     for (int u = 1;u <= n;u++) {
//         for (int c = 1; c <= 800; c++) {
//             DP[u][c] = DP[u][c - 1];
//             map<int, int> Map = From[u];
//             for (auto i : Map) {
//                 int to = i.first;
//                 int z = i.second;
//                 if (c >= z && DP[u][c] < DP[to][c - z] + v[u]) {
//                     DP[u][c] = DP[to][c - z] + v[u];
//                 }
//             }
//         }
//     }
//     while (q--) {
//         int u, c;
//         scanf("%d%d", &u, &c);
//         printf("%d\n", DP[u][c]);
//     }
// }

#include <iostream>
using namespace std;
const int N = 2005, M = 8005, Q = 1e5 + 5, C = 805;

struct Edge {
    int t, w, ne;
} e[M << 1];
int h[N], idx;
void add(int u, int v, int w) { e[++idx] = { v, w, h[u] }, h[u] = idx; }

int n, m, q;
int v[N];
int dp[N][C];
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", v + i);
    for (int x, y, z; m--;)
        scanf("%d%d%d", &x, &y, &z), add(x, y, z);
    for (int c = 1; c < C; c++)
        for (int u = 1; u <= n; u++)
            for (int i = h[u]; i; i = e[i].ne)
                if (c >= e[i].w && dp[u][c] < dp[e[i].t][c - e[i].w] + v[e[i].t])
                    dp[u][c] = dp[e[i].t][c - e[i].w] + v[e[i].t];
    for (int u, c; q--;)
        scanf("%d%d", &u, &c), printf("%d\n", dp[u][c] + v[u]);
}