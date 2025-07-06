#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "Grafo.h"
#include <string>
#include <vector>
#include <unordered_map>

/**
 * @brief Calcula las distancias mínimas desde un nodo origen usando el algoritmo de Dijkstra.
 *
 * @param grafo Grafo sobre el cual se realizará el cálculo.
 * @param origen Nodo de inicio para calcular las distancias.
 * @return std::unordered_map<std::string, int> Mapa con las distancias mínimas desde el origen a cada nodo.
 */
std::unordered_map<std::string, int> dijkstra(const Grafo &grafo, const std::string &origen);

/**
 * @brief Calcula las distancias mínimas y los predecesores de cada nodo desde un nodo origen usando Dijkstra.
 *
 * @param grafo Grafo sobre el cual se realizará el cálculo.
 * @param origen Nodo de inicio para calcular las distancias.
 * @param distancias Mapa que almacenará las distancias mínimas calculadas (salida).
 * @param predecesores Mapa que almacenará el nodo predecesor en el camino más corto (salida).
 */
void dijkstra_con_camino(const Grafo &grafo, const std::string &origen,
                         std::unordered_map<std::string, int> &distancias,
                         std::unordered_map<std::string, std::string> &predecesores);

/**
 * @brief Reconstruye el camino más corto hasta un nodo destino a partir del mapa de predecesores.
 *
 * @param destino Nodo destino para reconstruir el camino.
 * @param predecesores Mapa con los predecesores de cada nodo en el camino más corto.
 * @return std::vector<std::string> Secuencia de nodos que forman el camino desde el origen hasta el destino.
 */
std::vector<std::string> reconstruir_camino(const std::string &destino,
                                            const std::unordered_map<std::string, std::string> &predecesores);

/**
 * @brief Imprime o calcula las ciudades más distantes dentro del grafo.
 *
 * @param grafo Grafo que contiene las ciudades y sus conexiones.
 */
void ciudades_mas_distantes(const Grafo &grafo);

/**
 * @brief Encuentra y muestra los pares de ciudades más cercanas dentro del grafo.
 *
 * @param grafo Grafo que contiene las ciudades y sus conexiones.
 */
void encontrarParesMasCercanos(const Grafo &grafo);

/**
 * @brief Lista las ciudades ordenadas por su promedio de distancia a las demás ciudades.
 *
 * @param grafo Grafo que contiene las ciudades y sus conexiones.
 */
void listarCiudadesPorPromedioDistancia(const Grafo &grafo);

#endif
