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

// �� Catalan ���ķ���

/*
    ����ʽ����

    f(n) = 1/(n+1) * c[2*n][n]

    ���ڳ�����ȡģ����Ҫ��Ԫ
*/
int Catalan1(int n) {
    return 1 / (n + 1) * c[2*n][n];
}

/*
    ���Ʒ�:
    f(n) = (4*n-2)/(n+1) * f(n-1)

    ��ɢ�ٶ�̫�죬���ױ�long long, ���ڳ�����ȡģҲ������
*/
void Catalan2(int n, vector<int>& f) {
    f.assign(n+1,0);
    for (int i = 0; i <= n; ++i) {
        if (i == 0) f[i] = 1;
        else f[i] = (4*i-2)/(i+1) * f[i-1];
    }
}

/*
    ��������㷨
    f(n) = c[2*n][n] - c[2*n][n-1]

    �Ƽ��������ٶȿ죬ͬʱҲ����ȡģ
*/
int Catalan3(int n) {
    return c[2*n][n] - c[2*n][n-1];
}

signed main()
{
    getCombine();   //���������
    int n;
    cin >> n;
    cout << Catalan3(n) << endl;

    system("pause");
    return 0;
}