//���ﳢ����дȫ���к���
/* 
    ��������Ҫ����һ�㣬�������������ȫ���У��������ٶ�Ҫ���n!��
    ����ʱ�临�Ӷ�Ϊ O(n!)����ʱ�临�Ӷ���ߵģ����ȫ�����㷨���������Ӧ�ã�Ҫô���ݺ�С
    Ҫô����������ϵ�ʱ�򣬼����֦�����ش���
 */
#include <bits/stdc++.h>
using namespace std;

int arr[5] = {1,2,3,4,5};
int visited[5]; //��ʾ��ǰ�����Ƿ��Ѿ�����

int per[5]; //���ɵ�ȫ����

void dfs(int cur, int n) {  //curΪ��ǰ������nΪ���ղ�������������Ϊ���еĳ���
    //�������մ���
    if (cur == n) {
        for (int i = 0; i < 5; i++)
        {
            cout << per[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)   //����Ѿ����ʹ��ˣ�ֱ��������ǰ��
            continue;
        //�����ִ�������
        visited[i] = 1;
        per[cur] = arr[i];
        dfs(cur+1,n);
        visited[i] = 0; //���ݵ�ʱ�������ǣ�������������ʱ��ʹ��
    }
    
}

int main()
{
    dfs(0,5);

    system("pause");
    return 0;
}
