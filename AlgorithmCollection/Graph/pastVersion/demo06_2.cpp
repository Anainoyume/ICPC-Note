/* 
    使用类与结构体组成的图十分的占用内存与时间，
    我们使用数组来模拟，邻接表
 */
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int to;
    int color = 0;
    vector<int> head;
};

int n,m;
int color[2001];
node* g[2001];

bool setcolor(int p, int color) {
    g[p]->color = color;

    for (auto &&v : g[p]->head)
    {
        if (g[v]->color == 0) {
            if (!setcolor(v,(-1)*color)) return false;
        }
        else if (g[v]->color == g[p]->color) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        g[i] = new node();  //需要先初始化
    }
    
    
    int from, to;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        g[from-1]->head.push_back(to-1);
        g[to-1]->head.push_back(from-1);
    }
    
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (g[i]->color == 0)
            if (!setcolor(i,1))
                flag = false;
    }
    
    
    
    system("pause");
    return 0;
}
