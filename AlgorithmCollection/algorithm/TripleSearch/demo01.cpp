//三分查找
/*
    如果说二分查找针对线性函数
    三分就是针对二次函数

    主要分三种情况，考自己想象理解
    三分法有两个mid标尺， mid1  mid2

    考虑一个二次函数在区域[l,r]中存在极值点

    1. f(mid1) < f(mid2)，那么极值点一定在mid1的右边
       此时，移动区间 l 到 mid1
    2. f(mid1) > f(mid2)，那么极值点一定在mid2的左边
       此时，移动区间 r 到 mid2
    3. 如果 f(mid1) = f(mid2)，考虑是否mid1 == mid2，
       否则微调mid1, mid2

*/
#include "../head.h"
using namespace std;

//三分法，必须使用eps保持精度
int TripleSearch(vector<int>& nums, int l, int r) {
    double eps = 1e-6;
    double left = (double)l;
    double right = (double)r;

    while (right - left > eps) {
        double mid1 = left + (right - left) / 3.0;
        double mid2 = right - (right - left) / 3.0;

        if (nums[(int)mid1] <= nums[(int)mid2]) {
            left = mid1;
        }
        else {
            right = mid2;
        }
    }
    return nums[(int)left];
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 18, 17, 14, 12, 10, 8, 6, 4, 2};

    cout << TripleSearch(nums,0,nums.size()-1);

    cin.get();
    return 0;
}
