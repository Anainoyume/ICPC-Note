#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    int n{};
    cin >> n;

    vector<int> arr(n+2,0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    //正向最长上升子序列，再求一边最长下降子序列
    //我们采用单调栈做法
    vector<int> sta(n+2,0);
    vector<int> dpup(n+2,0);

    int k{};
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] > sta[k-1] || k == 0) {
            sta[k++] = arr[i];
        }
        else {
            auto p = lower_bound(sta.begin(),sta.begin()+k,arr[i]);
            *p = arr[i];
        }
        dpup[i] = k;
    }
    
    vector<int> dpdown(n+2,0);
    fill(sta.begin(),sta.end(),0);
    k = 0;
    for (int i = n; i >= 1; i--)
    {
        if (arr[i] > sta[k-1] || k == 0) {
            sta[k++] = arr[i];
        }
        else {
            auto p = lower_bound(sta.begin(),sta.begin()+k,arr[i]);
            *p = arr[i];
        }
        dpdown[i] = k;
    }

    
    int ans{};
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans,dpup[i]+dpdown[i+1]);
    }
    
    cout << n - ans << endl;
    
    system("pause");
    return 0;
}