//这里尝试自写全排列函数
/* 
    首先我们要明白一点，由于我们求的是全排列，我们最少都要输出n!次
    所以时间复杂度为 O(n!)，是时间复杂度最高的，因此全排列算法，如果真正应用，要么数据很小
    要么在与搜索配合的时候，加入剪枝和判重处理
 */
#include <bits/stdc++.h>
using namespace std;

int arr[5] = {1,2,3,4,5};
int visited[5]; //表示当前数字是否已经访问

int per[5]; //生成的全排列

void dfs(int cur, int n) {  //cur为当前层数，n为最终层数，这里体现为排列的长度
    //先做最终处理
    if (cur == n) {
        for (int i = 0; i < 5; i++)
        {
            cout << per[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)   //如果已经访问过了，直接跳过当前轮
            continue;
        //否则就执行下面的
        visited[i] = 1;
        per[cur] = arr[i];
        dfs(cur+1,n);
        visited[i] = 0; //回溯的时候清除标记，供重新搜索的时候使用
    }
    
}

int main()
{
    dfs(0,5);

    system("pause");
    return 0;
}
