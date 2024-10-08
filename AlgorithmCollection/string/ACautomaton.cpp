/* 
    AC�Զ��� (�������Ż�)
 */
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

// ������Ҫһ���ֵ��� (trie)
struct Node
{
    int end = 0;    //�Դ�Ϊ��β�ĵ�������
    string word;    //Ҳ����ѡ����ĩβ�洢һ������, ��ֹ���ظ�������

    int inDeg = 0;  //�����Ż�, ���
    int ans = 0;    //�����Ż�����ǰ���

    Node* fail = nullptr;   // AC�Զ���ʧ��ָ��

    vector<Node*> alphabet; //��ĸ����
    Node() {
        alphabet.assign(26,nullptr);
    }
};

class Trie
{
private:
    Node* voidNode = new Node();    //����
    Node* root = new Node();

    size_t wordCount = 0;   //����ĵ�������
    vector<Node*> Nodes;      //�洢���н��, �����ѯ

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
        Node* node = root;  //�Ӹ��ڵ㿪ʼ��ѯ
        for (auto&& c : word) {
            if (node->alphabet[c-'a'] == nullptr) {
                node->alphabet[c-'a'] = new Node();
            }
            node = node->alphabet[c-'a'];
        }
        node->end = index;  //����Ϊ��ǰ�ǵڼ�������ĵ���
        node->word = word;
        wordCount += 1;
    }

    // ����ʱ,ʹ�� Nodes ��¼���еĽ��
    void insertEx(const string& word, int index) {
        Node* node = root;  //�Ӹ��ڵ㿪ʼ��ѯ
        for (auto&& c : word) {
            if (node->alphabet[c-'a'] == nullptr) {
                node->alphabet[c-'a'] = new Node();
                Nodes.emplace_back(node->alphabet[c-'a']);  //��������Լ��ĳɾ�̬����, �ȿ�һ��ȫ�ֽ������
            }
            node = node->alphabet[c-'a'];
        }
        node->end = index;  //����Ϊ��ǰ�ǵڼ�������ĵ���
        node->word = word;
        wordCount += 1;
    }

    // ��ʼ��Ϊ AC�Զ���
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

    // ��ģʽƥ��, ���������¼�� count �ļ�ֵ����
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

    // ��ģʽƥ�� map�汾 (���������ϣ���Կ��ǻ��� unordered_map)
    void query(const string& s, unordered_map<string,int>& count) {
        Node* node = root;
        for (auto&& c : s) {
            node = node->alphabet[c-'a'];
            for (Node* p = node; p != root && p != voidNode; p = p->fail) {
                if (p->end) count[p->word] += 1;
            }
        }
    } 

    // �����Ż�
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

    // �����Ż� unordered_map �汾
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

    // �����Ż���ѯ
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