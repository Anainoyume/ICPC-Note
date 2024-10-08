/* 
    二分图

    1.如何判断一个图是二分图
    2.如果得到这个二分图的最大匹配数
 */
//我们依旧使用我们自己的图结构来解决
#include <bits/stdc++.h>
using namespace std;

struct Edge;
struct Node
{
    int data = 0;
    int index = 0;
    bool vis = false;
    vector<Edge*> edges;

    int color = 0;  //color表示当前点染成什么颜色(用于染色算法)

    int inDeg = 0;  //入度
    int outDeg = 0; //出度

    Node(int d, int i)
        : data(d), index(i)
    {} 
};

struct Edge
{
    Node* to = NULL;
    int weight = 1;
    bool vis = false;

    Edge(Node* t, int w = 1)
        : to(t), weight(w)
    {} 
};

class Graph
{
private:
    void clvis() {
        for (auto &&p : nodes)
            p->vis = false;
    }

    void _dfs(Node* p) {
        p->vis = true;
        cout << p->data << endl;

        for (auto &&edge : p->edges)
        {
            if (edge->to->vis == false)
                _dfs(edge->to);
        }
    }
public:
    vector<Node*> nodes;
    /* 
        样例：
        4 4
        1 3
        1 4
        2 3
        2 4
     */

    void init(int cnt) {    //初始化结点
        for (int i = 1; i <= cnt; i++)
            nodes.push_back(new Node(i,i));
    }

    void link(int from, int to) {   //连接边
        nodes[from-1]->edges.push_back(new Edge(nodes[to-1]));
        nodes[to-1]->edges.push_back(new Edge(nodes[from-1])); //无向图
    }

    void dfs() {
        clvis();   
        for (auto &&p : nodes)
        {
            if (p->vis == false)
                _dfs(p);
        }
    }

    bool setcolor(Node* p, int color) {
        p->color = color;

        for (auto &&edge : p->edges)
        {
            if (edge->to->color == 0) {
                if(!setcolor(edge->to, (-1)*color)) return false;   //如果继续染色没有出现错误，那么继续染
            }
            else if (edge->to->color == p->color) return false;
        }
        return true;
    }

    bool isBianry() {
        for (auto &&p : nodes)
        {
            if (p->color == 0 && !setcolor(p,1))
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Graph g;    //我们的图
    int n = 0, m = 0;
    cin >> n >> m;   //点的个数，和每条边
    g.init(n);

    int from = 0, to = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        g.link(from,to);
    }
    
    if (g.isBianry())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    
    
    
    system("pause");
    return 0;
}



