#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e4 + 5;

int pa[maxN];    //���鼯

int Find(int x) {
    return pa[x] == x ? x : pa[x] = Find(pa[x]);
}

// x �ϲ��� y ��
void Union(int x, int y) {
    pa[Find(x)] = Find(y);
}

bool Search(int x, int y) {
    return Find(x) == Find(y);
}

// ά���㵽������� ��Ȩ���鼯
// ÿ��ά���㵽������ʱ�ֽ���ǰ��deep����Ϊ1�����벢�鼯������find
int deep[maxN];
int find(int x) {
    if (pa[x] != x) {
        int t = find(pa[x]);
        deep[x] += deep[pa[x]];
        pa[x] = t;
    }
    return pa[x];
}

signed main()
{


    system("pause");
    return 0;
}