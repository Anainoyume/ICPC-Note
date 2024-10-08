#include <bits/stdc++.h>
using namespace std;

/*
    ����ֱ��
 */

const int maxN = 1e4+5;

vector<int> edges[maxN];
int ans;
int dp[maxN];

void dfs(int cur, int parent) {
    for (auto&& it : edges[cur]) {
        if (it == parent) continue; //�������һ��dfs�Ǹ��ڵ㣬����
        dfs(it,cur);
        ans = max(ans,dp[cur]+dp[it]+1);    //�����ظ�ѡ�񸸽ڵ㣬��Ϊ�Ѿ�������
        dp[cur] = max(dp[cur],dp[it]+1);    //Ҷ�ӽڵ㳤��Ϊ 0��ֱ���������أ���ȷ
    }
}

int main()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    dfs(1,0);

    cout << ans << endl;

    system("pause");
    return 0;
}