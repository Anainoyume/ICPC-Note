#include <bits/stdc++.h>
using namespace std;

/* 
    正向反向求最长上升子序列
    查找+二分

    7
    3 2 3 1 3 5 4
 */

const int maxN = 1e3+5;
int n, k;
int a[maxN];
int sta[maxN];
int prem[maxN];
int back[maxN];

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    //求解最长上升子序列
    for (int j = 0; j < n; j++) {
        fill(begin(sta),begin(sta)+k,0);
        k = 0;
        for (int i = j; i < n; i++)
        {
            if (a[i] > sta[k-1] || k == 0) {
                sta[k++] = a[i];
            }
            else {
                int p = lower_bound(sta,sta+k,a[i])-sta;
                sta[p] = a[i];
            }
        }
        prem[j] = k;
    }

    //逆向求解最长上升子序列
    //反向求下降子序列
    fill(begin(sta),begin(sta)+n,0);
    k = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if (a[i] < sta[k-1] || k == 0) {
            sta[k++] = a[i];
        }
        else {
            int p = lower_bound(sta,sta+k,a[i],greater())-sta;
            sta[p] = a[i];
        }
        back[i] = k;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << prem[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << back[i] << " ";
    }
    cout << endl;
    
    system("pause");
    return 0;
}
