#pragma once

template <typename DataType>
SLListNode<DataType>::SLListNode() : next(nullptr) {}

template <typename DataType>
SLListNode<DataType>::SLListNode(DataType key, SLListNode<DataType>* next)
    : key(key), next(next) {}

template <typename DataType>
SLListNode<DataType>::~SLListNode() {}

template <typename DataType>
DataType SLListNode<DataType>::getKey() const {
  return key;
}

template <typename DataType>
SLListNode<DataType>* SLListNode<DataType>::getNext() const {
  return next;
}

template <typename DataType>
void SLListNode<DataType>::setKey(DataType key) {
  this->key = key;
}

template <typename DataType>
void SLListNode<DataType>::setNext(SLListNode<DataType>* newNode) {
  next = newNode;
}

template <typename DataType>
SLList<DataType>::SLList() {
  nil = nullptr;
}

template <typename DataType>
SLList<DataType>::~SLList() {
  SLListNode<DataType>* current = nil;
  while (current != nullptr) {
    SLListNode<DataType>* temp = current;
    current = current->getNext();
    delete temp;
  }
}

template <typename DataType>
void SLList<DataType>::insert(const DataType& value) {
  SLListNode<DataType>* newNode = new SLListNode<DataType>(value, nil);
  nil = newNode;
}

template <typename DataType>
SLListNode<DataType>* SLList<DataType>::search(const DataType& value) const {
  SLListNode<DataType>* current = nil;
  while (current != nullptr) {
    if (current->getKey() == value) {
      return current;
    }
    current = current->getNext();
  }
  return nullptr;
}

template <typename DataType>
void SLList<DataType>::remove(const DataType& value) {
  SLListNode<DataType>* current = nil;
  SLListNode<DataType>* prev = nullptr;

  while (current != nullptr) {
    if (current->getKey() == value) {
      SLListNode<DataType>* toDelete = current;
      if (prev == nullptr) {
        nil = current->getNext();
      } else {
        prev->setNext(current->getNext());
      }
      current = current->getNext();
      delete toDelete;
    } else {
      prev = current;
      current = current->getNext();
    }
  }
}

template <typename DataType>
SLListNode<DataType>* SLList<DataType>::getNil() const {
  return nil;
}
