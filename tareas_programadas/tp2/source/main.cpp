#include "SinglyLinkedList.hpp"
#include <iostream>

int main() {
    SLList<int> lista;
    lista.insert(42);
    if (lista.search(41)) {
        std::cout << "Encontrado\n";
    } else {
        std::cout << "No encontrado\n";
    }
    return 0;
}
