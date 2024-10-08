#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxN = 1005;

int check(const string& s, int x, int y) {
    int result = 0;
    for (auto&& c : s) {
        if (c - '0' == x) {
            result += 1;
            swap(x,y);
        }
    }
    //如果此时获取的result长度为奇数 (注意不能使用s.size()，那个是总长度)
    if (result % 2 == 1 && x != y)
        result -= 1;    //去除一个数位，使得最大长度-1
    return result;
}

void solve() {
    string str;
    cin >> str;

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            ans = max(ans,check(str,i,j));
        }
    }

    //原长度减去最长的，就是我们需要去除的最少的
    cout << str.size()-ans << endl;
    
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