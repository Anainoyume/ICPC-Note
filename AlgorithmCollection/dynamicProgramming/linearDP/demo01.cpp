#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+5;
int cnt[maxN];

int digit(int num) {
    int ans{};
    while (num) {
        ans += num % 10;
        num /= 10;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n{}, k{};
    cin >> n >> k;

    int maxa{};
    for (int i = 0; i < n; i++)
    {
        int cur{};
        cin >> cur;
        cnt[cur]++;
        maxa = max(maxa,cur);
    }
    
    bool ok = false;
    for (int i = maxa; i >= 0; i--)
    {
        if (cnt[i] == 0) continue;
        int sum = digit(i);
        cnt[i-sum] += cnt[i];
        if (k <= cnt[i]) {
            cout << sum << endl;
            ok = true;
            break;
        }
        else {
            k -= cnt[i];
        }
    }
    
    if (ok == false) {
        cout << 0 << endl;
    }

    system("pause");
    return 0;
}
