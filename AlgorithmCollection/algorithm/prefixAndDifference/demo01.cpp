//һάǰ׺��
#include "../head.h"
using namespace std;

int main(int argc, char const *argv[])
{
    //���⣬��ο�����һ������������[L,R]֮��ĺ�
    //���ǿ��Ǽ��������������[0,i]�ĺͣ����ڴ�0��ʼ���ʳ�Ϊǰ׺��
    
    //����arr[n]��������sum[i]���飬��ʾarr��[0,i]�ĺ�
    //���ڵ��Ʊ��ʽ sum[i] = sum[i-1] + arr[i]
    //��Ȼ������ѧ�����е�ǰn��͹�ʽ֮һ

    //��ע�⣺sum[0] = arr[0]

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11};

    vector<int> sum(arr.size());

    sum[0] = arr[0];
    for (int i = 1; i < sum.size(); i++)
    {
        sum[i] = sum[i-1] + arr[i];
    }

    //����[L,R]
    int L, R = 0;
    cin >> L >> R;

    if (L == 0)
        cout << sum[R] << endl;
    else
        cout << sum[R] - sum[L-1] << endl;
    
    
    system("pause");
    return 0;
}
