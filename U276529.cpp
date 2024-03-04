// https://www.luogu.com.cn/problem/U276529
#include <bits/stdc++.h>
using namespace std;
int main() {
    string n; int k;
    cin >> n >> k;// C++中不要用scanf读字符串&s,因为C++和C风格的字符串不一样
    //一定要的话可以用 char str[100]; scanf("%s", str);
    int num = 0, res = 0;// num记录前缀
    //将输入从字符串转化为数组
    vector<int> array;
    for (int i = 0; i < n.size(); i++) {
        array.push_back(n[i] - '0');
    }
    //从数位高位到低位遍历
    for (int i = 0; i < array.size(); i++) {
        int c = array[i];
        int cur = array.size() - 1 - i;//cur记录后面还有几位数
        if (c > k) {// 如果c大于k
            res += (num + 1) * pow(10, cur);
        } else if (c < k) {
            res += num * pow(10, cur);
        } else {// c==k
            res += stoi(n) % (int)pow(10, cur) + 1;//加上后缀,还有自己
            res += num * pow(10, cur);
        }
        num = num * 10 + c;
    }
    cout << res << endl;
    return 0;
}