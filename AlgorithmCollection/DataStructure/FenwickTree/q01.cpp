//Ӧ��
/* 
    ͨ����������״����Ķ������߶���������Ȼ��״����д����������һ��

    ���⣺
    ���������ڲ�ͬ���ֵĸ���
    
    ����ʹ����״��������߶�����ά��һ��ԭ����
    ���������һ���µ����֣����Ϊ1�����������
    �ظ����֣��Ǿ͵���֮ǰ���ֳ��ֵĹ���
    
    ���ս��������������Ԫ�ص�1��ͣ����õ��˲�ͬ���ֵĸ���
 */
#include <bits/stdc++.h>
using namespace std;

int arr[50010];
int a[50010];
int n, m;
unordered_map<int,int> table;

//��lowBit����
int lowBit(int num) {
    return num & (-num);
}

//�����޸�
void update(int len, int index, int value) {
    for (int i = index; i <= len; i += lowBit(i))
        arr[i] += value;
}

//��ǰn���
int sum(int n) {
    int ans = 0;
    //��i��ʱ���ܽ���һ�����㣬֮��Ͳ����ˣ�i=1��ʱ��Ϊ��С
    for (int i = n; i; i -= lowBit(i))
        ans += arr[i];
    //nΪ0��ʱ�򷵻�0, arr�ĵ�0λҲΪ0
    return ans;
}

//�������
int areaSum(int left, int right) {
    return sum(right) - sum(left-1);
}

int main(int argc, char const *argv[])
{
    /* 
        10
        1 1 2 3 4 1 2 1 5 7
     */
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    cin >> m;
    int l = 0, r = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        for (int j = l; j <= r; j++)
        {
            if (table.find(a[j]) != table.end()) {
                //����Ѿ������
                update(n,table[a[j]],-1);   //ȡ����һ�εĹ���
            }

            update(n,j,1);
            table[a[j]] = j;
        }
        
        cout << areaSum(l,r) << endl;
    }
    

    system("pause");
    return 0;
}


