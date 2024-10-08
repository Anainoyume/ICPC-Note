#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int maxN = 1e5+5;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    
    int ans = INT64_MIN;
    for (int i = 0; i <= 5; i++) {
        int sum = 1;
        for (int j = 0; j < i; j++) {
            sum *= arr[j];
        }
        for (int j = n-1; j > (n-1)-(5-i); j--) {
            sum *= arr[j];
        }
        ans = max(ans,sum);
    }
    cout << ans << endl;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}