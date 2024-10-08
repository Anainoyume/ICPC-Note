#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
// #define double long double
#define endl '\n'

const int md = 1e9+7;
const int maxN = 1005;

// 1. 扩展欧里几得算法
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int FindInv(int a, int m) {
    int x{}, y{};
    int d = exgcd(a,m,x,y);
    if (d == 1)
        return (x % m + m) % m;  
    else
        return -1;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n+1);
    
    int x = 1;
    for (int i = 1; i <= n; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int k;
            cin >> k;
            x = (x * k) % m;
            arr[i] = k;
            cout << x << endl;
        }
        else {
            int pos;
            cin >> pos;
            x = (x * FindInv(arr[pos],m)) % m;
            cout << x << endl;
        }
    }
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