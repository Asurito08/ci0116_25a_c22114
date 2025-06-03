#pragma once

template <typename DataType>
DLListNode<DataType>::DLListNode(const DataType& value, DLListNode<DataType>* next, DLListNode<DataType>* prev)
    : key(value), next(next), prev(prev) {}

template <typename DataType>
DataType DLListNode<DataType>::getKey() const {
    return key;
}

template <typename DataType>
DLListNode<DataType>* DLListNode<DataType>::getPrev() const {
    return prev;
}

template <typename DataType>
DLListNode<DataType>* DLListNode<DataType>::getNext() const {
    return next;
}

template <typename DataType>
void DLListNode<DataType>::setKey(DataType key) {
    this->key = key;
}

template <typename DataType>
void DLListNode<DataType>::setPrev(DLListNode<DataType>* prev) {
    this->prev = prev;
}

template <typename DataType>
void DLListNode<DataType>::setNext(DLListNode<DataType>* next) {
    this->next = next;
}

template <typename DataType>
DLList<DataType>::DLList() {
    nil = new DLListNode<DataType>();
    nil->setNext(nil);
    nil->setPrev(nil);
}

template <typename DataType>
DLList<DataType>::~DLList() {
    DLListNode<DataType>* current = nil->getNext();
    while (current != nil) {
        DLListNode<DataType>* temp = current;
        current = current->getNext();
        delete temp;
    }
    delete nil;
}

template <typename DataType>
void DLList<DataType>::insert(const DataType& value) {
    DLListNode<DataType>* node = new DLListNode<DataType>(value, nil->getNext(), nil);
    nil->getNext()->setPrev(node);
    nil->setNext(node);
}

template <typename DataType>
DLListNode<DataType>* DLList<DataType>::search(const DataType& value) const {
    DLListNode<DataType>* current = nil->getNext();
    while (current != nil) {
        if (current->getKey() == value) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr; 
}

template <typename DataType>
void DLList<DataType>::remove(const DataType& value) {
    DLListNode<DataType>* node = search(value);
    if (node != nil) {
        remove(node);
    }
}

template <typename DataType>
void DLList<DataType>::remove(DLListNode<DataType>* node) {
    if (node == nil) return;
    node->getPrev()->setNext(node->getNext());
    node->getNext()->setPrev(node->getPrev());
    delete node;
}

template <typename DataType>
DLListNode<DataType>* DLList<DataType>::getNil() const {
    return nil;
}
