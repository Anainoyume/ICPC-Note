#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Vertex;
struct Edge
{
    Vertex* to;     //�յ�
    int weight;     //Ȩ��
    Edge(Vertex* t, int w) : to(t), weight(w) {}
};

struct Vertex
{
    string data;    //����
    vector<Edge*> edges;    //�ߵĶ�̬����
    bool isVisited; //�Ƿ񱻷���
    int inDegree;   //���
    int tempDistance = INT_MAX;   //��ʱ���룬Ĭ��Ϊ�����
    Vertex* prev = NULL;   //��Դ���
    Vertex(string value) : data(value) {}
};

/* 
    ��С�������㷨��
    ���Ǿ�ͼ��ͼ,Graph01.png,������7�����㣬������12���ߣ�������֪����
    ����7�����㣬��������ֻ��Ҫ6���߾�����ͨ���е㣬
    ��С�������Ľ�������ҵ���6���ߣ���ͨ���еĵ㣬���ҳɱ����
    Ҳ���Ǿ���·����Ȩ����С


    1. ��С������ Prim-�㷨
 */

void Prim(Vertex* v0) {
    //������һ��vector��������Ŷ���
    vector<Vertex*> temp;
    temp.push_back(v0);
    v0->tempDistance = 0;
    
    //��ʼ�㷨
    while (!temp.empty()) {
        //������ȡ����ʱ������С��
        sort(temp.begin(),temp.end(),[](Vertex* a, Vertex* b) -> bool {
            return a->tempDistance < b->tempDistance;
        });
        //��ȡ��ͷԪ��
        //������Χ��δ���ʵĶ��㣬������봦������
        Vertex* cur = temp.front();
        cur->isVisited = true;
        for (auto it : cur->edges) {
            if (it->to->isVisited == false) {
                //����δ���ʵĽ��
                temp.push_back(it->to);
                if(it->weight < it->to->tempDistance) {
                    //�����Dijkstra�㷨����һ�£�����Dijkstra�ж���·�����
                    //Prim��������ͨ�ܺ���С
                    /*
                        �Դ�ͼΪ��:
                        ����Prim�㷨����ͨ�ķֱ���
                        AB BC CD �ܺ�Ϊ 12
                        ���ǰ���Dijkstra������ A -> B -> C Ϊ 12
                        ����ֱ�� A -> C 5 ���ã������2�ߵ�����

                        ����Ҫ���ǣ�DijkstraֻҪ���ߵ��յ㣬��Ҫ���������е�
                                   B
                               4 / | \ 5
                                /  |  \   
                        A ---><    |4   >---> D
                                \  |  /
                               5 \ | / 4
                                   C
                    */
                    it->to->tempDistance = it->weight;  //������������ֱ�Ӱ���ʱ�������ΪȨ�ض������ۺ�
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
    //������ʹ�õ�ͼ���ɲο� Graph01.png
    Vertex *v1 = new Vertex("v1");
    Vertex *v2 = new Vertex("v2");
    Vertex *v3 = new Vertex("v3");
    Vertex *v4 = new Vertex("v4");
    Vertex *v5 = new Vertex("v5");
    Vertex *v6 = new Vertex("v6");
    Vertex *v7 = new Vertex("v7");

    v1->edges = {
        new Edge(v2,2),   //����ֱ������
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
