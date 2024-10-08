#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;

struct Edge {
    int to, weight;
};

const int maxN = 105;

int last[maxN];
int tempDis[maxN];
vector<Edge> edges[maxN];
unordered_map<string,int> mp;

int main()
{
    int n, m;
    cin >> n >> m;

    fill(tempDis,tempDis+maxN,INT_MAX);
    for (int i = 1; i <= n; ++i) {
        string sign = "A";
        sign += 'A'+i-1;
        mp[sign] = i;

        last[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        string _from, _to;
        int weight;
        cin >> _from >> _to >> weight;
        int from = mp[_from], to = mp[_to];
        edges[from].push_back({to,weight});
    }

    string _st, _ed;
    cin >> _st >> _ed;
    int st = mp[_st], ed = mp[_ed];

    priority_queue<PII,vector<PII>,greater<PII>> heap;
    tempDis[st] = 0;
    heap.push({0,st}); 

    while (!heap.empty()) {
        int dis = heap.top().first, cur = heap.top().second;
        heap.pop();

        for (int i = 0; i < edges[cur].size(); ++i) {
            int to = edges[cur][i].to, weight = edges[cur][i].weight;
            if (dis+weight < tempDis[to]) {
                last[to] = cur;
                tempDis[to] = dis+weight;
                heap.push({tempDis[to],to});
            }
        }
    }

    auto print = [&](auto self, int cur) -> void {
        if (last[cur] == cur) {
            string tmp = "A";
            tmp += 'A'+cur-1;
            cout << tmp;
            if (cur != ed) cout << " "; 
            return;
        }
        self(self,last[cur]);
        string tmp = "A";
        tmp += 'A'+cur-1;
        cout << tmp;
        if (cur != ed) cout << " "; 
        return;
    };

    print(print,ed);
    cout << endl;
    cout << tempDis[ed] << endl;

    /* 
        6 8
        AA AB 0
        AA AC 5
        AA AF 20
        AB AD 15
        AB AE 20
        AC AD 30
        AC AE 35
        AD AF 20
     */

    system("pause");
    return 0;
}

