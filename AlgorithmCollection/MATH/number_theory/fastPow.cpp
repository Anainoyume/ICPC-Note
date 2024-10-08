#include <bits/stdc++.h>
using namespace std;
/* 
    ¿ìËÙÃİ
 */
int fastPow(int a, int n, int m = 1){
    int ans = 1;
    while(n){
        if (n & 1) ans = ans * a % m;  
        a = a * a % m;        
        n >>= 1;       
    }
    return ans;
}

int main()
{


    system("pause");
    return 0;    
}