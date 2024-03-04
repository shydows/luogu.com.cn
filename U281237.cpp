#include <bits/stdc++.h>
using namespace std;
const int maxN = 10 + 10;
struct window {
    int id, x1, y1, x2, y2;
}W[maxN];
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d%d", &W[i].x1, &W[i].y1, &W[i].x2, &W[i].y2);
        W[i].id = i + 1;
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        int top = N - 1;
        for (; top >= 0; top--) {
            if (W[top].x1 <= x && W[top].x2 >= x &&
                W[top].y1 <= y && W[top].y2 >= y) {
                W[N++] = W[top];
                printf("%d\n", W[top].id);
                break;
            }
        }
        if (top < 0) printf("IGNORED\n");
    }
}