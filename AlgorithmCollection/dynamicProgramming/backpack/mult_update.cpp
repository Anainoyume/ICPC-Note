/* 
    ���ر������������Ż�
 */
//���ر��� ʱ���Ż�+�ռ��Ż�
#include <bits/stdc++.h>
using namespace std;

int C, n;
int c[10001], w[10001]; //c��ʾ���, w�Ǽ�ֵ
int dp[10001];

int main()
{
    cin >> C >> n;  //CΪ����������nΪ��Ʒ������ÿ����Ʒ�����޸�

    for (int i = 1; i <= n; i++)
        cin >> c[i] >> w[i];
    
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = c[i]; j <= C; j++)
        {
            dp[j] = max(dp[j],dp[j-c[i]]+w[i]);  //ʽ�ӿ����Ƶ�
        }
    }
    
    cout << dp[C] << endl;

    system("pause");
    return 0;
}