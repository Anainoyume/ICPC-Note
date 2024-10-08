//树状数组
/* 
    引入问题：
    给出一个数组，要求其支持单点修改和区间和的操作

    我们先考虑暴力解法：
    单点修改很简单 nums[i] = k; 即可 O(1)
    区间和我们可以使用for循环累加，但是复杂度为 O(n)
    当数据很长的时候，显然效率低下

    我们可以使用树状数组来解决这个问题

    前置知识：
    lowbit() 运算

    lowbit表示一个二进制数字从最后一个1开始以及它后面所有的0组成的数值
    例如：(b表示bin,二进制)
    lowbit(44) -> lowbit(101100b) -> 100b -> 4

    求这个值，我们可以将0...101100取反
    得到 1...010011
    我们再加1 得到 1...010100

    我们进行比对：
    0...101_100
    1...010_100
    可以看到除了最后的100，其他都相反
    使用按位与，即可获得lowbit的值

    lowbit(n) = n & (~n+1)
    我们都知道 ~n+1 = -n
    因此
    lowbit(n) = n & (-n)

    对于一个数组
    8 6 1 4 5 5 1 1 3 2 1 4 9 0 7 4

    我们使用树状数组
    arr[n]，树状数组的长度和nums一样
    arr的第i的元素代表一个从0开始，长度为lowbit(i)的区间和
    并且，对于arr[i]，它的父结点为arr[i+lowbit(i)]
    而它的左上方结点为arr[i-lowbit(i)]

    注意：这里的i为下标+1 ！！！
    下标从1开始记

    对于
    上面的数组，其树状数组为
    下标： 1   2   3   4   5   6    7   8   9   10  11   12   13   14   15   16
          8   14   1   19  5  10   1   31  3    5   1   10   9    9    7    61
 */
#include "../head.h"
using namespace std;

//求lowBit函数
int lowBit(int num) {
    return num & (-num);
}

//单点修改
void update(int *arr, int len, int index, int value) {
    for (int i = index; i <= len; i += lowBit(i))
        arr[i] += value;
}

//求前n项和
int sum(int *arr, int n) {
    int ans = 0;
    //到i的时候还能进行一次运算，之后就不行了，i=1的时候为最小
    for (int i = n; i; i -= lowBit(i))
        ans += arr[i];
    //n为0的时候返回0, arr的第0位也为0
    return ans;
}

//求区间和
int areaSum(int *arr, int left, int right) {
    return sum(arr,right) - sum(arr,left-1);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    int t = 0;
    cout << "请输入数组长度: \n";
    cin >> t;
    
    int nums[t+1];
    for (int i = 1; i < t+1; i++)
    {
        cin >> nums[i];
    }

    int arr[t+1];
    for (int i = 1; i < t+1; i++)
    {
        arr[i] = 0;
    }
    
    //得到树状数组
    //初始化
    for (int i = 1; i < t+1; i++)
    {
        update(arr,t+1,i,nums[i]);
    }
      
    for (int i = 1; i < t+1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    //注意树状数组的下标从1开始的
    cout << areaSum(arr,1,1) << endl;

    system("pause");
    return 0;
}
