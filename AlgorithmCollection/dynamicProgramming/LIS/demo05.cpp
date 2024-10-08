#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
int n, k;
int a[maxN];
int sta[maxN];
int prem[maxN];
int back[maxN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++)
    {
        if (k == 0 || a[i] > sta[k-1]) {
            sta[k++] = a[i];
        }
        else {
            int p = lower_bound(sta,sta+k,a[i])-sta;
            sta[p] = a[i];
        }
        prem[i] = k;
    }

    k = 0;
    fill(begin(sta),begin(sta)+n,0);
    for (int i = n-1; i >= 0; i--)
    {
        if (k == 0 || a[i] < sta[k-1]) {
            sta[k++] = a[i];
        }
        else {
            int p = lower_bound(sta,sta+k,a[i],greater<int>())-sta;
            sta[p] = a[i];
        }
        back[i] = k;
    }
    
    int ans{};
    for (int i = 0; i < n; i++)
    {
        ans = max(ans,prem[i]+back[i+1]);
    }
    
    cout << ans << endl;

    system("pause");
    return 0;
}