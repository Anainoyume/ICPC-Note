#include <bits/stdc++.h>
using namespace std;

// 一个递归的结构，参数还可以用来存数据，和记录数据 如求和
void dfs(int cur, int all) {
    if (cur == all) {
        //终点（条件）处理
        return;
    }

    //甚至如果有 多路递归， 我们可以加一个参数 route ，然后
    //在这个位置再加上一段递归的代码 route+1 所有数据初始化
    //表示这是第二轮递归，注意是第二轮，而不是一轮递归里的第二层

    for (int i = 0; i < 100; i++)
    {
        //上面的是 当前处理

        dfs(cur+1,all);

        //下面的是 回溯处理
    }

    //for跑完了还没有结果，那就是失配代码
    
}

//如果我们查询到了结果，想要快速返回，可以直接exit(0);退出所有递归，终止程序
//也可以使用int ok = 1;来切换状态，在回溯处理的上面
/* 
    加上：
    if (ok == 1)
        return;

    这样一路回退到起点，然后终止
 */

int main(int argc, char const *argv[])
{
    
    

    system("pause");
    return 0;
}
