/* 
    数论分块

    floor(a/(bc)) == floor(floor(a/b)/c)

    数论分块结论：
    使 floor(n/i) == floor(n/j)
    成立最大的 i <= j <= n 的 j 值为 floor(n/floor(n/i))。
    即值 floor(n/i) 所在的块的右端点为 floor(n/floor(n/i))
 */
#include <bits/stdc++.h>
using namespace std;

//       n
//计算   Σ floor(n/i)
//      i=1

int sum[10010];

//我们使用数论分块来优化
int f(int n) {
    int left = 1;   //一开始区块的左边界为left
    int ans = 0;
    while (left <= n) {
        int right = n / (n / left); //算出右端点
        ans += (sum[right] - sum[left-1]) * (n / left); //相同值*区间长度(区间函数)
        left = right + 1;   //左边界增加
    }
    return ans;
}

int main()
{
    //ceil天花板-向上取整  floor地板-向下取整
    //cout << ceil(5.3) << " " << floor(5.3) << endl;

    //C++的除法自带了一个向下取整

    int n = 0;
    int k = 0;

    // k % i = k - (k/i)*i;
    //而求解形如 (k/i)*i 的和，我们正好可以用数论分块
    cin >> n >> k;
    sum[1] = 1;
    for (int i = 2; i <= k; i++)
    {
        sum[i] = sum[i-1] + i;  //初始化和
    }
    

    cout << k*k - f(k) + (n-k)*k << endl;

    system("pause");
    return 0;
}

