#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
// #define double long double
#define endl '\n'

const int md = 998244353;
const int maxN = 2e5+5;

int fac[maxN];
void solve() {
    string str;
    cin >> str;
    vector<int> d;    // 每一段的 0, 1 数量
    
    int len = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (i > 0 && str[i] != str[i-1]) {
            d.push_back(len);
            len = 0;
        }
        len += 1;
    }
    if (len > 0) d.push_back(len);

    int sum = accumulate(d.begin(),d.end(),0,[&](int cal, int cur) -> int {
        return ((cal % md) + ((cur - 1) % md)) % md;
    });

    int mult = accumulate(d.begin(),d.end(),1,[&](int cal, int cur) -> int {
        return ((cal % md) * (cur % md)) % md;
    });

    fac[0] = 1;
    for (int i = 1; i <= sum; ++i) {
        fac[i] = ((i % md) * (fac[i-1] % md)) % md;
    }

    cout << sum << " " << ((fac[sum] % md) * (mult % md)) % md << endl;

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