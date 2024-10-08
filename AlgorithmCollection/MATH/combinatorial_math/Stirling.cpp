#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxN = 16;
const int md = 1e18+7;

int s1[maxN][maxN];
int s2[maxN][maxN];

// 斯特拉数采取递推计算即可
// 第一类斯特林数
void Stirling1() {
    for (int i = 0; i < maxN; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) s1[i][j] = 0;
            else if (i == j) s1[i][j] = 1;
            else s1[i][j] = s1[i-1][j-1] + (i-1)*s1[i-1][j];
        }
    } 
}

// 第二类斯特林数
void Stirling2() {
    for (int i = 0; i < maxN; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) s2[i][j] = 0;
            else if (i == j) s2[i][j] = 1;
            else s2[i][j] = s2[i-1][j-1] + j*s2[i-1][j];
        }
    } 
}

// 计算阶乘
int fac[maxN];
void getFactorial() {
    for (int i = 0; i < maxN; ++i) {
        if (i == 0) fac[i] = 1;
        else fac[i] = (i % md * fac[i-1] % md) % md;
    }
}

signed main()
{
    int box, ball;
    cin >> ball >> box;
    
    Stirling2();
    getFactorial();

    cout << s2[ball][box] * fac[box] << endl;


    system("pause");
    return 0;
}