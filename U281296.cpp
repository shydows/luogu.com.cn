// https://www.luogu.com.cn/problem/U281296
// 五子棋
#include <iostream>
using namespace std;

int g[20][20];
bool judge(int x, int y, int dx, int dy) {
    int cnts = 1;
    for (int xx = x - dx, yy = y - dy; g[xx][yy] == g[x][y];
        xx -= dx, yy -= dy)
        cnts++;
    for (int xx = x + dx, yy = y + dy; g[xx][yy] == g[x][y];
        xx += dx, yy += dy)
        cnts++;
    return cnts >= 5;
}

int n, winner, ans;
int main() {
    scanf("%d", &n);
    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d%d", &x, &y);
        int op = i & 1 ? 1 : 2;
        if (!winner) {
            g[x][y] = op;
            // 分别判断两个斜方向、竖直方向、水平方向有无五个连子
            if (judge(x, y, 1, 1) || judge(x, y, 1, 0) || judge(x, y, 1, -1) ||
                judge(x, y, 0, 1))
                winner = op, ans = i;
        }
    }
    if (winner == 0)
        printf("Tie");
    else if (winner == 1)
        printf("A %d", ans);
    else
        printf("B %d", ans);
}