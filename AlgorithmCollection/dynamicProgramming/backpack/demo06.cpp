/* 
    折半背包思想：
    例如一个数组，要将其划分为两个部分，两个部分的和要尽量接近。
    可以设置一个体积为一半，然后使用背包，将其尽可能多得装进背包里
 */
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr{0,1,2,3,4,5,6,39,10,10,10,10,10,5,5};
    int sum{}, cur{};
    for (auto &&num : arr)
        sum += num;
    
    int sz = arr.size();
    int v = sum/2;
    int dp[sz+1][v+1]{};

    for (int i = 1; i < sz; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            if (j < arr[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i]]+arr[i]);
        }
    }
    
    cout << dp[sz-1][sum/2] << " " << sum-dp[sz-1][sum/2] << endl;

    system("pause");
    return 0;
}
