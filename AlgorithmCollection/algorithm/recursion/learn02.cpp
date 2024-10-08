#include <bits/stdc++.h>
using namespace std;

//递归的结构学习 #2
//主要阐述两种思想
int ans;
int nums[100];
//1. 二维数组搜索
int n, m;   //n,m分别为数组的行列
void dfs(int x, int y, int data) {
    if (x > n) {    //如果所有行搜完了
        ans = max(ans,data);    //递归终止，处理data
        return;
    }
    if (y > m) {
        //如果当前这一行搜完了就搜下一行
        dfs(x+1,0,data);
        return;
    }

    //加上一些限制条件

    //持续搜索
    dfs(x,y+1,data);
}

//2. 分路搜索
//我们要把递归当成一个分支树来看待，不同的路线代表不同的分支，例如经典的 “取” 与 “不取” 两个状态
void dfs(int cur, int n, int sum) {
    //从线性的递归来看
    if (cur > n) {
        ans = max(ans,sum);
        return;
    }

    //状态分离
    dfs(cur+1,n,sum+nums[cur]); //取
    dfs(cur+1,n,sum);           //不取
}

int main(int argc, char const *argv[])
{
    
    

    system("pause");
    return 0;
}
