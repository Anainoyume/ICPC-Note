/* 
    ���ӣ�https://codeforces.com/gym/489511/problem/I
 */
#include <bits/stdc++.h>
using namespace std;

/* 
    ����λ����������ã�

    ���Ƕ�֪��  a & 1 ���ж���ż�Ե�����
    ��ô a & 1 ^ 1 ��������ʲô�أ�
    ���Ƿ�ת��ż��

 */

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;

    int sum = 0;             // ���ڼ�¼��ǰλ��֮ǰ������֮��
    long long a[2] {1, 0}; // ���ڼ�¼������ż��1�����������
    long long ans = 0;       // ���յĴ𰸣�������������1�������������

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        sum += x;             // ����ǰ���֣�0��1���ӵ�֮ǰ����֮����
        ans += a[sum & 1 ^ 1]; // ���ݵ�ǰ�ĺͣ����´𰸣����Ӱ���������1�������������
        a[sum & 1]++;         // ����������ż��1�����������
    }

    cout << ans << "\n";

    system("pause");
    return 0;
}
