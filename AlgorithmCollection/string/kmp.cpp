#include <bits/stdc++.h>
using namespace std;

//求 模式串(在主串中查找的那个串) 的 next
vector<int> getNext(const string& s) {
    vector<int> next(s.size());
    next[0] = -1;

    int i = 0, j = -1;
    while (i < s.size()-1) {
        if (j == -1 || s[i] == s[j]) {
            next[++i] = ++j;
        }
        else {
            j = next[j];
        }
    }
    return move(next);
}

// kmp 算法 (查询到子串就停止)
int kmp(const string& s, const string& p, vector<int>& next) {
    int i = 0, j = 0;
    vector<int> ans;
    while (i < s.size() && j < p.size()) {
        if (j == -1 || s[i] == p[j]) 
            i += 1, j += 1;
        else {
            j = next[j];
        }
    }

    return j == p.size() ? i - j : -1;
}

// kmp 算法 (查询所有符合条件的子串, 将 p 末尾添上 1 个非法字符)
vector<int> kmps(const string& s, const string& p, vector<int>& next) {
    int i = 0, j = 0;
    vector<int> ans;
    while (i < s.size()) {
        if (j == -1 || s[i] == p[j]) {
            i += 1, j += 1;
            if (j == p.size()-1) {
                ans.emplace_back(i - j);
            }
        }
        else {
            j = next[j];
        }
    }
    return move(ans);
}

signed main()
{
    string s, p;
    cin >> s >> p;

    p += '#';
    vector<int> next = getNext(p);

    vector<int> ans = kmps(s,p,next);
    for (auto&& i : ans) {
        cout << i+1 << endl;
    }

    for (int i = 0; i < next.size()-1; ++i) {
        if (i == 0) {
            cout << 0 << " ";
        }
        else {
            cout << next[i+1] << " ";
        }
    }

    system("pause");
    return 0;
}