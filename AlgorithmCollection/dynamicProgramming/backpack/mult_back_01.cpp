// ���ر����������Ż�
#include <bits/stdc++.h>
using namespace std;

#define N 50010

int w[N], c[N], m[N]; // ��ֵ�����������
int C, k;             // ���������Ʒ����

int new_w[N], new_c[N]; // �����Ʋ�ֵ�������
int new_n;

int dp[N];

int main(int argc, char const *argv[])
{
    cin >> k >> C;
    for (int i = 1; i <= k; i++)
        cin >> w[i] >> c[i] >> m[i];

    // �������Ż�
    /*
        �൱�ڰ�ÿһ����Ʒ�������ն����Ʋ�֣��γ��µ�new_n����Ʒ��ת��Ϊ
        0/1 ����
     */
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= m[i]; j <<= 1) // ÿ������1 *2
        {
            m[i] -= j; // ���в��
            new_c[++new_n] = j * c[i];
            new_w[new_n] = j * w[i];
        }
        if (m[i])
        { // ��������
            new_c[++new_n] = m[i] * c[i];
            new_w[new_n] = m[i] * w[i];
        }
    }

    for (int i = 1; i <= new_n; i++)
    {
        for (int j = C; j >= 1; j--)
        {
            if (new_c[i] <= j)
                dp[j] = max(dp[j], dp[j - new_c[i]] + new_w[i]);
        }
    }

    cout << dp[C] << endl;

    system("pause");
    return 0;
}
