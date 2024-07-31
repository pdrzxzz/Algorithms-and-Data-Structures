#include <iostream>

using namespace std;

class AVLNode{
    public:
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode();
    AVLNode(int key);

};

class AVL{
    public:
    AVLNode* root;
    int nodecount;

    AVL();

    void insert(int key);
    AVLNode* inserthelp(AVLNode* rt, int key);

    AVLNode* rightRotate(AVLNode* rt);
    AVLNode* leftRotate(AVLNode* rt);
    int h(AVLNode* rt);
    int getBalance(AVLNode* rt);
    void print_all(AVLNode*);
};

int main()
{
    int num_cases;
    cin >> num_cases;
    for(int i=0; i<num_cases; i++){
        AVL* avl = new AVL;
        int num_keys;
        cin >> num_keys;
        for(int j=0; j<num_keys; j++){
            int key;
            cin >> key;
            avl->insert(key);
        }
        avl->print_all(avl->root);
        cout << "END" << endl;
    }
    return 0;
}

AVL::AVL(){
    root = nullptr;
    nodecount = 0;
}

AVLNode::AVLNode(int k){
    key = k;
    height = 0;
    left = right = nullptr;
}

void AVL::insert(int key){
    root = inserthelp(root, key);
    nodecount++;
}

AVLNode* AVL::inserthelp(AVLNode* rt, int key){
    AVLNode* address = new AVLNode(key);
    if(rt == nullptr) return address;
    if(rt->key > key){
        rt->left = inserthelp(rt->left, key);
    }
    else{
        rt->right = inserthelp(rt->right, key);
    }

    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);
    if(balance < -1 && key >= rt->right->key) return leftRotate(rt);
    if(balance > 1 && key < rt->left->key) return rightRotate(rt);
    if(balance > 1 && key >= rt->left->key){
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if(balance < -1 && key < rt->right->key){
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }
    return rt;
}

AVLNode* AVL::rightRotate(AVLNode* rt){
    AVLNode* l = rt->left;
    AVLNode* lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
    return l;
}


AVLNode* AVL::leftRotate(AVLNode* rt){
    AVLNode* r = rt->right;
    AVLNode* rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    return r;
}


int AVL::getBalance(AVLNode* rt){
    if(rt == nullptr) return 0;
    return h(rt->left) - h(rt->right);
}

int AVL::h(AVLNode* rt){
    if(rt == nullptr) return -1;
    return rt->height;
}

void AVL::print_all(AVLNode* rt){
    if(rt != nullptr){
        cout << rt->key << endl;
        print_all(rt->left);
        print_all(rt->right);
    }
}


