#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<int> data(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> data[i];
    }

    priority_queue<int> topHeap;    // �󶥶�
    priority_queue<int, vector<int>, greater<int>> downHeap; // С����

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            // ��һ��Ԫ��
            topHeap.push(data[i]);
        }
        else {
            // �ж�ÿ�μӵ�����
            if (data[i] <= topHeap.top()) topHeap.push(data[i]);
            else downHeap.push(data[i]);
        }

        // ά����������������ƽ��
        while (abs((int)topHeap.size() - (int)downHeap.size()) > 1) {
            if (topHeap.size() > downHeap.size()) {
                downHeap.push(topHeap.top());
                topHeap.pop();
            }
            else {
                topHeap.push(downHeap.top());
                downHeap.pop();
            }
        }

        if (i & 1) 
            cout << (topHeap.size() > downHeap.size() ? topHeap.top() : downHeap.top()) << endl;
    }

    


    system("pause");
    return 0;
}