#ifndef BST_H
#define BST_H

#include <iostream>

template<typename T>
class BinarySearchTree {
    private:
        T key;
        BinarySearchTree<T>* left;        
        BinarySearchTree<T>* right;

    public:
        BinarySearchTree<T>(T value);
        void insert(T value);
        void preOrder();
        void inOrder();
        void postOrder(); // Fixed: Added declaration
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value) {
    key = value;
    left = nullptr;
    right = nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(T value) {
    if (value < key) {
        if (left == nullptr) {
            left = new BinarySearchTree<T>(value);
        } else {
            left->insert(value);
        }
    }
    else if (value > key) {
        if (right == nullptr) {
            right = new BinarySearchTree<T>(value);
        } else {
            right->insert(value);
        }
    }
}

template <typename T>
void BinarySearchTree<T>::preOrder() {
    std::cout << key << " ";
    
    if (left != nullptr) {
        left->preOrder();
    }
    if (right != nullptr) {
        right->preOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::inOrder() {
    if (left != nullptr) {
        left->inOrder();
    }
    std::cout << key << " ";
    if (right != nullptr) {
        right->inOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::postOrder() {
    // 1. Traverse left subtree
    if (left != nullptr) {
        left->postOrder();
    }
    // 2. Traverse right subtree
    if (right != nullptr) {
        right->postOrder();
    }
    // 3. Print node key last (Left -> Right -> Root)
    std::cout << key << " ";
}

#endif