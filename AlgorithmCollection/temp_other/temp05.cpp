#include <bits/stdc++.h>
using namespace std;

const int maxN = 35;
int n;
double m;
int ans = INT_MAX;
double arr[maxN];

struct nodeHash {
    size_t operator()(const node& n) {
        size_t a1 = hash<int>{}(n.cnt);
        size_t a2 = hash<int>{}(n.cur);
        size_t a3 = hash<double>{}(n.len);
        return a1 ^ a2 ^ a3;
    }
};

struct node
{
    int cur;
    int cnt;
    double len;
};

unordered_map<node,bool,nodeHash> vis;


signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    queue<node> que, inv;
    que.push({0,0,0});
    inv.push({n,3,m});
    while (!que.empty()) {
        node& a = que.front();
        vis[a] = true;

        if (a.len == m) {
            ans = a.cnt;
            break;
        }

        que.push({a.cur+1,a.cnt,a.len+arr[a.cur+1]});
        que.push({a.cur+1,a.cnt,a.len});
        que.push({a.cur+1,a.cnt+1,a.len+arr[a.cur+1]/2});

        que.pop();
    }

    cout << ans << endl;

    system("pause");
    return 0;
}