#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

/* 
    ʹ��ȫ�ֱ��� �� ���� ʵ�ֵ� AC�Զ��������ٶ��ϻ����һ��
 */

unordered_map<int,int> vis;

// ������Ҫһ���ֵ��� (trie)
struct Node
{
    int end = 0;    //�Դ�Ϊ��β�ĵ�������
    int inDeg = 0;  //�����Ż�, ���
    int ans = 0;    //�����Ż�����ǰ���
    int fail = 0;   // AC�Զ���ʧ��ָ��
    int son[26]; //��ĸ����
} trie[N];

int tot = 2;

class Trie
{
private:
    int voidNode = 0;
    int root = 1;

public:
    unordered_map<int,int> Map; //�����ظ����ʵ�ʱ��, ��ͬ����λ�õ�ӳ��

    // ����ʱ,ʹ�� Nodes ��¼���еĽ��
    void insert(const string& word, int index) {
        int node = root;  //�Ӹ��ڵ㿪ʼ��ѯ
        for (auto&& c : word) {
            if (!trie[node].son[c-'a']) {
                trie[node].son[c-'a'] = tot++;
            }
            node = trie[node].son[c-'a'];
        }
        if (!trie[node].end) trie[node].end = index;  //����Ϊ��ǰ�ǵڼ�������ĵ���
        Map[index] = trie[node].end;    //ӳ��
    }

    // ��ʼ��Ϊ AC�Զ���
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

    // �����Ż� unordered_map �汾
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

    // �����Ż���ѯ
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
    // ��ʼ�� (����)
    tot = 2;
    vis.clear();
    for (int i = 0; i < N; ++i) {
        trie[i].ans = trie[i].end = trie[i].fail = trie[i].inDeg = 0;
        for (int j = 0; j < 26; ++j) {
            trie[i].son[j] = 0;
        }
    }

    // ʹ��ʾ��
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


