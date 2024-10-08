#include <bits/stdc++.h>
using namespace std;

const int maxN = 25;
int n;
int cnt[maxN];
int graph[maxN][maxN];
int last[maxN];
int last_ans[maxN];
bool vis[maxN];

int ans, k;

void dfs(int cur, int sum) {
    for (int i = 1; i <= n; i++)
    {
        if (graph[cur][i] == 1 && (!vis[i])) {
            last[i] = cur;
            vis[cur] = true;
            dfs(i,sum+cnt[i]);
            vis[cur] = false;
        }
    }
    if (sum > ans) {
        ans = sum;
        k = cur;
        copy(begin(last),end(last),begin(last_ans));
    }
    return;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> cnt[i];
    
    for (int i = 1; i <= n-1; i++) {
        for (int j = i+1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }
        
    for (int i = 1; i <= n; i++)
    {
        fill(vis,vis+n,0);
        vis[i] = true;
        dfs(i,cnt[i]);
    }

    stack<int> sta;
    while (last_ans[k]) {
        sta.push(k);
        k = last_ans[k];
    }
    cout << k << " ";
    while (!sta.empty()) {
        cout << sta.top() << " ";
        sta.pop();
    }
    cout << endl;

    cout << ans << endl;

    system("pause");
    return 0;
}