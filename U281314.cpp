// https://www.luogu.com.cn/problem/U281314
// �ı������ʷ�ʽ�����������ı�����Եúܴ�
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;    //n ��ʾ�����С; q ��ʾ��������
    scanf("%d", &n);
    int m[n][n];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            int t;
            scanf("%d", &t);
            m[i][j] = t;
        }
    }
    scanf("%d", &q);
    bool flag = false;      //�Ƿ�ת�ı�־
    int row = 0, col = 0;   //row:�ƶ����У�col:�ƶ�����
    while (q--) {
        int q1, q2;
        scanf("%d", &q1);
        if (q1 == 1) flag = !flag;
        else if (q1 == 2) {
            scanf("%d", &q2);
            flag ? col -= q2 : row -= q2;   //��˳���й�ϵ��flag���ܵ���
        } else {
            scanf("%d", &q2);
            flag ? row -= q2 : col -= q2;
        }
    }
    row = row % n + n;  //��-11��% 10 == (-1)
    col = col % n + n;  //��֤������[0��n)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //�ԣ�row,col��Ϊ��׼������ȥ����
            int ret = flag ? m[(row + j) % n][(col + i) % n] : m[(row + 1) % n][(col + j) % n];
            printf("%d ", ret);
        }
        printf("\n");
    }
    return 0;
}