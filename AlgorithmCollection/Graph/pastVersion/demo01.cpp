/* 
    ͼ�۵�ϵͳѧϰ��
    1.������ͼ�ı�ʾ��ʽ
    demo01 - demo04 ��Ӧ4�з���
 */

//������
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
    //һ������ͼ����һ����
    
    
    system("pause");
    return 0;
}
