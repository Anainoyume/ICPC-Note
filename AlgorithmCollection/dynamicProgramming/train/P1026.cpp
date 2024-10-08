#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int maxN = 205;
int cnt[maxN][maxN];    //��ʾ [l,r] ֮����ڵĵ�������
int dp[maxN][maxN];


vector<string> mp;

signed main() {
    int n, k;
    cin >> n >> k;
    string str{};
    for (int i = 0; i < n; i++) {
        string p{};
        cin >> p;
        str += p;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string p{};
        cin >> p;
        mp.push_back(p);
    }

    auto check = [&](int left, int right) -> bool {
        // ֻҪ�� left ��ͷ�ĵ���ƥ�䣬���۶��ٸ�����ֻ����һ��
        string line = str.substr(left,right-left+1);
        for (auto&& s : mp) {
            if (line.find(s) == 0) return true;
        }
        return false;
    };

    // ͬ��ʹ��dp����Ԥ��������ĵ��ʸ���
    int len = str.size();
    // ���������������Ϊ���ʵĵ�һ����ĸ����һ�ξͲ���������
    for (int i = len-1; i >= 0; --i) {
        for (int j = i; j < len; j++) {
            cnt[i][j] = cnt[i+1][j];
            if (check(i,j))
                cnt[i][j] += 1;
        }
    }
    
    for (int i = 0; i < len; i++) {
        dp[i][1] = cnt[0][i];
    }
    
    //״̬ת��
    // dp[i][k] ��ʾ�� i Ϊֹ������Ϊ k ��
    // dp[i][k] = max{dp[j][k-1]+cnt[j+1][i]}; 0 <= j < i
    for (int i = 1; i < len; i++) {
        for (int j = 2; j <= k && j <= i; j++) {
            for (int m = j; m < i; m++) {
                dp[i][j] = max(dp[i][j],dp[m][j-1]+cnt[m+1][i]);
            }
        }
    }
    
    cout << dp[len-1][k] << endl;
    

    system("pause");
    return 0;
}