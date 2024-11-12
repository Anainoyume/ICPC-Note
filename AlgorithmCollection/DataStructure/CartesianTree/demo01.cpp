#include <bits/stdc++.h>
using namespace std;

/* 
    笛卡尔树
    建树: O(n)
 */

int main() {
    int n{};
    cin >> n;

    vector<int> w(n+1,0), ls(n+1,0), rs(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    // 单调栈建 笛卡尔树
    vector<int> stk(n+1,0);
    int top{};
    for (int i = 1; i <= n; ++i) {
        // 小根堆, 我们用单调栈维护一个最小值
        int k = top;                                // top 表示操作前的栈顶，k 表示当前栈顶
        while (k > 0 && w[stk[k]] > w[i]) k -= 1;   // 维护右链上的节点
        if (k) rs[stk[k]] = i;                      // 栈顶元素的右儿子 <- 当前元素
        if (k < top) ls[i] = stk[k + 1];            // 当前元素的左儿子 <- 上一个被弹出的元素
        stk[++k] = i;                               // 当前元素入栈
        top = k;
    }

    // 根节点为 stk[1]
    int root = stk[1];
}