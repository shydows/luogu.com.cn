//https://www.luogu.com.cn/problem/U276838

//方法3，100
//1，2都没有脱离顺序定位，而3是基于二分
//要找的最小点的前边全是false，后面全是true

#include <bits/stdc++.h>
using namespace std;
const int maxH = 1e5, maxN = 1e5;
int h[maxN + 1];    //顺序记录身高
int cnt[maxH + 1];  //cnt[i]记录身高为i的人数
bool isE(int r, int k, int m) {  //r:最右侧
    memset(cnt, 0, sizeof(cnt));    //刷新cnt数组 
    for (int i = 1; i <= r; i++)    //再重新录入
        cnt[h[i]]++;
    int num = 0;
    for (int i = 1; i <= maxH; i++) {
        if (i <= k + 1) num += cnt[i];
        else num += cnt[i] - cnt[i - k - 1];
        if (num >= m) return true;
    }
    return false;
}
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", h + i);
    }
    if (!isE(n, k, m)) {   //特判全部看完都不行，直接impossible
        printf("impossible\n");
        return 0;
    }
    int L = m, R = n, mid, ret;//二分法找最小点
    while (L <= R) {
        mid = (L + R) >> 1;
        if (isE(mid, k, m)) {
            ret = mid;
            R = mid - 1;
        } else L = mid + 1;
    }
    printf("%d\n", ret);
    return 0;
}

//方法2，91

// #include <bits/stdc++.h>
// using namespace std;
// const int maxH = 1e5;
// int H[maxH + 1] = { 0 };//H[i]记录所有以i为最低身高的距离k以内的人数和
// bool cht(int H[], int h, int k, int m) {//插入h后检查是否能成团
//   for (int i = 0; i <= k; i++) {
//     if (h - i > 0) {
//       H[h - i]++;
//       if (H[h - i] >= m) return true;
//     }
//   }
//   return false;
// }
// int main() {
//   int n, m, k, h;
//   scanf("%d%d%d", &n, &m, &k);
//   for (int i = 1; i <= n; i++) {
//     scanf("%d", &h);
//     if (cht(H, h, k, m)) {
//       printf("%d", i);
//       return 0;
//     }
//   }
//   printf("impossible\n");
//   return 0;
// }

//方法1，98

// #include <bits/stdc++.h>
// using namespace std;
// const int maxH = 1e5;
// int H[maxH + 1] = { 0 };
// bool cht(int H[], int begin, int end, int k, int m) {//检查是否能组成舞蹈团
//     int cnt = 0;
//     for (int i = 0; begin + i <= end; i++) {
//         if (i <= k) {//还不需要减去前面的
//             cnt += H[begin + i];
//         } else {
//             cnt = cnt + H[begin + i] - H[begin + i - k - 1];
//         }
//         if (cnt >= m) return true;
//     }
//     return false;
// }
// int main() {
//     int n, m, k, h;
//     scanf("%d%d%d", &n, &m, &k);
//     int begin = 1e5; int end = 1;//方便第一次检测是否满足成团
//     for (int i = 1; i <= m; i++) {//先录入前m个人的身高信息
//         scanf("%d", &h);
//         H[h]++;
//         if (h > end) end = h;
//         if (h < begin) begin = h;
//     }
//     int cnt = m;//记录看到第几个人了
//     while (!cht(H, begin, end, k, m) && cnt < n) {//不成团且还没看完，继续看下一个人
//         cnt++;
//         scanf("%d", &h);
//         H[h]++;
//         begin = (h - k) >= 1 ? (h - k) : 1;
//         end = (h + k) <= maxH ? (h + k) : maxH;
//     }
//     if (cht(H, begin, end, k, m)) printf("%d", cnt);
//     else printf("impossible\n");//查找失败
//     return 0;
// }