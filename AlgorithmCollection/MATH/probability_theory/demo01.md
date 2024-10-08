### 概率dp
 >**背景: n个硬币全部反面朝上，k次翻转。求k次翻转后正面朝上的最大数学期望。**

唉，终归还是要学概率dp啊...
因此就拿这道题来作为开门题吧！

#### 研究题目
使用 dp 之前，我们必定要找到一个状态转移方程。那我们可以先从小规模的数据来研究一下这个过程。
首先，直觉告诉我们：想要得到最大的正面朝上的数学期望，**我们就必须每次都翻转反面的硬币**。

先考虑一下翻转次数小于硬币数目的情况，例如：

$n = 2, k = 2$
> 一开始为 2枚反面 正面为0 翻转0次
>
> 我们随机选择一个反面银币翻转
>
> 现在，有 $0.5$ 的概率为 反1 正1 翻1
> 同时，也有 $0.5$ 的概率为 反2 正0 翻1

好像有那么点感觉了。再来一个
$n = 3, k = 3$
> 计算状态: 反3 正0 翻0
>
> $p = 0.5$ -> 反2 正1 翻1
> $p = 0.5$ -> 反3 正0 翻1
>
> 计算状态：反2 正1 翻1
> $p = 0.5$ -> 反1 正2 翻2
> $p = 0.5$ -> 反2 正1 翻2

由于抛硬币只存在两种可能，那么我们不妨设计：
$dp[i][j]$ 来表示 第 $i$ 次抛硬币以后，正面朝上的为 $j$ 的**概率**。

那么有：
$dp[i][j] = 0.5*dp[i-1][j] + 0.5*dp[i-1][j-1]$

这个式子，我们其实从右边往左边解读更好理解:

当前状态为：
$dp[i-1][j]$ 表示我已经抛了 $i-1$ 次，正面有 $j$ 个的概率
接下来，我抛第 $i$ 次，这时候，被抛的反面硬币要么是正面，要么还是反面。
因此，$dp[i-1][j]$ 一分为二，有 $0.5*dp[i-1][j]$ 的概率表示第 $i$ 次得到的还是反面，即贡献于 $dp[i][j]$

而另外 $0.5*dp[i-1][j-1]$ 的概率得到的情况是第 $i$ 次得到了正面，也对 $dp[i][j]$ 作出贡献。

并且由于一次只能抛一次硬币，所以不存在其他的状态了。

接下来我们要考虑一个稍微复杂的问题：
**如果抛掷次数大于正面硬币数怎么办？**
这个时候已经全部是正面了，因此只能继续抛正面硬币

假设 $ dp[i][j] $ 中 $j >= n$，那么接下来，我抛
第 $i+1$ 次的时候。要么一个正面变回反面，要么还是正面。
因此，$0.5*dp[i][j]$ 会对 $dp[i+1][j-1]$ 做一次贡献
另外一部分对 $dp[i+1][j]$ 做出贡献

由式子推理一下:
$dp[i][j-1]$ 若 $j-1 >= n$，同理对
$dp[i+1][j-2]$ 和 $dp[i+1][j-1]$ 做出贡献

因此有：$dp[i+1][j-1] = 0.5*dp[i][j] + 0.5*dp[i][j-1]$
变形得到：
$dp[i][j] = 0.5*dp[i-1][j+1] + 0.5*dp[i-1][j]$

这样我们的状态转移方程就得到了。
最后的用一个循环来求解，抛 $k$ 次得到的数学期望。

不过实际编码的时候，初始状态不太好计算。这时候我们可以从 $dp[0][0]$ 往外扩展。

不采用转移，而使用贡献：
$dp[i][j]$ -> $dp[i+1][j+1]$
$dp[i][j]$ -> $dp[i+1][j]$

$dp[i][j]$ -> $dp[i+1][j]$
$dp[i][j]$ -> $dp[i+1][j-1]$

#### AC代码:
```cpp
#include <bits/stdc++.h>
using namespace std;

int n,k;
double dp[405][405];

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    dp[0][0] = 1;
    for (int i = 0; i < k; i++) 
    {
        //这里的 i < j 时结果为0，不用考虑
        //因为不可能只翻2次却翻出3枚正面
        for (int j = 0; j < n; j++)
        {
            dp[i+1][j+1] += 0.5*dp[i][j];
            dp[i+1][j] += 0.5*dp[i][j];
        }
        //循环结束以后此时 j == n
        dp[i+1][n] += 0.5*dp[i][n];
        dp[i+1][n-1] += 0.5*dp[i][n];
        //不会出现 n+1 的情况，因为最多只有n枚
    }
    
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += i*dp[k][i];
    }
    
    printf("%.6lf\n",ans);  //保留6位小数
    
    system("pause");
    return 0;
}
```

> 参考资料: https://blog.csdn.net/sunny_hun/article/details/80182498