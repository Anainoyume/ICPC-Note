//邻接表
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100000;

struct Edge
{
    int index;  //指向的顶点在数组中的下标,也可以直接改成顶点的地址
    int weight; //权重
    Edge* next = NULL; //下一条边，形成链表结构
    Edge(int i, int w) : index(i), weight(w) {}
};

struct Vertex
{
    string data;
    Edge* firstTo;  //指向的邻接表
    bool isVisited = 0;     //是否被访问过
    Vertex() {}
    Vertex(string d, Edge* f) : data(d), firstTo(f) {}
};

struct Graph
{
    int Esize, Vsize;   //边数量和顶点的数量
    int index = 1;
    Vertex *vList = new Vertex[MAX_N];    //顶点数组,必须建立在堆上
    //Ps. 如果要写Vertex vList[MAX_N]; 会出现内存错误，因为栈上建立的数组不能太大

    ~Graph() {
        delete[] vList;
    }

    Graph& addVertex(Vertex& v) {
        vList[index++] = v;
        return *this;
    } 
};

void DFS(Vertex list[], int index) {
    if (list[index].isVisited == 1)
        return;

    cout << list[index].data << " ";
    list[index].isVisited = 1;

    Edge* e = list[index].firstTo;
    while (e != NULL) {
        DFS(list,e->index);
        e = e->next;
    }
}

int main(int argc, char const *argv[])
{
    Graph graph;
    
    Edge e12(2,2);
    Edge e13(3,3);
    Edge e27(7,8);
    Edge e24(4,1);
    Edge e25(5,5);
    Edge e35(5,7);
    Edge e46(6,6);
    Edge e65(5,2);
    Edge e74(4,3);

    Vertex v1("v1",&e12);
    e12.next = &e13;
    Vertex v2("v2",&e24);
    e24.next = &e25;
    e25.next = &e27;
    Vertex v3("v3",&e35);
    Vertex v4("v4",&e46);
    Vertex v5("v5",NULL);
    Vertex v6("v6",&e65);
    Vertex v7("v7",&e74);

    graph.addVertex(v1).addVertex(v2).addVertex(v3).addVertex(v4).addVertex(v5).addVertex(v6).addVertex(v7);

    DFS(graph.vList,1);

    system("pause");
    return 0;
}

