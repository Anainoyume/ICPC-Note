/* 
    01字典树
    是一般字典树的一种应用，但是该字典树只使用二进制来存储一系列的数

    例如对于序列  0 1 2 3 (00) (01) (10) (11)   //从高位到低位，注意保留了前导零

            root
          /     \
         0       1
          \     / \
           1   0   1
 */
#include <bits/stdc++.h>
using namespace std;

class Trie01
{
private:
    int maxBit = 31;    //最大位数

    struct Node //01字典树结点
    {
        bool bit = 0;
        Node** next;
        Node(bool b) {
            this->bit = b;
            next = new Node*[2];
            next[0] = nullptr;
            next[1] = nullptr;
        }
    };
    
    Node* root = new Node(0);   //根结点不存储值

public:
    Trie01() {}
    ~Trie01() {}

    void insert(int n) {
        Node* p = this->root;
        for (int i = maxBit; i >= 0; i--)
        {
            //取出最高位
            int bit = n >> i & 1;
            if (!p->next[bit]) {    //还没有结点
                p->next[bit] = new Node(bit);
            }
            p = p->next[bit];
        }
    }

    int findMax(int n) {
        //找到与n异或最大的数字，由于 0 ^ 1 = 1, 1 ^ 0 = 1
        //因此我们每次都选择与当前位不同的数字
        //该数字需要处在数列中
        int ans = 0;
        Node* p = this->root;
        for (int i = maxBit; i >= 0; i--)
        {
            int bit = n >> i & 1;
            if (!p->next[bit ^ 1]) {    //如果不存在相反的位结点
                p = p->next[bit];
            }
            else {
                p = p->next[bit ^ 1];
            }
            ans += (p->bit << i);
        }
        return ans;
    }

};


int main(int argc, char const *argv[])
{
    int nums[10] = {
        23476,
        234,
        25346,
        1534634,
        85345,
        192,
        3234,
        101010101,
        68943
    };
    int num = 0;
    
    Trie01 tree;
    for (int i = 0; i < 10; i++)
    {
        tree.insert(nums[i]);
    }
    

    cout << tree.findMax(23476) << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << nums[i] << ": ";
        cout << (23476 ^ nums[i]) << endl;
    }
    


    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        for (int j = 31; j >= 0; j--)
        {
            int bit = num >> j & 1;
            cout << bit;
        }
        cout << endl;
    }
    
    
    system("pause");
    return 0;
}
