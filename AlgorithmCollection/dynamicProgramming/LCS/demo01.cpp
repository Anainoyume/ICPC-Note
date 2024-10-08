#include <bits/stdc++.h>
using namespace std;

/* 
    ��������������� (LCS)
 */

const int maxN = 1e4+5;
int n;
int arr1[maxN], arr2[maxN];
int dp[maxN][maxN];

int main()
{
    cin >> n;
    int m = n;
    for (int i = 1; i <= n; i++)
        cin >> arr1[i];
    
    for (int i = 1; i <= m; i++)
        cin >> arr2[i];

    //�����������
    /* 
        ���ǿ������һ�� dp[i][j] ��ʾ��a[]ǰi��Ԫ�ص������� �� arr2[]ǰj��Ԫ�ص������� �����������

        ����:  9 8 1 2 7 4
               1 3 2 8 7 4

        ���Զ�ѡ�� [1 2 7 4]  len = 4;

        ��ô

        if (arr1[i] == arr2[j]) dp[i][j] = dp[i-1][j-1]+1;
        
        else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
     */    

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr1[i] == arr2[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    cout << dp[n][m] << endl;

    system("pause");
    return 0;
}