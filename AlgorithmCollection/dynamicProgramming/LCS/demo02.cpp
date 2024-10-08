/* 
    对于排列，或者元素相同，仅仅是位置不同的序列
    我们有个将 LCS 转化为 LIS 的做法

    举例：
    5 1 2 4 3
    5 2 3 4 1

    我们对
    5 1 2 4 3 进行一个标号为 a b c d e

    按照对应关系依次改变arr2数组的元素为
    a c e d b

    由于arr1标完以后一定保证为正序
    那么我们在arr2种随便取一个递增的子序列，它都一定是arr1的子序列

    那么我们求出换元以后的 arr2 的 LIS 就可以了

    实际操作的时候，
    5 1 2 4 3 对应 1 2 3 4 5 重新标号，通过这个映射关系
    我们改变arr2的值，可以使用哈希表来做到
 */
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
int n, k;
int arr[maxN];
int mp[maxN];
int sta[maxN];

int main(int argc, char const *argv[])
{
    cin >> n;
    int cur{};
    for (int i = 1; i <= n; i++)
    {
        cin >> cur;
        mp[cur] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] = mp[arr[i]];
    }

    for (int i = 0; i < n; i++)
    {
        if (k == 0 || sta[k-1] < arr[i]) {
            sta[k++] = arr[i];
        }
        else {
            int p = lower_bound(sta,sta+k,arr[i])-sta;
            sta[p] = arr[i];
        }
    }
    
    cout << k << endl;
    
    system("pause");
    return 0;
}
