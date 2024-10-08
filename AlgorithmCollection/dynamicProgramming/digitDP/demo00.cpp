#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define syc cin.tie(0)->sync_with_stdio(false);
const int md = 1e9 + 7;

int l, r;

int a[19]; // 数位数组
int f[19][100000];  //记录数组
// 表示[pos+1,len]已经填写完了，并且数位和为sum
// 而且我们的[1,len]可以随便填
// f[pos][sum]为满足约束的所有数的数位和之和

// pos为当前数位的位置，我们从最高位开始
/*
    假设我们的数字为 4132
    2   3   1   4
    1   2   3   4 = len

    因此从len开始
 */

//实际计算还有一层含义那便是
/* 
    例如我们要算 0 ~ 4132

    以0为前缀，后面的所有数字的数位和
    0   相当于降了一维

    1 以1为前缀，后面的所有数字的数位和，也就是 1000 ~ 1999

    2 同上

    3

    4

    而如果我们已经确定了 1???
    接下来选择

    比如 12??
    就是 1200 ~ 1299

    再选择比如 127?
    就是1270 ~ 1279

    相当于一个树的超多层展开，最后加和，而记忆化搜索的思路便是

    考虑 3100 ~ 3199
    和 2200 ~ 2299
    和 1300 ~ 1399

    我们会发现，后面不管怎么选择就是一样的，因为前2位的加和为4，已经确定了，后面都是00~99进行选择
    情况一致，因此我们可以这样来保存我们的状态
 */
LL dfs(int pos, bool limit, int sum)
{
    if (!pos) // 递归边界
        return sum;
    // ~ 按位取反，由于我们的f初始化为-1，~(-1)=0 表示还没搜索
    // 这里的含义就是dp已经搜索过了
    if (!limit && ~f[pos][sum]) // 没限制并且dp值已搜索过
        return f[pos][sum];
    int up = limit ? a[pos] : 9;    //limit代表有限制
    //如果有限制最高只能为a[pos]，否则可以取到0~9
    LL res = 0;
    for (int i = 0; i <= up; i++)
        res = (res + dfs(pos - 1, limit && (i == up), sum + i)) % md;
    if (!limit) // 记搜，可复用
        f[pos][sum] = res;
    return res;
}

LL solve(LL x)
{
    int len = 0;
    while(x > 0)
    {
        a[++ len] = x % 10;
        x /= 10;
    }
    return dfs(len, true, 0); //初始状态可以理解为len之前全部卡前导0的上
}

int main(int argc, char const *argv[])
{
    int t = 0;
    cin >> t;
    memset(f,-1,sizeof(f)); //要初始化为-1
    while (t--)
    {
        LL l, r;
        cin >> l >> r;
        cout << (solve(r)-solve(l-1)+md)%md << endl;
    }
    

    system("pause");
    return 0;
}
