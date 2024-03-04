#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 1;
int main() {
    int Num[N] = { 0 };
    int n;
    scanf("%d", &n);
    while (n--) {
        int num;
        scanf("%d", &num);
        Num[num]++;
    }
    for (int i = 0; i <= N; i++) {
        if (Num[i] == 0) {
            printf("%d", i);
            return 0;
        }
    }
}