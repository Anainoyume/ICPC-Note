/* 
    ����ɸ
    ��ʱ����ֻ��Ҫɸ��һ��������������ˣ������������ڵ����������ֽ�Ϊ��
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

// ������Ҫ������λ��
inline int dig(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

//ŷ��ɸ�㷨
int EulerSieve(int n) {
    int cnt = 0;
    memset(vis,0,sizeof(vis));
    memset(prime,0,sizeof(prime));

    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt; j++)   //������Ȼ����ͬʱ��iͬʱ�䵱�� ������� �� ����ɸѡ���� ���������
        {
            if (i * prime[j] > n) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return cnt;
}

// ����������ӣ����鿴 factor.cpp
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

// �ؼ�������
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


    // ����ɸ
    // ���ȣ�����Ҫɸȡ�������� [ n, n - maxN ] ��Χ�ڵ�����
    for (int i = 0; prime[i]*prime[i] <= n; ++i) {
        if (prime[i] <= maxM) { 
            // �����ǰ����С�� maxN������ζ�ţ�����������ڡ����Դ���һ����һ���Ǹ����ı���
            // �ٸ����ӣ����� prime[i] = 2, ɸ�����Ƕ�����������ż�����ӽ��зֽ⣬
            // prime[i] = 3, ����ÿ3��ֽ�һ��
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
            // ����� prime[i] ����������ĳ��ȣ���������Ҫ�� nȡģ�������������ֹ n Ϊֹ���Գ˳���
            // ����������������Ǹ�����������Ǹ�������Ȼ����������ʾ��ǰ���������ĳһ������
            // ��������������У���ʱ����ֻ��Ҫ����һ�����ֽ����Ӽ��ɣ���Ϊ��һ���������Բ������������
            // �����Ϳ��Խ�Լ�����ʱ��
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