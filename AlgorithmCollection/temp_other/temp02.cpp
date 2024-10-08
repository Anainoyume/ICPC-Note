#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
#define endl '\n'
#define double long double

const int eps = 1e-5;
const int md = 1e9+7;
const int maxN = 1005;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n), a(n/2), b(n/2);
    for (int i = 0; i < n; i++) {
        arr[i] = i+1;
    }
    
    for (int i = 0; i < n/2; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n/2; i++) {
        cin >> b[i];
    }
    
    int chi[2] = {0,0};
    bool x = 0;
    for (int i = 0; i < n; i++, x ^= 1) {
        int index = chi[x];
        if (x == 0) {
            int tmp = a[index]-1;
            a[index] = arr[tmp];
            arr.erase(arr.begin()+tmp);
        }
        else {
            int tmp = b[index]-1;
            b[index] = arr[tmp];
            arr.erase(arr.begin()+tmp);
        }
        chi[x] += 1;
    }
    
    for (auto&& e : a) {
        cout << e << " ";
    }
    cout << endl;
    for (auto&& e : b) {
        cout << e << " ";
    }
    cout << endl;
}

signed main()
{
    IOS;
    int t{1};
    //cin >> t;
    while (t--) {
        solve();
    }
    
    system("pause");
    return 0;
}
