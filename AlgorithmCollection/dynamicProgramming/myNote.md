### 动态规划dp 笔记合集
记录顺序随意，主要是记录许多不同的题型，来维护自己的算法思想，记住：**学习者，习思想者为上**

**1. P1164 小A点菜 (洛谷)**
这道题有很明显的一个问题特征："多少种方法"，"多少种情况"。即选取物品，满足条件的情况数。
我们很容易有一个记忆化搜索的写法：
```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxN = 105;
int n, m, w[maxN], dp[maxN][1005];

int dfs(int cur, int sum) {
    if (dp[cur][sum]) return dp[cur][sum];

    if (sum > m) return 0;

    if (cur > n) {
        if (sum == m) return 1;
        else return 0;
    }
    //当前这道菜，选或者不选
    dp[cur][sum] = dfs(cur+1,sum) + dfs(cur+1,sum+w[cur]);
    return dp[cur][sum];
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    
    int ans = dfs(1,0);

    cout << ans << endl;

    system("pause");
    return 0;
}
```
写记忆化搜索的关键，在于想象 **序贯树状图** ，其实就是一棵记录着各种情况的树。但是这个树的一些纸条存在重复部分。我们使用数组来记录这个结果，下次再遇到重复结果直接返回！

**dp做法：**
说起dp，重点在于，dp数组的设计，状态转移方程。
我们抓住那个设计的点，就可以很简单地写出代码。
这里的dp数组表示：**前i个物品恰好凑出j元的情况数**
```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[105][1005], w[105];
//dp[i][j]表示前i个物品恰好凑出j元的情况数

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        dp[i][0] = 1;
    }
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            //不选
            dp[i][j] += dp[i-1][j];
            //选
            if (j >= w[i]) dp[i][j] += dp[i-1][j-w[i]];
        } 
    }
    
    cout << dp[n][m] << endl;

    system("pause");
    return 0;
}
```
<br>

**2. P1077 [NOIP2012 普及组] 摆花 (洛谷)**
这一题和上面这题几乎完全一致，唯一不同的是物品不再是一件，而是很多件。但是有数量限制，因此这是一个类多重背包问题。但我们计算的是**情况数**.
```cpp
#include <bits/stdc++.h>
using namespace std;

const int md = 1e6+7;
int n, m;
int dp[105][105], cnt[105];
//dp[i][j]表示前i个物品恰好凑出j元的情况数

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i];
        dp[i][0] = 1;
    }
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] += dp[i-1][j] % md;    //注意不选的情况只贡献一次
            for (int k = 1; k <= cnt[i]; k++)
            {
                if (j >= k) dp[i][j] += dp[i-1][j-k] % md;
            }
        } 
    }
    
    cout << dp[n][m] % md << endl;

    system("pause");
    return 0;
}
```
<br>

**3. P2392 kkksc03考前临时抱佛脚**
折半背包思想：
例如一个数组，要将其划分为两个部分，两个部分的和要尽量接近。
可以设置一个体积为一半，然后使用背包，将其尽可能多得装进背包里。
这样就把另一部分划分出来了。
```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxN = 25;
int n;
int arr[maxN];
int dp[1205];
int cnt[4];

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 4; i++)
        cin >> cnt[i];
    
    int ans{};
    for (int i = 0; i < 4; i++)
    {
        int cur = cnt[i];
        int sum{};
        fill(begin(arr),end(arr),0);
        fill(begin(dp),end(dp),0);
        //折半求解
        for (int j = 1; j <= cur; j++) {
            cin >> arr[j];
            sum += arr[j];
        }
        
        for (int m = 1; m <= cur; m++)
        {
            for (int v = sum/2; v >= 0; v--)
            {
                if (v >= arr[m]) dp[v] = max(dp[v],dp[v-arr[m]]+arr[m]);
            }
        }
        
        ans += max(dp[sum/2],sum-dp[sum/2]);
    }
    
    cout << ans << endl;

    system("pause");
    return 0;
}
```