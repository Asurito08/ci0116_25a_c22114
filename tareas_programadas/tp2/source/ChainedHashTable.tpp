#pragma once
#include <iostream>

template <typename DataType>
size_t ChainedHashTable<DataType>::kmodm(const DataType& value) const {
    return static_cast<size_t>(value) % size;
}

template <typename DataType>
ChainedHashTable<DataType>::ChainedHashTable(size_t size)
    : size(size), table(size) {}

template <typename DataType>
ChainedHashTable<DataType>::~ChainedHashTable() {}

template <typename DataType>
void ChainedHashTable<DataType>::insert(const DataType& value) {
    size_t index = kmodm(value);
    if (table[index].search(value) == nullptr) {
        table[index].insert(value);
        std::cout << "[Insertar] Valor " << value << " insertado en índice " << index << "\n";
    } else {
        std::cout << "[Insertar] Valor " << value << " ya existe en índice " << index << "\n";
    }
}

template <typename DataType>
DLListNode<DataType>* ChainedHashTable<DataType>::search(const DataType& value) const {
    size_t index = kmodm(value);
    return table[index].search(value);
}

template <typename DataType>
void ChainedHashTable<DataType>::remove(const DataType& value) {
    size_t index = kmodm(value);
    DLListNode<DataType>* node = table[index].search(value);
    if (node != nullptr) {
        table[index].remove(value);
        std::cout << "[Eliminar] Valor " << value << " eliminado de índice " << index << "\n";
    } else {
        std::cout << "[Eliminar] Valor " << value << " no encontrado en índice " << index << "\n";
    }
}

template <typename DataType>
size_t ChainedHashTable<DataType>::getSize() const {
    return size;
}

template <typename DataType>
std::vector<DLList<DataType>> ChainedHashTable<DataType>::getTable() const {
    return table;
}

template <typename DataType>
void ChainedHashTable<DataType>::setTable(std::vector<DLList<DataType>> newTable) {
    if (newTable.size() == size) {
        table = std::move(newTable);
    }
}