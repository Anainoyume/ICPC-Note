/* 
    Ӧ���Ѿ��� DFS �൱��Ϥ�˰ɣ�
    ����ͨ��ʹ�õݹ������� DFS ����
    ������� ����ͨ�ԡ� �ж�

    ���磺
    �����ж� . ������ͨ����  * ����ˮ��  ��ɨ�����ͼ����¼�ж��ٸ�ˮ��

    .....
    .****
    ***..
    *....
    ...**

    ���������ͨ������ͨ�����Ǽ�������ͨ��Ϊһ��ˮ��
    ������ͼ��2��ˮ��

    ����������
    ..........
    ...***....
    ....**....
    ..........
    ..........
    ......****
    *.......**
    *.........
    ***.......
    ...**.....

    4��ˮ��
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //ͼ
    char a[1000][1000];
    //ͼ�Ĵ�С�ʹ�
    int n, m, ans;
    //����ƫ����
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    void dfs(int x, int y) {
        //�����ǰΪ *
        if (a[x][y] == '*')
            a[x][y] = '.';
        //������ͨͼ������һ��Ϊx,y
        for (int i = 0; i < 4; i++)
        {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] == '*')
                dfs(xx,yy);
        }
    }
};


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    Solution sol;
    cin >> sol.n >> sol.m;
    for (int i = 0; i < sol.n; i++)
    {
        for (int j = 0; j < sol.m; j++)
        {
            cin >> sol.a[i][j];
        } 
    }
    

    for (int i = 0; i < sol.n; i++)
    {
        for (int j = 0; j < sol.m; j++)
        {
            if (sol.a[i][j] == '*') {
                sol.ans++;
                sol.dfs(i,j);
            }
        } 
    }

    cout << sol.ans << endl;
    
    
    system("pause");
    return 0;
}
