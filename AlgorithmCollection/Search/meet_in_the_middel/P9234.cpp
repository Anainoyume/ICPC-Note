#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios::sync_with_stdio(false), cout.tie(0), cin.tie(0)

const int maxN = 35;
int n;
double m;
int ans = INT_MAX;
double arr[maxN];
unordered_map<int,int> vis;

void dfs(int cur, int cnt, int len) {
    if (cnt > ans || len > m) return;

    if (len == m) {
        ans = min(ans,cnt);
    }

    if (cur == n/2) {
        if (vis.count(len)) {
            vis[len] = min(vis[len],cnt);
        }
        else {
            vis[len] = cnt;
        }

        return;
    }

    //不切，选或者不选
    dfs(cur+1,cnt,len+arr[cur+1]*2);
    dfs(cur+1,cnt,len);

    //切了就一定要选，不然没有意义
    dfs(cur+1,cnt+1,len+arr[cur+1]);
}

void dfs2(int cur, int cnt, int len) {
    if (cnt > ans || len > m) return;

    if (len == m) {
        ans = min(ans,cnt);
    }

    if (cur == n) {
        if (vis.count(m-len) && len <= m) {
            ans = min(ans,cnt+vis[m-len]);
        }
        return;
    }

    //不切，选或者不选
    dfs2(cur+1,cnt,len+arr[cur+1]*2);
    dfs2(cur+1,cnt,len);

    //切了就一定要选，不然没有意义
    dfs2(cur+1,cnt+1,len+arr[cur+1]);
}

signed main()
{
    IOS;
    cin >> n >> m;
    m *= 2;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    sort(arr+1,arr+1+n);

    dfs(0,0,0);
    dfs2(n/2,0,0);

    cout << (ans == INT_MAX ? -1 : ans) << endl;

    system("pause");
    return 0;
}