//https://www.luogu.com.cn/problem/U412495
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int a[N];
vector<int> g[N];//�ڽӱ�ͼ
int A[N];//���ڵ㵽�õ�·���ϵ�����Ʒ������
bool st[N];//�ýڵ��Ƿ񱻷��ʹ�
set<int> zSet;
void dfs(int i) {
    st[i] = true;
    while (g[i].size()) {
        int j = g[i].back();
        g[i].pop_back();
        if (!st[j]) {
            int preSize = zSet.size();
            zSet.insert(a[j]);
            int change = zSet.size() - preSize;
            A[j] = change + A[i];
            dfs(j);
            if (change) {
                zSet.erase(a[j]);
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        // cin >> a[i];
    }
    //�Ӹ��ڵ㿪ʼ����
    A[n] = 1;
    st[n] = true;
    zSet.insert(a[n]);
    dfs(n);
    //���սڵ���˳�������������
    printf("%d", A[1]);
    for (int i = 2;i <= n;i++) {
        printf(" %d", A[i]);
    }
    printf("\n");
    return 0;
}