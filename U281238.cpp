#include <bits/stdc++.h>
using namespace std;
const int N = 26 + 1;
struct com {
    bool oc1;   //记录是否在第一行出现，初始化都是false
    bool oc2;   //记录是否在其他地方出现
    bool hs;    //记录是否含参
    string s;   //记录参数
}C[N];
void Print() {
    for (int i = 0; i < N; i++) {
        if (C[i].oc2) {
            C[i].oc2 = false;
            printf("-%c ", i + 'a');
            if (C[i].hs) printf("%s ", C[i].s);
        }
    }
    printf("\n");
}
int main() {
    int pre;
    string s1;
    cin >> s1;
    for (auto c : s1) {
        if (c == ':') {
            C[pre].hs = true;
        } else {
            pre = c - 'a';
            C[pre].oc1 = true;
        }
    }
    int N;
    scanf("%d", &N);
    string s, name;
    cin >> name;    //知晓name
    for (int i = 1; i <= N; i++) {
        s.clear();
        printf("Case %d: ", i);
        while (i > 1 && s != name) {
            cin >> s;   //洗掉后面无关的
        }
        pre = 26;    //确保C[pre].hs为false
        while (1) {
            cin >> s;
            if (s == name) {
                printf("\n");
                break;
            }
            if (s[0] == '-' && !C[pre].hs) {
                pre = s[1] - 'a';
                if (!C[pre].oc1) {
                    Print();
                    break;
                }
                if (!C[pre].hs) C[pre].oc2 = true;
            } else if (s[0] != '-' && C[pre].hs) {
                C[pre].s = s;
                C[pre].oc2 = true;
            } else {
                Print();
                break;
            }
        }
    }
}