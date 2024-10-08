//���ֲ���
/*
    ���˵���ֲ���������Ժ���
    ���־�����Զ��κ���

    ��Ҫ��������������Լ��������
    ���ַ�������mid��ߣ� mid1  mid2

    ����һ�����κ���������[l,r]�д��ڼ�ֵ��

    1. f(mid1) < f(mid2)����ô��ֵ��һ����mid1���ұ�
       ��ʱ���ƶ����� l �� mid1
    2. f(mid1) > f(mid2)����ô��ֵ��һ����mid2�����
       ��ʱ���ƶ����� r �� mid2
    3. ��� f(mid1) = f(mid2)�������Ƿ�mid1 == mid2��
       ����΢��mid1, mid2

*/
#include "../head.h"
using namespace std;

//���ַ�������ʹ��eps���־���
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
