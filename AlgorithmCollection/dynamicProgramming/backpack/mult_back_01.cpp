// 多重背包二进制优化
#include <bits/stdc++.h>
using namespace std;

#define N 50010

int w[N], c[N], m[N]; // 价值，体积，数量
int C, k;             // 总体积，物品种类

int new_w[N], new_c[N]; // 二进制拆分的新数组
int new_n;

int dp[N];

int main(int argc, char const *argv[])
{
    cin >> k >> C;
    for (int i = 1; i <= k; i++)
        cin >> w[i] >> c[i] >> m[i];

    // 二进制优化
    /*
        相当于把每一个物品，都按照二进制拆分，形成新的new_n个物品，转化为
        0/1 背包
     */
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= m[i]; j <<= 1) // 每次左移1 *2
        {
            m[i] -= j; // 进行拆分
            new_c[++new_n] = j * c[i];
            new_w[new_n] = j * w[i];
        }
        if (m[i])
        { // 最后的余数
            new_c[++new_n] = m[i] * c[i];
            new_w[new_n] = m[i] * w[i];
        }
    }

    for (int i = 1; i <= new_n; i++)
    {
        for (int j = C; j >= 1; j--)
        {
            if (new_c[i] <= j)
                dp[j] = max(dp[j], dp[j - new_c[i]] + new_w[i]);
        }
    }

    cout << dp[C] << endl;

    system("pause");
    return 0;
}
