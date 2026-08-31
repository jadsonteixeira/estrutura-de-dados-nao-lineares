#ifndef _BINARY_SEARCH_TREE_HPP_
#define _BINARY_SEARCH_TREE_HPP_

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node * left;
    Node * right;
    Node * parent;
};

class BinarySearchTree {

    private:
        Node * root;

    public:
        BinarySearchTree();
        ~BinarySearchTree();
        bool isEmpty() const;
        Node * getRoot() const;
        void clear();
        bool insert(int key);
        void inOrder() const;
    
    private:
        void clear(Node * node);
        void inOrder(Node * node) const;
};

#endif