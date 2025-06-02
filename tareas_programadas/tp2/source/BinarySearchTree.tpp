#pragma once
#include <iostream>
#include <random>

// ===== BSTreeNode Implementation =====
template <typename DataType>
BSTreeNode<DataType>::BSTreeNode(const DataType &value, BSTreeNode<DataType> *parent,
                                  BSTreeNode<DataType> *left, BSTreeNode<DataType> *right)
    : key(value), parent(parent), left(left), right(right) {}

template <typename DataType>
BSTreeNode<DataType>::~BSTreeNode() {
    // No eliminar left ni right aquí para evitar doble borrado
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

// ===== BSTree Implementation =====

// Constructor
template <typename DataType>
BSTree<DataType>::BSTree() : root(nullptr) {}

// Destructor - borra todo el árbol usando función auxiliar
template <typename DataType>
void BSTree<DataType>::deleteSubtree(BSTreeNode<DataType>* node) {
    if (!node) return;
    deleteSubtree(node->getLeft());
    deleteSubtree(node->getRight());
    delete node;
}

template <typename DataType>
BSTree<DataType>::~BSTree() {
    deleteSubtree(root);
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
BSTreeNode<DataType>* BSTree<DataType>::search(const BSTreeNode<DataType> *node,
                                               const DataType &value) const {
    if (!node || value == node->getKey())
        return const_cast<BSTreeNode<DataType> *>(node);

    if (value < node->getKey())
        return search(node->getLeft(), value);
    else
        return search(node->getRight(), value);
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
    if (node) {
        inorderWalk(node->getLeft());
        std::cout << node->getKey() << " ";
        inorderWalk(node->getRight());
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

// Función auxiliar para eliminar un nodo que tiene 0 o 1 hijo
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
void BSTree<DataType>::fastInsert(size_t n) {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<DataType> dist(0, 100);

    for (size_t i = 0; i < n; ++i) {
        insert(dist(gen));
    }
}
