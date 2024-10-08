/* 
    题目链接：https://www.luogu.com.cn/problem/P1854
    P1845 花店橱窗布置
 */

#include <bits/stdc++.h>
using namespace std;

const int maxN = 105;
int ans{INT_MIN}, f, v;
int arr[maxN][maxN];
int dp[maxN][maxN];
int last[maxN][maxN];

int dfs(int index, int th) {
    if (dp[index][th] != INT_MIN) return dp[index][th];

    if (index >= f) {
        dp[index][th] = arr[index][th];
        last[index][th] = -1;
        return arr[index][th];
    }

    for (int i = th+1; i <= v-f+index+1; i++) {
        int cur = dfs(index+1,i) + arr[index][th];
        if (dp[index][th] < cur) {
            dp[index][th] = cur;
            last[index][th] = i;    //核心：路径记录
        }
    }
    
    return dp[index][th];
}

void solve() {
    cin >> f >> v;
    for (int i = 1; i <= f; i++) {
        for (int j = 1; j <= v; j++) {
            cin >> arr[i][j];
            dp[i][j] = INT_MIN;
        }
    }

    int back{};
    for (int i = 1; i <= v-f+1; i++) {
        int cur = dfs(1,i);
        if (cur > ans) {
            ans = cur;
            back = i;
        }
    }

    cout << ans << endl;  
    int layer = 1;
    while (back != -1) {
        cout << back << " ";
        back = last[layer++][back];
    } 
    cout << endl;
}

int main()
{
    solve();

    system("pause");
    return 0;
}