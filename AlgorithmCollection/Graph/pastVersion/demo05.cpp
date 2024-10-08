//为了顺利实现 Kruskal算法 我们改变一下数据结构，并且引入并查集 union_find.h
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include "union_find.h"
using namespace std;

struct Vertex
{
    string data;
    bool isVisited = 0;
    int tempDist = INT_MAX;
    Vertex(string value) : data(value) {}
};

struct Edge
{
    int from;   //注意，这里是按照结点在图的结点集合里的下标存储的，这样方便使用并查集合并
    int to;
    int weight;     //权重
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

class Graph
{
public:
    vector<Vertex> vertexList;
};

vector<Edge> Kruskal(vector<Edge>& edges, vector<Vertex>& vertexList) {
    int VerCount = vertexList.size();
    UnionFind un(7);    //并查集
    //先对边按照权重大小从小到大排序
    sort(edges.begin(),edges.end(),[](Edge& a, Edge& b){
        return a.weight < b.weight;
    });

    vector<Edge> ans;   //计算出来的边
    while (ans.size() != VerCount-1 && (!edges.empty())) {  //边的条数为顶点个数减一时停止
        Edge& cur = edges.front();
        if (un.find(cur.from) != un.find(cur.to)) { //如果没有连通
            un.Union(cur.from,cur.to);
            ans.push_back(cur);
        }
        edges.erase(edges.begin());
    }

    return ans;
}

void printEdge(Edge& edge, vector<Vertex>& vertexList) {
    cout << vertexList[edge.from].data << " -> " << vertexList[edge.to].data << "  weight: " << edge.weight << endl;
}

int main()
{
    //本用例使用的图，可参考 Graph01.png
    Vertex v1("v1");
    Vertex v2("v2");
    Vertex v3("v3");
    Vertex v4("v4");
    Vertex v5("v5");
    Vertex v6("v6");
    Vertex v7("v7");

    Graph graph;
    graph.vertexList = {v1,v2,v3,v4,v5,v6,v7};

    Edge e1(0,1,2);   
    Edge e2(0,2,4);
    Edge e3(0,3,1);

    Edge e4(1,0,2);   
    Edge e5(1,3,3);
    Edge e6(1,4,10);

    Edge e7(2,0,4);
    Edge e8(2,3,2);
    Edge e9(2,5,5);

    Edge e10(3,0,1);   
    Edge e11(3,1,3);
    Edge e12(3,2,2);
    Edge e13(3,4,7);  
    Edge e14(3,5,8);
    Edge e15(3,6,4);

    Edge e16(4,1,10);  
    Edge e17(4,3,7);
    Edge e18(4,6,6);

    Edge e19(5,2,5);  
    Edge e20(5,3,8);
    Edge e21(5,6,1);

    Edge e22(6,5,1); 
    Edge e23(6,3,4);
    Edge e24(6,4,6);

    vector<Edge> edges = {e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24};

    vector<Edge> ans = Kruskal(edges,graph.vertexList);
    for (auto it : ans) {
        printEdge(it,graph.vertexList);
    }

    system("pause");
    return 0;
}
