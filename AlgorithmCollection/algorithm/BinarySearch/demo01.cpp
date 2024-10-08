/* 
    真 - 完美の二分模板
    只要check对了, 就能跑对
 */
#include <bits/stdc++.h>
using namespace std;

bool check(int x) {

}

// 模板一
// 第一个模板是尽量往左找目标, 只要是往左找答案，就用第一个模板，mid不用加一，r=mid，l加一
int binarySearch1(int left, int right) {
    int l{left}, r{right};
    
    while (l < r) {
        int mid = l + (r - l >> 1);	//(l+r)/2
        if (check(mid))  
            r = mid;    // check()判断mid是否满足性质
        else 
            l = mid + 1;
    }

    return l;
}

// 模板二
// 第二个模板是尽量往右找目标, 只要是往右找答案，就用第二个模板，mid要加一，l=mid，r要减一
int binarySearch2(int left, int right) {
    int l{left}, r{right};

    while (l < r) {
        int mid = l + (r - l + 1 >> 1);	//(l+r+1)/2
        if (check(mid))  
            l = mid;
        else 
            r = mid - 1;
    }
    
    return l;
}

signed main()
{




    system("pause");
    return 0;
}