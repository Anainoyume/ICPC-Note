#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Vertex;
struct Edge
{
    Vertex* to;     //终点
    int weight;     //权重
    Edge(Vertex* t, int w) : to(t), weight(w) {}
};

struct Vertex
{
    string data;    //数据
    vector<Edge*> edges;    //边的动态数组
    bool isVisited; //是否被访问
    int inDegree;   //入度
    int tempDistance = INT_MAX;   //临时距离，默认为无穷大
    Vertex* prev = NULL;   //来源结点
    Vertex(string value) : data(value) {}
};

/* 
    最小生成树算法：
    我们就图论图,Graph01.png,里面有7个顶点，但是有12条边，但我们知道，
    对于7个顶点，我们最少只需要6条边就能连通所有点，
    最小生成树的结果就是找到这6条边，连通所有的点，并且成本最低
    也就是经过路径的权重最小


    1. 最小生成树 Prim-算法
 */

void Prim(Vertex* v0) {
    //先设置一个vector，用来存放顶点
    vector<Vertex*> temp;
    temp.push_back(v0);
    v0->tempDistance = 0;
    
    //开始算法
    while (!temp.empty()) {
        //先排序，取出临时距离最小的
        sort(temp.begin(),temp.end(),[](Vertex* a, Vertex* b) -> bool {
            return a->tempDistance < b->tempDistance;
        });
        //获取队头元素
        //遍历周围的未访问的顶点，将其加入处理容器
        Vertex* cur = temp.front();
        cur->isVisited = true;
        for (auto it : cur->edges) {
            if (it->to->isVisited == false) {
                //加入未访问的结点
                temp.push_back(it->to);
                if(it->weight < it->to->tempDistance) {
                    //代码和Dijkstra算法基本一致，但是Dijkstra判断是路径最短
                    //Prim看的是连通总和最小
                    /*
                        以此图为例:
                        按照Prim算法，连通的分别是
                        AB BC CD 总和为 12
                        但是按照Dijkstra，与其 A -> B -> C 为 12
                        不如直接 A -> C 5 更好，这就是2者的区别

                        最重要的是：Dijkstra只要求走到终点，不要求连接所有点
                                   B
                               4 / | \ 5
                                /  |  \   
                        A ---><    |4   >---> D
                                \  |  /
                               5 \ | / 4
                                   C
                    */
                    it->to->tempDistance = it->weight;  //区别在于我们直接把临时距离更新为权重而不是累和
                    it->to->prev = cur;
                }
            }
        }
        temp.erase(temp.begin());
    }
}

void DFS(Vertex* v0) {
    if (v0->isVisited == true)
        return;
    if (v0->prev != NULL)
        cout << v0->data << " " << v0->prev->data << endl;
    else
        cout << v0->data << endl;
    v0->isVisited = true;
    for (auto it : v0->edges) {
        DFS(it->to);
    }
}


int main(int argc, char const *argv[])
{
    //本用例使用的图，可参考 Graph01.png
    Vertex *v1 = new Vertex("v1");
    Vertex *v2 = new Vertex("v2");
    Vertex *v3 = new Vertex("v3");
    Vertex *v4 = new Vertex("v4");
    Vertex *v5 = new Vertex("v5");
    Vertex *v6 = new Vertex("v6");
    Vertex *v7 = new Vertex("v7");

    v1->edges = {
        new Edge(v2,2),   //可以直接这样
        new Edge(v3,4),
        new Edge(v4,1)
    };

    v2->edges = {
        new Edge(v1,2),   
        new Edge(v4,3),
        new Edge(v5,10)
    };

    v3->edges = {
        new Edge(v1,4),   
        new Edge(v4,2),
        new Edge(v6,5)
    };

    v4->edges = {
        new Edge(v1,1),   
        new Edge(v2,3),
        new Edge(v3,2),
        new Edge(v5,7),   
        new Edge(v6,8),
        new Edge(v7,4)
    };

    v5->edges = {
        new Edge(v2,10),   
        new Edge(v4,7),
        new Edge(v7,6)
    };

    v6->edges = {
        new Edge(v3,5),   
        new Edge(v4,8),
        new Edge(v7,1)
    };

    v7->edges = {
        new Edge(v6,1),   
        new Edge(v4,4),
        new Edge(v5,6)
    };

    vector<Vertex*> Graph = {v1,v2,v3,v4,v5,v6,v7};

    Prim(v1);

    for (auto it : Graph) {
        it->isVisited = false;
    }

    DFS(v1);
    
    system("pause");    
    return 0;
}
