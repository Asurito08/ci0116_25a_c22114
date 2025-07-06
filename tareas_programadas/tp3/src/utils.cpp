#include "utils.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

void cargarGrafoDesdeCSV(const std::string& nombreArchivo, Grafo& grafo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    std::string linea;
    int lineaNum = 0;

    while (getline(archivo, linea)) {
        lineaNum++;

        // Saltar encabezado
        if (lineaNum == 1) continue;

        std::stringstream ss(linea);
        std::string id1, source, id2, target, pesoStr;

        if (!getline(ss, id1, ',') || !getline(ss, source, ',') ||
            !getline(ss, id2, ',') || !getline(ss, target, ',') ||
            !getline(ss, pesoStr)) {
            std::cerr << "Línea inválida en " << nombreArchivo << " (línea " << lineaNum << "): " << linea << std::endl;
            continue;
        }

        try {
            int peso = std::stoi(pesoStr);
            grafo.agregarArista(source, target, peso);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error al convertir a entero en línea " << lineaNum << ": " << pesoStr << std::endl;
        }
    }

    archivo.close();
}
