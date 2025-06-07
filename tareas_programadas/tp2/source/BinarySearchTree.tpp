#pragma once
#include <iostream>
#include <random>
#include <stack>

template <typename DataType>
BSTreeNode<DataType>::BSTreeNode(const DataType &value, BSTreeNode<DataType> *parent,
                                  BSTreeNode<DataType> *left, BSTreeNode<DataType> *right)
    : key(value), parent(parent), left(left), right(right) {}

template <typename DataType>
BSTreeNode<DataType>::~BSTreeNode() {
}

template <typename DataType>
DataType BSTreeNode<DataType>::getKey() const {
    return key;
}

template <typename DataType>
BSTreeNode<DataType> *BSTreeNode<DataType>::getParent() const {
    return parent;
}

template <typename DataType>
BSTreeNode<DataType> *BSTreeNode<DataType>::getLeft() const {
    return left;
}

template <typename DataType>
BSTreeNode<DataType> *BSTreeNode<DataType>::getRight() const {
    return right;
}

template <typename DataType>
void BSTreeNode<DataType>::setParent(BSTreeNode<DataType> *p) {
    parent = p;
}

template <typename DataType>
void BSTreeNode<DataType>::setLeft(BSTreeNode<DataType> *l) {
    left = l;
}

template <typename DataType>
void BSTreeNode<DataType>::setRight(BSTreeNode<DataType> *r) {
    right = r;
}

// Constructor
template <typename DataType>
BSTree<DataType>::BSTree() : root(nullptr) {}

template <typename DataType>
BSTree<DataType>::~BSTree() {
    deleteSubtree(root);
}

template <typename DataType>
void BSTree<DataType>::deleteSubtree(BSTreeNode<DataType>* node) {
    if (!node) return;
    deleteSubtree(node->getLeft());
    deleteSubtree(node->getRight());
    delete node;
}

template <typename DataType>
void BSTree<DataType>::insert(const DataType &value) {
    BSTreeNode<DataType> *newNode = new BSTreeNode<DataType>(value);
    BSTreeNode<DataType> *parent = nullptr;
    BSTreeNode<DataType> *current = root;

    while (current != nullptr) {
        parent = current;
        if (value < current->getKey())
            current = current->getLeft();
        else
            current = current->getRight();
    }

    newNode->setParent(parent);

    if (parent == nullptr)
        root = newNode;
    else if (value < parent->getKey())
        parent->setLeft(newNode);
    else
        parent->setRight(newNode);
}

template <typename DataType>
void BSTree<DataType>::remove(const DataType &value) {
    BSTreeNode<DataType>* node = search(root, value);
    if (!node) return;

    if (node->getLeft() == nullptr || node->getRight() == nullptr) {
        // Nodo con 0 o 1 hijo
        removeNode(node);
    } else {
        // Nodo con 2 hijos: buscar sucesor
        BSTreeNode<DataType>* successor = getMinimum(node->getRight());
        node->key = successor->getKey();
        removeNode(successor);
    }
}

template <typename DataType>
void BSTree<DataType>::removeNode(BSTreeNode<DataType>* node) {
    BSTreeNode<DataType>* child = node->getLeft() ? node->getLeft() : node->getRight();

    if (node->getParent() == nullptr) {
        root = child;
    } else if (node == node->getParent()->getLeft()) {
        node->getParent()->setLeft(child);
    } else {
        node->getParent()->setRight(child);
    }

    if (child) child->setParent(node->getParent());

    node->setLeft(nullptr);
    node->setRight(nullptr);
    delete node;
}

template <typename DataType>
BSTreeNode<DataType>* BSTree<DataType>::search(const BSTreeNode<DataType> *node,
                                               const DataType &value) const {
    while (node) {
        if (value == node->getKey())
            return const_cast<BSTreeNode<DataType> *>(node);
        else if (value < node->getKey())
            node = node->getLeft();
        else
            node = node->getRight();
    }
    return nullptr;
}

template <typename DataType>
BSTreeNode<DataType>* BSTree<DataType>::getMinimum(const BSTreeNode<DataType> *node) const {
    while (node && node->getLeft())
        node = node->getLeft();
    return const_cast<BSTreeNode<DataType> *>(node);
}

template <typename DataType>
BSTreeNode<DataType>* BSTree<DataType>::getMaximum(const BSTreeNode<DataType> *node) const {
    while (node && node->getRight())
        node = node->getRight();
    return const_cast<BSTreeNode<DataType> *>(node);
}

template <typename DataType>
BSTreeNode<DataType>* BSTree<DataType>::getSuccessor(const BSTreeNode<DataType> *node) const {
    if (node->getRight())
        return getMinimum(node->getRight());

    const BSTreeNode<DataType> *p = node->getParent();
    while (p && node == p->getRight()) {
        node = p;
        p = p->getParent();
    }
    return const_cast<BSTreeNode<DataType> *>(p);
}

template <typename DataType>
BSTreeNode<DataType>* BSTree<DataType>::getRoot() const {
    return root;
}

template <typename DataType>
void BSTree<DataType>::inorderWalk(BSTreeNode<DataType> *node) const {
    std::stack<BSTreeNode<DataType>*> stack;

    while (node || !stack.empty()) {
        // Llega al nodo más izquierdo
        while (node) {
            stack.push(node);
            node = node->getLeft();
        }

        // Procesa el nodo en la cima del stack
        node = stack.top();
        stack.pop();

        std::cout << node->getKey() << " ";

        // Cambia al subárbol derecho
        node = node->getRight();
    }
}

template <typename DataType>
void BSTree<DataType>::preorderWalk(BSTreeNode<DataType> *node) const {
    if (node) {
        std::cout << node->getKey() << " ";
        preorderWalk(node->getLeft());
        preorderWalk(node->getRight());
    }
}

template <typename DataType>
void BSTree<DataType>::postorderWalk(BSTreeNode<DataType> *node) const {
    if (node) {
        postorderWalk(node->getLeft());
        postorderWalk(node->getRight());
        std::cout << node->getKey() << " ";
    }
}

template <typename T>
void BSTree<T>::fastInsert(size_t n) {
    if (n == 0) return;

    root = new BSTreeNode<T>(0); // Insertar la raíz manualmente
    BSTreeNode<T>* current = root;

    for (size_t i = 1; i < n; ++i) {
        current->right = new BSTreeNode<T>(i);
        current = current->right;
    }
}
