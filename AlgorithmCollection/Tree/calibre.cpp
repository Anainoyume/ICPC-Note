#include <bits/stdc++.h>
using namespace std;

/*
    树的直径
 */

const int maxN = 1e4+5;

vector<int> edges[maxN];
int ans;
int dp[maxN];

void dfs(int cur, int parent) {
    for (auto&& it : edges[cur]) {
        if (it == parent) continue; //如果是下一个dfs是父节点，跳过
        dfs(it,cur);
        ans = max(ans,dp[cur]+dp[it]+1);    //不会重复选择父节点，因为已经跳过了
        dp[cur] = max(dp[cur],dp[it]+1);    //叶子节点长度为 0，直接跳过返回，正确
    }
}

int main()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    dfs(1,0);

    cout << ans << endl;

    system("pause");
    return 0;
}