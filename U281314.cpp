// https://www.luogu.com.cn/problem/U281314
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int matrix[N][N];
int[][] fun1(int[][] matrix) {
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int s = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = s;
        }
    }
    return matrix;
}
int[][] fun2(int[][] matrix, int k) {

}
int[][] fun3(int[][] matrix, int k) {

}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= n; j++) {
            int t;
            scanf("%d", &t);
            matrix[i][j] = t;
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int q1;
        scanf("%d", &q1);
        if (q1 == 1) matrix = fun1(matrix);
    }


    return 0;
}