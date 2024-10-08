### ��̬�滮dp �ʼǺϼ�
��¼˳�����⣬��Ҫ�Ǽ�¼��಻ͬ�����ͣ���ά���Լ����㷨˼�룬��ס��**ѧϰ�ߣ�ϰ˼����Ϊ��**

**1. P1164 СA��� (���)**
������к����Ե�һ������������"�����ַ���"��"���������"����ѡȡ��Ʒ�������������������
���Ǻ�������һ�����仯������д����
```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxN = 105;
int n, m, w[maxN], dp[maxN][1005];

int dfs(int cur, int sum) {
    if (dp[cur][sum]) return dp[cur][sum];

    if (sum > m) return 0;

    if (cur > n) {
        if (sum == m) return 1;
        else return 0;
    }
    //��ǰ����ˣ�ѡ���߲�ѡ
    dp[cur][sum] = dfs(cur+1,sum) + dfs(cur+1,sum+w[cur]);
    return dp[cur][sum];
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    
    int ans = dfs(1,0);

    cout << ans << endl;

    system("pause");
    return 0;
}
```
д���仯�����Ĺؼ����������� **�����״ͼ** ����ʵ����һ�ü�¼�Ÿ�����������������������һЩֽ�������ظ����֡�����ʹ����������¼���������´��������ظ����ֱ�ӷ��أ�

**dp������**
˵��dp���ص����ڣ�dp�������ƣ�״̬ת�Ʒ��̡�
����ץס�Ǹ���Ƶĵ㣬�Ϳ��Ժܼ򵥵�д�����롣
�����dp�����ʾ��**ǰi����Ʒǡ�ôճ�jԪ�������**
```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[105][1005], w[105];
//dp[i][j]��ʾǰi����Ʒǡ�ôճ�jԪ�������

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        dp[i][0] = 1;
    }
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            //��ѡ
            dp[i][j] += dp[i-1][j];
            //ѡ
            if (j >= w[i]) dp[i][j] += dp[i-1][j-w[i]];
        } 
    }
    
    cout << dp[n][m] << endl;

    system("pause");
    return 0;
}
```
<br>

**2. P1077 [NOIP2012 �ռ���] �ڻ� (���)**
��һ����������⼸����ȫһ�£�Ψһ��ͬ������Ʒ������һ�������Ǻܶ�����������������ƣ��������һ������ر������⡣�����Ǽ������**�����**.
```cpp
#include <bits/stdc++.h>
using namespace std;

const int md = 1e6+7;
int n, m;
int dp[105][105], cnt[105];
//dp[i][j]��ʾǰi����Ʒǡ�ôճ�jԪ�������

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i];
        dp[i][0] = 1;
    }
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] += dp[i-1][j] % md;    //ע�ⲻѡ�����ֻ����һ��
            for (int k = 1; k <= cnt[i]; k++)
            {
                if (j >= k) dp[i][j] += dp[i-1][j-k] % md;
            }
        } 
    }
    
    cout << dp[n][m] % md << endl;

    system("pause");
    return 0;
}
```
<br>

**3. P2392 kkksc03��ǰ��ʱ�����**
�۰뱳��˼�룺
����һ�����飬Ҫ���仮��Ϊ�������֣��������ֵĺ�Ҫ�����ӽ���
��������һ�����Ϊһ�룬Ȼ��ʹ�ñ��������価���ܶ��װ�������
�����Ͱ���һ���ֻ��ֳ����ˡ�
```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxN = 25;
int n;
int arr[maxN];
int dp[1205];
int cnt[4];

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 4; i++)
        cin >> cnt[i];
    
    int ans{};
    for (int i = 0; i < 4; i++)
    {
        int cur = cnt[i];
        int sum{};
        fill(begin(arr),end(arr),0);
        fill(begin(dp),end(dp),0);
        //�۰����
        for (int j = 1; j <= cur; j++) {
            cin >> arr[j];
            sum += arr[j];
        }
        
        for (int m = 1; m <= cur; m++)
        {
            for (int v = sum/2; v >= 0; v--)
            {
                if (v >= arr[m]) dp[v] = max(dp[v],dp[v-arr[m]]+arr[m]);
            }
        }
        
        ans += max(dp[sum/2],sum-dp[sum/2]);
    }
    
    cout << ans << endl;

    system("pause");
    return 0;
}
```