#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
#define endl '\n'
#define double long double

const int md = 1e9+7;
const int maxN = 1e5+5;

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

void solve() {
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n-1; i++)
    {
        int from, to;
        cin >> from >> to;
        edges[from+1].push_back(to+1);
        edges[to+1].push_back(from+1);
    }
    dfs(1,0);
    int uni = (n-1)/p;
    int res = (n-1)%p;

    if (ans == n-1) {
        cout << p << endl;
    }
    else {
        cout << ans*uni+res << endl;
    }
    
}

signed main()
{
    //IOS;
    int t{1};
    //cin >> t;
    while (t--) {
        solve();
    }
    
    system("pause");
    return 0;
}
