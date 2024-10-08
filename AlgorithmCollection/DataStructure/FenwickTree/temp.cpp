#include <bits/stdc++.h>
using namespace std;
/* 
    测试样例：
    6
    1 2 3 4 3 5
    3
    1 2
    3 5
    2 6
 */
//arr为维护的树状数组，a为原数组，p[x]表示元素x在数组a中最后一次出现的位置的下标，ans为答案数组
//n为a数组元素个数，m为查询次数
int arr[500005], a[500005], p[1000005], ans[200005];
int n, m;

//求lowBit函数
int lowBit(int num) {
    return num & (-num);
}

//单点修改
void add(int index, int value) {
    for (int i = index; i <= n; i += lowBit(i))
        arr[i] += value;
}

//求前n项和
int query(int n) {
    int ans = 0;
    //到i的时候还能进行一次运算，之后就不行了，i=1的时候为最小
    for (int i = n; i; i -= lowBit(i))
        ans += arr[i];
    //n为0的时候返回0, arr的第0位也为0
    return ans;
}

struct ask  //查询结构体
{
    int l, r, id;
} q[200005];
// q 为查询结构体数组

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }

    //将所有的查询，按照右端点从小到大排序
    sort(q + 1, q + 1 + m, [&](const ask a, const ask b){
        return a.r < b.r; 
    });

    // r 用于追踪数组 a 中元素的当前处理位置
    int r = 0;
    for (int i = 1; i <= m; ++i)    //依次遍历每个查询
    {
        while (r < q[i].r)
        {
            ++r;
            add(r, 1);

            if (p[a[r]])    //如果已经查到过
                add(p[a[r]], -1);

            p[a[r]] = r;    //更新最后出现的下标
        }

        ans[q[i].id] = query(r) - query(q[i].l - 1);
    }

    for (int i = 1; i <= m; ++i)
        cout << ans[i] << endl;

    system("pause");
    return 0;
}
