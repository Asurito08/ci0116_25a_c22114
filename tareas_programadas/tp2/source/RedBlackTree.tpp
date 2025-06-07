#pragma once

#include <iostream>
#include "RedBlackTree.hpp"

template <typename DataType>
RBTreeNode<DataType>::RBTreeNode(const DataType &value, RBTreeNode<DataType> *parent,
                                 RBTreeNode<DataType> *left, RBTreeNode<DataType> *right,
                                 enum colors c)
    : key(value), parent(parent), left(left), right(right), color(c) {}

template <typename DataType>
RBTreeNode<DataType>::~RBTreeNode() {}

template <typename DataType>
DataType RBTreeNode<DataType>::getKey() const {
    return key;
}

template <typename DataType>
RBTreeNode<DataType> *RBTreeNode<DataType>::getParent() const {
    return parent;
}

template <typename DataType>
RBTreeNode<DataType> *RBTreeNode<DataType>::getLeft() const {
    return left;
}

template <typename DataType>
RBTreeNode<DataType> *RBTreeNode<DataType>::getRight() const {
    return right;
}

template <typename DataType>
enum colors RBTreeNode<DataType>::getColor() const {
    return color;
}

template <typename DataType>
void RBTreeNode<DataType>::setKey(DataType newKey) {
    key = newKey;
}

template <typename DataType>
void RBTreeNode<DataType>::setColor(enum colors newColor) {
    color = newColor;
}

template <typename DataType>
void RBTreeNode<DataType>::setParent(RBTreeNode<DataType> *newParent) {
    parent = newParent;
}

template <typename DataType>
void RBTreeNode<DataType>::setLeft(RBTreeNode<DataType> *newLeft) {
    left = newLeft;
}

template <typename DataType>
void RBTreeNode<DataType>::setRight(RBTreeNode<DataType> *newRight) {
    right = newRight;
}

template <typename DataType>
RBTree<DataType>::RBTree() {
    nil = new RBTreeNode<DataType>();
    nil->setColor(BLACK);
    nil->setLeft(nullptr);
    nil->setRight(nullptr);
    nil->setParent(nullptr);
    root = nil;
}

template <typename DataType>
RBTree<DataType>::~RBTree() {
    delete nil;
}

template <typename DataType>
RBTreeNode<DataType> *RBTree<DataType>::getRoot() const {
    return root;
}

template <typename DataType>
RBTreeNode<DataType> *RBTree<DataType>::getNil() const {
    return nil;
}

template <typename DataType>
void RBTree<DataType>::setRoot(RBTreeNode<DataType> *newRoot) {
    root = newRoot;
}

template <typename DataType>
void RBTree<DataType>::setNil(RBTreeNode<DataType> *newNil) {
    nil = newNil;
}

template <typename DataType>
void RBTree<DataType>::rotateLeft(RBTreeNode<DataType> *x) {
    RBTreeNode<DataType> *y = x->getRight();
    x->setRight(y->getLeft());
    if (y->getLeft() != nil)
        y->getLeft()->setParent(x);
    y->setParent(x->getParent());
    if (x->getParent() == nullptr)
        root = y;
    else if (x == x->getParent()->getLeft())
        x->getParent()->setLeft(y);
    else
        x->getParent()->setRight(y);
    y->setLeft(x);
    x->setParent(y);
}

template <typename DataType>
void RBTree<DataType>::rotateRight(RBTreeNode<DataType> *x) {
    RBTreeNode<DataType> *y = x->getLeft();
    x->setLeft(y->getRight());
    if (y->getRight() != nil)
        y->getRight()->setParent(x);
    y->setParent(x->getParent());
    if (x->getParent() == nullptr)
        root = y;
    else if (x == x->getParent()->getRight())
        x->getParent()->setRight(y);
    else
        x->getParent()->setLeft(y);
    y->setRight(x);
    x->setParent(y);
}

template <typename DataType>
void RBTree<DataType>::insert(const DataType &value) {
    RBTreeNode<DataType> *newNode = new RBTreeNode<DataType>(value);
    newNode->setLeft(nil);
    newNode->setRight(nil);
    newNode->setColor(RED);

    RBTreeNode<DataType> *parent = nullptr;
    RBTreeNode<DataType> *current = root;

    while (current != nil) {
        parent = current;
        if (value < current->getKey())
            current = current->getLeft();
        else
            current = current->getRight();
    }

    newNode->setParent(parent);

    if (parent == nullptr) {
        root = newNode;
    } else if (value < parent->getKey()) {
        parent->setLeft(newNode);
    } else {
        parent->setRight(newNode);
    }

    if (newNode->getParent() == nullptr) {
        newNode->setColor(BLACK);
        return;
    }

    if (newNode->getParent()->getParent() == nullptr) {
        return;
    }

    insertFixup(newNode);
}

template <typename DataType>
void RBTree<DataType>::insertFixup(RBTreeNode<DataType> *node) {
    while (node != root && node->getParent()->getColor() == RED) {
        RBTreeNode<DataType> *parent = node->getParent();
        RBTreeNode<DataType> *grandparent = parent->getParent();

        if (parent == grandparent->getLeft()) {
            RBTreeNode<DataType> *uncle = grandparent->getRight();
            if (uncle->getColor() == RED) {
                parent->setColor(BLACK);
                uncle->setColor(BLACK);
                grandparent->setColor(RED);
                node = grandparent;
            } else {
                if (node == parent->getRight()) {
                    node = parent;
                    rotateLeft(node);
                    parent = node->getParent();
                }
                parent->setColor(BLACK);
                grandparent->setColor(RED);
                rotateRight(grandparent);
            }
        } else {
            RBTreeNode<DataType> *uncle = grandparent->getLeft();
            if (uncle->getColor() == RED) {
                parent->setColor(BLACK);
                uncle->setColor(BLACK);
                grandparent->setColor(RED);
                node = grandparent;
            } else {
                if (node == parent->getLeft()) {
                    node = parent;
                    rotateRight(node);
                    parent = node->getParent();
                }
                parent->setColor(BLACK);
                grandparent->setColor(RED);
                rotateLeft(grandparent);
            }
        }
    }
    root->setColor(BLACK);
}

template <typename DataType>
RBTreeNode<DataType> *RBTree<DataType>::search(const RBTreeNode<DataType> *rootOfSubtree,
                                               const DataType &value) const {
    if (rootOfSubtree == nil || rootOfSubtree == nullptr) return nullptr;
    if (value == rootOfSubtree->getKey()) return const_cast<RBTreeNode<DataType> *>(rootOfSubtree);

    if (value < rootOfSubtree->getKey())
        return search(rootOfSubtree->getLeft(), value);
    else
        return search(rootOfSubtree->getRight(), value);
}

template <typename DataType>
RBTreeNode<DataType> *RBTree<DataType>::getMinimum(const RBTreeNode<DataType> *rootOfSubtree) const {
    const RBTreeNode<DataType> *current = rootOfSubtree;
    if (!current) return nullptr;

    while (current->getLeft() != nil) {
        current = current->getLeft();
    }
    return const_cast<RBTreeNode<DataType> *>(current);
}

template <typename DataType>
RBTreeNode<DataType> *RBTree<DataType>::getMaximum(const RBTreeNode<DataType> *rootOfSubtree) const {
    const RBTreeNode<DataType> *current = rootOfSubtree;
    if (!current) return nullptr;

    while (current->getRight() != nil) {
        current = current->getRight();
    }
    return const_cast<RBTreeNode<DataType> *>(current);
}

template <typename DataType>
RBTreeNode<DataType> *RBTree<DataType>::getSuccessor(const RBTreeNode<DataType> *node) const {
    if (node->getRight() != nil) {
        return getMinimum(node->getRight());
    }

    RBTreeNode<DataType> *parent = node->getParent();
    RBTreeNode<DataType> *current = const_cast<RBTreeNode<DataType> *>(node);

    while (parent != nullptr && current == parent->getRight()) {
        current = parent;
        parent = parent->getParent();
    }
    return parent;
}

template <typename DataType>
void RBTree<DataType>::transplant(RBTreeNode<DataType>* u, RBTreeNode<DataType>* v) {
    if (u->getParent() == nullptr) {
        root = v;
    } else if (u == u->getParent()->getLeft()) {
        u->getParent()->setLeft(v);
    } else {
        u->getParent()->setRight(v);
    }
    v->setParent(u->getParent());
}

template <typename DataType>
void RBTree<DataType>::remove(const DataType& value) {
    RBTreeNode<DataType>* z = search(root, value);
    if (z == nullptr || z == nil) return;

    RBTreeNode<DataType>* y = z;
    enum colors yOriginalColor = y->getColor();
    RBTreeNode<DataType>* x;

    if (z->getLeft() == nil) {
        x = z->getRight();
        transplant(z, z->getRight());
    } else if (z->getRight() == nil) {
        x = z->getLeft();
        transplant(z, z->getLeft());
    } else {
        y = getMinimum(z->getRight());
        yOriginalColor = y->getColor();
        x = y->getRight();

        if (y->getParent() == z) {
            x->setParent(y);
        } else {
            transplant(y, y->getRight());
            y->setRight(z->getRight());
            y->getRight()->setParent(y);
        }

        transplant(z, y);
        y->setLeft(z->getLeft());
        y->getLeft()->setParent(y);
        y->setColor(z->getColor());
    }

    if (yOriginalColor == BLACK) {
        removeFixup(x);
    }

    delete z;
}

template <typename DataType>
void RBTree<DataType>::removeFixup(RBTreeNode<DataType>* x) {
    while (x != root && x->getColor() == BLACK) {
        if (x == x->getParent()->getLeft()) {
            RBTreeNode<DataType>* w = x->getParent()->getRight();
            if (w->getColor() == RED) {
                w->setColor(BLACK);
                x->getParent()->setColor(RED);
                rotateLeft(x->getParent());
                w = x->getParent()->getRight();
            }
            if (w->getLeft()->getColor() == BLACK && w->getRight()->getColor() == BLACK) {
                w->setColor(RED);
                x = x->getParent();
            } else {
                if (w->getRight()->getColor() == BLACK) {
                    w->getLeft()->setColor(BLACK);
                    w->setColor(RED);
                    rotateRight(w);
                    w = x->getParent()->getRight();
                }
                w->setColor(x->getParent()->getColor());
                x->getParent()->setColor(BLACK);
                w->getRight()->setColor(BLACK);
                rotateLeft(x->getParent());
                x = root;
            }
        } else {
            RBTreeNode<DataType>* w = x->getParent()->getLeft();
            if (w->getColor() == RED) {
                w->setColor(BLACK);
                x->getParent()->setColor(RED);
                rotateRight(x->getParent());
                w = x->getParent()->getLeft();
            }
            if (w->getRight()->getColor() == BLACK && w->getLeft()->getColor() == BLACK) {
                w->setColor(RED);
                x = x->getParent();
            } else {
                if (w->getLeft()->getColor() == BLACK) {
                    w->getRight()->setColor(BLACK);
                    w->setColor(RED);
                    rotateLeft(w);
                    w = x->getParent()->getLeft();
                }
                w->setColor(x->getParent()->getColor());
                x->getParent()->setColor(BLACK);
                w->getLeft()->setColor(BLACK);
                rotateRight(x->getParent());
                x = root;
            }
        }
    }
    x->setColor(BLACK);
}
