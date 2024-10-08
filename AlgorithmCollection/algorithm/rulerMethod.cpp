//尺取法
/*
    尺取法其实就是双指针法
    用两个变量模拟两个指针
    
    例如以下的查找
*/
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    //例如查找 7
    int target = 7;
    int left = 0;
    int right = nums.size();
    while (left < right) {
        //两边同时走
        if (nums[left] == target) {
            cout << "下标为: " << left << endl;
            break;
        }

        if (nums[right] == target) {
            cout << "下标为: " << right << endl;
            break;
        }

        left++;
        right--;
    }
    

    cin.get();
    return 0;
}

