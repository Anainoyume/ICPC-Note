/* 
    回文自动机 (回文树)
*/
#include <bits/stdc++.h>
using namespace std;

// 空间复杂度 O(N), N 为字符串长度
const int N = 5e5+5;

// 一个回文的数量，就是fail树上以该节点结尾的深度
// 注意是在 "Fail树" 上的深度
struct Node {
    int len, fail, deep, next[26];
} node[N];

// 输入的字符串
string s;
int tot = 1;

// u - 状态, i - 下标
int getFail(int u, int i) {
    while (i - node[u].len - 1 <= 0 || s[i-node[u].len-1] != s[i])
        u = node[u].fail;
    return u;
}

// s 不需要人为处理添加展位首字母, 已经在函数内部处理
void eertree() {
    int n = s.size();
    s = '#' + s; // 对齐下标

    node[0].fail = node[1].fail = 1;
    node[1].len = -1;

    for (int i = 1, now = 0; i <= n; ++i) {
        int pos = getFail(now, i), c = s[i] - 'a';

        if (!node[pos].next[c]) {
            node[++tot].fail = node[getFail(node[pos].fail,i)].next[c];
            node[pos].next[c] = tot;
            node[tot].len = node[pos].len + 2;
            node[tot].deep = node[node[tot].fail].deep + 1;
        }
        now = node[pos].next[c];

        // cout << node[now].deep << " ";
    
    }
} 

signed main()
{
    cin >> s;
    eertree();
    cout << endl;

    system("pause");
    return 0;
}