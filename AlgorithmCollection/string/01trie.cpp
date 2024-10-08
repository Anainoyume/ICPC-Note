/* 
    01�ֵ���
    ��һ���ֵ�����һ��Ӧ�ã����Ǹ��ֵ���ֻʹ�ö��������洢һϵ�е���

    �����������  0 1 2 3 (00) (01) (10) (11)   //�Ӹ�λ����λ��ע�Ᵽ����ǰ����

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
    int maxBit = 31;    //���λ��

    struct Node //01�ֵ������
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
    
    Node* root = new Node(0);   //����㲻�洢ֵ

public:
    Trie01() {}
    ~Trie01() {}

    void insert(int n) {
        Node* p = this->root;
        for (int i = maxBit; i >= 0; i--)
        {
            //ȡ�����λ
            int bit = n >> i & 1;
            if (!p->next[bit]) {    //��û�н��
                p->next[bit] = new Node(bit);
            }
            p = p->next[bit];
        }
    }

    int findMax(int n) {
        //�ҵ���n����������֣����� 0 ^ 1 = 1, 1 ^ 0 = 1
        //�������ÿ�ζ�ѡ���뵱ǰλ��ͬ������
        //��������Ҫ����������
        int ans = 0;
        Node* p = this->root;
        for (int i = maxBit; i >= 0; i--)
        {
            int bit = n >> i & 1;
            if (!p->next[bit ^ 1]) {    //����������෴��λ���
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
