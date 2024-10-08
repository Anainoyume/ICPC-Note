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
        if (Map[i][j] && !vis[j])   //����ͨ�����ұ�ѡ����Ǹ��㻹δ���ʹ�
        {
            vis[j] = 1; //���Ϊ�Ѿ�����
            if (p[j] == 0 || match(p[j]))   //���������һ���ǻ�δ��ѡ��
            {                               //����Ѿ�ѡ�񣬾�ȥ�޸�֮ǰ�����ӣ�������ӿɱ��޸ģ�����true
                p[j] = i;   //����
                return true;    //�����޸ģ�������ȷ�ź�
            }
        }
    }
    return false;   //��������������еıߣ���û�н������ӣ���ô˵������ʧ��
}

int Hungarian()
{
    int cnt = 0;
    for (int i = 1; i <= M; ++i)    //����һ����ߵ����е�
    {
        memset(vis, 0, sizeof(vis));    //����vis����
        if (match(i))   //�����ƥ������
            cnt++;      //������һ
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