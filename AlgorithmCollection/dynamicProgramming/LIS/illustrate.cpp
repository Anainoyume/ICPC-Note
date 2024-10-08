#include <bits/stdc++.h>
using namespace std;

/* 
    ���ֺ�������
    1. lower_bound(begin,end,target);   ��һ�����ڵ���target��λ��(��ַ)
    2. upper_bound(begin,end,target);   ��һ������target��λ��(��ַ)

    �� arr[i]: 1 1 2 3 4 7 7 7 9 9 10
       index:  0 1 2 3 4 5 6 7 8 9 10
    
    lower_bound(begin,end,7) -> 5
    upper_bound(begin,end,7) -> 8

    lower_bound(begin,end,6); -> 5
    upper_bound(begin,end,6); -> 5

    greater() �º����������Ƿ�ת�ȽϽ��
    ���磺
    lower_bound(begin,end,target,greater());   ��һ��С�ڵ���target��λ��(��ַ)
    upper_bound(begin,end,target,greater());   ��һ��С��target��λ��(��ַ)

    ȷ�������ǽ��򣬷�����������

    �� arr[i]: 10 9 9 7 7 7 4 3 2 1 1
       index:  0  1 2 3 4 5 6 7 8 9 10

    lower_bound(begin,end,7,greater()) -> 3
    upper_bound(begin,end,7,greater()) -> 6

    lower_bound(begin,end,6,greater()); -> 6
    upper_bound(begin,end,6,greater()); -> 6
 */

int main(int argc, char const *argv[])
{
   vector arr = {1,2,2,3,3};

   cout << lower_bound(arr.begin(),arr.end(),2) - arr.begin() << endl;

   system("pause");
   return 0;
}
