/*
    �������ֽ�
    (pro�棬��һ������)

    �Ż�����ʹ��ȫ�����飬���Ӷ� O( sqrt(n)/logn )
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1.1e6; // ��ǰn�����м�������
int prime[N+5];
int vis[N+5]; //ע��ĳ�int

int EulerSieve(int n)
{
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(prime, 0, sizeof(prime));

    vis[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            prime[cnt++] = i;
            vis[i] = i; // �������������С����������������
        }
        for (int j = 0; j < cnt; j++)
        {
            if (i * prime[j] > n)
                break;
            vis[i * prime[j]] = prime[j]; // �����������С������
            if (i % prime[j] == 0)
                break;
        }
    }
    return cnt;
}

// ��ͨ��
vector<pair<int,int>> getFactor(int num) {
    int x = num;
    vector<pair<int,int>> fac;
    for (int i = 0; prime[i]*prime[i] <= x; ++i) {
        int cnt{};
        while (x % prime[i] == 0) {
            x /= prime[i];
            cnt += 1;
        }
        if (cnt) fac.push_back({prime[i],cnt});
    }
    if (x > 1) fac.push_back({x,1});
    return move(fac);
}

void dfs(int acc, int cur, vector<pair<int,int>>& facs) {
    if (cur >= facs.size()) {
        cout << acc << endl;
        return;
    }

    auto&& [fac, pow] = facs[cur];
    int temp = 1;
    for (int i = 0; i <= pow; ++i) {
        dfs(acc*temp,cur+1,facs);
        temp *= fac;
    }
}


signed main()
{
    int cnt = EulerSieve(N);     
    
    auto facs = getFactor(2*2*2*5*5*17);
    dfs(1,0,facs);

    system("pause");
    return 0;
}
