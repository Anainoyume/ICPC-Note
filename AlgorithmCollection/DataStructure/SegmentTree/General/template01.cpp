#include <bits/stdc++.h>
using namespace std;

#define int long long

class SegmentTree
{
private:
    struct Node {
            int sum;
            int left, right;
            int tag;

            Node* ls = nullptr;
            Node* rs = nullptr;

            // ����: sum, tag, left, right
            Node(int _sum, int _tag, int _left, int _right) 
            : sum(_sum), tag(_tag), left(_left), right(_right) 
            {}
        };

    inline void pushup(Node* node) {
        node->sum = node->ls->sum + node->rs->sum; //pushup����
    }

    inline void pushdown(Node* node) {
        if (node->tag){
            //�������ڵ����������
            node->ls->tag += node->tag;
            node->rs->tag += node->tag;

            //������ڵ������Ǹ����������ӽڵ�
            node->ls->sum += node->tag * (node->ls->right - node->ls->left + 1);
            node->rs->sum += node->tag * (node->rs->right - node->rs->left + 1);

            node->tag = 0;
            //�������������ڵ�������
        }
    }

public:
    using Node = SegmentTree::Node;

    SegmentTree() {}

    // ����߶���
    void clear(Node* node) {
        if (node->ls != nullptr) clear(node->ls);
        if (node->rs != nullptr) clear(node->rs);
        delete node;
    }

    // �����߶����ĸ����
    Node* build(int l, int r, vector<int>& arr){
        if(l == r){
            return new Node(arr[l],0,l,r);
        }

        Node* curNode = new Node(0,0,l,r);

        int mid = l + ((r - l) >> 1);
        curNode->ls = build(l,mid,arr);
        curNode->rs = build(mid+1,r,arr);
        pushup(curNode);

        return curNode;
    }

    // ��ѯ arr �ĺ�, node ��д�����
    int query(int l, int r, Node* node) {
        if(l <= node->left && r >= node->right) 
            return node->sum;

        pushdown(node); //ע�⣬�����ѯʱҲҪ���������

        int mid = node->left + ((node->right - node->left) >> 1);
        int sum = 0;

        if(l <= mid) sum += query(l,r,node->ls);
        if(r > mid) sum += query(l,r,node->rs);
        return sum; 
    }

    // �޸� arr ��ֵ, varΪ�޸ĵ�ֵ, node ��д�����
    void update(int l, int r, int var, Node* node){
        if(l <= node->left && r >= node->right) {
            //����鵽��������
            node->sum += var * (node->right - node->left + 1);   //���޸��������
            node->tag += var;                               //Ȼ��������������
            //ע������һ��Ҫ����˳�����޸ģ��ٱ�ǣ�
        }
        else{
            //�����Ҫ�������²�ѯ
            pushdown(node);  //�Ȱ���������´�
            int mid = node->left + ((node->right - node->left) >> 1);
            //������������ѯ
            if(l <= mid) update(l,r,var,node->ls);
            if(r > mid) update(l,r,var,node->rs);
            pushup(node); //��������pushupһ��
        }
    }
};

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    SegmentTree tr;
    SegmentTree::Node* root = tr.build(1,n,arr);

    for (int i = 1; i <= m; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            tr.update(x,y,k,root);
        }
        else {
            int x,y;
            cin >> x >> y;
            cout << tr.query(x,y,root) << endl;
        }
    }

    

    system("pause");
    return 0;
}