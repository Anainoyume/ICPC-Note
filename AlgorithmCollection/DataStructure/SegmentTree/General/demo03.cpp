/* 
    维护差分数组

    1. 区间修改
    2. 区间值相同
    3. 区间严格递增
    4. 区间严格递减
    5. 区间为单峰
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using State = array<int, 4>;

#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)

const int maxN = 2e5+5;
int n, q;
ll a[maxN], b[maxN];
State tag[maxN << 2];

State unite(State a, State b){
    State tmp;
    tmp[0] = a[0] & b[0];   //相同状态
    tmp[1] = a[1] & b[1];   //递增状态
    tmp[2] = a[2] & b[2];   //递减状态

    // 单峰状态，允许合并
    tmp[3] = (a[1] & b[2]) | (a[1] & b[3]) | (a[3] & b[2]);
    return tmp;
}

// 状态转换
void push_up(int x) {
    tag[x] = unite(tag[ls(x)], tag[rs(x)]);
}

void build(int x, int l, int r){
    if(l == r) {
        if (b[l] == 0)      // 差分为 0，相同
            tag[x][0] = 1;
        else if (b[l] > 0)  // 差分(导数)大于0，递增
            tag[x][1] = 1;
        else                // 差分(导数)小于0，递减
            tag[x][2] = 1;
        return;
    }
    int mid = l + (r - l >> 1);
    build(ls(x), l, mid);
    build(rs(x), mid+1, r);
    push_up(x);
}

// p 为分界表， 差分数组 区间修改，[0,l] 和 [r+1,n] 是不一样的
void update(int x, int l, int r, int p, int v){
    if(l == r){
        b[l] += v;
        tag[x][0] = tag[x][1] = tag[x][2] = tag[x][3] = 0;

        if (b[l] == 0) 
            tag[x][0] = 1;
        else if(b[l] > 0) 
            tag[x][1] = 1;
        else 
            tag[x][2] = 1;
        return;
    }

    int mid = l + (r - l >> 1);
    if(p <= mid) 
        update(ls(x), l, mid, p, v);
    else 
        update(rs(x), mid+1, r, p, v);

    push_up(x);
}

State query(int x, int l, int r, int L, int R){
    if(L <= l && r <= R)
        return {tag[x][0], tag[x][1], tag[x][2], tag[x][3]};

    int mid = l + (r - l >> 1);;

    if (R <= mid) 
        return query(ls(x), l, mid, L, R);
    else if (L > mid) 
        return query(rs(x), mid+1, r, L, R);
    else {
        State left = query(ls(x), l, mid, L, R);
        State right = query(rs(x), mid+1, r, L, R);
        return unite(left, right);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i] - a[i-1];
    }
    build(1, 2, n);
    cin >> q;
    while(q--){
        int op, l, r, x;
        cin >> op >> l >> r;
        if(op == 1) {
            cin >> x;
            if(l > 1) update(1, 2, n, l, x);
            if(r < n) update(1, 2, n, r+1, -x);
        } 
        else if(op == 2) {
            if(l == r){
                cout << "1\n";
                continue;
            }
            cout << query(1, 2, n, l+1, r)[0] << "\n";
        } 
        else if(op == 3) {
            if(l == r){
                cout << "1\n";
                continue;
            }
            cout << query(1, 2, n, l+1, r)[1] << "\n";
        } 
        else if(op == 4) {
            if(l == r){
                cout << "1\n";
                continue;
            }
            cout << query(1, 2, n, l+1, r)[2] << "\n";
        } 
        else {
            cout << query(1, 2, n, l+1, r)[3] << "\n";
        }
    }
    return 0;
}