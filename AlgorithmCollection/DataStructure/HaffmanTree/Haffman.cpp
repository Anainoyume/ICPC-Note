#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int weight = 0;
    char c = '\0';  //用于叶子结点的字符
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int w, char ch, Node* l, Node* r)
    : weight(w), c(ch), left(l), right(r)
    {}
};

struct cmp {
    bool operator()(const Node* a, const Node* b) const {
        return a->weight > b->weight;
    }
};



class Haffman
{
private:
    Node* root = nullptr;
    unordered_map<char,string> code;
    unordered_map<string,char> incode;
    string text;

    void _encode(Node* cur, string code) {
        if (cur->left == nullptr && cur->right == nullptr) {
            this->code[cur->c] = code;
            this->incode[code] = cur->c;
            return;
        }

        _encode(cur->left,code+"0");
        _encode(cur->right,code+"1");
        return;
    }
    
public:
    Haffman(const string& text) {
        this->text = text;

        unordered_map<char,int> p;
        for (auto&& c : text) {
            p[c] += 1;
        }

        priority_queue<Node*,vector<Node*>,cmp> wait;
        for (auto&& [key, weight] : p) {
            Node* node = new Node(weight,key,nullptr,nullptr);
            wait.push(node);
        }

        while (wait.size() != 1) {
            Node* fi = wait.top();
            wait.pop();
            Node* se = wait.top();
            wait.pop();

            Node* node = new Node(fi->weight+se->weight,'\0',fi,se);
            wait.push(node);
        }

        this->root = wait.top();
    }

    void encode() {
        _encode(this->root,"");
    }

    void decode(const string& code) {
        Node* index = this->root;
        for (auto&& c : code) {
            if (c == '0') {
                index = index->left;
            }
            else {
                index = index->right;
            }

            if (index->left == nullptr && index->right == nullptr) {
                cout << index->c;
                index = this->root;
            }
        }
    }

    string getCode() {
        string res;
        for (auto&& c : this->text) {
            res += code[c];
        }
        return res;
    }

    void print() {
        for (auto&& c : this->text) {
            cout << code[c];
        }
        cout << endl;
    }
};

int main()
{
    Haffman haff("abchdbccchadaabdbbd");
    haff.encode();

    string code = haff.getCode();
    cout << code << endl;

    haff.decode(code);
    cout << endl;

    system("pause");
    return 0;
}