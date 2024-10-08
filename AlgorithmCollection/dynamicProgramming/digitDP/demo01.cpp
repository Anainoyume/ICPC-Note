#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define syc cin.tie(0)->sync_with_stdio(false)
const int md = 1e9+7;


int a[13];
int cnt[11];

//isZero 为是否含有前导零
void dfs(int pos, bool limit, bool isZero, int k, int last) {
    if (pos == 0)
        return;
    
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; i++)
    {
        if(!isZero || i != 0) cnt[i] += k;
        dfs(pos-1, limit && i == up, i == 0, k, i);
        if((!isZero || i != 0) && last != 0) cnt[last] += k;
    }
}

void solve(int x, int m) {
    int k = 0;
    while (x) {
        a[++k] = x % 10;
        x /= 10;
    }
    return dfs(k, true, false, m, 10);
}


int main(int argc, char const *argv[])
{
    int l, r;
    cin >> l >> r;
    
    solve(r,1);
    solve(l-1,-1);

    for (auto &&i : cnt)
    {
        cout << i << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
