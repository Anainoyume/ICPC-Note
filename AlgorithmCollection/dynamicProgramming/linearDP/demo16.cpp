#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// #define int long long
// #define double long double
#define endl '\n'

const int md = 998244353;
const int maxN = 105;

int dp[maxN][maxN]; //��ǰi��λ�÷���j���飬���ҵ�i��λ��һ��������
void solve() {
    fill(dp[0],dp[0]+maxN*maxN,INT_MAX);
    int n, k;   //n���飬ȡ��k����
    cin >> n >> k;
    vector<pair<int,int>> arr(n);
    for (int i = 0; i < n; ++i) {
        int height, width;
        cin >> height >> width;
        arr[i] = {height,width};
    }
    sort(arr.begin(),arr.end());
    for (int i = 0; i < n; ++i) {
        dp[i][1] = 0;
    }

    //���ǲ�ȡ����˼ά����nȡ��k���飬�������Ϊ����"�������"��С��n-k����
    for (int j = 2; j <= n-k; ++j) {
        for (int i = j-1; i < n; ++i) {
            for (int t = j-2; t < i; ++t) {
                dp[i][j] = min(dp[i][j],dp[t][j-1]+abs(arr[i].second-arr[t].second));
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        ans = min(ans,dp[i][n-k]);
    }

    cout << ans << endl;

}

signed main() {
    //IOS;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    //system("pause");
    return 0;
}