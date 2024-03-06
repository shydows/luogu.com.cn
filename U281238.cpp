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
        // ������ͷ������
        if (!valid)
            continue;
    // �����ո���ǲ���������
        else if (s[i] == ' ')
            ans[op][idx] = 0,//char��ֵΪ0���Ƕ��ˣ������ж�Ҳ��֪������û����
            vis2[op] = true, op = idx = 0;
    // �����������
        else if (op)
            ans[op][idx++] = s[i];
    // ����Ϸ���������ѡ��
    // islower(s[i + 1])�ж��Ƿ���Сд��ĸ
        else if (s[i] == '-' && islower(s[i + 1]) && s[i + 2] == ' ' && (op1[s[i + 1]] || op2[s[i + 1]])) {
            // ��������
            if (op1[s[i + 1]])
                vis1[s[i + 1]] = true;
            // ������
            else
                op = s[i + 1];
            // �����������
            i += 2;
        }
    // �Ƿ��ַ�
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
    // �ǵ��������з�
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        int idx = 0;
        for (char c; c = getchar(), c && c != '\n';)
            s[idx++] = c;
        // ��β������һ���ո񣬱��ں�������
        s[idx++] = ' ', s[idx] = 0;
        printf("Case %d:", i), process();
    }
}