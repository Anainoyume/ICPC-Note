/* 
    带区间修改和区间查询的树状数组
 */
#include <bits/stdc++.h>
using namespace std;

struct Fenwick 
{
    // 原数组 和 差分数组1, 2
    vector<int> arr, d1, d2;
    size_t size;

    inline int lowbit(int x) {
        return x & (-x);
    }
    
    // 下标从 1 开始
    void init(size_t n) {
        arr.resize(n+1,0);
        d1.resize(n+2,0);
        d2.resize(n+2,0);
        size = n;
    }

    // 高级树状数组
    // 对 d 的区间修改
    // 初始化差分数组
    void initDarr() {
        d1[1] = d2[1] = arr[1];
        for (int i = 2; i <= size; ++i) {
            d1[i] = arr[i] - arr[i-1];
            d2[i] = i * (arr[i] - arr[i-1]);
        }
    }

    // 对差分数组的增加
    void add(int index, int value){ 
        for (int i = index; i <= size; i += lowbit(i))
            d1[i] += value, d2[i] += value * index;
    }

    //给区间[l, r]加上x
    void range_add(int left, int right, int value){ 
        add(left, value), add(right + 1, -value);
    }

    // 前缀查询
    int sum(int index) {
        int res = 0;
        for(int i = index; i; i -= lowbit(i))
            res += (index + 1) * d1[i] - d2[i];
        return res;
    }

    // 区间和查询
    int sum(int left, int right) {
        return sum(right) - sum(left - 1);
    }

};

signed main()
{
    Fenwick tr;
    tr.init(10);

    cout << tr.sum(1,10) << endl;
    tr.range_add(2,5,2);
    tr.range_add(6,6,3);
    cout << tr.sum(1,10) << endl;

    system("pause");
    return 0;
}