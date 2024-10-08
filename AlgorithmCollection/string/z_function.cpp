/**
 * @brief Z-function (扩展kmp)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i-l] < r - i + 1)           //对应的前缀点的 z 没有越过 z-box
            z[i] = z[i - l];
        else
        {       // 越界了, 需要重新暴力判断
            z[i] = max(0, r-i+1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])  //别忘记 z[i] 不仅是 z-box 边界, 也是此时的"步数"
                ++z[i];
        }
        if (i + z[i] - 1 > r)
            l = i, r = i+z[i]-1;
    }
    return z;
}

signed main()
{
    auto arr = z_function("abbbabbbcabab");
    for (auto &&i : arr)
    {
        cout << i << " ";
    }

    system("pause");
    return 0;
}