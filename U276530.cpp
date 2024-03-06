// https://www.luogu.com.cn/problem/U276530

//90�֣���֪����������
#include <bits/stdc++.h>
using namespace std;
vector<int> HNC, HNR;
const int MAX = 1002;
//num ����flag ����ĵط���row ÿ���вhrow �Ƿ������в�
int num[MAX][MAX], flag[MAX][MAX], row[MAX], col[MAX], hrow[MAX], hcol[MAX];
//��ȫ��i��
void bur(int i, int row, int m) {
    int j = 1;
    while (!num[i][j]) j++;
    int j1 = j;//��С�ı���
    while (j1-- > 1) {
        if (num[i][j1]) continue;
        num[i][j1] = num[i][j1 + 1] - row;
        flag[i][j1] = num[i][j1];
    }
    int j2 = j;//���ı���
    while (j2++ < m) {
        if (num[i][j2]) continue;
        num[i][j2] = num[i][j2 - 1] + row;
        flag[i][j2] = num[i][j2];
    }
}
//��ȫ��j��
void buc(int j, int col, int n) {
    int i = 1;
    while (!num[i][j]) i++;
    int i1 = i - 1;//��С�ı���
    while (i1 >= 1) {
        if (num[i1][j]) {
            i1--; continue;
        }
        num[i1][j] = num[i1 + 1][j] - col;
        flag[i1][j] = num[i1][j];
        i1--;
    }
    int i2 = i + 1;//���ı���
    while (i2 <= n) {
        if (num[i2][j]) {
            i2++; continue;
        }
        num[i2][j] = num[i2 - 1][j] + col;
        flag[i2][j] = num[i2][j];
        i2++;
    }
}
//�����еȲ�
void cr(int m, int n, int* row) {
    for (int i = 1; i <= n; i++) {
        if (hrow[i]) continue;
        int j = 1, a, b, A = 0, B = 0;
        while (j <= m && !num[i][j]) j++;
        if (j <= m) {
            a = num[i][j];
            A = j;
            j++;
        }
        while (j <= m && !num[i][j]) j++;
        if (j <= m) {
            b = num[i][j];
            B = j;
        }
        if (A && B) {
            row[i] = (b - a) / (B - A);
            hrow[i] = 1;
            HNR.push_back(i);//��������µ��еȲ�
        }

    }
}
//�����еȲ�
void cc(int m, int n, int* col) {
    for (int j = 1; j <= m; j++) {
        if (hcol[j]) continue;
        int i = 1, a, b, A = 0, B = 0;
        while (i <= n && !num[i][j]) i++;
        if (i <= n) {
            a = num[i][j];
            A = i;
            i++;
        }
        while (i <= m && !num[i][j]) i++;
        if (i <= m) {
            b = num[i][j];
            B = i;
        }
        if (A && B) {
            col[j] = (b - a) / (B - A);
            hcol[j] = 1;
            HNC.push_back(j);//��������µ��еȲ�
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    memset(flag, 0, sizeof flag);
    memset(hrow, 0, sizeof hrow);
    memset(hcol, 0, sizeof hcol);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> num[i][j];
        }
    }
    cr(m, n, row);
    cc(m, n, col);
    while (!HNR.empty() || !HNC.empty()) {
        while (!HNR.empty()) {
            int i = HNR.back();
            HNR.pop_back();
            bur(i, row[i], m);
        }
        while (!HNC.empty()) {
            int j = HNC.back();
            HNC.pop_back();
            buc(j, col[j], n);
        }
        cr(m, n, row);
        cc(m, n, col);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (flag[i][j] <= 0) continue;
            cout << i << " " << j << " " << flag[i][j] << endl;
        }
    }
}
// #include <iostream>
// using namespace std;
// const int N = 1005;

// // g Ϊ����ľ���ans Ϊ�ָ���ľ���
// int g[N][N], ans[N][N];
// // row��col �ֱ��¼ÿ��/���ж��ٸ��� 0 Ԫ��
// int row[N], col[N];
// int n, m;

// // �ָ����������ɹ��ָ���Ԫ�أ����� true�����򷵻� false
// bool fix() {
//     bool tag = false;
//     // ����ÿһ��
//     for (int i = 1; i <= n; i++)
//         // ������еķ� 0 Ԫ�ظ������� 2��˵�����п��������ػָ�
//         if (row[i] >= 2) {
//             int a = 0, b = 0;
//             // ����ÿһ�У��ҵ���һ�е�ǰ������ 0 Ԫ��
//             for (int j = 1; j <= m && !(a && b); j++)
//                 if (ans[i][j])
//                     if (!a)
//                         a = j;
//                     else
//                         b = j;
//             // ������еĹ���
//             int diff = (ans[i][b] - ans[i][a]) / (b - a);
//             ans[i][0] = ans[i][a] - diff * a;
//             for (int j = 1; j <= m; j++)
//                 if (!ans[i][j])
//                     // �ǵø��¶�Ӧ�е����
//                     col[j]++, ans[i][j] = ans[i][j - 1] + diff;
//             // �ָ���֮�󣬽������� 0�������ظ�����
//             row[i] = 0, tag = true;
//         }
//     // ����ÿһ�У�������ͬ��
//     for (int j = 1; j <= m; j++)
//         if (col[j] >= 2) {
//             int a = 0, b = 0;
//             for (int i = 1; i <= n && !(a && b); i++)
//                 if (ans[i][j])
//                     if (!a)
//                         a = i;
//                     else
//                         b = i;
//             int diff = (ans[b][j] - ans[a][j]) / (b - a);
//             ans[0][j] = ans[a][j] - diff * a;
//             for (int i = 1; i <= n; i++)
//                 if (!ans[i][j])
//                     row[i]++, ans[i][j] = ans[i - 1][j] + diff;
//             col[j] = 0, tag = true;
//         }
//     return tag;
// }

// int main() {
//     scanf("%d%d", &n, &m);
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             scanf("%d", &g[i][j]),
//             ans[i][j] = g[i][j],
//             row[i] += g[i][j] > 0,
//             col[j] += g[i][j] > 0;
//     // ÿ�λָ���֮�󣬿����»ָ�����ֵ���԰����ָ�������Ϣ
//     // ֱ���ָ������������˳�ѭ��
//     while (fix())
//         ;
//     // ���
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             if (ans[i][j] ^ g[i][j])
//                 printf("%d %d %d\n", i, j, ans[i][j]);
// }