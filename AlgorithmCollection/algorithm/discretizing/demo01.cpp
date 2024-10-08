/* 
    ����ѧϰ��ɢ����

    ���
    ��ɢ����һ�����ݴ���ļ��ɣ������Ͽ��Կ�����һ�� ��ϣ��
    �䱣֤�����ڹ�ϣ�Ժ���Ȼ����ԭ����ȫ/ƫ���ϵ��
    ͨ�׵ؽ����ǵ���Щ������Ϊ����ܴ�������Ͳ�֧�֣������޷���Ϊ������±�������ش���
    ��Ӱ�����ս����ֻ��Ԫ��֮�����Դ�С��ϵʱ�����ǿ��Խ�ԭ�������ݰ����������������⣬����ɢ����
    ������ɢ���Ŀ����Ǵ����������������ַ����ȵȡ�
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//˳���Լ�ʵ��һ�¿�������
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
    cout << "���鳤��Ϊ��";
    cin >> N;
    int nums[N];
    
    //setRand(nums,N,1,100);    ��nums��ֵ1-100�������
    //print(nums,N);
    cout << endl;

    //������ɢ��
    Data arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i].value = nums[i];
        arr[i].id = i;
    }

    quickSort(arr,0,N-1);  //����������

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

