#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;
int g[maxN][maxN];
bool vis[maxN][maxN];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int n,m,ans;

void dfs(int x, int y, int acc) {
    for (int i = 0; i < 4; i++)
    {
        int tx = x+dx[i];
        int ty = y+dy[i];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= n) {
            if (g[tx][ty] > g[x][y]) {
                dfs(tx,ty,acc+1);
            }
        }
    }
    ans = max(ans,acc);
}

int main()
{
    cin >> n >> m;
    int time{}, x{}, y{};
    for (int i = 0; i < m; i++)
    {
        cin >> time >> x >> y;
        g[x][y] = time;
    }

    
    
    

    system("pause");
    return 0;
}