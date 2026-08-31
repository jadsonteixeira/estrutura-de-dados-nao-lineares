#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree() {
    this->root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    this->clear();
}

bool BinarySearchTree::isEmpty() const {
    return this->root == nullptr;
}

Node * BinarySearchTree::getRoot() const {
    return this->root;
}

void BinarySearchTree::clear() {
    this->clear(this->root);
    this->root = nullptr;
}

// deleta as chaves em pós-ordem para apagar primeiro os filhos e depois o pai
void BinarySearchTree::clear(Node * node) {
    if (node == nullptr) {
        return;
    }

    this->clear(node->left);
    this->clear(node->right);
    delete node;
}

bool BinarySearchTree::insert(int key) {
    // cria o novo nó z, já com esquerda e direita apontando para NIL
    Node * z = new Node();
    z->key = key;
    z->left = nullptr;
    z->right = nullptr;
    z->parent = nullptr;
 
    Node * y = nullptr;       // y: rastro do último nó visitado (futuro pai de z)
    Node * x = this->root;    // x: explorador, começa na raiz
 
    // desce pela árvore até x cair em NIL (achar o buraco onde z entra)
    while (x != nullptr) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
 
    // y agora é o pai de z (ou NIL, se a árvore estava vazia)
    z->parent = y;
 
    if (y == nullptr) {
        this->root = z; // a árvore estava vazia, z vira a raiz
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
 
    return true;
}

void BinarySearchTree::inOrder() const {
    this->inOrder(this->root);
    cout << endl;
}

void BinarySearchTree::inOrder(Node * node) const {
    if (node == nullptr) {
        return;
    }
    this->inOrder(node->left);
    cout << node->key << " ";
    this->inOrder(node->right);
}