#include <bits/stdc++.h>
using namespace std;
/* 
    单调队列优化 线性DP
 */

int val = INT_MIN;
const int maxN = 2e5+5;
int n, l, r;
int arr[maxN];
int dp[maxN];

int main(int argc, char const *argv[])
{
    cin >> n >> l >> r;
    int k = r-l+1;
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
        dp[i] = val;
    }
    
    dp[0] = 0;
    int ans = val;
    deque<int> que;

    for(int i = l; i <= n; i++)
    {
        if (i >= l) {
            while (!que.empty() && dp[i-l] > dp[que.back()]) que.pop_back();
            que.emplace_back(i-l);

            if (!que.empty() && que.front() < i-r) que.pop_front();
        }

        dp[i] = dp[que.front()] + arr[i];

        if(i + r > n) 
            ans = max(dp[i], ans);
    }
    
    cout << ans << endl;
    
    system("pause");
    return 0;
}

