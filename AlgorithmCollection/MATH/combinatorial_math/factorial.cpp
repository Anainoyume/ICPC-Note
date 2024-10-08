#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e4+5;
const int md = 1e9+7;
// ¼ÆËã½×³Ë
int fac[maxN];
void getFactorial() {
    for (int i = 0; i < maxN; ++i) {
        if (i == 0) fac[i] = 1;
        else fac[i] = (i % md * fac[i-1] % md) % md;
    }
}

signed main()
{


    system("pause");
    return 0;
}