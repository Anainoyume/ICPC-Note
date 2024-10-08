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

struct cmp
{
    bool operator() (int a, int b) {
        return nodes[a].tempDist < nodes[b].tempDist;
    }
};

//Prim Algorithm
int Prim() {
    int result = 0;
    priority_queue<int,vector<int>,cmp> select;

    select.push(1);
    nodes[1].tempDist = 0;

    while (!select.empty()) {
        int cur = select.top();
        if (nodes[cur].vis) {
            select.pop();
            continue;
        }
        
        nodes[cur].vis = true;
        result += nodes[cur].tempDist;
        select.pop();

        for (auto &&edge : edges[cur])
        {
            if (!nodes[edge.to].vis) {
                if (edge.weight < nodes[edge.to].tempDist) {
                    nodes[edge.to].tempDist = edge.weight;
                    nodes[edge.to].prev = cur;
                }
                select.push(edge.to);
            }
        }
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
