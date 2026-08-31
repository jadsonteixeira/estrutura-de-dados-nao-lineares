#include "BinarySearchTree.hpp"

#include <cstdlib>

int main() {
    system("clear");

    BinarySearchTree tree;

    tree.insert(6);
    tree.insert(5);
    tree.insert(2);
    tree.insert(5);
    tree.insert(7);
    tree.insert(8);

    Node * root = tree.getRoot();

    cout << "Raiz: " << root->key << endl;
    cout << "Filho da esquerda: " << root->left->key << endl;
    cout << "Filho da direita: " << root->right->key << endl;

    cout << "\nPercurso em-ordem" << endl;
    tree.inOrder();

    return 0;
}