// https://www.luogu.com.cn/problem/U281302

#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int cost[N];
int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int pre;string s;
        cin >> pre >> s;
        int t = s.size() + 1;//加上前面的"/"
        cost[i] = cost[pre] + t;
        sum += cost[i];
    }
    cout << sum << endl;
}