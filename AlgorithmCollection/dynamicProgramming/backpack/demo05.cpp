#include <bits/stdc++.h>
using namespace std;

struct node
{
    int index, money, weight, prev;
};

const int maxN = 65;
int n, k, ans;
node arr[maxN];
bool vis[maxN]; //������ѡ�����
int cnt[maxN];  //������Ӧ������ѡ������

void dfs(int cur, int sum, int res) {
    if (cur > k) {
        ans = max(ans,sum);
        return;
    }

    //��ѡ��
    dfs(cur+1,sum,res); 

    //ѡ��
    if (arr[cur].prev == 0) {
        //����
        if (res >= arr[cur].money) {
            vis[arr[cur].index] = true;
            dfs(cur+1,sum+arr[cur].money*arr[cur].weight,res-arr[cur].money);
            vis[arr[cur].index] = false;
        }
    }
    else {
        //��ǰ�Ǹ���
        if (res >= arr[cur].money && vis[arr[cur].prev] && cnt[arr[cur].prev] < 2) {
            vis[arr[cur].index] = true;
            cnt[arr[cur].prev]++;
            dfs(cur+1,sum+arr[cur].money*arr[cur].weight,res-arr[cur].money);
            cnt[arr[cur].prev]--;
            vis[arr[cur].index] = false;
        }
    }

}

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> arr[i].money >> arr[i].weight >> arr[i].prev;
        arr[i].index = i;
    }
    
    sort(begin(arr)+1,begin(arr)+1+k,[](node a, node b){    //������֤������
        return a.prev < b.prev;
    });
    
    dfs(1,0,n);

    cout << ans << endl;
    
    system("pause");
    return 0;
}
