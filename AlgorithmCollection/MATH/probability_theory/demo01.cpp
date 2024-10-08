/* 
    ����dp
 */
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
        //����� i < j ʱ���Ϊ0�����ÿ���
        //��Ϊ������ֻ��2��ȴ����3ö����
        for (int j = 0; j < n; j++)
        {
            dp[i+1][j+1] += 0.5*dp[i][j];
            dp[i+1][j] += 0.5*dp[i][j];
        }
        //ѭ�������Ժ��ʱ j == n
        dp[i+1][n] += 0.5*dp[i][n];
        dp[i+1][n-1] += 0.5*dp[i][n];
        //������� n+1 ���������Ϊ���ֻ��nö
    }
    
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += i*dp[k][i];
    }
    
    printf("%.6lf\n",ans);  //����6λС��
    
    system("pause");
    return 0;
}


