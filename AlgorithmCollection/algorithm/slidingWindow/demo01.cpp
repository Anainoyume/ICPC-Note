/* 
    ������������
    1. �����������ֵ
 */
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+5;
int n, k;
int arr[maxN];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    deque<int> que; //���󻬶��������ֵ����������ϸ��˳�������
    /* 
        ���ǵ� deque ������һ����������
        ����һ�����ڣ�����ÿ�δӴ��ڵ��ұ߽������Ԫ�ء�

        ������������һ����С�����֣���ô����һ�ֿ��ܣ������һϵ�����ֶ���������ָ�С��
        �����Ļ����������Ҳ�ǿ��ܳ�Ϊ ĳһ������ �����ֵ�ġ�

        ��������ֵ���һ����������֣���ô��ʱ�����������ұ߽���ߵ����бȵ�ǰ����С�������Ͷ�����
        �߳������ˣ���Ϊ�����Ѿ��������ٳ�Ϊ���ֵ�ˡ�

        ͬʱ�������뿪���ڵ�Ԫ�أ�����ҲҪ����ɾ����

        ������һ�����������������Ӧֵ���±꣬������ֵ����
     */

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        //ɾ�����²���Ԫ��С����
        while (!que.empty() && arr[i] > arr[que.back()]) que.pop_back();
        que.emplace_back(i);
    
        if (!que.empty() && que.front() <= i-k) que.pop_front();

        if (i >= k) {
            ans.push_back(arr[que.front()]);
        }
    }
    
    for (auto &&num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    

    system("pause");
    return 0;
}