#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

#define endl '\n'
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define iter(x) x.begin(),x.end()
// #define int long long
// #define double long double

const int md = 1e9+7;
const int maxN = 1e4+5;

bool check(int x) {
    
}

int binarySearch2(int left, int right) {
    int l{left}, r{right};

    while (l < r) {
        int mid = l + (r - l + 1 >> 1);	//(l+r+1)/2
        if (check(mid))  
            l = mid;
        else 
            r = mid - 1;
    }
    
    return l;
}

signed main()
{

    system("pause");
    return 0;
}