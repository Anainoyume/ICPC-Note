//��׼����ȫ����
#include <bits/stdc++.h>
using namespace std;

int C, n;
int c[10001], w[10001]; //c��ʾ���, w�Ǽ�ֵ
int dp[10001][10001];

//������ȫ�����㷨
int main()
{
    cin >> C >> n;  //CΪ����������nΪ��Ʒ������ÿ����Ʒ�����޸�

    for (int i = 1; i <= n; i++)
        cin >> c[i] >> w[i];
    
    //��k����Ʒ��������������������üӸ������ʻ���01����
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= C; j++) {
            dp[i][j] = dp[i-1][j];

            for (int k = 0; k <= C/c[i]; k++) {
                if (k*w[i] <= j) {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-k*c[i]]+k*w[i]);
                }
            }
        }
    }
    
    cout << dp[n][C] << endl;

    system("pause");
    return 0;
}