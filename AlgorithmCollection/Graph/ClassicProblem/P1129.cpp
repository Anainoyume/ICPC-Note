#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// #define int long long
// #define double long double
#define endl '\n'

const int md = 1e9+7;
const int maxN = 1005;

int Map[502][502], p[502], vis[502], M, N;
bool match(int i)
{
    for (int j = 1; j <= N; ++j)
    {
        if (Map[i][j] && !vis[j])   //若连通，并且被选择的那个点还未访问过
        {
            vis[j] = 1; //标记为已经访问
            if (p[j] == 0 || match(p[j]))   //两种情况，一种是还未被选择
            {                               //如果已经选择，就去修改之前的连接，如果连接可被修改，返回true
                p[j] = i;   //连接
                return true;    //可以修改，返回正确信号
            }
        }
    }
    return false;   //如果遍历完了所有的边，都没有进行连接，那么说明连接失败
}

int Hungarian()
{
    int cnt = 0;
    for (int i = 1; i <= M; ++i)    //遍历一次左边的所有点
    {
        memset(vis, 0, sizeof(vis));    //重置vis数组
        if (match(i))   //如果可匹配连接
            cnt++;      //数量加一
    }
    return cnt;
}

void solve() {
    memset(p, 0, sizeof(p));
    int n;
    cin >> n;
    
    M = n;
    N = n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> Map[i][j];
        }
    }

    int ans = Hungarian();

    cout << (ans == n ? "Yes" : "No") << endl;
}

signed main() {
    //IOS;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    system("pause");
    return 0;
}