#include <bits/stdc++.h>
using namespace std;

int n;  //求前n个数有几个素数
int prime[10000];
int nums[10000];
bool vis[10000];

//埃及筛算法
int EgyptSieve(int n) {
    int cnt = 0;    //素数个数
    memset(vis,0,sizeof(vis));
    for (int i = 2; i <= n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        prime[cnt++] = i;
        for (int j = 2*i; j <= n; j += i)   //条件这样写更好
            vis[j] = 1;   //素数所有倍数全部不是素数
    }
    return cnt;
}

//欧拉筛算法
int EulerSieve(int n) {
    int cnt = 0;
    memset(vis,0,sizeof(vis));
    memset(prime,0,sizeof(prime));

    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt; j++)   //遍历自然数的同时，i同时充当了 被检测数 和 质数筛选倍数 的两个身份
        {
            if (i * prime[j] > n) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
            /* 
                如果 i % prime[j] == 0;
                说明 i = prime[j] * k;  (k为整数)
                ∴ i * prime[j] = prime[j] * prime[j] * k;
                这里的 k < i; prime[j] < i;
                
                例如： 6 % 2 == 0;
                6 = 2*3;
                vis[2*2*3] = 1;
             */
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    int cnt = EgyptSieve(500);
    for (int i = 0; i < cnt; i++)
    {
        cout << prime[i] << endl;
    }
    
    

    system("pause");
    return 0;
}
