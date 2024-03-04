// https://www.luogu.com.cn/problem/U276503

#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    int x;
    scanf("%d", &x);
    int add = 0;
    while (true) {
        if (isPrime(stoi(to_string(x) + to_string(++add)))) {
            printf("%s\n", (to_string(x) + to_string(add)).c_str());
            // ����Ҫ��.c_str()���������ת��
            // ��Ϊto_stringĬ����C++�����ַ�������printf��ҪC�����ַ���
            // cout << to_string(x) << to_string(add);
            break;
        }
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// bool isPrime(int x) {
//     if (x < 2) return false;
//     for (int i = 2; i * i <= x; i++) {
//         if (x % i == 0) return false;
//     }
//     return true;
// }
// int numLens(int x) {
//     //Ĭ�ϴ���Ķ�������
//     int cnt = 1;
//     while (x > 10) {
//         cnt++;
//         x /= 10;
//     }
//     return cnt;
// }
// int main() {
//     int NUM, add = 0;
//     scanf("%d", &NUM);
//     while (1) {
//         add++;
//         int cnt = numLens(add);//��һ��add�����ж���λ
//         int num = NUM * pow(10, cnt) + add;
//         if (isPrime(num)) {
//             printf("%d\n", num);
//             return 0;
//         }
//     }
// }