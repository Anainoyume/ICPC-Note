//导弹拦截
#include <bits/stdc++.h>
using namespace std;

//导弹问题的实质是 求最长单调子序列，我们这里假设为不严格单调递减的
int n;
int a[100000];    //数列
int sta[100000];    //单调栈

int ans;

void print(int k) {
    for (int i = 0; i < k; i++)
    {
        cout << sta[i] << " ";
    }
    cout << endl;  
}

int main(int argc, char const *argv[])
{
    while (cin >> a[n++]); n--;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    int b[n];

    for (int i = 0; i < n; i++)
        b[n-1-i] = a[i];

    // for (int i = 0; i < n; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    
    int k = 1;
    sta[0] = b[0];
    for (int i = 1; i < n; i++)
    {
        print(k);
        if (b[i] >= sta[k-1]) {
            sta[k++] = b[i];
        }
        else {
            // 1 2 2 3 4 5 5 5 7 7 8 8 9 9  <- 7
            // 这里必须用upper_bound
            int index = upper_bound(sta,sta+k,b[i])-sta;
            sta[sta[index] == b[i] ? index-1 : index] = b[i];

            cout << (sta[index] == b[i] ? index+1 : index) << endl;
        }
    }

    cout << k << endl;

    memset(sta,0,k*sizeof(int));
    k = 1;

    sta[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > sta[k-1]) {
            sta[k++] = a[i];
        }
        else {
            sta[lower_bound(sta,sta+k,a[i])-sta] = a[i];
        }

    }
    
    cout << k << endl;
    
    
    system("pause");
    return 0;
}
