/* 
    AC自动机 (带拓扑优化)
 */
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

// 首先需要一个字典树 (trie)
struct Node
{
    int end = 0;    //以此为结尾的单词数量
    string word;    //也可以选择在末尾存储一个单词, 防止有重复的输入

    int inDeg = 0;  //拓扑优化, 入度
    int ans = 0;    //拓扑优化，当前点答案

    Node* fail = nullptr;   // AC自动机失配指针

    vector<Node*> alphabet; //字母表结点
    Node() {
        alphabet.assign(26,nullptr);
    }
};

class Trie
{
private:
    Node* voidNode = new Node();    //虚结点
    Node* root = new Node();

    size_t wordCount = 0;   //插入的单词数量
    vector<Node*> Nodes;      //存储所有结点, 方便查询

public:
    ~Trie() {
        queue<Node*> que;
        que.push(voidNode);
        while (!que.empty()) {
            Node* node = que.front();
            que.pop();

            for (int i = 0; i < 26; ++i) {
                if (node->alphabet[i] != nullptr)
                    que.push(node->alphabet[i]);
            }

            
        }
    }

    void insert(const string& word, int index) {
        Node* node = root;  //从根节点开始查询
        for (auto&& c : word) {
            if (node->alphabet[c-'a'] == nullptr) {
                node->alphabet[c-'a'] = new Node();
            }
            node = node->alphabet[c-'a'];
        }
        node->end = index;  //设置为当前是第几个插入的单词
        node->word = word;
        wordCount += 1;
    }

    // 插入时,使用 Nodes 记录所有的结点
    void insertEx(const string& word, int index) {
        Node* node = root;  //从根节点开始查询
        for (auto&& c : word) {
            if (node->alphabet[c-'a'] == nullptr) {
                node->alphabet[c-'a'] = new Node();
                Nodes.emplace_back(node->alphabet[c-'a']);  //如果慢了自己改成静态插入, 先开一个全局结点数组
            }
            node = node->alphabet[c-'a'];
        }
        node->end = index;  //设置为当前是第几个插入的单词
        node->word = word;
        wordCount += 1;
    }

    // 初始化为 AC自动机
    void init() {
        for (int i = 0; i < 26; ++i) {
            voidNode->alphabet[i] = root;
        }
        root->fail = voidNode;
        
        queue<Node*> que;
        que.push(root);

        while (!que.empty()) {
            Node* curNode = que.front();
            que.pop();

            for (int i = 0; i < 26; ++i) {
                if (curNode->alphabet[i]) {
                    curNode->alphabet[i]->fail = curNode->fail->alphabet[i];
                    curNode->alphabet[i]->fail->inDeg += 1;

                    que.push(curNode->alphabet[i]);
                }
                else {
                    curNode->alphabet[i] = curNode->fail->alphabet[i];
                    if (curNode->alphabet[i] == nullptr)
                        curNode->alphabet[i] = root;
                }
            }
        }
    }

    // 多模式匹配, 各个结果记录在 count 的键值对中
    void query(const string& s, vector<int>& count) {
        count.resize(wordCount+1);
        Node* node = root;
        for (auto&& c : s) {
            node = node->alphabet[c-'a'];
            for (Node* p = node; p != root && p != voidNode; p = p->fail) {
                if (p->end) count[p->end] += 1;
            }
        }
    } 

    // 多模式匹配 map版本 (如果不卡哈希可以考虑换成 unordered_map)
    void query(const string& s, unordered_map<string,int>& count) {
        Node* node = root;
        for (auto&& c : s) {
            node = node->alphabet[c-'a'];
            for (Node* p = node; p != root && p != voidNode; p = p->fail) {
                if (p->end) count[p->word] += 1;
            }
        }
    } 

    // 拓扑优化
    void topoOpt(vector<int>& count) {
        count.resize(wordCount+1);
        queue<Node*> que;
        for (int i = 0; i < Nodes.size(); ++i) {
            if (Nodes[i]->inDeg == 0) que.push(Nodes[i]);
        }

        while (!que.empty()) {
            Node* node = que.front();
            que.pop();
            if (node->end) count[node->end] = node->ans;
            node->fail->inDeg -= 1;
            node->fail->ans += node->ans;
            
            if (node->fail->inDeg == 0)
                que.push(node->fail);
        }
    }

    // 拓扑优化 unordered_map 版本
    void topoOpt(unordered_map<string,int>& count) {
        queue<Node*> que;
        for (int i = 0; i < Nodes.size(); ++i) {
            if (Nodes[i]->inDeg == 0) que.push(Nodes[i]);
        }

        while (!que.empty()) {
            Node* node = que.front();
            que.pop();
            if (node->end) count[node->word] = node->ans;
            node->fail->inDeg -= 1;
            node->fail->ans += node->ans;
            
            if (node->fail->inDeg == 0)
                que.push(node->fail);
        }
    }

    // 拓扑优化查询
    void queryEx(const string& s) {
        Node* node = root;
        for (auto&& c : s) {
            node = node->alphabet[c-'a'];
            node->ans += 1;
        }
    }
};

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    vector<string> arr(n+1);
    Trie tr;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        tr.insertEx(arr[i],i);
    }

    tr.init();

    string s;
    cin >> s;
    
    unordered_map<string,int> ans;
    tr.queryEx(s);
    tr.topoOpt(ans);
    for (int i = 1; i <= n; ++i) {
        cout << ans[arr[i]] << endl;
    }

    system("pause");
    return 0;
}