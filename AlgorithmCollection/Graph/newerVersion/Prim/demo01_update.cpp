#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;
int n, mp[maxN][maxN];

int dist[maxN], vis[maxN];

int Prim() {
    int result{};

    dist[1] = 0;
    vis[1] = true;
    for (int i = 2; i <= n; i++)
    {
        dist[i] = mp[1][i];
    }

    for (int i = 2; i <= n; i++)
    {
        int t = -1;
        int temp = INT_MAX;
        for (int j = 2; j <= n; j++)
        {
            if ((!vis[j]) && dist[j] < temp) {
                temp = dist[j];
                t = j;
            }
        }

        if (t == -1) return -1;
        vis[t] = true;
        result += dist[t];
        for (int j = 2; j <= n; j++) dist[j] = min(dist[j],mp[t][j]);        
    }
    
    return result;
}

//ÁÚ½Ó¾ØÕóÐ´·¨ O(n^2)
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 0) mp[i][j] = INT_MAX;
        }
        dist[i] = INT_MAX;
    }

    cout << Prim() << endl;
    
    
    system("pause");
    return 0;
}
