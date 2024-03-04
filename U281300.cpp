#include <bits/stdc++.h>
using namespace std;
const int maxN = 2048 + 1;
int N[maxN] = { 0 };
int main() {
    int n;
    scanf("%d", &n);
    int num;
    while (n--) {
        scanf("%d", &num);
        N[num]++;
    }
    int ret = 0, max = 0;
    for (int i = 1; i <= maxN; i++) {
        if (N[i] >= max) {
            ret = i;
            max = N[i];
        }
    }
    printf("%d", ret);
    return 0;
}