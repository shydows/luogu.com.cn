// https://www.luogu.com.cn/problem/U276863
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<string> s;
    string t;
    for (int i = 0; i < n; i++) {// 注意不能cin>>s[i]，vector访问不能像数组那样
        cin >> t;
        s.push_back(t);
    }
    while (m--) {
        int NUM[10] = { 0 };
        for (int i = 0; i < n; i++) {
            int t = s[i][m] - '0';
            NUM[t]++;
        }
        int max = 0, max_num = 0;
        for (int i = 0; i < 10; i++) {
            if (NUM[i] > max) {
                max = NUM[i];
                max_num = i;
            }
        }
        printf("%d\n", max_num);
    }
    return 0;
}