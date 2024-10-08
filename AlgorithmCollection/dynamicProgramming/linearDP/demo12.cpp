#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS cin.tie(0)->sync_with_stdio(false)
const int md = 1e9+7;
const int maxN = 1005;

/* 
    给定一个长为n的数列a，和一个数字k
    例如 n = 6, k = 3
    a = [1, 1, 4, 5, 1, 4]

    将这个数列按照顺序划分子数列，并且子数列之和必须为 k 的倍数
    求出最多划分出的和为 k 倍数 的 子数列数量
 */

int n, k;
int a[maxN], sum[maxN];

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    
    unordered_map<int,int> mp;
    // ... 
    

    system("pause");
    return 0;
}
