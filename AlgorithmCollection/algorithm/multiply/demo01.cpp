#include "../head.h"
using namespace std;
//倍增法
/*
    例如：
    如何用尽可能少的砝码称量出 [0,31] 之间的所有重量？（只能在天平的一端放砝码）

    我们当然可以用 weight:1 的一个一个放31个
    但更好的方法是用
    1 2 4 8 16，这样只要5个了

    思维就是任意数字可以用2的n次方和来表示
    我们就可以从尽可能大的开始选择

    我们使用
    f[i][n] 来表示 在从起点 i 开始，往后面跳 2^n 格
    我们注意到 例如 f[i][n] 我们跳了2^n
    我们也可以跳两次 2^n-1 距离
    所以有
    f[i][n] = f[f[i][n-1]][n-1]
    递推表达式就有了

*/

int main(int argc, char const *argv[])
{
    int target = 7;    //目标为31

    int to[1000][6];  //跳转数组
    int count = 0;  //计数

    for (int i = 0; i < 1000; i++) {
        to[i][0] = i+1;
    }

    for (int j = 1; j < 6; j++) {
        for (int i = 0; i < 32; i++)
        {
            to[i][j] = to[to[i][j-1]][j-1];
        }  
    }

    //输出跳转数组
    // for (int i = 0; i < 31; i++) {
    //     for (int j = 0; j < 6; j++)
    //     {
    //         cout << to[i][j] << " ";
    //     }  
    //     cout << endl;
    // }

    int i = 0;
    int n = 5;
    while (to[i][n] != target) {
        cout << to[i][n] << endl;
        if (to[i][n] > target) {
            n--;
        }
        else if (to[i][n] < target) {
            i = to[i][n];
            count++;
        }
        else {
            break;
        }
    }
    cout << endl;

    cout << count+1 << endl;

    cin.get();
    return 0;
}
