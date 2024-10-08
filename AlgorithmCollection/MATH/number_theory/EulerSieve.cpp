#include <bits/stdc++.h>
using namespace std;

int n;  //��ǰn�����м�������
int prime[10000];
int nums[10000];
bool vis[10000];

//����ɸ�㷨
int EgyptSieve(int n) {
    int cnt = 0;    //��������
    memset(vis,0,sizeof(vis));
    for (int i = 2; i <= n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        prime[cnt++] = i;
        for (int j = 2*i; j <= n; j += i)   //��������д����
            vis[j] = 1;   //�������б���ȫ����������
    }
    return cnt;
}

//ŷ��ɸ�㷨
int EulerSieve(int n) {
    int cnt = 0;
    memset(vis,0,sizeof(vis));
    memset(prime,0,sizeof(prime));

    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt; j++)   //������Ȼ����ͬʱ��iͬʱ�䵱�� ������� �� ����ɸѡ���� ���������
        {
            if (i * prime[j] > n) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
            /* 
                ��� i % prime[j] == 0;
                ˵�� i = prime[j] * k;  (kΪ����)
                �� i * prime[j] = prime[j] * prime[j] * k;
                ����� k < i; prime[j] < i;
                
                ���磺 6 % 2 == 0;
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
