#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "Grafo.h"

/**
 * @brief Carga un grafo desde un archivo CSV.
 *
 * El archivo debe contener las aristas con formato adecuado para construir el grafo.
 * Esta función lee el archivo y agrega las aristas al objeto Grafo proporcionado.
 *
 * @param nombreArchivo Ruta o nombre del archivo CSV a leer.
 * @param grafo Objeto Grafo donde se almacenarán las aristas cargadas.
 */
void cargarGrafoDesdeCSV(const std::string &nombreArchivo, Grafo &grafo);

#endif
