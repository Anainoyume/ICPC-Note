/* 
    数论分块

    floor(a/(bc)) == floor(floor(a/b)/c)

    数论分块结论：
    使 floor(n/i) == floor(n/j)
    成立最大的 i <= j <= n 的 j 值为 floor(n/floor(n/i))。
    即值 floor(n/i) 所在的块的右端点为 floor(n/floor(n/i))
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//       n
//计算   Σ floor(n/i)
//      i=1

//我们使用数论分块来优化
ll f(ll N, ll k) {
    ll n = N;
    if (n > k)
        n = k;
    ll left = 1;   //一开始区块的左边界为left
    ll ans = 0;
    while (left <= n) {
        ll right = min(k / (k / left),n);   //取最小值是因为 n可能小于 k
        ans += ((left+right)*(right-left+1)/2) * (k / left); //相同值*区间长度(区间函数)
        left = right + 1;   //左边界增加
    }
    return ans;
}

int main()
{
    //ios::sync_with_stdio(false);
    //ceil天花板-向上取整  floor地板-向下取整
    //cout << ceil(5.3) << " " << floor(5.3) << endl;

    //C++的除法自带了一个向下取整

    ll n = 0;
    ll k = 0;

    // k % i = k - (k/i)*i;
    //而求解形如 (k/i)*i 的和，我们正好可以用数论分块
    cin >> n >> k;  //n可能比k小
    
    cout << n*k - f(n,k) << endl;

    //system("pause");
    return 0;
}

