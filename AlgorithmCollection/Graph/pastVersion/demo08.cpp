/* 
    ÇóÊ÷µÄÖ±¾¶
 */
#include <bits/stdc++.h>
using namespace std;

const int maxN = 105;

struct node
{
    int data = 0;
    bool vis = false;
    int tempDis = INT_MAX;
    node(int a = 0)
    : data(a) {}
};

struct edges
{
    int index = 0;
    int weight = 1;
    edges(int a = 0, int b = 1)
    : index(a), weight(b) {}
};

vector<node> Vertex;

vector<edges> Edges[maxN];

void dfs(int cur) {
    cout << Vertex[cur].data << endl;

    if (Edges[cur].empty()) return;

    for (auto &&sub : Edges[cur])
    {
        if (!Vertex[sub.index].vis) {
            Vertex[sub.index].vis = true;
            dfs(sub.index);
        }
    }
}

int curTemp;
int node_index;
void dfs_dis(int cur, int dis) {
    if (dis > curTemp) {
        curTemp = dis;
        node_index = cur;
    }

    if (Edges[cur].empty()) return;

    for (auto &&sub : Edges[cur])
    {
        if (!Vertex[sub.index].vis) {
            Vertex[sub.index].vis = true;
            dfs_dis(sub.index,dis+sub.weight);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;

    Vertex.push_back('\n');
    for (int i = 0; i < n; i++)
    {
        Vertex.push_back('A'+i);
    }
    
    int from = 0, to = 0;
    for (int i = 0; i < n-1; i++)
    {   
        cin >> from >> to;
        Edges[from].push_back(to);
        Edges[to].push_back(from);
    }

    /* 
        5
        1 2
        1 3
        3 4
        4 5
     */

    Vertex[1].vis = true;
    dfs_dis(1,0);
    Vertex[1].vis = false;

    cout << node_index << endl;
    cout << curTemp << endl;

    for (int i = 1; i <= n; i++)
    {
        Vertex[i].vis = false;
    }
    
    curTemp = 0;
    Vertex[node_index].vis = true;
    dfs_dis(node_index,0);
    Vertex[node_index].vis = false;

    cout << curTemp << endl;
    
    system("pause");
    return 0;
}
