#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
// #define double long double
#define endl '\n'
/* 
    二进制拆位前缀和
 */

const int md = 1e9+7;
const int maxN = 1005;
const int Bits = 29;
int arr[maxN];
int prf[maxN][Bits];    // prf[i][j] 表示前 i 个数字，第 j 位bit 的前缀和

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    // 拆位前缀和
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= Bits; ++j) {
            prf[i][j] = prf[i-1][j] + (((1 << (j-1)) & arr[i]) != 0);
        }
    }

    int query;
    cin >> query;
    while (query--) {
        int left, k;
        cin >> left >> k;   //寻找一个最大的与前缀 >= k 下标
        //由于连续的 按位与 会使得前缀与 递减，单调性，可以使用二分，至于快速检索，[l,mid] 的前缀与，就可以用
        //上面的二进制拆前缀和拉！

        // 二分
        int ans = -1;
        int l = left, r = n;
        while (l <= r) {
            int mid = l + (r - l >> 1);
            //获取前缀与
            int cur = 0;
            for (int j = 1; j <= Bits; ++j) {
                // 一个细节，注意是 prf[mid][j]-prf[left-1][j] 而不是 prf[mid][j]-prf[l-1][j]，我们的区间左边 left不变，l是变动的
                if (prf[mid][j]-prf[left-1][j] == mid-left+1) //表示 [l,mid] 的第i位全部有1，那么与之和就是1
                    cur += 1 << (j-1);
            }

            if (cur >= k) {
                l = mid+1;
                ans = max(ans,mid);
            }
            else {
                r = mid-1;
            }
        }
        //cout << format("({},{})\n",l,r);
        cout << ans << " ";
    }

    cout << endl;
}

signed main() {
    //IOS;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    system("pause");
    return 0;
}