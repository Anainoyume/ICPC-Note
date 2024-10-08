#include <bits/stdc++.h>
using namespace std;

bool setColor() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n+1, vector<int>{});
    for (int i = 1; i <= m; ++i) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    vector<int> color(n+1, 0);

    // °Ñ u È¾É«³É col
    function<bool(int,int)> dfs = [&](int u, int col) -> bool {
        color[u] = col;
        for (auto&& to : edges[u]) {
            if (!color[to]) {
                if (!dfs(to, 3 - col)) return false;
            }
            if (color[to] == color[u]) return false;
        }
        return true;
    };

    for (int i = 1; i <= n; ++i) {
        if (!color[i]) {
            if (!dfs(i,1)) {
                return false;
            }
        }
    }
    return true;
}

int main()
{


    system("pause");
    return 0;
}