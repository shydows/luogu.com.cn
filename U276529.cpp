// https://www.luogu.com.cn/problem/U276529
#include <bits/stdc++.h>
using namespace std;
int main() {
    string n; int k;
    cin >> n >> k;// C++�в�Ҫ��scanf���ַ���&s,��ΪC++��C�����ַ�����һ��
    //һ��Ҫ�Ļ������� char str[100]; scanf("%s", str);
    int num = 0, res = 0;// num��¼ǰ׺
    //��������ַ���ת��Ϊ����
    vector<int> array;
    for (int i = 0; i < n.size(); i++) {
        array.push_back(n[i] - '0');
    }
    //����λ��λ����λ����
    for (int i = 0; i < array.size(); i++) {
        int c = array[i];
        int cur = array.size() - 1 - i;//cur��¼���滹�м�λ��
        if (c > k) {// ���c����k
            res += (num + 1) * pow(10, cur);
        } else if (c < k) {
            res += num * pow(10, cur);
        } else {// c==k
            res += stoi(n) % (int)pow(10, cur) + 1;//���Ϻ�׺,�����Լ�
            res += num * pow(10, cur);
        }
        num = num * 10 + c;
    }
    cout << res << endl;
    return 0;
}