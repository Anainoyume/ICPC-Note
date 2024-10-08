#include <bits/stdc++.h>
using namespace std;

int pow(int a, int x) {
    //递归实现快速幂
    if (x == 0) 
        return 1;

    int val = pow(a,x/2);
    if (x & 1) return val*val*a;
    else return val*val;
}

int main(int argc, char const *argv[])
{

    for (int i = 0; i < 11; i++)
    {
        cout << pow(2,i) << endl;
    }
    

    system("pause");
    return 0;
}
