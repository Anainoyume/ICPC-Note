//��׼��01����
#include <bits/stdc++.h>
using namespace std;

int C, n;
int c[10001], w[10001]; //c��ʾ���, w�Ǽ�ֵ
int dp[10001];

int main()
{
    cin >> C >> n;  //CΪ����������nΪ��Ʒ����

    for (int i = 1; i <= n; i++)
        cin >> c[i] >> w[i];
    
    //ʹ�ù���������пռ��Ż�
    //һ��������������һ���ܵĽ�������ұ߿�ʼ�ܵ�ǰ�ֵĽ��
    for (int i = 1; i <= n; i++)
    {
        for (int j = C; j >= c[i]; j--) //ע������Ϊʲô�� j >= c[i]
        {
            dp[j] = max(dp[j],dp[j-c[i]]+w[i]);
            /* 
                ԭ��Ӧ��Ϊ
                if (c[i] <= j)
                    dp[j] = max(dp[j],dp[j-c[i]]+w[i]);
                �������ϴ������Ҳ���ǲ�������������ֱ�Ӱ�c[i]����ѭ�����1
             */
        }
    }
    
    cout << dp[C] << endl;

    system("pause");
    return 0;
}