/* 
    DP ���ǵ��������Ż�
    ���Դ� �������� ��������

    priority_queueԭ��
    template<
        class T,
        class Container = std::vector<T>,
        class Compare = std::less<typename Container::value_type>
    > class priority_queue;

    Ĭ�ϴӴ�С���� std::less
 */
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;
int n, k;
int arr[maxN];

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    priority_queue<int,vector<int>,less<int>> que1; 
    priority_queue<int,vector<int>,greater<int>> que2; 
    //��ʼ��
    int del = arr[0];
    for (size_t i = 0; i < k; i++)
    {
        que1.push(arr[i]);
        que2.push(arr[i]);
    }

    for (int i = k-1; i < n; i++)
    {
        
    }
    
    
    
    system("pause");
    return 0;
}



