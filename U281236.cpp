#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000 + 1;
int main() {
    int pos[maxN] = { 0 }, neg[maxN] = { 0 };
    int N;
    scanf("%d", &N);
    int num;
    while (N--) {
        scanf("%d", &num);
        if (num > 0) pos[num]++;
        else {
            num = -num;
            neg[num]++;
        }
    }
    int ret = 0;
    for (int i = 1; i < maxN; i++) {
        if (pos[i] && neg[i]) ret++;
    }
    printf("%d", ret);
    return 0;
}