#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

const int maxN = 40;
const int md = 1e9+7;

int c[maxN][maxN];

void getCombine() {
    for (int i = 0; i < maxN; i++) {
        for (int j = 0; j <= i; j++) {
            if(j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

// 求 Catalan 数的方法

/*
    定义式法：

    f(n) = 1/(n+1) * c[2*n][n]

    存在除法，取模还需要逆元
*/
int Catalan1(int n) {
    return 1 / (n + 1) * c[2*n][n];
}

/*
    递推法:
    f(n) = (4*n-2)/(n+1) * f(n-1)

    发散速度太快，容易爆long long, 存在除法，取模也不方便
*/
void Catalan2(int n, vector<int>& f) {
    f.assign(n+1,0);
    for (int i = 0; i <= n; ++i) {
        if (i == 0) f[i] = 1;
        else f[i] = (4*i-2)/(i+1) * f[i-1];
    }
}

/*
    组合数计算法
    f(n) = c[2*n][n] - c[2*n][n-1]

    推荐，计算速度快，同时也方便取模
*/
int Catalan3(int n) {
    return c[2*n][n] - c[2*n][n-1];
}

signed main()
{
    getCombine();   //处理组合数
    int n;
    cin >> n;
    cout << Catalan3(n) << endl;

    system("pause");
    return 0;
}