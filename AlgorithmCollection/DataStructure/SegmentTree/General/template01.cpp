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

            // 参数: sum, tag, left, right
            Node(int _sum, int _tag, int _left, int _right) 
            : sum(_sum), tag(_tag), left(_left), right(_right) 
            {}
        };

    inline void pushup(Node* node) {
        node->sum = node->ls->sum + node->rs->sum; //pushup操作
    }

    inline void pushdown(Node* node) {
        if (node->tag){
            //如果这个节点上有懒标记
            node->ls->tag += node->tag;
            node->rs->tag += node->tag;

            //把这个节点的懒标记给他的两个子节点
            node->ls->sum += node->tag * (node->ls->right - node->ls->left + 1);
            node->rs->sum += node->tag * (node->rs->right - node->rs->left + 1);

            node->tag = 0;
            //别忘了清空这个节点的懒标记
        }
    }

public:
    using Node = SegmentTree::Node;

    SegmentTree() {}

    // 清空线段树
    void clear(Node* node) {
        if (node->ls != nullptr) clear(node->ls);
        if (node->rs != nullptr) clear(node->rs);
        delete node;
    }

    // 返回线段树的根结点
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

    // 查询 arr 的和, node 填写根结点
    int query(int l, int r, Node* node) {
        if(l <= node->left && r >= node->right) 
            return node->sum;

        pushdown(node); //注意，区间查询时也要下懒传标记

        int mid = node->left + ((node->right - node->left) >> 1);
        int sum = 0;

        if(l <= mid) sum += query(l,r,node->ls);
        if(r > mid) sum += query(l,r,node->rs);
        return sum; 
    }

    // 修改 arr 的值, var为修改的值, node 填写根结点
    void update(int l, int r, int var, Node* node){
        if(l <= node->left && r >= node->right) {
            //如果查到子区间了
            node->sum += var * (node->right - node->left + 1);   //先修改这个区间
            node->tag += var;                               //然后给它打上懒标记
            //注：这里一定要分清顺序，先修改，再标记！
        }
        else{
            //如果需要继续向下查询
            pushdown(node);  //先把懒标记向下传
            int mid = node->left + ((node->right - node->left) >> 1);
            //这里很像区间查询
            if(l <= mid) update(l,r,var,node->ls);
            if(r > mid) update(l,r,var,node->rs);
            pushup(node); //最后别忘了pushup一下
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