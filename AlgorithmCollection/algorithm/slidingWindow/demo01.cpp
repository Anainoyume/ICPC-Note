/* 
    滑动窗口问题
    1. 滑动窗口最大值
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
    
    deque<int> que; //先求滑动窗口最大值，我们来仔细理顺这个过程
    /* 
        我们的 deque 首先是一个单调队列
        对于一个窗口，我们每次从窗口的右边界加入新元素。

        如果这个数字是一个更小的数字，那么存在一种可能，后面的一系列数字都比这个数字更小。
        这样的话，这个数字也是可能成为 某一个区间 的最大值的。

        但如果出现的是一个更大的数字，那么此时，这个区间里，右边界左边的所有比当前数字小的数。就都可以
        踢出队列了，因为它们已经不可能再成为最大值了。

        同时，对于离开窗口的元素，我们也要将其删除。

        我们用一个队列来储存数组对应值的下标，而不是值本身
     */

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        //删除比新插入元素小的数
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