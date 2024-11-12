#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 105;
const int M = 5005;
const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f3f3f3f3f;

// ����, ����, Դ��, ���
int n, m, s, t, idx;
int deep[N], cur[N], head[N]; // ��ȣ���ǰ�ߣ�ǰ����ͷ

struct edge {
    int to, cap, next;
    bool rev;   // �Ƿ�Ϊ�����
} edges[M << 1];

// from, to, cap
// head �� u ���һ���߱��, next ����ǰ����
inline void add(int u, int v, int c, bool r) {
    edges[idx] = {v, c, head[u], r};
    head[u] = idx++;
}

inline void addedge(int from, int to, int cap) {
    add(from, to, cap, false);
    add(to, from, 0, true);
}

// ��·���㣬�ֲ������Ż�
bool bfs() {
    memset(deep, 0, sizeof(deep));

    queue<int> q;
    q.push(s), deep[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = edges[i].next) {
            int v = edges[i].to;
            if (!deep[v] && edges[i].cap) {
                deep[v] = deep[u] + 1;
                q.push(v);

                if (v == t) return true;
            }
        }
    }
    return false;
}

int dfs(int u, int limit) {
    if (u == t) return limit;
    
    int ret = 0;
    for (int i = cur[u]; ~i && limit > 0 ; i = edges[i].next) {
        cur[u] = i;// ��ǰ���Ż�
        int v = edges[i].to;

        if (deep[v] == deep[u] + 1 && edges[i].cap) {
            int incf = dfs(v, min(limit, edges[i].cap));
            if (!incf) deep[v] = 0; //��֦�Ż�

            edges[i].cap -= incf;
            edges[i ^ 1].cap += incf;
            
            ret += incf;
            limit -= incf;
        }
    }
    return ret;
}

int dinic() {
    int ret = 0;
    while (bfs())
        memcpy(cur, head, sizeof(head)), ret += dfs(s, inf);
    return ret;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ��ʼ��Ϊ -1
    memset(head, -1, sizeof(head));

    cin >> m >> n;
    int from, to;

    while (true) {
        cin >> from >> to;
        addedge(from, to, 1);

        if (from == -1 && to == -1) break;
    }

    for (int i = 1; i <= n; ++i) {
        if (i <= m) {
            addedge(n+1, i, 1);
        }
        else {
            addedge(i, n+2, 1);
        }
    }

    // Դ�� s - ��� t
    s = n+1;
    t = n+2;
    
    int cnt = dinic();
    cout << cnt << endl;
    for (int i = 1; i <= m; ++i) {
        for (int j = head[i]; ~j; j = edges[j].next) {
            int cap = edges[j].cap;
            bool rev = edges[j].rev;
            if (cap == 0 && !rev) {
                cout << i << " " << edges[j].to << endl;
                break;
            }
        }
    }

    return 0;
}
