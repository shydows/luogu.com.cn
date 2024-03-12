//https://www.luogu.com.cn/problem/U412490
//N[i]��ʾ����Ϊi������һλ��β�ĺϷ���ϸ���
//N[i]=(N[i-1]+N[i-2])*2;
//ans[i]=N[i]+N[i-1];
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAX = 1e6 + 1, M = 1e16, Mod = 1e10;
LL N[MAX], ans[MAX];

int main() {
    N[0] = 0;
    N[1] = 3;
    ans[0] = 0;
    ans[1] = 3;
    for (LL i = 2; i <= 36; i++) {
        N[i] = (N[i - 1] + N[i - 2]) << 1;
        ans[i] = N[i] + N[i - 1];
    }
    for (LL i = 2; i <= 36; i++) {
        N[i] = ((((N[i - 1] % Mod) + (N[i - 2] % Mod)) % Mod) * 2) % Mod;
    }
    for (LL i = 37; i <= MAX; i++) {
        N[i] = ((((N[i - 1] % Mod) + (N[i - 2] % Mod)) % Mod) * 2) % Mod;
        ans[i] = (N[i] + N[i - 1]) % Mod;
    }
    int T;
    cin >> T;
    int s;
    while (cin >> s) {
        if (s > 36) {
            cout << "......";
            //ans[s]���ܲ���ʮλ��Ҫ��0
            LL i = ans[s];
            if (i == 0) cout << "000000000";
            else {
                while (i < 1e9) {
                    cout << "0";
                    i *= 10;
                }
            }
        }
        cout << ans[s] << endl;
    }
    return 0;
}