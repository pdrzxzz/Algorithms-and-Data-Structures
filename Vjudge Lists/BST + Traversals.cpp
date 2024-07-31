#include <iostream>

using namespace std;

class BSTNode{
    public:
    int element;
    BSTNode* left;
    BSTNode* right;
};

class BST{
    public:
    BSTNode* root;
    int nodecount;

    BST(){
        this->root = nullptr;
        this->nodecount = 0;
    }

    BSTNode* create_node(int element){
        BSTNode* node = new BSTNode;
        node->element = element;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }

    void insert(int key){
        this->root = inserthelp(this->root, key);
        this->nodecount++;
    }

    BSTNode* inserthelp(BSTNode* rt, int key){
        if(rt == nullptr) return create_node(key);
        if(rt->element > key) rt->left = inserthelp(rt->left, key);
        else rt->right = inserthelp(rt->right, key);
        return rt;
    }

    void print_preorder(BSTNode* root){
        if(root != nullptr){
            cout << " " << root->element;
            this->print_preorder(root->left);
            this->print_preorder(root->right);
        }
    }

    void print_inorder(BSTNode* root){
        if(root != nullptr){
            this->print_inorder(root->left);
            cout << " " << root->element;
            this->print_inorder(root->right);
        }
    }

    void print_postorder(BSTNode* root){
        if(root != nullptr){
            this->print_postorder(root->left);
            this->print_postorder(root->right);
            cout << " " << root->element;
            delete root;
        }
    }
};


int main()
{
    BST* bst = new BST();
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int num; cin >> num;
        bst->insert(num);
    }
    cout << "Pre order :";
    bst->print_preorder(bst->root);
    cout << endl;
    cout << "In order  :";
    bst->print_inorder(bst->root);
    cout << endl;
    cout << "Post order:";
    bst->print_postorder(bst->root);
    delete bst;
    return 0;
}
