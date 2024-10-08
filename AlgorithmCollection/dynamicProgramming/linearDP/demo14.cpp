#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// #define int long long
#define endl '\n'

const int md = 1e9 + 7;
const int maxN = 1005;
/*
    整数划分问题

    对于一个数字，比如：
    5 = 1 + 2 + 2
    可以拆分成任意的不等于自身的数字之和，这就是一个拆分。

    给定 n, m, 求数字n拆分成m个数字之和总共有多少种不同的拆分方法

    这一题的核心关键思想在于找出 "对立事件"
    我们知道，如果 A∪B = R, A∩B = 0
    即，A,B相互对立。由A，B就可以组成R的所有事件

    我们如果整数划分，看作一个排列组合问题。就是在说：
    存在n个小球，m个盒子。求解不同的放法，且小球相同，盒子相同，注意盒子不为空。

    我们不妨使用这样的一个对立事件：分出的小球存在单独1个的，分出的小球不存在任何单独1个的
    显然这两种情况确实相互对立。

    那么 dp[i][j] 会等于什么？

    dp[i][j] = dp[i-1][j-1] + dp[i-j][j];

    dp[i-1][j-1]表示单独提1个小球出来，其他的随便放

    dp[i-j][j] 表示先给所有的盒子都放一个小球，剩下的小球随便放。由于盒子不为空，所以如果我们提前放入1个小球
    对于 dp[i-j][j]来说，也至少会在每一个盒子都放上1个小球，因此不存在出现只有一个盒子为1个小球的情况

    那么这样我们就可以求出最终答案了 O(n^2)
 */
void solve()
{
    int n, m;
    cin >> n >> m;

    int dp[n + 1][m + 1]{};

    //边界条件
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i > j) {
                dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
            }
            else {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    
    cout << dp[n][m] << endl;

}

signed main(int argc, char const *argv[])
{
    int t{1};
    cin >> t;
    while (t--)
    {
        solve();
    }

    system("pause");
    return 0;
}
