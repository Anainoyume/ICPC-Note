#include <bits/stdc++.h>
using namespace std;

//�ݹ�Ľṹѧϰ #2
//��Ҫ��������˼��
int ans;
int nums[100];
//1. ��ά��������
int n, m;   //n,m�ֱ�Ϊ���������
void dfs(int x, int y, int data) {
    if (x > n) {    //���������������
        ans = max(ans,data);    //�ݹ���ֹ������data
        return;
    }
    if (y > m) {
        //�����ǰ��һ�������˾�����һ��
        dfs(x+1,0,data);
        return;
    }

    //����һЩ��������

    //��������
    dfs(x,y+1,data);
}

//2. ��·����
//����Ҫ�ѵݹ鵱��һ����֧������������ͬ��·�ߴ���ͬ�ķ�֧�����羭��� ��ȡ�� �� ����ȡ�� ����״̬
void dfs(int cur, int n, int sum) {
    //�����Եĵݹ�����
    if (cur > n) {
        ans = max(ans,sum);
        return;
    }

    //״̬����
    dfs(cur+1,n,sum+nums[cur]); //ȡ
    dfs(cur+1,n,sum);           //��ȡ
}

int main(int argc, char const *argv[])
{
    
    

    system("pause");
    return 0;
}
