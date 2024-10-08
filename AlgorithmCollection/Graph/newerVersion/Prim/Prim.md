## Prim算法(最小生成树)
这个算法类似 **Dijkstra算法**，区别在于：**每次取出顶点的`TempDistance`从 累加 变成了 覆盖 。**

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;
//Nowadays we more often use this to represent the adjacency table.
struct Node
{
    int data, inDeg, outDeg;
    int prev;   //precursor node
    int tempDist = INT_MAX;
    bool vis = false;
};

struct Edge
{
    int weight, to;
    bool vis = false;
};

vector<Edge> edges[maxN];
Node nodes[maxN];

//Prim Algorithm
int Prim() {
    int result = 0;
    vector<int> select;

    select.push_back(1);
    nodes[1].tempDist = 0;

    while (!select.empty()) {
        sort(select.begin(),select.end(),[](int a, int b){
            return nodes[a].tempDist < nodes[b].tempDist;
        });

        int cur = select.front();
        //判重(见 图1)
        if (nodes[cur].vis) {
            select.erase(select.begin());
            continue;
        }
        nodes[cur].vis = true;

        result += nodes[cur].tempDist;

        for (auto &&edge : edges[cur])
        {
            if (!nodes[edge.to].vis) {
                select.push_back(edge.to);
                if (edge.weight < nodes[edge.to].tempDist) {
                    //这一步从累加变成了直接用边的权重覆盖
                    nodes[edge.to].tempDist = edge.weight;
                    nodes[edge.to].prev = cur;
                }
            }
        }
        select.erase(select.begin());
    }

    return result;
}

int main(int argc, char const *argv[])
{
    /* 
        7
        1 2 3 4 5 6 7
        1 2 23
        1 7 36
        1 6 28
        2 3 20
        2 7 1
        3 7 4
        3 4 15
        4 7 9
        4 5 3
        5 7 16
        5 6 17
        6 7 25
        0 0 0
     */
    int n{};    //the number of points.
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nodes[i].data;
    }
    
    int from{}, to{}, weight{};
    do {
        cin >> from >> to >> weight;
        Edge cur;

        cur.to = to;
        cur.weight = weight;
        edges[from].push_back(cur);

        cur.to = from;
        cur.weight = weight;
        edges[to].push_back(cur);

    } while (!(from == 0 && to == 0 && weight == 0));
    
    cout << Prim() << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << nodes[i].tempDist << " " << nodes[i].prev << endl;
    }
    

    system("pause");
    return 0;
}
```
---------------------------------------
**图1：**
![Note01.png](../NodeImage/note01.png)

