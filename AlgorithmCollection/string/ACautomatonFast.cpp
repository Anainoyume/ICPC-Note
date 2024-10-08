#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

/* 
    使用全局变量 和 数组 实现的 AC自动机，在速度上会更快一点
 */

unordered_map<int,int> vis;

// 首先需要一个字典树 (trie)
struct Node
{
    int end = 0;    //以此为结尾的单词数量
    int inDeg = 0;  //拓扑优化, 入度
    int ans = 0;    //拓扑优化，当前点答案
    int fail = 0;   // AC自动机失配指针
    int son[26]; //字母表结点
} trie[N];

int tot = 2;

class Trie
{
private:
    int voidNode = 0;
    int root = 1;

public:
    unordered_map<int,int> Map; //插入重复单词的时候, 不同插入位置的映射

    // 插入时,使用 Nodes 记录所有的结点
    void insert(const string& word, int index) {
        int node = root;  //从根节点开始查询
        for (auto&& c : word) {
            if (!trie[node].son[c-'a']) {
                trie[node].son[c-'a'] = tot++;
            }
            node = trie[node].son[c-'a'];
        }
        if (!trie[node].end) trie[node].end = index;  //设置为当前是第几个插入的单词
        Map[index] = trie[node].end;    //映射
    }

    // 初始化为 AC自动机
    void init() {
        for (int i = 0; i < 26; ++i) {
            trie[voidNode].son[i] = root;
        }
        trie[root].fail = voidNode;
        
        queue<int> que;
        que.push(root);

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            int Fail = trie[u].fail;

            for (int i = 0; i < 26; ++i) {
                int s = trie[u].son[i];
                if (!s) {
                    trie[u].son[i] = trie[Fail].son[i];
                    continue;
                }
                trie[s].fail = trie[Fail].son[i];
                trie[trie[s].fail].inDeg += 1;
                que.push(s);
            }
        }
    }

    // 拓扑优化 unordered_map 版本
    void topoOpt() {
        queue<int> que;
        for (int i = root; i < tot; ++i) {
            if (trie[i].inDeg == 0) que.push(i);
        }

        while (!que.empty()) {
            int u = que.front();
            que.pop();
            vis[trie[u].end] = trie[u].ans;

            int Fail = trie[u].fail;
            trie[Fail].inDeg -= 1;
            trie[Fail].ans += trie[u].ans;
            
            if (trie[Fail].inDeg == 0)
                que.push(Fail);
        }
    }

    // 拓扑优化查询
    void query(const string& s) {
        int u = root;
        for (auto&& c : s) {
            u = trie[u].son[c-'a'];
            trie[u].ans += 1;
        }
    }
};

signed main()
{
    // 初始化 (重置)
    tot = 2;
    vis.clear();
    for (int i = 0; i < N; ++i) {
        trie[i].ans = trie[i].end = trie[i].fail = trie[i].inDeg = 0;
        for (int j = 0; j < 26; ++j) {
            trie[i].son[j] = 0;
        }
    }

    // 使用示例
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    vector<string> arr(n+1);
    Trie tr;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        tr.insert(arr[i],i);
    }

    tr.init();

    string s;
    cin >> s;
    
    tr.query(s);
    tr.topoOpt();
    for (int i = 1; i <= n; ++i) {
        cout << vis[tr.Map[i]] << endl;
    }

    system("pause");
    return 0;
}


