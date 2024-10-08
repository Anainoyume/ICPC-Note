/* 
    �����Զ��� (������)
*/
#include <bits/stdc++.h>
using namespace std;

// �ռ临�Ӷ� O(N), N Ϊ�ַ�������
const int N = 5e5+5;

// һ�����ĵ�����������fail�����Ըýڵ��β�����
// ע������ "Fail��" �ϵ����
struct Node {
    int len, fail, deep, next[26];
} node[N];

// ������ַ���
string s;
int tot = 1;

// u - ״̬, i - �±�
int getFail(int u, int i) {
    while (i - node[u].len - 1 <= 0 || s[i-node[u].len-1] != s[i])
        u = node[u].fail;
    return u;
}

// s ����Ҫ��Ϊ�������չλ����ĸ, �Ѿ��ں����ڲ�����
void eertree() {
    int n = s.size();
    s = '#' + s; // �����±�

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