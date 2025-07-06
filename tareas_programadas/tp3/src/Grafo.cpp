#include "Grafo.h"

void Grafo::agregarArista(const std::string &origen, const std::string &destino, int peso)
{
    adyacencias[origen].push_back({destino, peso});
    // Asegura que destino también exista en el mapa aunque no tenga salidas
    adyacencias[destino];
}

std::vector<std::string> Grafo::obtenerNodos() const
{
    std::vector<std::string> nodos;
    for (const auto &par : adyacencias)
        nodos.push_back(par.first);
    return nodos;
}

const std::unordered_map<std::string, std::list<std::pair<std::string, int>>> &Grafo::obtenerAdyacencias() const
{
    return adyacencias;
}
