//https://www.luogu.com.cn/problem/U276860
//���� 
// ��ν�ı�׼�𰸣�����ֱ�ӿ���
// #include <iostream>
// #include <set>
// using namespace std;
// typedef pair<int, int> pii;
// const int N = 105, K = 1005;
// const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
// //С��
// struct Node {
//     int x, y, d, f;
//     bool alive;
//     // bool operator<(Node other) {
//     //     return value < other.value;
//     // }
// }q[K];
// //����
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
//         //С���н�
//         for (int i = 1;i <= k;i++) {
//             if (!q[i].alive) continue;
//             int x = q[i].x + dx[q[i].d], y = q[i].y + dy[q[i].d];
//             //С���ƶ�
//             if (x >= 1 && x <= n && y >= 1 && y <= m)
//                 g[q[i].x][q[i].y].erase({ q[i].f, i }),
//                 q[i].x = x,
//                 q[i].y = y,
//                 g[q[i].x][q[i].y].insert({ q[i].f, i });
//             else //��ת����
//                 q[i].d ^= 1;//���λ�ð�λ���
//         }
//         //С��ս��
//         for (int i = 1;i <= n;i++)
//             for (int j = 1;j <= m;j++)
//                 //set�Դ����򣬿��Լ��ع��ṹ���е�operator<,������ṹ��
//                 while (g[i][j].size() > 1) {
//                     pii p = *g[i][j].begin();
//                     g[i][j].erase(p);
//                     q[p.second].alive = false;
//                 }
//     }
//     for (int i = 1;i <= k;i++)
//         printf("%d %d\n", q[i].x, q[i].y);
// }

//9�� �о�û������Ҳ�ܹ������ǳ���������
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

//     //di 0123�ֱ������������
//     //0 x--; 1 x++��2 y--; 3 y++
//     //N��~x,M��~y
//     int cnt[N + 1][M + 1];
//     for (int i = 0; i <= N; i++) {
//         for (int j = 0; j <= M; j++) {
//             cnt[i][j] = -1;
//         }
//     }

//     while (t) {
//         t--;
//         //�ı�λ�úͷ���
//         for (int i = 0; i < K; i++) {
//             while (f[i] == 0) i++;//ս����Ϊ0�������ή�������ƶ���

//             cnt[x[i]][y[i]] = -1;//����ԭλ��
//             switch (d[i]) {
//             case 0:
//                 x[i]--;
//                 if (x[i] <= 0) {//Խ��
//                     d[i] = 0;
//                     x[i]++;//�ص�ԭֵ
//                 }
//                 break;
//             case 1:
//                 x[i]++;
//                 if (x[i] > N) {//Խ��
//                     d[i] = 1;
//                     x[i]--;//�ص�ԭֵ
//                 }
//                 break;
//             case 2:
//                 y[i]--;
//                 if (y[i] <= 0) {//Խ��
//                     d[i] = 3;
//                     y[i]++;//�ص�ԭֵ
//                 }
//                 break;
//             case 3:
//                 y[i]++;
//                 if (y[i] > M) {//Խ��
//                     d[i] = 2;
//                     y[i]--;//�ص�ԭֵ
//                 }
//                 break;
//             default: break;
//             }
//         }

//         //�����˵�һ��������ٿ��Ƿ����µ�ս��
//         for (int i = 0; i < K; i++) {
//             while (f[i] == 0) i++;//ս����Ϊ0�������ή�������ƶ���
//             if (cnt[x[i]][y[i]] == -1) {
//                 cnt[x[i]][y[i]] = i;
//             } else {//����ս��
//                 int j = cnt[x[i]][y[i]];
//                 if (f[i] > f[j]) {//�µ�ʤ��    
//                     f[j] = 0;
//                     cnt[x[i]][y[i]] = i;
//                 } else {//�ɵ�ʤ�� 
//                     f[i] = 0;
//                 }
//             }
//         }
//     }
//     //����������xi,yi
//     for (int i = 0; i < K; i++) {
//         printf("%d %d\n", x[i], y[i]);
//     }
//     return 0;
// }