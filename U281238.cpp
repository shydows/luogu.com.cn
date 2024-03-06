//https://www.luogu.com.cn/problem/U281238
#include <iostream>
#include <string.h>
using namespace std;
const int N = 'z' + 1, M = 260;

char s[M], ans[N][M];
bool op1[N], op2[N], vis1[N], vis2[N];
void process() {
    memset(ans, 0, sizeof ans), memset(vis1, 0, sizeof vis1), memset(vis2, 0, sizeof vis2);
    for (int i = 0, op = 0, idx = 0, valid = false; s[i]; valid = valid || s[i] == ' ', i++)
        // 跳过开头的命令
        if (!valid)
            continue;
    // 遇到空格必是参数读完了
        else if (s[i] == ' ')
            ans[op][idx] = 0,//char赋值为0就是断了，后面判断也就知道后面没有了
            vis2[op] = true, op = idx = 0;
    // 读入参数过程
        else if (op)
            ans[op][idx++] = s[i];
    // 读入合法的命令行选项
    // islower(s[i + 1])判断是否是小写字母
        else if (s[i] == '-' && islower(s[i + 1]) && s[i + 2] == ' ' && (op1[s[i + 1]] || op2[s[i + 1]])) {
            // 不带参数
            if (op1[s[i + 1]])
                vis1[s[i + 1]] = true;
            // 带参数
            else
                op = s[i + 1];
            // 跳过这个参数
            i += 2;
        }
    // 非法字符
        else
            break;

    for (char c = 'a'; c <= 'z'; c++)
        if (vis1[c])
            printf(" -%c", c);
        else if (vis2[c])
            printf(" -%c %s", c, ans[c]);
    printf("\n");
}

int main() {
    scanf("%s", s);
    for (int i = 0; s[i]; i++)
        if (s[i + 1] == ':')
            op2[s[i++]] = true;
        else
            op1[s[i]] = true;

    int n;
    // 记得跳过换行符
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        int idx = 0;
        for (char c; c = getchar(), c && c != '\n';)
            s[idx++] = c;
        // 结尾处插入一个空格，便于后续处理
        s[idx++] = ' ', s[idx] = 0;
        printf("Case %d:", i), process();
    }
}