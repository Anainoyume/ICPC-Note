/*
    ����demo01.cpp��dp�ⷨ
 */
#include <bits/stdc++.h>
using namespace std;

const int maxN = 25;
int n;
int nodes[maxN];
bool g[maxN][maxN];
int dp[maxN];
int last[maxN];
int ans, k;

void print(int i) {
    if (i == 0) return;
    print(last[i]);
    cout << i << " ";
    if (i == k) cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i];
        dp[i] = nodes[i];
    }
    
    for (int i = 1; i <= n-1; i++)
        for (int j = i+1; j <= n; j++)
            cin >> g[i][j];
        
    // �ⷨ�ο����ͣ�https://blog.csdn.net/sai_2021/article/details/119788912
    /* 
        ���ķǳ��ĺá�

        ��������������˵˵�����ڵĹ۵㣨By the way��������ʱ״̬�ر�ã�
        ��������Ҫ����һ���£�
        ���⣬��������ͼ��ʵ����������

        ����dp ��������

        ��������Ȼ���ӽṹ���޺�Ч�ԣ�����Ȼ��Ȼ��dp
        
        ��������Ҫ�����������������ͼ��ͼ������ǰ�ߵĿ����ԡ�������������ṹ��
        ��������һֱ��������Ҷ�ӽڵ㣬�������dp�Ϳ����ˡ�
     */

    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (g[i][j] && dp[i]+nodes[j] > dp[j]) {
                dp[j] = dp[i]+nodes[j];
                last[j] = i;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > ans) {
            ans = dp[i];
            k = i;
        }
    }
    
    print(k);
    cout << ans << endl;

    system("pause");
    return 0;
}