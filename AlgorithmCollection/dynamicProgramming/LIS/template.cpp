//LIS问题模板代码
#include <bits/stdc++.h>
using namespace std;

int n, ans;
int b[100000];    //数列
int sta[100000];    //单调栈

int main(int argc, char const *argv[])
{
    int n{};
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    int k{};
    for (int i = 0; i < n; i++)
    {
        if (b[i] >= sta[k-1] || k == 0) {
            sta[k++] = b[i];
        }
        else {
            int index = upper_bound(sta,sta+k,b[i])-sta;
            sta[index] = b[i];
        }
    }

    /* 
        1）若需要求最长下降子序列，将
        int index = lower_bound(sta,sta+k,b[i])-sta;
        改为
        int index = lower_bound(sta,sta+k,b[i],greater())-sta;

        if语句中的>号改为<号即可。

        2）若需要求最长不降子序列，将lower_bound改为upper_bound，if语句中的>号改为>=号即可。

        3）若需要求最长不升子序列，将1）中的lower_bound改为upper_bound，if语句中的<号改为<=号即可。
           保留使用greater()
     */

    cout << k << endl;
    
    system("pause");
    return 0;
}
