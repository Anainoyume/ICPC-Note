#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
//#define int long long
#define endl '\n'

#define up 0
#define right 1
#define down 2
#define left 3

const int md = 1e9+7;
const int maxN = 55;
const int maxM = 55;

int n, m;

struct node {
    int x, y, step = 0, dirt = 0; //顺时针,初始为上
};

struct pos {
    bool wall[4] = {0,0,0,0};   //方向上是否有墙
    bool vis[4] = {0,0,0,0};    //每个方向上的访问情况
    bool curPos = true;
    int first_step[4] = {INT_MAX,INT_MAX,INT_MAX,INT_MAX}; //记录最小到达的step
};

pos mp[maxN][maxN];

string tran(int dirt) {
    if (dirt == up) return "上";
    if (dirt == right) return "右";
    if (dirt == down) return "下";
    if (dirt == left) return "左";
    return "\0";
}

void setwall(int x, int y, bool iswall) {
    mp[x][y].wall[right] = mp[x][y].wall[right] ? true : iswall;
    mp[x][y].wall[down] = mp[x][y].wall[down] ? true : iswall;

    mp[x+1][y].wall[right] = mp[x+1][y].wall[right] ? true : iswall;
    mp[x+1][y].wall[up] = mp[x+1][y].wall[up] ? true : iswall;

    mp[x][y+1].wall[left] = mp[x][y+1].wall[left] ? true : iswall;
    mp[x][y+1].wall[down] = mp[x][y+1].wall[down] ? true : iswall;

    mp[x+1][y+1].wall[up] = mp[x+1][y+1].wall[up] ? true : iswall;
    mp[x+1][y+1].wall[left] = mp[x+1][y+1].wall[left] ? true : iswall;

    if (iswall) {
        mp[x][y].curPos = false;
        mp[x+1][y].curPos = false;
        mp[x][y+1].curPos = false;
        mp[x+1][y+1].curPos = false;
    }
}

void nextPos(int x, int y, int dirt, int road, int& nx, int& ny) {
    nx = x, ny = y;
    if (dirt == 0) nx -= road;
    if (dirt == 1) ny += road;
    if (dirt == 2) nx += road;
    if (dirt == 3) ny -= road;
    //判断是否越界
    if (nx <= 1 || nx >= n+1 || ny <= 1 || ny >= m+1) {
        nx = -1;
        ny = -1;
    }
}

int mhd_s(int sx, int sy, int ex, int ey) {
    return abs(sx-ex)+abs(sy-ey);
}

int st_x, st_y, end_x, end_y, dir;

struct cmp
{
    bool operator()(node& a, node& b) {
        return ((a.step+mhd_s(a.x,a.y,end_x,end_y)) < (b.step+mhd_s(b.x,b.y,end_x,end_y)));
    }
};


void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            bool wall = false;
            cin >> wall;
            setwall(i,j,wall);
        }
    }

    // for (int i = 1; i <= n+1; i++)
    // {
    //     for (int j = 1; j <= m+1; j++)
    //     {
    //         if (mp[i][j].wall[right] && mp[i][j].wall[down]) cout << "┌ ";
    //         else if (mp[i][j].wall[right] && mp[i][j].wall[up]) cout << "└ ";
    //         else if (mp[i][j].wall[left] && mp[i][j].wall[down]) cout << "┐ ";
    //         else if (mp[i][j].wall[left] && mp[i][j].wall[up]) cout << "┘ ";
    //         else cout << "+ ";
    //     }
    //     cout << endl;
    // }
    
    // 这题不能 A* 因为转向也算一次step
    //priority_queue<node,vector<node>,cmp> que;
    queue<node> que;
    
    char dir_;
    cin >> st_x >> st_y >> end_x >> end_y >> dir_;
    st_x += 1;
    st_y += 1;
    end_x += 1;
    end_y += 1;

    if (mp[st_x][st_y].curPos == false || mp[end_x][end_y].curPos == false) {
        cout << -1 << endl;
        return;
    }

    if (dir_ == 'N') dir = up;
    if (dir_ == 'E') dir = right;
    if (dir_ == 'S') dir = down;
    if (dir_ == 'W') dir = left;

    que.push({st_x,st_y,0,dir});
    while (!que.empty()) {
        node cur = que.front();

        cout << format("x:{}, y:{}, 朝向:{}, 步数:{}\n",cur.x,cur.y,tran(cur.dirt),cur.step);

        if (cur.x == end_x && cur.y == end_y) {
            cout << cur.step << endl;
            return;
        }
        else {
            int curdir = cur.dirt; //当前朝向
            //往前走一格
            int go1x = 0, go1y = 0;
            nextPos(cur.x,cur.y,curdir,1,go1x,go1y);
            if (go1x != -1 && go1y != -1 && mp[go1x][go1y].vis[curdir] == false && mp[cur.x][cur.y].wall[curdir] == false && mp[go1x][go1y].curPos) {
                mp[go1x][go1y].vis[curdir] = true;
                que.push({go1x,go1y,cur.step+1,cur.dirt});
            }

            //往前走两格
            int go2x = 0, go2y = 0;
            nextPos(cur.x,cur.y,curdir,2,go2x,go2y);
            if (go2x != -1 && go2y != -1 && mp[go2x][go2y].vis[curdir] == false && mp[cur.x][cur.y].wall[curdir] == false && mp[go1x][go1y].wall[curdir] == false && mp[go2x][go2y].curPos) {
                mp[go2x][go2y].vis[curdir] = true;
                que.push({go2x,go2y,cur.step+1,cur.dirt});
            }

            //往前走三格
            int go3x = 0, go3y = 0;
            nextPos(cur.x,cur.y,curdir,3,go3x,go3y);
            if (go3x != -1 && go3y != -1 && mp[go3x][go3y].vis[curdir] == false && mp[cur.x][cur.y].wall[curdir] == false && mp[go1x][go1y].wall[curdir] == false && mp[go2x][go2y].wall[curdir] == false && mp[go3x][go3y].curPos) {
                mp[go3x][go3y].vis[curdir] = true;
                que.push({go3x,go3y,cur.step+1,cur.dirt});
            }

            //左转1次
            int leftDir1 = (curdir - 1 < 0) ? (curdir -1 + 4) : curdir-1;
            if (mp[cur.x][cur.y].vis[leftDir1] == false) {
                mp[cur.x][cur.y].vis[leftDir1] = true;
                que.push({cur.x,cur.y,cur.step+1,leftDir1});
            }

            //右转1次
            int rightDir1 = (curdir+1)%4;
            if (mp[cur.x][cur.y].vis[rightDir1] == false) {
                mp[cur.x][cur.y].vis[rightDir1] = true;
                que.push({cur.x,cur.y,cur.step+1,rightDir1});
            }
        }
        que.pop();
    }

    cout << -1 << endl;

}

signed main(int argc, char const *argv[])
{
    int t{1};
    //cin >> t;
    while (t--) {
        solve();
    }
    
    system("pause");
    return 0;
}
