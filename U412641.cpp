// https://www.luogu.com.cn/problem/U412641
#include<bits/stdc++.h>
using namespace std;

int rd() {
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = 0;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return f ? k : -k;
}
void wr(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar((x % 10) ^ '0');
}

const int N = 514114;
const int left_tail = N - 2, right_tail = N - 1;
// list size, mission number, size limit
int pre[N], nxt[N], val[N], sz, no, limit;
// <-importance, number>
set<pair<int, int>> s;

void init(int lim) {
    nxt[left_tail] = right_tail, pre[right_tail] = left_tail, limit = lim;
}

// insert at pos's right, assume mission doesn't exist
// mission number = num (1\le num \le n), importance = a (1\le a \le n)
void insert(int pos, int num, int a) {
    val[num] = a, pre[num] = pos, nxt[num] = nxt[pos];
    pre[nxt[pos]] = num, nxt[pos] = num;
    s.insert(make_pair(-a, num)), ++sz;
}

// remove mission by num, assume mission exists.
void remove(int num) {
    pre[nxt[num]] = pre[num], nxt[pre[num]] = nxt[num];
    s.erase(s.find(make_pair(-val[num], num)));
    pre[num] = nxt[num] = val[num] = 0, --sz;
}

// operation 1 : insert at back
void op_1(int a) {
    ++no; // new number whether success or not.
    if (sz == limit)
        return (void)puts("ERR");
    insert(pre[right_tail], no, a);
    wr(no), putchar('\n'); // insert success, print number.
}

// operation 2 : insert at x's left
void op_2(int a, int x) {
    ++no;
    if (sz == limit || !val[x])
        return (void)puts("ERR");
    insert(pre[x], no, a);
    wr(no), putchar('\n');
}

// operation 3 : pop left
void op_3() {
    if (!sz)
        return (void)puts("ERR");
    wr(nxt[left_tail]), putchar('\n');
    remove(nxt[left_tail]);
}

// operation 4 : pop biggest importance
void op_4() {
    if (!sz)
        return (void)puts("ERR");
    wr(s.begin()->second), putchar('\n');
    remove(s.begin()->second);
}

void print_list() {
    int cnt = 0;
    for (int i = nxt[left_tail]; i ^ right_tail; i = nxt[i])
        wr(i), putchar(' '), wr(val[i]), putchar('\n'), ++cnt;
    putchar('\n');
    assert(!(cnt ^ sz));
}

int main() {
    int n = rd(), m = rd();
    int op = 0, a = 0, x = 0;
    init(m);
    while (n--) {
        op = rd();
        switch (op) {
        case 1:
            a = rd(), op_1(a);
            break;
        case 2:
            a = rd(), x = rd(), op_2(a, x);
            break;
        case 3:
            op_3();
            break;
        case 4:
            op_4();
            break;
        default:
            break;
        }
    }
}