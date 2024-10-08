/* 
    ��dp[i][j]��ʾ��word1��ǰi���ַ�ת����word2��ǰj���ַ�����С����������
    ���ȿ������ּ򵥵�������������Կ��ַ�����ת����ת���ɿ��ַ���ʱ��

    dp[0][j] = j;
    dp[i][0] = i;

    Ȼ�����ͨ����������������Ѿ�֪��dp[i-1][j-1]��ͬ���ֳ����ֽ��п��ǣ�
    ��word1[i-1] == word2[j-1]ʱ�� ��dp[i-1][j-1]�Ļ����ϣ� ������Ҫ���в�������dp[i][j] = dp[i-1][j-1]
    ��word1[i-1] != word2[j-1]ʱ�����ܽ��еĲ����в��룬ɾ�����滻���֣�������������ۣ�

    ���룺���������Ѿ�֪��dp[i][j-1]�����ַ���word1[0...i-1]��ת����word2[0...j-2]��
    ��ôֻ��Ҫ��word1[0...i-1]�������word2[j-1]���ɣ�����dp[i][j] = dp[i][j-1] + 1;

    ɾ�������Ƶأ� dp[i][j] = dp[i-1][j] + 1;

    �滻�����Ƶأ�dp[i][j] = dp[i-1][j-1] + 1;
    ����Ϊֹ���Ѿ��ҵ��˽���������������״̬ת�Ʒ��̣��Ϳ�����dp����ˡ�

 */
#include <bits/stdc++.h>
using namespace std;
int word_change(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int i = 1; i <= m; i++)
        dp[0][i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1]) // ״̬ת�Ʒ��̣�����һ����ͨ�ĵ㣬���з�������״̬���ܣ�
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
        }
    }
    return dp[n][m];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << word_change(s1, s2) << endl;
    ;
}