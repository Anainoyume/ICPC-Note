#include "../head.h"
using namespace std;
//һά���
/*
    ���⣺
    ���Ǹ���һ������arr[n]
    ���ǽ���m�β������ֱ���arr��������[L,R]+v (vΪ����)
    ����m�β����Ժ������ʣ��������������ʲô���ģ�

    ����������
    ����arr = {1 , 3 , 5 , 7 , 9};
    d = {1 , 2 , 2 , 2 , 2};
    Ҳ����˵ d[0] = arr[0]
            d[i] = arr[i] - arr[i-1]

    ��������ʲô���أ�
    ���ǳ��Զ�d����ʹ��ǰ׺���
    sum(d) = {1 , 3 , 5 , 7 , 9};
    ���Ƿ���sum��d��ԭΪ��arr

    ���Ǵ���ѧ�ĽǶȣ����Դӻ�����΢��������������
    ��������Ҫ��ȷ�������ǰ׺�͵�������
    ����ֱ������ѧ֤��
                n        n
    sum(d)[n] = �� d[i] = �� (arr[i] - arr[i-1]) + arr[0] = arr[n]
               i=0      i=1

    ������֤����

    ����ͬʱ���ǣ�����һ������ arr
    ������[L,R]ͬʱ +v ,��ô���ǵĲ�֣�����d[L]+v d[R+1]-v
    �м�����Ĳ��ȫ�����䣬��Ϊͬʱ���ϼ�ȥһ����������
    ����ģ����R+1 = arr.size()-1 ��ôֻ��d[L]+v�������ȫ������

    Ȼ����������ǰ׺�ͻָ����
*/


int main(int argc, char const *argv[])
{
    //һά���
    vector<int> arr = {1 , 3 , 5 , 7 , 9 , 12};

    //����������
    vector<int> d(arr.size());
    d[0] = arr[0];
    for (int i = 1; i < d.size(); i++)
    {
        d[i] = arr[i] - arr[i-1];
    }
    

    int m, L, R, v = 0;
    cin >> m;   //����m�β���
    for (int i = 0; i < m; i++)
    {
        cout << "���������������:";
        cin >> L >> R >> v;
        cout << endl;

        d[L] += v;
        if (R < arr.size()-1)
            d[R+1] -= v;
    }

    vector<int> sum_d(d.size());
    //ǰ׺�͸�ԭ�������
    sum_d[0] = d[0];
    for (int i = 1; i < sum_d.size(); i++)
    {
        sum_d[i] = sum_d[i-1] + d[i];
    }
    
    cout << endl;
    //�����ԭ����
    for (int num : sum_d) {
        cout << num << " ";
    }
    cout << endl;
    

    // cin.get();   ��������������Ҫ����cin����Ϊ��������ݵĻس��ᱻcin.get���յ�
    // cin.get();

    system("pause");    //ʹ��pause����
    return 0;
}
