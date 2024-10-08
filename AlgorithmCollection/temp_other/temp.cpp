#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// #define int long long
// #define double long double
#define endl '\n'

const int md = 1e9+7;
const int maxN = 1005;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i+1 <= n; i += 2) {
        cout << "? " << i << " " << i+1 << endl;
        cout.flush();
        int result;
        cin >> result;

        if (result == 1) {
            int p1 = (i+1)%n + 1;
            int p2 = (i+2)%n + 1;

            cout << "? " << i << " " << p1 << endl;
            cout.flush();
            int res1;
            cin >> res1;

            if (res1 == 1) {
                cout << "? " << i << " " << p2 << endl;
                cout.flush();

                int res2;
                cin >> res2;
                if (res2 == 1) {
                    cout << "! 2" << endl;
                    return;
                }
            }
            else {
                cout << "? " << i+1 << " " << p1 << endl;
                cout.flush();

                int res3;
                cin >> res3;
                if (res3 == 1) {
                    cout << "? " << i+1 << " " << p2 << endl;
                    cout.flush();

                    int res2;
                    cin >> res2;
                    if (res2 == 1) {
                        cout << "! 2" << endl;
                        return;
                    }
                }
            }
        }

    }
    cout << "! 1" << endl;
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