// 稀疏表 ST表
/*
    shift + alt + A 放置多行注释内容
    shift + alt + F 自动对齐
    shift + del 删除一行
 */
/*
    问题：
    给定一个数组arr[n]，现在进行m次查找，每次都寻找区间[L,R]中的最值（以最大值为例）

    我们显然可以使用暴力解法，时间复杂度为O(nm)

    但如果我们n非常小，但是查询m次数非常大时，必然会出现许多重复情况
    我们需要充分利用我们的结果
    考虑使用动态规划
    dp[i][j] 表示[i,j]的最大值 dp[i][i] = arr[i];
    dp[i][j] = max(dp[i][j-1],arr[j]);

    这样便得到了一个递推式，时间复杂度，预处理为O(n?)
    当n < m时，会有明显优化

    然而当n很大的时候呢？显然又不行了，无论时间空间都会有很大的压力

    这时候我们就可以考虑ST表，利用二分思想（倍增思想）
    例如我们要求[0,x]的最值
    我们将区间一分为二[0,x/2]  [x/2,x]，分别再求区间最大值，并且比较
    求[0,x/2] [x/2,x]进行递归处理即可

    如果这样一直分下去。
    因此，我们就有了稀疏表(ST表)

    st[i][j] 的含义为，从i开始，区间长度为2^j的区间中的最大值

 */
#include "head.h"
using namespace std;

// 取对数log2算法
int log2(int num)
{
    int ans = 0;
    while (num >>= 1)
        ans++;
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 5, 54, 12, 13, 2, 76, 23, 4, 123, 23, 99, 34, 72, 42};
    vector<vector<int>> st(nums.size());

    for (int i = 0; i < st.size(); i++)
    {
        st[i].resize(4);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        st[i][0] = nums[i];
    }

    for (int j = 1; j < 4; j++)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + (1 << j) < nums.size())
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    // for (auto vec : st)
    // {
    //     for (int num : vec)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    // 而我们在使用ST进行查询的时候
    /*
        我们固然可以考虑将长度拆分为二进制之和
        例如 13 = 8 + 4 + 1
        但没有必要

        求最大值的区间是可以相交的
        例如我们要查找[4,13]
        我们完全可以查找[4,11]与[10,13]
        也就是st[4][3]和st[10][2]
        这样就不必拆分，而是两步到位
     */

    int m, L, R = 0;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> L >> R;
        int len = R - L + 1;
        int eps = log2(len);

        //只需要1次比较即可
        cout << max(st[L][eps],st[R-(1 << eps)+1][eps]) << endl;

    }

    system("pause");
    return 0;
}
