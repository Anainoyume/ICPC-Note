#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3+5;
const int md = 10007;

// µÝÍÆÇó½×³Ë
int c[maxN][maxN];
void getCombine() {
    for (int i = 0; i < maxN; i++) {
        for (int j = 0; j <= i; j++) {
            if(j == 0) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] % md + c[i - 1][j - 1] % md) % md;
        }
    }
}

using i64 = long long;
i64 fastPow(i64 a, i64 n, i64 m = md) {
    i64 ans{1};
    while (n) {
        if (n&1) ans = (ans*a) % m;
        a = (a*a) % m;
        n >>= 1;
    }
    return ans;
}

signed main()
{
    getCombine();
    int a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;

    cout << c[k][n] % md * (fastPow(b,k-n) % md) * (fastPow(a,n) % md) % md << endl;


    system("pause");
    return 0;
}