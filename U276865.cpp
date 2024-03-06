// 零入度算法
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5, M = 5e5 + 5, mod = 1e9 + 7;

struct Edge {
    int t, ne;  //从t到ne的边
} e[M << 1];    //为什么要乘2？
int h[2][N], idx;   //h:? idx:?
void add(int u, int v, int op) { e[++idx] = { v, h[op][u] }, h[op][u] = idx; }

ll min_[N], max_[N];
ll ans1, ans2;
int a[N], n, m;
int q[N];
void toposort(ll d[N], int deg[N], bool op) {
    if (op)
        memset(d, 0x3f, sizeof min_);
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
        if (!deg[i])
            q[r++] = i, d[i] = op ? ans1 - a[i] : 0;
    while (l < r) {
        int x = q[l++];
        for (int i = h[op][x]; i; i = e[i].ne) {
            deg[e[i].t]--;
            if (!deg[e[i].t])
                q[r++] = e[i].t;
            d[e[i].t] = op ? min(d[e[i].t], d[x] - a[e[i].t]) : max(min_[e[i].t], min_[x] + a[x]);
        }
    }
}

int in[N], out[N];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int u, v; m--;)
        scanf("%d%d", &u, &v), add(u, v, 0), add(v, u, 1), in[v]++, out[u]++;

    toposort(min_, in, 0);
    for (int i = 1; i <= n; i++)
        ans1 = max(ans1, min_[i] + a[i]);
    toposort(max_, out, 1);

    ans2 = 1;
    for (int i = 1; i <= n; i++)
        ans2 = ans2 * (max_[i] - min_[i] + 1) % mod;
    printf("%lld\n%lld\n", ans1, ans2);
}



// 零出度算法
// #include <iostream>
// using namespace std;
// typedef long long ll;
// const int N = 1e5 + 5, M = 5e5 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;

// struct Edge {
//     int t, ne;
// } e[M << 1];
// int h1[N], h2[N], idx;
// void add(int h[N], int u, int v) { e[++idx] = { v, h[u] }, h[u] = idx; }

// bool have_in[N], have_out[N];

// ll d1[N], ans1;
// int a[N];
// bool vis[N];
// void dfs1(int x) {
//     vis[x] = true;

//     for (int i = h2[x]; i; i = e[i].ne) {
//         if (!vis[e[i].t])
//             dfs1(e[i].t);
//         d1[x] = max(d1[x], d1[e[i].t]);
//     }

//     d1[x] += a[x], ans1 = max(ans1, d1[x]);
// }

// ll d2[N], ans2 = 1;
// void dfs2(int x) {
//     vis[x] = false, d2[x] = ans1;

//     for (int i = h1[x]; i; i = e[i].ne) {
//         if (vis[e[i].t])
//             dfs2(e[i].t);
//         d2[x] = min(d2[x], d2[e[i].t]);
//     }

//     d2[x] -= a[x], ans2 = ans2 * (d2[x] - d1[x] + a[x] + 1) % mod;
// }

// int main() {
//     int n, m;
//     scanf("%d%d", &n, &m);
//     for (int i = 1; i <= n; i++)
//         scanf("%d", &a[i]);
//     for (int u, v; m--;)
//         scanf("%d%d", &u, &v), add(h1, u, v), add(h2, v, u), have_in[v] = have_out[u] = true;

//     for (int i = 1; i <= n; i++)
//         if (!have_out[i])
//             dfs1(i);

//     for (int i = 1; i <= n; i++)
//         if (!have_in[i])
//             dfs2(i);

//     printf("%lld\n%lld\n", ans1, ans2);
// }