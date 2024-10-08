/* 
    �㷨ѧϰ��
    �ֵ��� (ǰ׺��)
    Trie�������ֵ������ֳƵ��ʲ��������������һ�����νṹ����һ�ֹ�ϣ���ı��֡�
    ����Ӧ��������ͳ�ƺ�����������ַ����������������ַ����������Ծ�������������ϵͳ�����ı���Ƶͳ�ơ�
    �����ŵ��ǣ������ַ����Ĺ���ǰ׺�����ٲ�ѯʱ�䣬����޶ȵؼ�����ν���ַ����Ƚϡ�

    Trie�ĺ���˼���ǿռ任ʱ�䡣�����ַ����Ĺ���ǰ׺�����Ͳ�ѯʱ��Ŀ����Դﵽ���Ч�ʵ�Ŀ�ġ�

    ǰ׺����3���������ʣ�
     - ���ڵ㲻�����ַ��������ڵ���ÿһ���ڵ㶼ֻ����һ���ַ���
     - �Ӹ��ڵ㵽ĳһ�ڵ㣬·���Ͼ������ַ�����������Ϊ�ýڵ��Ӧ���ַ�����
     - ÿ���ڵ�������ӽڵ�������ַ�������ͬ��
 */
#include <bits/stdc++.h>
using namespace std;

//�ֵ����Ľ��ṹ
struct Node
{
    int prefix = 0; //�Դ�Ϊǰ׺������
    int end = 0;    //�Դ�Ϊ��β�ĵ�������
    Node** alphabet;
    Node() {
        alphabet = new Node*[26];
        for (int i = 0; i < 26; i++)
            alphabet[i] = NULL;
    }
};

class Trie
{
public:
    Node* root = new Node();   //���ڵ�

    //���ʲ���
    void insert(string word) {
        //ÿ����ĸ�������Ƚ�
        Node* cur = this->root;    //ÿ�δӸ���ʼ
        for (int i = 0; i < word.size(); i++)
        {
            //���û�н�㣬���²���һ��
            if (cur->alphabet[word[i]-'a'] == NULL) {
                cur->alphabet[word[i]-'a'] = new Node();    
            }
            cur = cur->alphabet[word[i]-'a'];
            cur->prefix++;
            if (i == word.size()-1)
                cur->end++;
        }   
    }

    //�������
    void eachPrint(Node* root) {
        if (root == NULL)
            return;
        for (int i = 0; i < 26; i++)
        {
            if (root->alphabet[i] == NULL)
                continue;;
            cout << char('a'+i) << ": " << root->alphabet[i]->prefix << " " << root->alphabet[i]->end << endl;
            eachPrint(root->alphabet[i]);
        }
    }

    //������str��ͷ�ĵ�������
    int searchPrefix(string str) {
        Node* cur = this->root;
        for (int i = 0; i < str.size(); i++)
        {
            //ÿ����ĸ���μ���
            if (cur->alphabet[str[i]-'a'] == NULL)  //������
                return 0;
            
            cur = cur->alphabet[str[i]-'a'];
        }
        return cur->prefix;
    }

};


int main()
{
    Trie trie;
    trie.insert("apple");
    trie.insert("dog");
    trie.insert("amazing");
    trie.insert("holyshit");
    trie.insert("touhou");
    trie.insert("propose");
    trie.insert("promotion");
    trie.insert("progress");
    trie.insert("prosperity");


    cout << trie.searchPrefix("to") << endl;
    cout << trie.searchPrefix("pro") << endl;
    cout << trie.searchPrefix("appl") << endl;
    cout << trie.searchPrefix("mine") << endl;


    system("pause");
    return 0;
}

