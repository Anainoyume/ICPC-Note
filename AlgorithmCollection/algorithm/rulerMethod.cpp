//��ȡ��
/*
    ��ȡ����ʵ����˫ָ�뷨
    ����������ģ������ָ��
    
    �������µĲ���
*/
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    //������� 7
    int target = 7;
    int left = 0;
    int right = nums.size();
    while (left < right) {
        //����ͬʱ��
        if (nums[left] == target) {
            cout << "�±�Ϊ: " << left << endl;
            break;
        }

        if (nums[right] == target) {
            cout << "�±�Ϊ: " << right << endl;
            break;
        }

        left++;
        right--;
    }
    

    cin.get();
    return 0;
}

