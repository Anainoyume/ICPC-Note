/* 
    �������㷨 O(nm)
 */
#include <bits/stdc++.h>
using namespace std;
/* 
    һ��ʼǣ�
    �����Ƕ���ͼ�� Ⱦɫ�㷨 �� �������㷨
    ���õ��˵ݹ���źŴ��ݣ����ݹ鷵��ֵΪtrue or false

    ͨ����������void ������������ʧ����������� �������õ� �·�
    ������ĵݹ����ͨ��һ������Ľṹ
    ����ֱ�����������ж������ �����жϣ�

    ��ʧ������� �Ե����ϻ��� ת��Ϊ�� �Զ�����������
 */
//MapΪͼ��pΪ�ұ߱�˭ѡ��vis���Ƿ��Ѿ����ʹ��õ㣬NΪ
int Map[502][502], p[502], vis[502], S, T, n;

bool match(int i)
{
    for (int j = 1; j <= T; ++j)
    {
        if (Map[i][j] && !vis[j])   //����ͨ�����ұ�ѡ����Ǹ��㻹δ���ʹ�
        {
            vis[j] = 1; //���Ϊ�Ѿ�����
            if (p[j] == 0 || match(p[j]))   //���������һ���ǻ�δ��ѡ��
            {                               //����Ѿ�ѡ�񣬾�ȥ�޸�֮ǰ�����ӣ�������ӿɱ��޸ģ�����true
                p[j] = i;   //����
                return true;    //�����޸ģ�������ȷ�ź�
            }
        }
    }
    return false;   //��������������еıߣ���û�н������ӣ���ô˵������ʧ��
}

int Hungarian()
{
    int cnt = 0;
    for (int i = 1; i <= S; ++i)    //����һ����ߵ����е�
    {
        memset(vis, 0, sizeof(vis));    //����vis����
        if (match(i))   //�����ƥ������
            cnt++;      //������һ
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    cin >> S >> T >> n;
    int from, to;
    for (int i = 0; i < n; i++)
    {
        cin >> from >> to;
        Map[from][to] = 1;
    }
    
    int ans = Hungarian();

    for (int i = 1; i <= T; i++)
    {
        printf("Left: %d ---> Right: %d\n",p[i],i);
    }
    
    cout << ans << endl;
    
    system("pause");
    return 0;
}

