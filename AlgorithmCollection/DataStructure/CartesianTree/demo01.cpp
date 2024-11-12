#include <bits/stdc++.h>
using namespace std;

/* 
    �ѿ�����
    ����: O(n)
 */

int main() {
    int n{};
    cin >> n;

    vector<int> w(n+1,0), ls(n+1,0), rs(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    // ����ջ�� �ѿ�����
    vector<int> stk(n+1,0);
    int top{};
    for (int i = 1; i <= n; ++i) {
        // С����, �����õ���ջά��һ����Сֵ
        int k = top;                                // top ��ʾ����ǰ��ջ����k ��ʾ��ǰջ��
        while (k > 0 && w[stk[k]] > w[i]) k -= 1;   // ά�������ϵĽڵ�
        if (k) rs[stk[k]] = i;                      // ջ��Ԫ�ص��Ҷ��� <- ��ǰԪ��
        if (k < top) ls[i] = stk[k + 1];            // ��ǰԪ�ص������ <- ��һ����������Ԫ��
        stk[++k] = i;                               // ��ǰԪ����ջ
        top = k;
    }

    // ���ڵ�Ϊ stk[1]
    int root = stk[1];
}