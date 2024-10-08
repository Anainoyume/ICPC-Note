#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxN = 1005;

int check(const string& s, int x, int y) {
    int result = 0;
    for (auto&& c : s) {
        if (c - '0' == x) {
            result += 1;
            swap(x,y);
        }
    }
    //�����ʱ��ȡ��result����Ϊ���� (ע�ⲻ��ʹ��s.size()���Ǹ����ܳ���)
    if (result % 2 == 1 && x != y)
        result -= 1;    //ȥ��һ����λ��ʹ����󳤶�-1
    return result;
}

void solve() {
    string str;
    cin >> str;

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            ans = max(ans,check(str,i,j));
        }
    }

    //ԭ���ȼ�ȥ��ģ�����������Ҫȥ�������ٵ�
    cout << str.size()-ans << endl;
    
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}