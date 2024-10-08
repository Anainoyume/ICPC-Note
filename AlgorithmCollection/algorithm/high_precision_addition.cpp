/* 
    高精度加法：
    我们在处理一些大数据的时候，常规的数据结构，哪怕是unsigned long long也不能满足我们的需求的时候
    我们就需要自己实现大数据的高精度加法

    原理很简单，便是模拟竖式加法，两位依次相加，满十进一
    注意我们在相加的时候是从个位开始加，所以我们的数字要倒过来，同理，输出的时候也是倒序输出

    代码如下：
 */
#include <bits/stdc++.h>
using namespace std;

int a[5010], b[5010], result[5010]; //预设有5010位数字

void hp(string& strA, string& strB) {
    int len = max(strA.size(),strB.size());    //表示数字的位数
    //倒序输入数据
    for (int i = 0; i < strA.size(); i++)
    {
        a[strA.size()-1-i] = strA[i] - '0';
    }
    for (int i = 0; i < strB.size(); i++)
    {
        b[strB.size()-1-i] = strB[i] - '0';
    }

    //核心代码，相加
    for (int i = 0; i < len; i++)
    {
        result[i] += a[i] + b[i];
        result[i+1] = result[i]/10;
        result[i] %= 10;
    }
    
    if (result[len]) len++; //存在数字就长度加一

    //倒序输出
    for (int i = len-1; i >= 0; i--)
    {
        cout << result[i];
    }
    cout << endl;
    
}

int main(int argc, char const *argv[])
{
    string strA, strB;  //两个数字的字符串
    strA = "249759387198273897154892772";
    strB = "9734874871289274783275223";

    hp(strA,strB);
    
    
    system("pause");
    return 0;
}


