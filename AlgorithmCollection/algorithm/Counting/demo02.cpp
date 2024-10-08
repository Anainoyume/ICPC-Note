#include <bits/stdc++.h>
using namespace std;

//倍增实现快速幂
int pow(int a, int x) {
    int val = 1;
    while (x) {
        if (x & 1) val *= a;
        a *= a;
        x >>= 1;
    }
    return val;
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


