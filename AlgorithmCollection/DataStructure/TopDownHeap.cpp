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

    priority_queue<int> topHeap;    // 大顶堆
    priority_queue<int, vector<int>, greater<int>> downHeap; // 小顶堆

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            // 第一个元素
            topHeap.push(data[i]);
        }
        else {
            // 判断每次加到哪里
            if (data[i] <= topHeap.top()) topHeap.push(data[i]);
            else downHeap.push(data[i]);
        }

        // 维护两个队列数量的平衡
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