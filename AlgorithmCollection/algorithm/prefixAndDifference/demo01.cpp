//一维前缀和
#include "../head.h"
using namespace std;

int main(int argc, char const *argv[])
{
    //问题，如何快速球一个数组在区间[L,R]之间的和
    //我们考虑计算出该数组所有[0,i]的和，由于从0开始，故称为前缀和
    
    //假设arr[n]，我们有sum[i]数组，表示arr在[0,i]的和
    //存在递推表达式 sum[i] = sum[i-1] + arr[i]
    //显然这是数学中数列的前n项和公式之一

    //但注意：sum[0] = arr[0]

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11};

    vector<int> sum(arr.size());

    sum[0] = arr[0];
    for (int i = 1; i < sum.size(); i++)
    {
        sum[i] = sum[i-1] + arr[i];
    }

    //输入[L,R]
    int L, R = 0;
    cin >> L >> R;

    if (L == 0)
        cout << sum[R] << endl;
    else
        cout << sum[R] - sum[L-1] << endl;
    
    
    system("pause");
    return 0;
}
