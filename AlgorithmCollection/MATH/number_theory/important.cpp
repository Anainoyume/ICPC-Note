#include <bits/stdc++.h>
using namespace std;

int n;  //求前n个数有几个素数
int prime[10000];
int nums[10000];
bool vis[10000];

//欧拉筛的模板代码，欧拉筛基本上能处理一切积性函数问题，非常重要，只是在此代码上加以变形
int EulerSieve(int n) {
    int cnt = 0;
    memset(vis,0,sizeof(vis));
    memset(prime,0,sizeof(prime));

    for (int i = 2; i <= n; i++) {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt; j++) {
            if (i * prime[j] > n) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    

    system("pause");
    return 0;
}
