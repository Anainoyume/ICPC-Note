#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
// #define double long double
#define endl '\n'
/* 
    �����Ʋ�λǰ׺��
 */

const int md = 1e9+7;
const int maxN = 1005;
const int Bits = 29;
int arr[maxN];
int prf[maxN][Bits];    // prf[i][j] ��ʾǰ i �����֣��� j λbit ��ǰ׺��

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    // ��λǰ׺��
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= Bits; ++j) {
            prf[i][j] = prf[i-1][j] + (((1 << (j-1)) & arr[i]) != 0);
        }
    }

    int query;
    cin >> query;
    while (query--) {
        int left, k;
        cin >> left >> k;   //Ѱ��һ��������ǰ׺ >= k �±�
        //���������� ��λ�� ��ʹ��ǰ׺�� �ݼ��������ԣ�����ʹ�ö��֣����ڿ��ټ�����[l,mid] ��ǰ׺�룬�Ϳ�����
        //����Ķ����Ʋ�ǰ׺������

        // ����
        int ans = -1;
        int l = left, r = n;
        while (l <= r) {
            int mid = l + (r - l >> 1);
            //��ȡǰ׺��
            int cur = 0;
            for (int j = 1; j <= Bits; ++j) {
                // һ��ϸ�ڣ�ע���� prf[mid][j]-prf[left-1][j] ������ prf[mid][j]-prf[l-1][j]�����ǵ�������� left���䣬l�Ǳ䶯��
                if (prf[mid][j]-prf[left-1][j] == mid-left+1) //��ʾ [l,mid] �ĵ�iλȫ����1����ô��֮�;���1
                    cur += 1 << (j-1);
            }

            if (cur >= k) {
                l = mid+1;
                ans = max(ans,mid);
            }
            else {
                r = mid-1;
            }
        }
        //cout << format("({},{})\n",l,r);
        cout << ans << " ";
    }

    cout << endl;
}

signed main() {
    //IOS;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    system("pause");
    return 0;
}