//LIS����ģ�����
#include <bits/stdc++.h>
using namespace std;

int n, ans;
int b[100000];    //����
int sta[100000];    //����ջ

int main(int argc, char const *argv[])
{
    int n{};
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    int k{};
    for (int i = 0; i < n; i++)
    {
        if (b[i] >= sta[k-1] || k == 0) {
            sta[k++] = b[i];
        }
        else {
            int index = upper_bound(sta,sta+k,b[i])-sta;
            sta[index] = b[i];
        }
    }

    /* 
        1������Ҫ����½������У���
        int index = lower_bound(sta,sta+k,b[i])-sta;
        ��Ϊ
        int index = lower_bound(sta,sta+k,b[i],greater())-sta;

        if����е�>�Ÿ�Ϊ<�ż��ɡ�

        2������Ҫ������������У���lower_bound��Ϊupper_bound��if����е�>�Ÿ�Ϊ>=�ż��ɡ�

        3������Ҫ������������У���1���е�lower_bound��Ϊupper_bound��if����е�<�Ÿ�Ϊ<=�ż��ɡ�
           ����ʹ��greater()
     */

    cout << k << endl;
    
    system("pause");
    return 0;
}
