/* 
    ��֦��Ӧ�ã�
    ���P1433.������
 */
#include <bits/stdc++.h>
using namespace std;

int n = 0;
double ans = 0x7f7f7f7f;

double pos[16][2];
int vis[16];

void dfs(int layer, double dist, double x, double y) {
    if (layer == n) {
        ans = min(ans,dist);
        return;
    }

    if (dist > ans) //��֦
        return;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs(layer+1,dist+sqrt((pos[i][0]-x)*(pos[i][0]-x)+(pos[i][1]-y)*(pos[i][1]-y)),pos[i][0],pos[i][1]);
            vis[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pos[i][0] >> pos[i][1];

    //��ʼ����Ϊ(0,0)�����ǽ����������򣬼�ȫ��������
    dfs(0,0,0,0);

    printf("%.2lf\n",ans);

    system("pause");
    return 0;
}
