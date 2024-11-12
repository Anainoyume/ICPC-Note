/* 
    匈牙利算法 O(nm)
 */
#include <bits/stdc++.h>
using namespace std;
/* 
    一点笔记：
    无论是二分图的 染色算法 与 匈牙利算法
    都用到了递归的信号传递，即递归返回值为true or false

    通常暴力搜索void ，都将子树的失败情况回溯至 函数调用的 下方
    但这里的递归可以通过一种特殊的结构
    可以直接置于条件判断语句中 进行判断，

    将失配情况从 自底向上回溯 转变为了 自顶向下搜索。
 */
//Map为图，p为右边被谁选择，vis是是否已经访问过该点，N为
int Map[502][502], p[502], vis[502], S, T, n;

bool match(int i)
{
    for (int j = 1; j <= T; ++j)
    {
        if (Map[i][j] && !vis[j])   //若连通，并且被选择的那个点还未访问过
        {
            vis[j] = 1; //标记为已经访问
            if (p[j] == 0 || match(p[j]))   //两种情况，一种是还未被选择
            {                               //如果已经选择，就去修改之前的连接，如果连接可被修改，返回true
                p[j] = i;   //连接
                return true;    //可以修改，返回正确信号
            }
        }
    }
    return false;   //如果遍历完了所有的边，都没有进行连接，那么说明连接失败
}

int Hungarian()
{
    int cnt = 0;
    for (int i = 1; i <= S; ++i)    //遍历一次左边的所有点
    {
        memset(vis, 0, sizeof(vis));    //重置vis数组
        if (match(i))   //如果可匹配连接
            cnt++;      //数量加一
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

