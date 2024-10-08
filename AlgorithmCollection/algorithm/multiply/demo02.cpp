#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    int arr[n+1]{}, st[n+1][31]{};
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        st[i][0] = arr[i];
    }

    for (int j = 1; j <= 31; ++j) {
        for (int i = 1; i+(1<<(j-1)) <= n; ++i) {
            st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }

    //Çólog2
    int Log2[n+1]{};
    Log2[1] = 0;
    for (int i = 2; i <= n; ++i) {
        Log2[i] = Log2[i/2] + 1;
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        int s = Log2[r-l+1];
        cout << max(st[l][s],st[r-(1<<s)+1][s]) << endl;
    }

    system("pause");
    return 0;
}