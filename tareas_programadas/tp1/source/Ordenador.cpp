#include "Ordenador.hpp"


class Ordenador {
    private:

    int heapsize = 0;
    // Función para encontrar el hijo izquierdo en un árbol
    int hijoIzq(int i) {
        return 2*i;
    }

    // Función para encontrar el hijo derecho en un árbol
    int hijoDer(int i) {
        return 2*i+1;
    }

    // Función para crear un montículo máximo en un árbol
    void maximizarMonticulo(uint32_t *A, uint32_t n) {
        int l = hijoIzq(n);
        int r = hijoDer(n);
        if(l < sizeof(A)) {}
    }

    // Esta función llama por primera vez a la función para crear el montículo máximo
    void crearMonticuloMaximo(uint32_t *A, uint32_t n) {
        for(int i = floor(n/2); i >= 0; i--) {
            maximizarMonticulo(A, i);
        }
    }


    public:

    void ordenamientoPorSeleccion(uint32_t *A, uint32_t n) {
        for(int i = 0; i < n - 1; i++) {
            int minimo = i;
            for(int j = i + 1; j < n; j++) {
                if(A[j] < A[minimo]) {
                    minimo = j;
                }
            }
            if(minimo != i) {
                std::swap(A[i], A[minimo]);
            }
        }
    }

    void ordenamientoPorInsercion(uint32_t *A, uint32_t n) {
        int elementoAInsertar, j;
        for(int i = 2; i < n; i++) {
            elementoAInsertar = A[i];
            j = i-1;
            while (j >= 0 && A[j] > elementoAInsertar) {
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = elementoAInsertar;
        }
    }

    void ordenamientoPorMezcla(uint32_t *A, uint32_t n) {
        
    }
};