#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;

struct Node
{
    int data{}, inDeg{};
    bool vis = false;
};

struct Edge
{
    int to;
};


int n;
vector<Edge> edges[maxN];
Node nodes[maxN];

int ans;

void solve()
{
    vector<int> temp;

    do
    {
        if (!temp.empty()) temp.erase(temp.begin());
        for (int i = 1; i <= n; i++)
        {
            if ((!nodes[i].vis) && nodes[i].inDeg == 0)
            {
                temp.push_back(i);
                nodes[i].vis = true;
            }
        }

        sort(temp.begin(), temp.end(), [](int a, int b)
             { return nodes[a].data < nodes[b].data; });

        int cur = temp.front();
        int minus = nodes[cur].data;
        
        for (auto &&edge : edges[cur])
        {
            nodes[edge.to].inDeg--;
        }
        
        ans += minus;
        for (auto &&it : temp)
        {
            nodes[it].data -= minus;
        }

    } while (!temp.empty());

}

int main(int argc, char const *argv[])
{
    cin >> n;
    int t = n;
    while (t--)
    {
        int from{};
        cin >> from;
        cin >> nodes[from].data;
        int to{};
        cin >> to;
        while (to)
        {
            edges[to].push_back({from});
            nodes[from].inDeg += 1;
            cin >> to;
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << nodes[i].inDeg << " \n"[i == n];
    // }
    
    solve();

    cout << ans << endl;

    system("pause");
    return 0;
}
