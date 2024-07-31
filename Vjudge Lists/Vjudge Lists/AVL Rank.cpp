#include <iostream>
#include <vector>

using namespace std;

class AVLNode {
public:
    int key;
    int height;
    int size;
    AVLNode* left;
    AVLNode* right;

    AVLNode();
    AVLNode(int key);
};

class AVL {
public:
    AVLNode* root;
    int nodecount;

    AVL();

    void insert(int key);
    AVLNode* inserthelp(AVLNode* rt, int key);
    AVLNode* find(int key, AVLNode* rt);
    int size(AVLNode* rt);
    void updateSize(AVLNode* node);
    int rank(AVLNode* root, int key);

    AVLNode* rightRotate(AVLNode* rt);
    AVLNode* leftRotate(AVLNode* rt);
    int h(AVLNode* rt);
    int getBalance(AVLNode* rt);
    void print_all(AVLNode* rt);
};

int main() {
    AVL* avl = new AVL;
    int num_operations;
    cin >> num_operations;
    for (int j = 0; j < num_operations; j++) {
        int op_num, key;
        cin >> op_num;
        cin >> key;
        if (op_num == 1) {
            avl->insert(key);
        } else {
            AVLNode* rt = avl->find(key, avl->root);
            if (rt == nullptr) {
                cout << "Data tidak ada" << endl;
            } else {
                int index = avl->rank(avl->root, key);
                cout << index+1 << endl;
            }
        }
    }
    return 0;
}

//--CONSTRUTORES--
AVL::AVL() {
    root = nullptr;
    nodecount = 0;
}

AVLNode::AVLNode() {
    key = 0;
    height = 0;
    size = 1;
    left = right = nullptr;
}

AVLNode::AVLNode(int k) {
    key = k;
    height = 0;
    size = 1;
    left = right = nullptr;
}

//--INSERT--
void AVL::insert(int key) {
    root = inserthelp(root, key);
    nodecount++;
}

AVLNode* AVL::inserthelp(AVLNode* rt, int key) {
    if (rt == nullptr) return new AVLNode(key);

    if (key < rt->key) {
        rt->left = inserthelp(rt->left, key);
    } else if (key > rt->key) {
        rt->right = inserthelp(rt->right, key);
    } else {
        return rt; // Chave duplicada não é permitida
    }

    rt->height = 1 + max(h(rt->left), h(rt->right));
    updateSize(rt);
    int balance = getBalance(rt);

    // Rotação à esquerda
    if (balance < -1 && key > rt->right->key) return leftRotate(rt);

    // Rotação à direita
    if (balance > 1 && key < rt->left->key) return rightRotate(rt);

    // Rotação esquerda-direita
    if (balance > 1 && key > rt->left->key) {
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }

    // Rotação direita-esquerda
    if (balance < -1 && key < rt->right->key) {
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }

    return rt;
}

int AVL::rank(AVLNode* rt, int key) {
    if (rt == nullptr) return 0;

    if (key < rt->key) {
        return rank(rt->left, key);
    } else if (key > rt->key) {
        return size(rt->left) + 1 + rank(rt->right, key);
    } else {
        return size(rt->left);
    }
}

AVLNode* AVL::find(int key, AVLNode* rt) {
    if (rt == nullptr) return nullptr;
    if (key < rt->key) {
        return find(key, rt->left);
    } else if (key > rt->key) {
        return find(key, rt->right);
    }
    return rt;
}

int AVL::size(AVLNode* rt) {
    if (rt == nullptr) return 0;
    return rt->size;
}

void AVL::updateSize(AVLNode* rt) {
    if (rt != nullptr) {
        rt->size = size(rt->left) + size(rt->right) + 1;
    }
}

void AVL::print_all(AVLNode* rt) {
    if (rt != nullptr) {
        cout << rt->key << endl;
        print_all(rt->left);
        print_all(rt->right);
    }
}

//--BALANCEAMENTO--

AVLNode* AVL::rightRotate(AVLNode* rt) {
    AVLNode* l = rt->left;
    AVLNode* lr = l->right;
    l->right = rt;
    rt->left = lr;

    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;

    updateSize(rt);
    updateSize(l);

    return l;
}

AVLNode* AVL::leftRotate(AVLNode* rt) {
    AVLNode* r = rt->right;
    AVLNode* rl = r->left;
    r->left = rt;
    rt->right = rl;

    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;

    updateSize(rt);
    updateSize(r);

    return r;
}

int AVL::getBalance(AVLNode* rt) {
    if (rt == nullptr) return 0;
    return h(rt->left) - h(rt->right);
}

int AVL::h(AVLNode* rt) {
    if (rt == nullptr) return -1;
    return rt->height;
}
