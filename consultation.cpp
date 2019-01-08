#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(const T& dt, Node<T>* lft = nullptr,
         Node<T>* rgt = nullptr)
    {
        data = dt;
        left = lft;
        right = rgt;
    }
};
void printNegative(Node<int>* crr)
{
    if(crr==nullptr)return;
    if(crr->data<0)cout<<crr->data<<" ";  
    printNegative(crr->left);
    printNegative(crr->right);   
}
void printBFS(Node<int>* node)
{
    if(node==nullptr)return;
    queue<Node<int>*> q;
    q.push(node);
    Node<int>* crr;
    while(!q.empty())
    {
        crr=q.front();
        q.pop();
        cout<<crr->data<<" ";
        if(crr->left)q.push(crr->left);
        if(crr->right)q.push(crr->right);
    }
}

void printDFS(Node<int>* node)
{
    if(node==nullptr)return;
    stack<Node<int>*> stack;
    stack.push(node);
    Node<int>* crr;
    while(!stack.empty())
    {
        crr=stack.top();
        stack.pop();
        cout<<crr->data<<" ";
        if(crr->right)stack.push(crr->right);   
        if(crr->left)stack.push(crr->left);
    }
}

void deleteNode(Node<int>
bool isBSTHelper(Node<int>* node, int min, int max) {
  
    if (node == nullptr) return true;

    return node->data >= min &&
           node->data < max &&
           isBSTHelper(node->left, min, node->data) &&
           isBSTHelper(node->right, node->data, max);
   
}
bool isBST(Node<int>* node) {
  
    return isBSTHelper(node, INT_MIN, INT_MAX);
   
}

template <typename T>
struct TreeNode{
    
    T data;
    vector<TreeNode*> children;

    TreeNode(const T& _data, 
            vector<TreeNode*> _children){
        
        data = _data;
        children = _children;
    } 
};

void printBFS(TreeNode<T>* node){
    
    if(node == nullptr){
        
        return;
    }

    queue<TreeNode<T>*> q;

    q.push(node);

    TreeNode<T>* crr;

    while(!q.empty()){
        crr = q.front();
        q.pop();
        cout<<crr->data;

        for(int i = 0; i < crr->children.size(); i++){
            
            q.push(crr->children[i]);
        }
    }
}
















int main()
{
    cout<<"Hello World"<<endl;
}
