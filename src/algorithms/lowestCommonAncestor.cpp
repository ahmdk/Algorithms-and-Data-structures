// Finds the lowest common ancestor of two nodes in a binary search tree
#include <iostream>
#include <vector>

struct Node
{
    int key;
    Node *left;
    Node *right;    
    Node(){} // default constructor
    Node(int _key) : key(_key), left(nullptr), right(nullptr){}
    Node(int _key, Node *_left, Node *_right) : key(_key), left(_left), right(_right){}
};

struct Result_t
{
    int nodes_found;
    Node *lca;
};

void insert(int key, Node *&root)
{
    if(!root)
    {
        root = new Node(key);
        return;
    }
    if(key < root->key) return insert(key, root->left);
    else if(key > root->key) return insert(key, root->right);
}

void buildTree(std::vector<int> &vec, Node *&root)
{
    for(auto key : vec)
    {
        insert(key, root);
    }
}

Node *find(int key, Node *root)
{
    if(!root || key == root->key) return root;
    if(key < root->key) return find(key, root->left);
    if(key > root->key) return find(key, root->right);
    return nullptr;
}

void printTree(Node *root)
{
    if(!root) return;
    printTree(root->left);
    std::cout << root->key << " ";
    printTree(root->right);
}

Result_t findLCAhelper(Node *root, Node *a, Node *b)
{
    if(!root) return {0, nullptr};
    Result_t left_result = findLCAhelper(root->left, a, b);
    if(left_result.nodes_found == 2) return left_result;
    
    Result_t right_result = findLCAhelper(root->right, a, b);
    if(right_result.nodes_found == 2) return right_result;
    
    int numOfNodes = left_result.nodes_found + right_result.nodes_found + (root->key == a->key) + (root->key == b->key);
    return {numOfNodes, numOfNodes == 2 ? root : nullptr};   
}

Node *findLCA(Node *root, Node *a, Node *b)
{
    return findLCAhelper(root, a, b).lca;
}

int main()
{
    Node *root = nullptr;
    std::vector<int> vec{10, 5, 20, 30, 25, 6, 3, 2, 4, 27, 24, 7};
    buildTree(vec, root);
    printTree(root);
    std::cout << std::endl;
    Node *a = find(3, root);
    Node *b = find(7, root);
    Node * lca = findLCA(root, a, b);
    if(lca) std::cout << "LCA of: " << a->key << " and " << b->key << " is " << lca->key << std::endl; 
    return 0;
}
