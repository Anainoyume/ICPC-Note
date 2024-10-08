#include "head.h"
using namespace std;
/*
    ���� N ������������ ��10 < N < 100 000����ÿ��������С�ڻ���� 10000��
    �Լ�һ�������� S ��S < 100 000 000����
    ��дһ����������������������Ԫ�ص������е���С���ȣ����ܺʹ��ڻ���� S��
*/

int main(int argc, char const *argv[])
{
    // //���ݴ���
    // srand(time(0)); 
    // //10000 - 10 + 1��ȡ���ȣ�����ȡģ5,�ͻ�ĵõ� 0 - 4 ֮�ڵ�����
    // int size = rand() % (10000 - 10 + 1) + 10;

    // //�������ʹ��˫ָ������
    // vector<int> nums(size);
    // for (int num : nums) {
    //     num = rand() % 10001;
    // }

    // int S = rand() % 100000000;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int S = 60;

    //ʹ�ó�ȡ��
    int left = 0;
    int right = 0;
    int sum = nums[0];
    int minLen = nums.size();
    while (right < nums.size() && left <= right) {
        //��0��ʼ���ұ߼�,����0��ʼ,һ����һ����
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
