#include <bits/stdc++.h>
#include "../UnionFind.hpp"
using namespace std;

int main()
{
    Uf uf(10);

    cout << uf.getCount() << endl;

    uf.Union(0,1).Union(1,2).Union(2,3).Union(8,9);

    cout << uf.getCount() << endl;

    cout << uf.Connect(0,3) << endl;
    cout << uf.Connect(7,8) << endl;
    cout << uf.Connect(8,9) << endl;


    system("pause");
    return 0;
}