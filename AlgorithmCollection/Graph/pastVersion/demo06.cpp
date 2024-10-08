/* 
    ����ͼ

    1.����ж�һ��ͼ�Ƕ���ͼ
    2.����õ��������ͼ�����ƥ����
 */
//��������ʹ�������Լ���ͼ�ṹ�����
#include <bits/stdc++.h>
using namespace std;

struct Edge;
struct Node
{
    int data = 0;
    int index = 0;
    bool vis = false;
    vector<Edge*> edges;

    int color = 0;  //color��ʾ��ǰ��Ⱦ��ʲô��ɫ(����Ⱦɫ�㷨)

    int inDeg = 0;  //���
    int outDeg = 0; //����

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
        ������
        4 4
        1 3
        1 4
        2 3
        2 4
     */

    void init(int cnt) {    //��ʼ�����
        for (int i = 1; i <= cnt; i++)
            nodes.push_back(new Node(i,i));
    }

    void link(int from, int to) {   //���ӱ�
        nodes[from-1]->edges.push_back(new Edge(nodes[to-1]));
        nodes[to-1]->edges.push_back(new Edge(nodes[from-1])); //����ͼ
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
                if(!setcolor(edge->to, (-1)*color)) return false;   //�������Ⱦɫû�г��ִ�����ô����Ⱦ
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
    Graph g;    //���ǵ�ͼ
    int n = 0, m = 0;
    cin >> n >> m;   //��ĸ�������ÿ����
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



