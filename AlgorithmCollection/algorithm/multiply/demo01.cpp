#include "../head.h"
using namespace std;
//������
/*
    ���磺
    ����þ������ٵ���������� [0,31] ֮���������������ֻ������ƽ��һ�˷����룩

    ���ǵ�Ȼ������ weight:1 ��һ��һ����31��
    �����õķ�������
    1 2 4 8 16������ֻҪ5����

    ˼ά�����������ֿ�����2��n�η�������ʾ
    ���ǾͿ��ԴӾ����ܴ�Ŀ�ʼѡ��

    ����ʹ��
    f[i][n] ����ʾ �ڴ���� i ��ʼ���������� 2^n ��
    ����ע�⵽ ���� f[i][n] ��������2^n
    ����Ҳ���������� 2^n-1 ����
    ������
    f[i][n] = f[f[i][n-1]][n-1]
    ���Ʊ��ʽ������

*/

int main(int argc, char const *argv[])
{
    int target = 7;    //Ŀ��Ϊ31

    int to[1000][6];  //��ת����
    int count = 0;  //����

    for (int i = 0; i < 1000; i++) {
        to[i][0] = i+1;
    }

    for (int j = 1; j < 6; j++) {
        for (int i = 0; i < 32; i++)
        {
            to[i][j] = to[to[i][j-1]][j-1];
        }  
    }

    //�����ת����
    // for (int i = 0; i < 31; i++) {
    //     for (int j = 0; j < 6; j++)
    //     {
    //         cout << to[i][j] << " ";
    //     }  
    //     cout << endl;
    // }

    int i = 0;
    int n = 5;
    while (to[i][n] != target) {
        cout << to[i][n] << endl;
        if (to[i][n] > target) {
            n--;
        }
        else if (to[i][n] < target) {
            i = to[i][n];
            count++;
        }
        else {
            break;
        }
    }
    cout << endl;

    cout << count+1 << endl;

    cin.get();
    return 0;
}
