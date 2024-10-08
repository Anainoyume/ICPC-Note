#include <bits/stdc++.h>
using namespace std;

/* 
    �������ʵ����һ�������⣬������Ŷ������׿�������
    �ؼ������ڣ���δ��� �������븽���� �Ĺ�ϵ

    ����һ���������2�����������ǿ��Լ򵥶࿪�����������洢����

    ��ʵ����ֻҪ�� 01���� ��2�����
    ��дΪ ��Ӧ�� 5����� ����
 */

int n, k, w[65], level[65], cnt[65], dp[65][32005];
int fw[65][3], fl[65][3]; //��ʾ��i�������ĸ���

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    int money, weight, prev;
    for (int i = 1; i <= k; i++)
    {
        cin >> money >> weight >> prev; 
        if (!prev) {
            w[i] = money;
            level[i] = weight;
        }
        else {
            cnt[prev]++;
            fw[prev][cnt[prev]] = money;
            fl[prev][cnt[prev]] = weight;
        }
    }
    
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j >= w[i]) dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]]+w[i]*level[i]);
            if (j >= w[i]+fw[i][1]) dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]-fw[i][1]]+w[i]*level[i]+fw[i][1]*fl[i][1]);
            if (j >= w[i]+fw[i][2]) dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]-fw[i][2]]+w[i]*level[i]+fw[i][2]*fl[i][2]);
            if (j >= w[i]+fw[i][1]+fw[i][2]) dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]-fw[i][1]-fw[i][2]]+w[i]*level[i]+fw[i][1]*fl[i][1]+fw[i][2]*fl[i][2]);
        }
    }
    
    cout << dp[k][n] << endl;

    system("pause");
    return 0;
}
