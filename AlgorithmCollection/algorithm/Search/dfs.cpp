/* 
    应该已经对 DFS 相当熟悉了吧（
    我们通常使用递归来进行 DFS 搜索
    这里进行 “连通性” 判断

    例如：
    我们判断 . 代表普通格子  * 代表水洼  ，扫描这个图，记录有多少个水洼

    .....
    .****
    ***..
    *....
    ...**

    这里分四连通，八连通，我们假设四连通的为一个水洼
    例如上图有2个水洼

    测试用例：
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

    4个水洼
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //图
    char a[1000][1000];
    //图的大小和答案
    int n, m, ans;
    //设置偏移量
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    void dfs(int x, int y) {
        //如果当前为 *
        if (a[x][y] == '*')
            a[x][y] = '.';
        //对于连通图，参数一般为x,y
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
