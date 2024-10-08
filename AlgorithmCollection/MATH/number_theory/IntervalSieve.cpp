/* 
    区间筛
    有时我们只需要筛出一个区间的数就行了，这里以区间内的数质因数分解为例
 */

#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define int long long
// #define double long double
#define endl '\n'

const int md = 1e9+7;
const int maxN = 1005;

const int N = 1.1e6, M = 108;
int prime[N+5], tot;
bool vis[N+5];

int primeCnt, ans;
vector<pair<int,int>> a[110];

// 这题需要的求数位和
inline int dig(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

//欧拉筛算法
int EulerSieve(int n) {
    int cnt = 0;
    memset(vis,0,sizeof(vis));
    memset(prime,0,sizeof(prime));

    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt; j++)   //遍历自然数的同时，i同时充当了 被检测数 和 质数筛选倍数 的两个身份
        {
            if (i * prime[j] > n) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return cnt;
}

// 输出所有因子，详情看 factor.cpp
void dfs(int acc, int cur, int sm) {
    if (cur >= a[sm].size()) {
        if (acc > sm && dig(acc) == sm) {
            //cout << acc << " " << sm << endl;
            ans += 1;
        }
        return;
    }

    auto [fac, pow] = a[sm][cur];
    int temp = 1;
    for (int i = 0; i <= pow; ++i) {
        dfs(acc*temp,cur+1,sm);
        temp *= fac;
    }
}

// 关键在这里
void solve() {
    ans = 0;

    int n;
    cin >> n;

   
    vector<int> val(M+1,0);
    int maxM = M;
    for (int i = 0; i <= M; ++i) {
        if (n - i <= 0) {
            maxM = i-1;
            break;
        }
        val[i] = n - i;
        a[i].clear();
    }


    // 区间筛
    // 首先，我们要筛取得是区间 [ n, n - maxN ] 范围内的因数
    for (int i = 0; prime[i]*prime[i] <= n; ++i) {
        if (prime[i] <= maxM) { 
            // 如果当前质数小于 maxN，这意味着，在这个区间内。绝对存在一个数一上是该数的倍数
            // 举个例子，例如 prime[i] = 2, 筛法就是对区间内所有偶数格子进行分解，
            // prime[i] = 3, 就是每3格分解一次
            for (int j = 0; j <= maxM; ++j) {
                int cnt{};
                while (val[j] % prime[i] == 0) {
                    val[j] /= prime[i];
                    cnt += 1;
                }
                if (cnt) a[j].push_back({prime[i], cnt});
            }
        }
        else if (n % prime[i] <= maxM) {
            // 而如果 prime[i] 大于了区间的长度，我们则需要用 n取模这个质数，看截止 n 为止可以乘除的
            // 份数，最后多出来的那个余数，如果那个余数仍然在区间里。则表示当前这个素数的某一个倍数
            // 存在于这个区间中，此时我们只需要对那一个数分解因子即可，因为下一个倍数绝对不在这个区间内
            // 这样就可以节约大幅的时间
            int j = n % prime[i], cnt{};
            while (val[j] % prime[i] == 0) {
                val[j] /= prime[i];
                cnt += 1;
            }
            if (cnt) a[j].push_back({prime[i], cnt});
        }
    }

    for (int i = 0; i <= maxM; ++i) {
        if (val[i] > 1) a[i].push_back({val[i],1}); 
    }

    for (int i = 0; i <= maxM; ++i) {
        dfs(1,0,i);
    }

    cout << ans << endl;
}

signed main() {

    EulerSieve(N);

    //IOS;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    system("pause");
    return 0;
}