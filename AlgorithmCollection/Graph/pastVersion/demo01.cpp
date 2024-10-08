/* 
    图论的系统学习：
    1.先掌握图的表示方式
    demo01 - demo04 对应4中方法
 */

//数组存边
#include <iostream>
using namespace std;

struct Edge
{
    int tail, head;
    Edge() {}
    Edge(int u, int v) : tail(u), head(v) {}
};

int main(int argc, char const *argv[])
{
    Edge edges[5] = {
        {0,1},
        {1,2},
        {2,3},
        {3,4},
        {4,0}
    };
    //一个有向图，是一个环
    
    
    system("pause");
    return 0;
}
