//https://www.luogu.com.cn/problem/U276860
//棋盘 
// 所谓的标准答案，运行直接卡死
// #include <iostream>
// #include <set>
// using namespace std;
// typedef pair<int, int> pii;
// const int N = 105, K = 1005;
// const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
// //小葱
// struct Node {
//     int x, y, d, f;
//     bool alive;
//     // bool operator<(Node other) {
//     //     return value < other.value;
//     // }
// }q[K];
// //棋盘
// set<pii> g[N][N];
// int main() {
//     int n, m, k;
//     scanf("%d%d%d", &n, &m, &k);
//     for (int i = 1, x, y, d, f; i <= K; i++)
//         scanf("%d%d%d%d", &x, &y, &d, &f),
//         q[i] = { x,y,d,f,true },
//         g[x][y].insert({ f,i });
//     int t;
//     scanf("%d", &t);
//     while (t--) {
//         //小葱行进
//         for (int i = 1;i <= k;i++) {
//             if (!q[i].alive) continue;
//             int x = q[i].x + dx[q[i].d], y = q[i].y + dy[q[i].d];
//             //小葱移动
//             if (x >= 1 && x <= n && y >= 1 && y <= m)
//                 g[q[i].x][q[i].y].erase({ q[i].f, i }),
//                 q[i].x = x,
//                 q[i].y = y,
//                 g[q[i].x][q[i].y].insert({ q[i].f, i });
//             else //调转方向
//                 q[i].d ^= 1;//最低位置按位异或
//         }
//         //小葱战斗
//         for (int i = 1;i <= n;i++)
//             for (int j = 1;j <= m;j++)
//                 //set自带排序，可自己重构结构体中的operator<,见上面结构体
//                 while (g[i][j].size() > 1) {
//                     pii p = *g[i][j].begin();
//                     g[i][j].erase(p);
//                     q[p.second].alive = false;
//                 }
//     }
//     for (int i = 1;i <= k;i++)
//         printf("%d %d\n", q[i].x, q[i].y);
// }

//9分 感觉没错，用例也能过，但是超过限制了
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     int N, M, K, t;
//     scanf("%d%d%d", &N, &M, &K);
//     int x[K], y[K], d[K], f[K];

//     for (int i = 0; i < K; i++) {
//         int r;
//         scanf("%d", &r);
//         x[i] = r;
//         scanf("%d", &r);
//         y[i] = r;
//         scanf("%d", &r);
//         d[i] = r;
//         scanf("%d", &r);
//         f[i] = r;
//     }
//     scanf("%d", &t);

//     //di 0123分别代表下上左右
//     //0 x--; 1 x++；2 y--; 3 y++
//     //N行~x,M列~y
//     int cnt[N + 1][M + 1];
//     for (int i = 0; i <= N; i++) {
//         for (int j = 0; j <= M; j++) {
//             cnt[i][j] = -1;
//         }
//     }

//     while (t) {
//         t--;
//         //改变位置和方向
//         for (int i = 0; i < K; i++) {
//             while (f[i] == 0) i++;//战斗力为0，代表枯萎，不再移动；

//             cnt[x[i]][y[i]] = -1;//重置原位置
//             switch (d[i]) {
//             case 0:
//                 x[i]--;
//                 if (x[i] <= 0) {//越界
//                     d[i] = 0;
//                     x[i]++;//回到原值
//                 }
//                 break;
//             case 1:
//                 x[i]++;
//                 if (x[i] > N) {//越界
//                     d[i] = 1;
//                     x[i]--;//回到原值
//                 }
//                 break;
//             case 2:
//                 y[i]--;
//                 if (y[i] <= 0) {//越界
//                     d[i] = 3;
//                     y[i]++;//回到原值
//                 }
//                 break;
//             case 3:
//                 y[i]++;
//                 if (y[i] > M) {//越界
//                     d[i] = 2;
//                     y[i]--;//回到原值
//                 }
//                 break;
//             default: break;
//             }
//         }

//         //所有人的一步走完后，再看是否有新的战斗
//         for (int i = 0; i < K; i++) {
//             while (f[i] == 0) i++;//战斗力为0，代表枯萎，不再移动；
//             if (cnt[x[i]][y[i]] == -1) {
//                 cnt[x[i]][y[i]] = i;
//             } else {//爆发战斗
//                 int j = cnt[x[i]][y[i]];
//                 if (f[i] > f[j]) {//新的胜利    
//                     f[j] = 0;
//                     cnt[x[i]][y[i]] = i;
//                 } else {//旧的胜利 
//                     f[i] = 0;
//                 }
//             }
//         }
//     }
//     //最后依次输出xi,yi
//     for (int i = 0; i < K; i++) {
//         printf("%d %d\n", x[i], y[i]);
//     }
//     return 0;
// }