#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS cin.tie(0)->sync_with_stdio(false)
const int md = 1e9+7;
const int maxN = 1005;

/* 
    ����һ����Ϊn������a����һ������k
    ���� n = 6, k = 3
    a = [1, 1, 4, 5, 1, 4]

    ��������а���˳�򻮷������У�����������֮�ͱ���Ϊ k �ı���
    �����໮�ֳ��ĺ�Ϊ k ���� �� ����������
 */

int n, k;
int a[maxN], sum[maxN];

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    
    unordered_map<int,int> mp;
    // ... 
    

    system("pause");
    return 0;
}
