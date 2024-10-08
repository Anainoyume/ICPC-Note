class tree
{
private:
    struct Node
    {
        int data = 0;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int d = 0, Node* l = nullptr, Node* r = nullptr)
            : data(d), left(l), right(r)
        {}

    };
    
    Node* root = nullptr;
public:
    tree(int value) {
        this->root = new Node(value,nullptr,nullptr);
    }

    Node* getRoot() {
        return this->root;
    }

    Node* node(int d = 0, Node* l = nullptr, Node* r = nullptr) {
        return new Node(d,l,r);
    }
};