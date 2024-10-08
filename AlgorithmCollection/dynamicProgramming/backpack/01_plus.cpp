//标准的01背包
#include <bits/stdc++.h>
using namespace std;

int C, n;
int c[10001], w[10001]; //c表示体积, w是价值
int dp[10001];

int main()
{
    cin >> C >> n;  //C为背包容量，n为物品数量

    for (int i = 1; i <= n; i++)
        cin >> c[i] >> w[i];
    
    //使用滚动数组进行空间优化
    //一个数组的左边是上一轮跑的结果，从右边开始跑当前轮的结果
    for (int i = 1; i <= n; i++)
    {
        for (int j = C; j >= c[i]; j--) //注意这里为什么是 j >= c[i]
        {
            dp[j] = max(dp[j],dp[j-c[i]]+w[i]);
            /* 
                原本应该为
                if (c[i] <= j)
                    dp[j] = max(dp[j],dp[j-c[i]]+w[i]);
                否则保留上次情况，也就是不做操作，这里直接把c[i]换到循环里的1
             */
        }
    }
    
    cout << dp[C] << endl;

    system("pause");
    return 0;
}