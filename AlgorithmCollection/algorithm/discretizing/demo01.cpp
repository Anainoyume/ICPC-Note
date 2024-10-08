/* 
    这里学习离散化：

    简介
    离散化是一种数据处理的技巧，本质上可以看成是一种 哈希，
    其保证数据在哈希以后仍然保持原来的全/偏序关系。
    通俗地讲就是当有些数据因为本身很大或者类型不支持，自身无法作为数组的下标来方便地处理，
    而影响最终结果的只有元素之间的相对大小关系时，我们可以将原来的数据按照排名来处理问题，即离散化。
    用来离散化的可以是大整数、浮点数、字符串等等。
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//顺便自己实现一下快速排序
void quickSort(int* nums, int l, int r) {
    if (l >= r)
        return;

    int mark = nums[l];
    int left = l;
    int right = r;
    while (left < right) {
        while (nums[right] >= mark && left < right) right--;
        nums[left] = nums[right];
        while (nums[left] <= mark && left < right) left++;
        nums[right] = nums[left];
    }
    nums[left] = mark;

    quickSort(nums,l,left-1);
    quickSort(nums,left+1,r);
}

struct Data
{
    int value;
    int id;
};

void quickSort(Data* nums, int l, int r) {
    if (l >= r)
        return;

    Data mark = nums[l];
    int left = l;
    int right = r;
    while (left < right) {
        while (nums[right].value >= mark.value && left < right) right--;
        nums[left] = nums[right];
        while (nums[left].value <= mark.value && left < right) left++;
        nums[right] = nums[left];
    }
    nums[left] = mark;

    quickSort(nums,l,left-1);
    quickSort(nums,left+1,r);
}

void quickSort_id(Data* nums, int l, int r) {
    if (l >= r)
        return;

    Data mark = nums[l];
    int left = l;
    int right = r;
    while (left < right) {
        while (nums[right].id >= mark.id && left < right) right--;
        nums[left] = nums[right];
        while (nums[left].id <= mark.id && left < right) left++;
        nums[right] = nums[left];
    }
    nums[left] = mark;

    quickSort_id(nums,l,left-1);
    quickSort_id(nums,left+1,r);
}

int main(int argc, char const *argv[])
{
    int N = 0;
    cout << "数组长度为：";
    cin >> N;
    int nums[N];
    
    //setRand(nums,N,1,100);    给nums赋值1-100的随机数
    //print(nums,N);
    cout << endl;

    //进行离散化
    Data arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i].value = nums[i];
        arr[i].id = i;
    }

    quickSort(arr,0,N-1);  //对数据排序

    for (int i = 0; i < N; i++)
    {
        cout << "(" << arr[i].value << "," << arr[i].id << ") "; 
    }
    cout << endl;

    for (int i = 0; i < N; i++)
    {
        arr[i].value = i+1;
    }

    for (int i = 0; i < N; i++)
    {
        cout << "(" << arr[i].value << "," << arr[i].id << ") "; 
    }
    cout << endl;

    quickSort_id(arr,0,N-1);

    for (int i = 0; i < N; i++)
    {
        cout << "(" << arr[i].value << "," << arr[i].id << ") "; 
    }
    cout << endl;

    cout << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i].value << " ";
    }
    cout << endl;
    

    
    

    
    
    system("pause");
    return 0;
}

