#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        h[i] = a[i];
    }

    // Ω¯––¿Î…¢ªØ
    sort(h.begin(),h.end());

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(h.begin(), h.end(), a[i]) - h.begin();
    }

    for (auto&& i : b) {
        cout << i << " ";
    }
    cout << endl;

    for (auto&& i : a) {
        cout << i << " ";
    }    

    system("pause");
    return 0;
}
