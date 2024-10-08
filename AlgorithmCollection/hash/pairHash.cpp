#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

struct pairHash {
    template <class T1, class T2>
    size_t operator()(const pair<T1,T2>& p) const {
        size_t hash1 = hash<T1>{}(p.first);
        size_t hash2 = hash<T2>{}(p.second);      
        // If hash1 == hash2, their XOR is zero.
        return hash1 != hash2 ? (hash1 ^ hash2) : hash1;
    }
};

signed main()
{
    unordered_map<pii,bool,pairHash> mp;
    mp[{1,2}] = true;
    mp[{1,1}] = true;
    mp[{2,1}] = true;
    mp[{1,0}] = true;

    for (auto&& [key, value] : mp) {
        cout << format("({},{}): {}\n",key.first,key.second,value);
    }

    system("pause");
    return 0;
}