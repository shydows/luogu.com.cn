#include<bits/stdc++.h>
using namespace std;

const int N = 17;
const int dx[] = { 1,0,1,1 }, dy[] = { 0,1,1,-1 };
int G[N][N];//棋盘，初始化为-1，1表示黑棋A，0表示白起B

bool isIn(int x, int y) {
    return(x >= 1 && x <= 15 && y >= 1 && y <= 15);
}

bool add(int x1, int y1, int i) {
    G[x1][y1] = i % 2;
    int flag = G[x1][y1];
    for (int i = 0;i < 4;i++) {
        int cnt = 1;
        int x2 = x1 + dx[i], y2 = y1 + dy[i];
        while (isIn(x2, y2) && (G[x2][y2] == flag) && cnt < 5) {
            cnt++; x2 += dx[i]; y2 += dy[i];
        }
        //千万别忘了两个方向
        x2 = x1 - dx[i], y2 = y1 - dy[i];
        while (isIn(x2, y2) && (G[x2][y2] == flag) && cnt < 5) {
            cnt++; x2 -= dx[i]; y2 -= dy[i];
        }
        if (cnt == 5) return true;
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);

    memset(G, -1, sizeof G);

    for (int i = 1;i <= n;i++) {
        int x1, y1;
        scanf("%d%d", &x1, &y1);
        if (add(x1, y1, i)) {
            if (i % 2) {
                printf("A %d\n", i);return 0;
            } else {
                printf("B %d\n", i);return 0;
            }
        }
    }
    printf("Tie\n");
    return 0;
}
