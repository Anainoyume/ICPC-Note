/* 
    �۰뱳��˼�룺
    ����һ�����飬Ҫ���仮��Ϊ�������֣��������ֵĺ�Ҫ�����ӽ���
    ��������һ�����Ϊһ�룬Ȼ��ʹ�ñ��������価���ܶ��װ��������
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
