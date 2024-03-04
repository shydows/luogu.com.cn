//https://www.luogu.com.cn/problem/U276838

//����3��100
//1��2��û������˳��λ����3�ǻ��ڶ���
//Ҫ�ҵ���С���ǰ��ȫ��false������ȫ��true

#include <bits/stdc++.h>
using namespace std;
const int maxH = 1e5, maxN = 1e5;
int h[maxN + 1];    //˳���¼���
int cnt[maxH + 1];  //cnt[i]��¼���Ϊi������
bool isE(int r, int k, int m) {  //r:���Ҳ�
    memset(cnt, 0, sizeof(cnt));    //ˢ��cnt���� 
    for (int i = 1; i <= r; i++)    //������¼��
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
    if (!isE(n, k, m)) {   //����ȫ�����궼���У�ֱ��impossible
        printf("impossible\n");
        return 0;
    }
    int L = m, R = n, mid, ret;//���ַ�����С��
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

//����2��91

// #include <bits/stdc++.h>
// using namespace std;
// const int maxH = 1e5;
// int H[maxH + 1] = { 0 };//H[i]��¼������iΪ�����ߵľ���k���ڵ�������
// bool cht(int H[], int h, int k, int m) {//����h�����Ƿ��ܳ���
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

//����1��98

// #include <bits/stdc++.h>
// using namespace std;
// const int maxH = 1e5;
// int H[maxH + 1] = { 0 };
// bool cht(int H[], int begin, int end, int k, int m) {//����Ƿ�������赸��
//     int cnt = 0;
//     for (int i = 0; begin + i <= end; i++) {
//         if (i <= k) {//������Ҫ��ȥǰ���
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
//     int begin = 1e5; int end = 1;//�����һ�μ���Ƿ��������
//     for (int i = 1; i <= m; i++) {//��¼��ǰm���˵������Ϣ
//         scanf("%d", &h);
//         H[h]++;
//         if (h > end) end = h;
//         if (h < begin) begin = h;
//     }
//     int cnt = m;//��¼�����ڼ�������
//     while (!cht(H, begin, end, k, m) && cnt < n) {//�������һ�û���꣬��������һ����
//         cnt++;
//         scanf("%d", &h);
//         H[h]++;
//         begin = (h - k) >= 1 ? (h - k) : 1;
//         end = (h + k) <= maxH ? (h + k) : maxH;
//     }
//     if (cht(H, begin, end, k, m)) printf("%d", cnt);
//     else printf("impossible\n");//����ʧ��
//     return 0;
// }