#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <unordered_map>
#include <vector>
#include <list>

/**
 * @class Grafo
 * @brief Representa un grafo dirigido ponderado usando listas de adyacencia.
 * 
 * Cada nodo está identificado por un string y las aristas tienen un peso entero.
 */
class Grafo {
public:
    /**
     * @brief Agrega una arista dirigida desde el nodo origen al nodo destino con un peso dado.
     * 
     * Si los nodos no existen, se crean automáticamente.
     * 
     * @param origen Nodo desde donde parte la arista.
     * @param destino Nodo al que llega la arista.
     * @param peso Peso o costo asociado a la arista.
     */
    void agregarArista(const std::string& origen, const std::string& destino, int peso);

    /**
     * @brief Obtiene todos los nodos existentes en el grafo.
     * 
     * @return std::vector<std::string> Vector con los nombres de todos los nodos.
     */
    std::vector<std::string> obtenerNodos() const;

    /**
     * @brief Obtiene la estructura de adyacencias del grafo.
     * 
     * @return const std::unordered_map<std::string, std::list<std::pair<std::string, int>>>&  
     *         Mapa donde cada clave es un nodo y el valor es la lista de pares (nodo destino, peso).
     */
    const std::unordered_map<std::string, std::list<std::pair<std::string, int>>>& obtenerAdyacencias() const;

private:
    std::unordered_map<std::string, std::list<std::pair<std::string, int>>> adyacencias; ///< Lista de adyacencia para cada nodo.
};

#endif
