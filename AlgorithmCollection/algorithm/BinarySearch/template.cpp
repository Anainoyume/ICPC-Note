#include <bits/stdc++.h>
using namespace std;
/* 
    完美二分查找模板 (ps. 查找最接近的值)
    左闭右闭，查找最接近的值
 */
int main()
{
    int target = 23;
    vector<int> a = {1,4,5,5,6,7,9,9,12,13,16,16,16,16,19};

    /* --------------------------------------------------------------------------- */
    auto search = [&](int target, vector<int>& a) -> int {
        int l = 0, r = a.size()-1;
        while (l <= r) {
            int mid = l + ((r-l) >> 1);
            if (target >= a[mid]) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        if (r < 0) return l;
        if (l > a.size()-1) return r;
        return abs(a[l]-target) < abs(a[r]-target) ? l : r;
    };

    // 如果是同一个数组中，避免查到自己
    auto judge = [&](int index, vector<int>& a) -> int {
        int i = search(a[index],a);
        if (i != index) return i;
        else {
            if (i == 0) {
                return 1;
            }
            if (i == a.size()-1) {
                return a.size()-2;
            }
            return abs(a[i]-a[i-1]) < abs(a[i]-a[i+1]) ? i-1 : i+1;
        }
    };
    /* --------------------------------------------------------------------------- */
    
    while (target != 114514) {
        cin >> target;
        cout << a[search(target,a)] << endl;
    }
    

    system("pause");
    return 0;
}