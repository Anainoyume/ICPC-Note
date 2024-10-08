#include "head.h"
using namespace std;
/*
    给出 N 个正整数序列 （10 < N < 100 000），每个正整数小于或等于 10000，
    以及一个正整数 S （S < 100 000 000）。
    编写一个程序来查找序列中连续元素的子序列的最小长度，其总和大于或等于 S。
*/

int main(int argc, char const *argv[])
{
    // //数据处理
    // srand(time(0)); 
    // //10000 - 10 + 1是取长度，例如取模5,就会的得到 0 - 4 之内的数字
    // int size = rand() % (10000 - 10 + 1) + 10;

    // //这题可以使用双指针来做
    // vector<int> nums(size);
    // for (int num : nums) {
    //     num = rand() % 10001;
    // }

    // int S = rand() % 100000000;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int S = 60;

    //使用尺取法
    int left = 0;
    int right = 0;
    int sum = nums[0];
    int minLen = nums.size();
    while (right < nums.size() && left <= right) {
        //从0开始往右边加,都从0开始,一个快一个慢
        if (sum >= S) {
            minLen = min(minLen, right - left + 1);
            if (right >= left)
                sum -= nums[left];
                left++;
        }
        else {
            right++;
            sum += nums[right];
        }
    }

    cout << minLen << endl;
    
    cin.get();
    return 0;
}
