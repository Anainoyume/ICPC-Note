//应用
/* 
    通常，能用树状数组的都能用线段树，但显然树状数组写起来更方便一点

    问题：
    查找区间内不同数字的个数
    
    我们使用树状数组或者线段树来维护一个原数组
    如果出现了一个新的数字，标记为1，如果出现了
    重复数字，那就调整之前数字出现的贡献
    
    最终将这个区间里所有元素的1求和，即得到了不同数字的个数
 */
#include <bits/stdc++.h>
using namespace std;

int arr[50010];
int a[50010];
int n, m;
unordered_map<int,int> table;

//求lowBit函数
int lowBit(int num) {
    return num & (-num);
}

//单点修改
void update(int len, int index, int value) {
    for (int i = index; i <= len; i += lowBit(i))
        arr[i] += value;
}

//求前n项和
int sum(int n) {
    int ans = 0;
    //到i的时候还能进行一次运算，之后就不行了，i=1的时候为最小
    for (int i = n; i; i -= lowBit(i))
        ans += arr[i];
    //n为0的时候返回0, arr的第0位也为0
    return ans;
}

//求区间和
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
                //如果已经查过了
                update(n,table[a[j]],-1);   //取消上一次的贡献
            }

            update(n,j,1);
            table[a[j]] = j;
        }
        
        cout << areaSum(l,r) << endl;
    }
    

    system("pause");
    return 0;
}


