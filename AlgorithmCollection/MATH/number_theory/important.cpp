#include <bits/stdc++.h>
using namespace std;

int n;  //��ǰn�����м�������
int prime[10000];
int nums[10000];
bool vis[10000];

//ŷ��ɸ��ģ����룬ŷ��ɸ�������ܴ���һ�л��Ժ������⣬�ǳ���Ҫ��ֻ���ڴ˴����ϼ��Ա���
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
