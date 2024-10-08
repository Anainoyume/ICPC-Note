#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int maxN = 105;

struct Edge
{
    int to = 1, weight = 1;
};

vector<Edge> edges[maxN];
int inDeg[maxN];

class cmp {
public:
    bool operator()(int a, int b) {
        return inDeg[a] > inDeg[b];
    }
};

signed main()
{
    int n = 0;
    cin >> n;

    for (int from = 1; from <= n; from++) {
        int to = 1;
        while (to) {
            cin >> to;
            if (to == 0) break;
            edges[from].push_back({to,1});
            inDeg[to] += 1;
        }
    }

    priority_queue<int,vector<int>,cmp> heap;
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0) heap.push(i);
    }
    
    while (!heap.empty()) {
        int cur = heap.top();
        heap.pop();

        cout << cur << " ";
        for (auto&& [to, weight] : edges[cur]) {
            inDeg[to] -= 1;
            if (inDeg[to] == 0) heap.push(to);
        }
    }
    cout << endl;

    system("pause");
    return 0;
}