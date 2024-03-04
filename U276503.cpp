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
            // 必须要有.c_str()这个函数的转换
            // 因为to_string默认是C++风格的字符串，但printf需要C风格的字符串
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
//     //默认传入的都是正数
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
//         int cnt = numLens(add);//算一下add部分有多少位
//         int num = NUM * pow(10, cnt) + add;
//         if (isPrime(num)) {
//             printf("%d\n", num);
//             return 0;
//         }
//     }
// }