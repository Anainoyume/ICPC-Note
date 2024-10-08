#include "../head.h"
using namespace std;
//一维差分
/*
    问题：
    我们给定一个数组arr[n]
    我们进行m次操作，分别让arr任意区间[L,R]+v (v为常数)
    进行m次操作以后，我们问：这个数组现在是什么样的？

    我们引入差分
    对于arr = {1 , 3 , 5 , 7 , 9};
    d = {1 , 2 , 2 , 2 , 2};
    也就是说 d[0] = arr[0]
            d[i] = arr[i] - arr[i-1]

    这个差分有什么用呢？
    我们尝试对d数组使用前缀求和
    sum(d) = {1 , 3 , 5 , 7 , 9};
    我们发现sum将d还原为了arr

    我们从数学的角度，可以从积分与微分来理解这个操作
    首先我们要明确，差分是前缀和的逆运算
    我们直接用数学证明
                n        n
    sum(d)[n] = Σ d[i] = Σ (arr[i] - arr[i-1]) + arr[0] = arr[n]
               i=0      i=1

    这样便证明了

    我们同时考虑，对于一列数字 arr
    其区间[L,R]同时 +v ,那么它们的差分，除了d[L]+v d[R+1]-v
    中间的数的差分全部不变，因为同时加上减去一个数，其差不变
    特殊的，如果R+1 = arr.size()-1 那么只有d[L]+v，其余差全部不变

    然后我们再用前缀和恢复差分
*/


int main(int argc, char const *argv[])
{
    //一维差分
    vector<int> arr = {1 , 3 , 5 , 7 , 9 , 12};

    //先求差分数组
    vector<int> d(arr.size());
    d[0] = arr[0];
    for (int i = 1; i < d.size(); i++)
    {
        d[i] = arr[i] - arr[i-1];
    }
    

    int m, L, R, v = 0;
    cin >> m;   //进行m次操作
    for (int i = 0; i < m; i++)
    {
        cout << "请输入区间与差数:";
        cin >> L >> R >> v;
        cout << endl;

        d[L] += v;
        if (R < arr.size()-1)
            d[R+1] -= v;
    }

    vector<int> sum_d(d.size());
    //前缀和复原差分数组
    sum_d[0] = d[0];
    for (int i = 1; i < sum_d.size(); i++)
    {
        sum_d[i] = sum_d[i-1] + d[i];
    }
    
    cout << endl;
    //输出复原数组
    for (int num : sum_d) {
        cout << num << " ";
    }
    cout << endl;
    

    // cin.get();   这里如果用这个需要两个cin，因为最后传入数据的回车会被cin.get接收到
    // cin.get();

    system("pause");    //使用pause更好
    return 0;
}
