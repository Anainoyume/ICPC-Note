//��׼����ȫ����
#include <bits/stdc++.h>
using namespace std;

int C, n;
int c[10001], w[10001]; //c��ʾ���, w�Ǽ�ֵ
int dp[10001];

//�������� �Ż� ��ȫ����
int main()
{
    cin >> C >> n;  //CΪ����������nΪ��Ʒ������ÿ����Ʒ�����޸�

    for (int i = 1; i <= n; i++)
        cin >> c[i] >> w[i];
    
    //�������飬ѹά�Ż�
    for (int i = 1; i <= n; i++)
    {
        for (int j = C; j >= 1; j--)
        {
            for (int k = 0; k <= C/c[i]; k++)
            {
                dp[j] = max(dp[j],dp[j-k*c[i]]+k*w[i]);
            }
        }
    }
    
    cout << dp[C] << endl;

    system("pause");
    return 0;
}