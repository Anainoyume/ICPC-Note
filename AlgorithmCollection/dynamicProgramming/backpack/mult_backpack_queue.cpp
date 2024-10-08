
#include <bits/stdc++.h>

/* 
    单调队列解决多重背包问题 O(n^2)
 */

constexpr int MAXV = 4e4 + 10;
constexpr int MAXN = 1e2 + 10;

using namespace std;

using pii = pair<int,int>;

int n, W, last = 0, now = 1;
array<int, MAXN> v, w, k;
array<array<int, MAXV>, 2> f;

// [first : id,  second : val]
deque<pii> q;

int main()
{

    ios::sync_with_stdio(false);
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i] >> k[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int y = 0; y < w[i]; y++) {
            // 清空队列, swap 更快
            deque<pii>().swap(q);
            for (int x = 0; x * w[i] + y <= W; x++) {
                // 弹出不在范围的元素       
                while (!q.empty() && q.front().first < x - k[i]) {
                    q.pop_front();
                }           

                // 保证队列单调 
                while (!q.empty() && q.back().second < f[last][x*w[i]+y] - x*v[i]) {
                    q.pop_back();
                }
 
                q.push_back({x, f[last][x * w[i] + y] - x * v[i]});
                f[now][x * w[i] + y] = max(f[now][x * w[i] + y],  q.front().second + x*v[i]);
            }
        }
        swap(last, now);
    }
    cout << f[last][W] << endl;
    
    system("pause");
    return 0;
}
