#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

#define z(x,y) (5*(x)+(y))

const int maxN = 6;

int dx[8] = {-1,-1,1,1,-2,-2,2,2};
int dy[8] = {-2,2,-2,2,-1,1,-1,1};

struct node 
{
    string stats;
    int x, y, step, dist;
    node(string s, int a, int b, int st, int di) {
        stats = s;
        x = a;
        y = b;
        step = st;
        dist = di;
    }
};

void print(const node& n) {
    const string& s = n.stats;
    cout << "---" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1') cout << "¡ö";
        if (s[i] == '*') cout << "_";
        if (s[i] == '0') cout << "¡õ";
        if ((i+1)%5 == 0) cout << endl;
    }
    cout << "step: " << n.step << " dist: " << n.dist << endl;
    cout << "---" << endl;
}

int cal(string stats) {
    int result = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0 && stats[z(i,j)] == '1') result += 1;
            if (i == 1 && ((j == 0 && stats[z(i,j)] == '0') || (j >= 1 && stats[z(i,j)] == '1'))) result += 1;
            if (i == 2 && ((j <= 1 && stats[z(i,j)] == '0') || (j >= 3 && stats[z(i,j)] == '1'))) result += 1;
            if (i == 3 && ((j <= 3 && stats[z(i,j)] == '0') || (j == 4 && stats[z(i,j)] == '1'))) result += 1;
            if (i == 4 && stats[z(i,j)] == '0') result += 1;
        }
    }
    return result;
}

void solve()
{
    int sx, sy;
    string line[5];
    for (int i = 0; i < 5; i++) {
        cin >> line[i];
        for (int j = 0; j < 5; j++) {
            if (line[i][j] == '*') {
                sx = i;
                sy = j;
            }
        }   
    }

    string str = line[0]+line[1]+line[2]+line[3]+line[4];

    unordered_map<string,bool> vis;
    
    node st(str,sx,sy,0,cal(str));
    vis[str] = true;
    vector<node> que;
    que.push_back(st);

    int res = 3700;

    while (!que.empty()) {
        res -= 1;
        node cur = que.front();
        //print(cur);
        if (res == 0) break;
        if (cur.step > 15) break;
        if (cur.dist == 24) {
            cout << cur.step << endl;
            return;
        }
    
        for (int i = 0; i < 8; i++)
        {
            int tx = cur.x+dx[i];
            int ty = cur.y+dy[i];
            if (tx < 0 || tx > 4 || ty < 0 || ty > 4) continue;
            
            string nextstr = cur.stats;
            swap(nextstr[z(cur.x,cur.y)],nextstr[z(tx,ty)]);

            if (vis[nextstr] == false) {
                vis[nextstr] = true;
                node n(nextstr,tx,ty,cur.step+1,cal(nextstr));
                que.push_back(n);
            }
        }
        que.erase(que.begin());
        sort(que.begin(),que.end(),[&](node& a, node& b) -> bool {
            return 24-a.dist+a.step < 24-b.dist+b.step;
        });
    }
    
    cout << -1 << endl;
}

signed main()
{
    int t{};
    cin >> t;
    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}