//https://www.luogu.com.cn/problem/U276602
// 70分，会TLE
#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7, N = 1e5 + 5;
int main() {
    int n, m;
    long long ret = 0;
    cin >> n >> m;
    multiset<int> set;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        set.insert(num);
    }
    vector<int> Num;
    Num.push_back(0);
    for (int c : set) {
        Num.push_back(c);
    }
    for (int i = n; i > 1; i--) {
        if (Num[i] > m) continue;
        for (int j = 1; j < i;j++) {
            if (Num[i] + Num[j] > m) continue;
            ret++;
        }
    }
    ret %= M;
    cout << ret << endl;
}

//错误思路：构建一个数组，sum[i]表示数组中比i小的数字的个数和
//原因：空间会超：sum[maxM] = { 0 }, num[maxM] = { 0 };
// #include<bits/stdc++.h>
// using namespace std;
// const int maxM = 1e9, MOD = 1e9 + 7;
// int sum[maxM] = { 0 }, num[maxM] = { 0 };
// int main() {
//     int n, M, ret = 0;
//     scanf("%d%d", &n, &M);
//     while (n--) {
//         int i;
//         scanf("%d", &i);
//         num[i]++;
//     }
//     for (int i = 0; i < maxM; i++) {
//         sum[i] += num[i];
//     }
//     for (int i = 1;i * 2 < M;i++) {
//         int j = M - i;//j一定大于i
//         if (num[i]) { //确保i存在
//             ret += sum[j] - sum[i];
//             ret %= MOD;
//         }
//     }
//     printf("%intd", ret);
// }

// 归并排序
// #include <iostream>
// using namespace std;
// typedef long long ll;
// const int N = 1e5 + 5, mod = 1e9 + 7;
// int a[N], tmp[N];
// int n, m;
// ll ans;
// void merge_sort(int l, int r) {
//   if (l >= r)
//     return;
//   int mid = l + r >> 1;
//   merge_sort(l, mid), merge_sort(mid + 1, r);
//   // 计算符合要求的整数对
//   for (int i = mid, j = mid + 1; j <= r; j++) {
//     while (i >= l && a[i] + a[j] > m)
//       i--;
//     ans += i - l + 1;
//   }
//   // merge sort
//   int k = 0;
//   for (int i = l, j = mid + 1; i <= mid || j <= r;)
//     if (j > r || i <= mid && a[i] <= a[j])
//       tmp[k++] = a[i++];
//     else
//       tmp[k++] = a[j++];
//   for (int i = l, j = 0; i <= r; i++, j++)
//     a[i] = tmp[j];
// }
// int main() {
//   scanf("%d%d", &n, &m);
//   for (int i = 1; i <= n; i++)
//     scanf("%d", a + i);
//   merge_sort(1, n);
//   printf("%lld\n", ans % mod);
// }

// 离散化 + 树状数组
// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 1e5 + 5, mod = 1e9 + 7;
// int tr[N];
// void update(int x) {
//   while (x < N)
//     tr[x]++, x += x & -x;
// }
// int sum(int x) {
//   int res = 0;
//   while (x)
//     res += tr[x], x -= x & -x;
//   return res;
// }
// int a[N], b[N], tot;
// int find(int x) { return upper_bound(b + 1, b + tot, x) - b; }
// int n, m;
// int main() {
//   scanf("%d%d", &n, &m);
//   for (int i = 1; i <= n; i++)
//     scanf("%d", a + i), b[i] = a[i];
//   sort(b + 1, b + n + 1);
//   tot = unique(b + 1, b + n + 1) - b;
//   int ans = 0;
//   for (int i = 1; i <= n; update(find(a[i])), i++)
//     if (a[i] <= m)
//       ans = (ans + sum(find(m - a[i]))) % mod;
//   printf("%d\n", ans);
// }