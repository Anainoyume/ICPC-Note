/* 
    �� - �����ζ���ģ��
    ֻҪcheck����, �����ܶ�
 */
#include <bits/stdc++.h>
using namespace std;

bool check(int x) {

}

// ģ��һ
// ��һ��ģ���Ǿ���������Ŀ��, ֻҪ�������Ҵ𰸣����õ�һ��ģ�壬mid���ü�һ��r=mid��l��һ
int binarySearch1(int left, int right) {
    int l{left}, r{right};
    
    while (l < r) {
        int mid = l + (r - l >> 1);	//(l+r)/2
        if (check(mid))  
            r = mid;    // check()�ж�mid�Ƿ���������
        else 
            l = mid + 1;
    }

    return l;
}

// ģ���
// �ڶ���ģ���Ǿ���������Ŀ��, ֻҪ�������Ҵ𰸣����õڶ���ģ�壬midҪ��һ��l=mid��rҪ��һ
int binarySearch2(int left, int right) {
    int l{left}, r{right};

    while (l < r) {
        int mid = l + (r - l + 1 >> 1);	//(l+r+1)/2
        if (check(mid))  
            l = mid;
        else 
            r = mid - 1;
    }
    
    return l;
}

signed main()
{




    system("pause");
    return 0;
}