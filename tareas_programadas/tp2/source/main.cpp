#include "BinarySearchTree.hpp"
#include "RedBlackTree.hpp"
#include "SinglyLinkedList.hpp"
#include <iostream>

// int main() {
//     SLList<int> lista;
//     lista.insert(42);
//     lista.insert(41);
//     if (lista.search(41)) {
//         std::cout << "Encontrado\n";
//     } else {
//         std::cout << "No encontrado\n";
//     }
//     return 0;
// }

// int main() {
//     BSTree<int> tree;

//     // Insertar elementos
//     tree.insert(50);
//     tree.insert(30);
//     tree.insert(70);
//     tree.insert(20);
//     tree.insert(40);
//     tree.insert(60);
//     tree.insert(80);

//     std::cout << "Recorrido Inorden: ";
//     tree.inorderWalk(tree.getRoot());
//     std::cout << "\n";

//     std::cout << "Recorrido Preorden: ";
//     tree.preorderWalk(tree.getRoot());
//     std::cout << "\n";

//     std::cout << "Recorrido Postorden: ";
//     tree.postorderWalk(tree.getRoot());
//     std::cout << "\n";

//     // Buscar un elemento
//     int key = 40;
//     auto node = tree.search(tree.getRoot(), key);
//     if (node)
//         std::cout << "Elemento encontrado: " << node->getKey() << "\n";
//     else
//         std::cout << "Elemento " << key << " no encontrado.\n";

//     // Eliminar un elemento
//     tree.remove(30);
//     std::cout << "Inorden después de eliminar 30: ";
//     tree.inorderWalk(tree.getRoot());
//     std::cout << "\n";

//     // Insertar valores aleatorios
//     std::cout << "Insertando 5 valores aleatorios...\n";
//     tree.fastInsert(5);
//     std::cout << "Inorden actual: ";
//     tree.inorderWalk(tree.getRoot());
//     std::cout << "\n";

//     return 0;
// }

// int main() {
//     // Crear tabla hash con tamaño 10
//     ChainedHashTable<int> hashTable(10);

//     // Insertar valores
//     hashTable.insert(5);
//     hashTable.insert(15);
//     hashTable.insert(25);

//     // Buscar un valor
//     auto node = hashTable.search(15);
//     if (node != nullptr) {
//         std::cout << "Valor 15 encontrado en la tabla." << std::endl;
//     } else {
//         std::cout << "Valor 15 no encontrado." << std::endl;
//     }

//     // Eliminar un valor
//     hashTable.remove(15);
//     node = hashTable.search(15);
//     if (node == nullptr) {
//         std::cout << "Valor 15 eliminado correctamente." << std::endl;
//     }

//     return 0;
// }



