/* 
    ��������к�

    һ�����д��� ���������� �ҳ�������е����������кͣ�Ҫ������������
 */
#include <bits/stdc++.h>
using namespace std;

//�������������
int n, nums[10010], dp[10010];
/* 
    dp����ĺ��壺��i��β����������к�
    ��˵����Ǽ���dp[i]��ʱ��
    �����Ѿ�֪��
    dp[i-1]�Ľ��

    ��˷����������Ҫô����dp[i-1]�Ľ�����ӳ����У�Ҫô�����кͻ�����nums[i]��ǰһ�����ִ�
    ����ȡ���ߵ����ֵ

    dp[i] = max(dp[i-1]+nums[i],nums[i]);

    ��ʵ����������Ʊ��ʽ��д������Ѿ���ѹ����
 */

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    dp[0] = nums[0];
    int ans = dp[0];
    for (int i = 0; i < n; i++) //ʱ�临�Ӷ�Ϊ O(n)
    {
        dp[i] = max(dp[i-1]+nums[i],nums[i]);
        ans = max(ans,dp[i]);
    }
    
    cout << ans << endl;
}

int main()
{
    int t = 0;
    cin >> t;

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}