#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int maxN = 105;
int mp[maxN][maxN];

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> path(m);
    for (int i = 0; i < m; i++) {
        cin >> path[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mp[i][j];
            // if (mp[i][j] == 0) mp[i][j] = INT_MAX;
        }
    }
    
    // ������pass ����д�������
    for (int pass = 1; pass <= n; pass++) {
        for (int from = 1; from <= n; from++) {
            // ����Ҫ���������������㣬�����pass����ͨ��Ҳ����
            if (from == pass || mp[from][pass] == INT_MAX) continue;
            for (int to = 1; to <= n; to++) {
                // ������㲻��ͨ���ߵ��ﱾ������
                if (from == to || mp[pass][to] == INT_MAX) continue;
                mp[from][to] = min(mp[from][pass]+mp[pass][to],mp[from][to]);
            }   
        }
    }
    
    int ans = 0;
    for (int i = 1; i < m; i++) {
        ans += mp[path[i-1]][path[i]];
    }
    
    cout << ans << endl;

    system("pause");
    return 0;
}