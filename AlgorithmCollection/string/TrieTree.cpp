/* 
    算法学习：
    字典树 (前缀树)
    Trie树，即字典树，又称单词查找树或键树，是一种树形结构，是一种哈希树的变种。
    典型应用是用于统计和排序大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。
    它的优点是：利用字符串的公共前缀来减少查询时间，最大限度地减少无谓的字符串比较。

    Trie的核心思想是空间换时间。利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。

    前缀树的3个基本性质：
     - 根节点不包含字符，除根节点外每一个节点都只包含一个字符。
     - 从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串。
     - 每个节点的所有子节点包含的字符都不相同。
 */
#include <bits/stdc++.h>
using namespace std;

//字典树的结点结构
struct Node
{
    int prefix = 0; //以此为前缀的数量
    int end = 0;    //以此为结尾的单词数量
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
    Node* root = new Node();   //根节点

    //单词插入
    void insert(string word) {
        //每次字母依次做比较
        Node* cur = this->root;    //每次从根开始
        for (int i = 0; i < word.size(); i++)
        {
            //如果没有结点，就新插入一个
            if (cur->alphabet[word[i]-'a'] == NULL) {
                cur->alphabet[word[i]-'a'] = new Node();    
            }
            cur = cur->alphabet[word[i]-'a'];
            cur->prefix++;
            if (i == word.size()-1)
                cur->end++;
        }   
    }

    //遍历输出
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

    //查找以str开头的单词数量
    int searchPrefix(string str) {
        Node* cur = this->root;
        for (int i = 0; i < str.size(); i++)
        {
            //每个字母依次检索
            if (cur->alphabet[str[i]-'a'] == NULL)  //不存在
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

