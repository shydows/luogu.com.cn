//https://www.luogu.com.cn/problem/U276782
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL num(LL len, LL m) {//连续长度为len的全1段有多少个长度至少为m的全1段的数量
    if (len < m) return 0;
    LL i = len - m + 1;
    LL res = (1 + i) * i / 2;
    return res;
}
int main() {
    LL N, M, ret = 0;
    cin >> N >> M;
    string s;
    cin >> s;
    LL len = 0;
    for (auto c : s) {
        if (c == '1') {
            len++;
        } else {
            ret += num(len, M);
            len = 0;
        }
    }
    if (s[s.size() - 1] == '1') ret += num(len, M);
    cout << ret << endl;
    return 0;
}