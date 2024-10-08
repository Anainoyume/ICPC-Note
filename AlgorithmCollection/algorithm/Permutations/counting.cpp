/* 
    ������
    ������ a^n �� n��a ���
    ������ʹ�ñ����㷨�Ľ����ʱ�临�Ӷ�Ϊ O(n) ,��Ϊ������Ҫ��n��a���
    ���ǲ���˼���Ƿ���� �����ٵķ���
 */
#include <bits/stdc++.h>
using namespace std;

long long quickCount(int a, int n) {
    /*
        ����˼��������Ҫ�� a^8
        �����Ƿ���� a*a = a^2
        �ٽ����Գ� a^2 * a^2 = a^4
        a^4 * a^4 = a^8
        �����Ͱ�ʱ�临�ӶȽ����� O(logn)
    */
    if (n == 0) return 1;
    if (n == 1) return a;
    long long temp = quickCount(a,n/2);
    if (n & 1 == 1) 
        return temp*temp*a;
    else 
        return temp*temp;
}

int main(int argc, char const *argv[])
{
    cout << quickCount(2,31) << endl;
    
    system("pause");
    return 0;
}
