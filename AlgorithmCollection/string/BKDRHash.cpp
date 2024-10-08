#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct Hash
{
    const i64 P = 1e12 + 39;
    const int B = 13331;
    vector<i64> h, p;
    Hash(string s) : h(s.size() + 1), p(s.size() + 1) {
        int n = s.size();
        p[0] = 1;
        for (int i = 0; i < n; i++) {
            h[i + 1] = (h[i] * B + s[i]) % P;
            p[i + 1] = p[i] * B % P;
        }
    }

    //左闭右开 从 0 开始
    i64 get(int l, int r) {
        return (h[r] + __int128(h[l]) * (P - p[r - l])) % P;
    }
};

int main()
{
    Hash h1("abwuiwbi");
    Hash h2("wui");

    cout << (h1.get(2,5) == h2.get(0,3)) << endl;
    

    system("pause");
    return 0;
}