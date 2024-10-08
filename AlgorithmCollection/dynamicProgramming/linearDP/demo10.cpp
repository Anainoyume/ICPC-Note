#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/* 
    ��Ŀ���ӣ�https://www.luogu.com.cn/problem/P1435
    �����ִ�
 */

//����������������һ���Ǳ༭���������
void solve1()
{
    string str{};
    cin >> str;
    int len = str.size();

    int dp[len+5][len+5]{};
    // dp[i][j] ��ʾ str��i��jת���ɻ��Ĵ���Ҫ�����ַ�

    for (int i = len; i >= 1; i--)
    {
        for (int j = i; j <= len; j++)  //ע�⻭ͼ����ת�Ʒ���
        {
            if (i == j) dp[i][j] = 0;
            if (str[i-1] == str[j-1]) {
                dp[i][j] = dp[i+1][j-1];
            }
            else {
                dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;
            }
        }
    }
    cout << dp[1][len] << endl;
}


//���������������
/* 
    ��Ȼ���Ĵ����ص������Ŷ����Ŷ�һ������ô���ǿ����ȷ����ַ�����
    �ٽ������ַ�����������������е�ƥ�䡣
    ûƥ���ϵ��ַ���Ȼ���Ǹ��Բ�һ����ĸ���ɡ�
 */
void solve2()
{
    string s1{};
    cin >> s1;
    string s2{s1};
    reverse(s2.begin(),s2.end());

    int len = s1.size();
    int dp[len+1][len+1]{};

    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    cout << len - dp[len][len] << endl;

}

int main()
{
    solve2();
    
    system("pause");
    return 0;
}