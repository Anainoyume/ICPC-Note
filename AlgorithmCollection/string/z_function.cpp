/**
 * @brief Z-function (��չkmp)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i-l] < r - i + 1)           //��Ӧ��ǰ׺��� z û��Խ�� z-box
            z[i] = z[i - l];
        else
        {       // Խ����, ��Ҫ���±����ж�
            z[i] = max(0, r-i+1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])  //������ z[i] ������ z-box �߽�, Ҳ�Ǵ�ʱ��"����"
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