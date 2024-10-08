#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define trans(x,y) (3*(x)+(y))

const string endstr = "123804765";

int pos[9][2] = {
    {1,1},{0,0},{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{1,0}
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct node
{
    string stats;
    int x, y, step, dist;
    node() {}
    node(string s, int a, int b, int st, int d) {
        stats = s;
        x = a;
        y = b;
        step = st;
        dist = d;
    }
};

int getD(int x1, int y1, int x2, int y2) {
    return abs(x1-x2)+abs(y1-y2);
}

int manDist(const string& cur) {
    int result = 0;
    for (int i = 0; i < 8; i++) {
        int x = i/3, y = i%3;
        int c = cur[i]-'0';
        result += getD(x,y,pos[c][0],pos[c][1]);
    }
    return result;
}

struct cmp {
    bool operator()(const node& a, const node& b) {
        return a.dist+a.step > b.dist+b.step;
    }
};

signed main()
{
    string st{};
    cin >> st;
    int sx = 0, sy = 0;
    for (int i = 0; i < st.size(); i++) {
        if (st[i] == '0') {
            sx = i/3;
            sy = i%3;
            break;
        }
    }
    

    vector<node> que;
    que.push_back({st,sx,sy,0,manDist(st)});

    unordered_map<string,bool> vis;
    vis[st] = true;

    while (!que.empty()) {
        node cur = que.front();
        if (cur.stats == endstr) {
            cout << cur.step << endl;
            break;
        }

        //四种情况
        for (int i = 0; i < 4; ++i) {
            string nextStr = cur.stats;
            int tx = cur.x+dx[i];
            int ty = cur.y+dy[i];

            if (tx < 0 || tx > 2 || ty < 0 || ty > 2) continue;
            swap(nextStr[trans(cur.x,cur.y)],nextStr[trans(tx,ty)]);
        
            if (vis[nextStr] == false) {
                vis[nextStr] = true;
                node a(nextStr,tx,ty,cur.step+1,manDist(nextStr));
                que.push_back(a);
            }
        }

        que.erase(que.begin());
        sort(que.begin(),que.end(),[&](const node& a, const node& b) -> bool {
            return a.dist + a.step < b.dist + b.step;
        });
    }

    system("pause");
    return 0;
}