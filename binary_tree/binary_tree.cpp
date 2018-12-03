#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;

    Node<T>* parent;

    Node(const T& dt,
         Node<T>* lft = nullptr,
         Node<T>* rt = nullptr)
         {
            data = dt;
            left = lft;
            right = rt;
            parent = nullptr;
         }
};

template <typename T>
class binary_tree
{
private:
    Node<T>* root;
    size_t size;

    bool isRoot(Node<T>* current)
    {
        return current->parent == nullptr;
    }

    bool isLeaf(Node<T>* current)
    {
        return current->left == nullptr
        && current->right == nullptr;
    }
    Node<T>* copyNode(Node<T>* current)
    {
        if(current==nullptr)return nullptr;
        Node<T>* temp = new Node<T>(current->data, copyNode(current->left),copyNode(current->right));
        if(temp->left)temp->left->parent = temp;
        if(temp->right)temp->right->parent = temp;
        return temp;
    }
    void copy(const binary_tree& other)
    {
        this->size = other.size;
        this->root=copyNode(other.root);
    }
    void deleteSubTree(Node<T>* crr)
    {
        if(!crr) return;
        deleteSubTree(crr->left);
        deleteSubTree(crr->right);
        delete crr;
    }
    void printNode(Node<T>* crr){
        if(crr){
            cout<<crr->data<<" ";
            printNode(crr->left);
            printNode(crr->right);
        }
    }
    void printNodeLeaf(Node<T>* crr){
        if(crr){
            if(isLeaf(crr))
                cout<<crr->data<<" ";

            printNodeLeaf(crr->left);
            printNodeLeaf(crr->right);
        }
    }
    void erase()
    {
        deleteSubTree(this->root);
    }
    void helperPush(Node<T>* crr,vector<T>& vec)
    {
        if(!crr)
        {
            return;
        }
        vec.push_back(crr->data);
        helperPush(crr->left,vec);
        helperPush(crr->right,vec);
    }

    void helperPushLeaf(Node<T>* crr,vector<T>& vec)
    {
        if(!crr)
        {
            return;
        }
        if(isLeaf(crr))
            vec.push_back(crr->data);
        helperPushLeaf(crr->left,vec);
        helperPushLeaf(crr->right,vec);
    }

public:
    binary_tree()
    {
        root = nullptr;
        size=0;
    }
    binary_tree(const binary_tree& other)
    {
        copy(other);
    }
    binary_tree& operator=(const binary_tree& other)
    {
        if(this!=&other)
        {
            erase();
            copy(other);
        }
        return *this;
    }
    ~binary_tree()
    {
        erase();
    }

    size_t getSize() const
    {
        return this->size;
    }

    void insert();
    void removeByData(T data);
    void removeOneByData(T data);
    void removeByDepth(size_t depth);
    bool isEmpty() const
    {
        return size == 0;
    }
    void print() const{
        printNode(this->root);
    }
    void printAllLeafs() const{
        printNodeLeaf(this->root);
    }
    vector<T> getDataInVector() const
    {
        vector<T> vec;
        helperPush(root,vec);
        return vec;

    }
    vector<T> getLeafsInVector() const
    {
        vector<T> vec;
        helperPushLeaf(root,vec);
        return vec;
    }

};

int main()
{

}
