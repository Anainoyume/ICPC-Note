//ȫ�����㷨
/* 
    �����㷨��Ӧ�ö��ֶ�����
    ���� ������ ���⣬��DFS BFS�������ô��ܶ�
 */
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //�����Ƚ��ܱ�׼��� next_permutation() ����
    /* 
        ���������ʾ
        ������һ��ȫ���С���������3����ǰ����Ϊ�����������һ��Ϊ��д����
        next_permutation()�����ӵ�ǰ��ȫ���п�ʼ�������������ȫ���У�������������е�ȫ����
        ��ps.���Ϊ�ַ��������ֵ�������
        ����ֵΪbool������Ѿ�û�и����ȫ�����������false

        Ҫ�õ����е�ȫ���У�������Ҫ����С�����п�ʼ�����������С�ģ���������sort����    
     */
    vector<int> arr = {1,5,4,2,3};
    //�����򣬴���С��ʼ�������ȫ������ 5! ������ǻ���� 5! = 120��
    sort(arr.begin(),arr.end());
    while (next_permutation(arr.begin(),arr.end()))
    {
        for (auto& i : arr) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    //���䣬��ǰһ��ȫ����
    //prev_permutation(arr.begin(),arr.end());

    system("pause");
    return 0;
}
