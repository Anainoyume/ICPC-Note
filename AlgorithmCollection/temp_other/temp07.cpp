#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
#define double long double
#define endl '\n'

const double eps = 1e-7;
const int md = 1e9+7;
const int maxN = 1005;

using pii = pair<int,int>;

double dis(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void solve() {
    int n;
    cin >> n;
    string str{};
    cin >> str;
    str.insert(str.begin(),'&');
    vector<pii> arr(n+1);

    vector<bool> vis(n+1,false);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;

        auto [x1,y1] = arr[i];
        double len = 0;
        int index = 0;

        for (int j = 1; j <= n; ++j) {
            auto [x2,y2] = arr[j];

            if (i == j || vis[j]) continue;

            if (str[j] == str[i]) {
                double l = dis(x1,y1,x2,y2);
                if (l > len) {
                    len = l;
                    index = j;
                }
            }
        }
        vis[i] = true;
        vis[index] = true;
        ans += len;
    }

    printf("%.8Lf\n",ans);

}

signed main() {
    //IOS;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    system("pause");
    return 0;
}