#include <bits/stdc++.h>
using namespace std;

/* 
    二分函数介绍
    1. lower_bound(begin,end,target);   第一个大于等于target的位置(地址)
    2. upper_bound(begin,end,target);   第一个大于target的位置(地址)

    如 arr[i]: 1 1 2 3 4 7 7 7 9 9 10
       index:  0 1 2 3 4 5 6 7 8 9 10
    
    lower_bound(begin,end,7) -> 5
    upper_bound(begin,end,7) -> 8

    lower_bound(begin,end,6); -> 5
    upper_bound(begin,end,6); -> 5

    greater() 仿函数的作用是反转比较结果
    例如：
    lower_bound(begin,end,target,greater());   第一个小于等于target的位置(地址)
    upper_bound(begin,end,target,greater());   第一个小于target的位置(地址)

    确保数列是降序，否则会出现问题

    如 arr[i]: 10 9 9 7 7 7 4 3 2 1 1
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
