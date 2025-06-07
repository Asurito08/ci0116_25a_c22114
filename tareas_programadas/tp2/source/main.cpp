#include "BinarySearchTree.hpp"
#include "ChainedHashTable.hpp"
#include "RedBlackTree.hpp"
#include "SinglyLinkedList.hpp"
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <random>

const int N = 1'000'000;
const int E = 10'000;
const int range = 3 * N;

void singlyLinkedList() {
    SLList<int> list;
    std::cout << "Inicio de inserciones aleatorias...\n";
    
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, range - 1);

    for(int i = 0; i < N; i++) {
        int value = dist(rng);
        list.insert(value);
    }

    std::cout << "Inserción completada.\n";

    auto start_search = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < E; i++) {
        int value = dist(rng);
        list.search(value);
    }
    auto end_search = std::chrono::high_resolution_clock::now();
    auto time_search = std::chrono::duration_cast<std::chrono::milliseconds>(end_search - start_search).count();
    std::cout << "Tiempo total de búsqueda: " << time_search << " ms\n";

    auto start_remove = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < E; i++) {
        int value = dist(rng);
        list.remove(value);
    }
    auto end_remove = std::chrono::high_resolution_clock::now();
    auto time_remove = std::chrono::duration_cast<std::chrono::milliseconds>(end_remove - start_remove).count();
    std::cout << "Tiempo total de eliminación: " << time_remove << " ms\n";
}

void singlyLinkedListOrdenado() {
    SLList<int> list;
    std::cout << "Inicio de inserciones secuenciales...\n";

    for (int i = 0; i < N; ++i) {
        list.insert(i);
    }
    std::cout << "Inserción completada.\n";

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, range - 1);

    auto start_search = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < E; ++i) {
        int value = dist(rng);
        list.search(value);
    }
    auto end_search = std::chrono::high_resolution_clock::now();
    auto time_search = std::chrono::duration_cast<std::chrono::milliseconds>(end_search - start_search).count();
    std::cout << "Tiempo total de búsqueda: " << time_search << " ms\n";

    auto start_remove = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < E; ++i) {
        int value = dist(rng);
        list.remove(value);
    }
    auto end_remove = std::chrono::high_resolution_clock::now();
    auto time_remove = std::chrono::duration_cast<std::chrono::milliseconds>(end_remove - start_remove).count();
    std::cout << "Tiempo total de eliminación: " << time_remove << " ms\n";
}

void binarySearchTree() {
    BSTree<int> tree;
    std::cout << "Inicio de inserciones aleatorias...\n";
    
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, range - 1);

    for(int i = 0; i < N; i++) {
        int value = dist(rng);
        tree.insert(value);
    }

    std::cout << "Inserción completada.\n";

    auto start_search = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < E; i++) {
        int value = dist(rng);
        tree.search(tree.getRoot(), value);
    }
    auto end_search = std::chrono::high_resolution_clock::now();
    auto time_search = std::chrono::duration_cast<std::chrono::milliseconds>(end_search - start_search).count();
    std::cout << "Tiempo total de búsqueda: " << time_search << " ms\n";

    auto start_remove = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < E; i++) {
        int value = dist(rng);
        tree.remove(value);
    }
    auto end_remove = std::chrono::high_resolution_clock::now();
    auto time_remove = std::chrono::duration_cast<std::chrono::milliseconds>(end_remove - start_remove).count();
    std::cout << "Tiempo total de eliminación: " << time_remove << " ms\n";
}

void binarySearchTreeOrdenado() {
    BSTree<int> tree;
    std::cout << "Inicio de inserciones secuenciales...\n";

    tree.fastInsert(N);
    std::cout << "Inserción completada.\n";

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, range - 1);

    auto start_search = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < E; ++i) {
        int value = dist(rng);
        tree.search(tree.getRoot(), value);
    }
    auto end_search = std::chrono::high_resolution_clock::now();
    auto time_search = std::chrono::duration_cast<std::chrono::milliseconds>(end_search - start_search).count();
    std::cout << "Tiempo total de búsqueda: " << time_search << " ms\n";

    auto start_remove = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < E; ++i) {
        int value = dist(rng);
        tree.remove(value);
    }
    auto end_remove = std::chrono::high_resolution_clock::now();
    auto time_remove = std::chrono::duration_cast<std::chrono::milliseconds>(end_remove - start_remove).count();
    std::cout << "Tiempo total de eliminación: " << time_remove << " ms\n";
}

void redBlackTree() {
    RBTree<int> tree;
    std::cout << "Inicio de inserciones aleatorias...\n";
    
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, range - 1);

    for(int i = 0; i < N; i++) {
        int value = dist(rng);
        tree.insert(value);
    }

    std::cout << "Inserción completada.\n";

    auto start_search = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < E; i++) {
        int value = dist(rng);
        tree.search(tree.getRoot(), value);
    }
    auto end_search = std::chrono::high_resolution_clock::now();
    auto time_search = std::chrono::duration_cast<std::chrono::milliseconds>(end_search - start_search).count();
    std::cout << "Tiempo total de búsqueda: " << time_search << " ms\n";

    auto start_remove = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < E; i++) {
        int value = dist(rng);
        tree.remove(value);
    }
    auto end_remove = std::chrono::high_resolution_clock::now();
    auto time_remove = std::chrono::duration_cast<std::chrono::milliseconds>(end_remove - start_remove).count();
    std::cout << "Tiempo total de eliminación: " << time_remove << " ms\n";
}

void redBlackTreeOrdenado() {
    RBTree<int> tree;
    std::cout << "Inicio de inserciones secuenciales...\n";

    for (int i = 0; i < N; ++i) {
        tree.insert(i);
    }
    std::cout << "Inserción completada.\n";

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, range - 1);

    auto start_search = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < E; ++i) {
        int value = dist(rng);
        tree.search(tree.getRoot(), value);
    }
    auto end_search = std::chrono::high_resolution_clock::now();
    auto time_search = std::chrono::duration_cast<std::chrono::milliseconds>(end_search - start_search).count();
    std::cout << "Tiempo total de búsqueda: " << time_search << " ms\n";

    auto start_remove = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < E; ++i) {
        int value = dist(rng);
        tree.remove(value);
    }
    auto end_remove = std::chrono::high_resolution_clock::now();
    auto time_remove = std::chrono::duration_cast<std::chrono::milliseconds>(end_remove - start_remove).count();
    std::cout << "Tiempo total de eliminación: " << time_remove << " ms\n";
}

void hashTable() {
    ChainedHashTable<int> table(N);
    std::cout << "Inicio de inserciones aleatorias...\n";

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, range - 1);

    for (int i = 0; i < N; i++) {
        int value = dist(rng);
        table.insert(value);
    }

    std::cout << "Inserción completada.\n";

    auto start_search = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < E; i++) {
        int value = dist(rng);
        table.search(value);
    }
    auto end_search = std::chrono::high_resolution_clock::now();
    auto time_search = std::chrono::duration_cast<std::chrono::milliseconds>(end_search - start_search).count();
    std::cout << "Tiempo total de búsqueda: " << time_search << " ms\n";

    auto start_remove = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < E; i++) {
        int value = dist(rng);
        table.remove(value);
    }
    auto end_remove = std::chrono::high_resolution_clock::now();
    auto time_remove = std::chrono::duration_cast<std::chrono::milliseconds>(end_remove - start_remove).count();
    std::cout << "Tiempo total de eliminación: " << time_remove << " ms\n";
}

void hashTableOrdenado() {
    ChainedHashTable<int> table(N);
    std::cout << "Inicio de inserciones secuenciales...\n";

    for (int i = 0; i < N; ++i) {
        table.insert(i);
    }

    std::cout << "Inserción completada.\n";

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, range - 1);

    auto start_search = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < E; ++i) {
        int value = dist(rng);
        table.search(value);
    }
    auto end_search = std::chrono::high_resolution_clock::now();
    auto time_search = std::chrono::duration_cast<std::chrono::milliseconds>(end_search - start_search).count();
    std::cout << "Tiempo total de búsqueda: " << time_search << " ms\n";

    auto start_remove = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < E; ++i) {
        int value = dist(rng);
        table.remove(value);
    }
    auto end_remove = std::chrono::high_resolution_clock::now();
    auto time_remove = std::chrono::duration_cast<std::chrono::milliseconds>(end_remove - start_remove).count();
    std::cout << "Tiempo total de eliminación: " << time_remove << " ms\n";
}

int main() {
    int opcion;
    do {
        std::cout << "1. Lista simplemente enlazada.\n";
        std::cout << "2. Arbol de búsqueda binaria\n";
        std::cout << "3. Arbol de rojo y negro\n";
        std::cout << "4. Tabla de dispersión\n";
        std::cout << "5. Salir.\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                singlyLinkedList();
                singlyLinkedListOrdenado();
                break;
            case 2:
                binarySearchTree();
                binarySearchTreeOrdenado();
                break;
            case 3:
                redBlackTree();
                redBlackTreeOrdenado();
                break;
            case 4:
                hashTable();
                hashTableOrdenado();
            case 5:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
