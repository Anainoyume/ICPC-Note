//全排列算法
/* 
    排列算法的应用多种多样：
    例如 八数码 问题，在DFS BFS搜索中用处很多
 */
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //我们先介绍标准库的 next_permutation() 函数
    /* 
        这个函数表示
        “求下一个全排列”，参数有3个，前两个为迭代器，最后一个为自写函数
        next_permutation()函数从当前的全排列开始，逐个输出更大的全排列，而不是输出所有的全排列
        （ps.如果为字符，则按照字典序来）
        返回值为bool，如果已经没有更大的全排列了则输出false

        要得到所有的全排列，我们需要从最小的排列开始，如果不是最小的，可以先用sort排序    
     */
    vector<int> arr = {1,5,4,2,3};
    //先排序，从最小开始，这里的全排列是 5! 因此我们会输出 5! = 120个
    sort(arr.begin(),arr.end());
    while (next_permutation(arr.begin(),arr.end()))
    {
        for (auto& i : arr) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    //补充，求前一个全排列
    //prev_permutation(arr.begin(),arr.end());

    system("pause");
    return 0;
}
