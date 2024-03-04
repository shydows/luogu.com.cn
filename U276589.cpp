#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int cnt = 0;
    while (n--) {
        int num;
        scanf("%d", &num);
        if (abs(num) > k) cnt++;
    }
    printf("%d", cnt);
    return 0;
}