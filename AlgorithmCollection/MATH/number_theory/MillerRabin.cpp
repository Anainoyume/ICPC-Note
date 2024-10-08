#include <bits/stdc++.h>
using namespace std;

int64_t mul(int64_t a, int64_t b, int64_t MOD) {
    __int128 x = a, y = b, m = MOD;
    return (int64_t)(x * y % m);
}

int64_t fastPow(int64_t a, int64_t x, int64_t m) {
    int64_t ans = 1ll;
    while (x) {
        if (x&1) ans = mul(ans, a, m);
        a = mul(a, a, m);
        x >>= 1;
    }
    return ans;
}

bool millerRabin(int64_t n) {
    if (n < 3 || n % 2 == 0) return n == 2;
    if (n % 3 == 0) return n == 3;

    int64_t u = n - 1;
    int t = 0;
    while (u % 2 == 0) u /= 2ll, t += 1;
    // test_time Ϊ���Դ�����������Ϊ��С�� 8
    // �������Ա�֤��ȷ�ʣ���Ҳ���˹��󣬷����Ӱ��Ч��
    int test_time = 10;
    for (int i = 0; i < test_time; ++i) {
        // 0, 1, n-1 ����ֱ��ͨ������, a ȡֵ��Χ [2, n-2]
        int64_t a = rand() % (n - 3ll) + 2ll, v = fastPow(a, u, n);
        if (v == 1) continue;
        int s{};
        for (s = 0; s < t; ++s) {
            if (v == n - 1) break;  // �õ�ƽ��ƽ���� n-1��ͨ�����ֲ���
            v = mul(v, v, n);
        }
        // ����ҵ��˷�ƽ��ƽ��������������޷���ǰ break; �����е� s == t
        // ��� Fermat ���Բ����޷�ͨ������һֱ���е� s == t ǰ v ��������� -1
        if (s == t) return false;
    }
    return true;
}

signed main()
{
    int64_t x{};
    while (cin >> x) {
        cout << (millerRabin(x) ? "Y" : "N") << endl;
    }

    system("pause");
    return 0;
}