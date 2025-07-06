#include "Algoritmos.h"

#include <iostream>
#include <queue>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

std::unordered_map<std::string, int> dijkstra(const Grafo &grafo, const std::string &origen)
{
    const int INF = std::numeric_limits<int>::max();
    std::unordered_map<std::string, int> distancias;
    auto nodos = grafo.obtenerNodos();

    for (const auto &nodo : nodos)
        distancias[nodo] = INF;

    using Par = std::pair<int, std::string>;
    std::priority_queue<Par, std::vector<Par>, std::greater<Par>> pq;

    distancias[origen] = 0;
    pq.push({0, origen});

    while (!pq.empty())
    {
        auto [dist, actual] = pq.top();
        pq.pop();

        if (dist > distancias[actual])
            continue;

        for (const auto &[vecino, peso] : grafo.obtenerAdyacencias().at(actual))
        {
            if (dist + peso < distancias[vecino])
            {
                distancias[vecino] = dist + peso;
                pq.push({distancias[vecino], vecino});
            }
        }
    }

    return distancias;
}

void dijkstra_con_camino(const Grafo &grafo, const std::string &origen,
                         std::unordered_map<std::string, int> &distancias,
                         std::unordered_map<std::string, std::string> &predecesores)
{
    const int INF = std::numeric_limits<int>::max();
    auto nodos = grafo.obtenerNodos();
    distancias.clear();
    predecesores.clear();

    for (const auto &nodo : nodos)
        distancias[nodo] = INF;

    using Par = std::pair<int, std::string>;
    std::priority_queue<Par, std::vector<Par>, std::greater<Par>> pq;

    distancias[origen] = 0;
    pq.push({0, origen});

    while (!pq.empty())
    {
        auto [dist, actual] = pq.top();
        pq.pop();

        if (dist > distancias[actual])
            continue;

        const auto &adyacentes = grafo.obtenerAdyacencias();
        auto it = adyacentes.find(actual);
        if (it != adyacentes.end())
        {
            // Aquí recorremos una lista en vez de vector
            for (const auto &vecino_peso : it->second)
            {
                const std::string &vecino = vecino_peso.first;
                int peso = vecino_peso.second;

                if (dist + peso < distancias[vecino])
                {
                    distancias[vecino] = dist + peso;
                    predecesores[vecino] = actual;
                    pq.push({distancias[vecino], vecino});
                }
            }
        }
    }
}

std::vector<std::string> reconstruir_camino(const std::string &destino,
                                            const std::unordered_map<std::string, std::string> &predecesores)
{
    std::vector<std::string> camino;
    std::string actual = destino;

    while (predecesores.find(actual) != predecesores.end())
    {
        camino.push_back(actual);
        actual = predecesores.at(actual);
    }
    camino.push_back(actual);
    std::reverse(camino.begin(), camino.end());
    return camino;
}

Grafo invertir_grafo(const Grafo &grafo)
{
    Grafo invertido;

    for (const auto &nodo : grafo.obtenerNodos())
    {
        invertido.agregarArista(nodo, nodo, 0);
    }

    const auto &adyacencias = grafo.obtenerAdyacencias();
    for (const auto &[nodo, vecinos] : adyacencias)
    {
        for (const auto &[vecino, peso] : vecinos)
        {
            if (nodo != vecino || peso != 0)
            {
                invertido.agregarArista(vecino, nodo, peso);
            }
        }
    }

    return invertido;
}

void mejores_ciudades_origen(const Grafo &grafo, const std::string &x)
{
    Grafo invertido = invertir_grafo(grafo);

    std::unordered_map<std::string, int> distancias;
    std::unordered_map<std::string, std::string> predecesores;
    dijkstra_con_camino(invertido, x, distancias, predecesores);

    int min_dist = std::numeric_limits<int>::max();
    for (const auto &[ciudad, dist] : distancias)
    {
        if (ciudad != x && dist < min_dist)
        {
            min_dist = dist;
        }
    }

    if (min_dist == std::numeric_limits<int>::max())
    {
        std::cout << "No hay ninguna ciudad con ruta a " << x << "\n";
        return;
    }

    std::vector<std::string> mejores;
    for (const auto &[ciudad, dist] : distancias)
    {
        if (dist == min_dist)
        {
            mejores.push_back(ciudad);
        }
    }

    std::cout << "Mejor tiempo para llegar a " << x << ": " << min_dist << "\n";
    std::cout << "Ciudades de origen con ese tiempo:\n";
    for (const auto &ciudad_origen : mejores)
    {
        std::cout << "- " << ciudad_origen << "\n";
        auto ruta = reconstruir_camino(ciudad_origen, predecesores);
        std::cout << "  Ruta: ";
        for (const auto &c : ruta)
            std::cout << c << " ";
        std::cout << "\n";
    }
}

void ciudades_mas_distantes(const Grafo &grafo)
{
    auto nodos = grafo.obtenerNodos();
    const int INF = std::numeric_limits<int>::max();

    int max_distancia = -1;
    std::vector<std::pair<std::string, std::string>> pares_mas_distantes;
    std::unordered_map<std::string, int> distancias;
    std::unordered_map<std::string, std::string> predecesores;

    for (const auto &origen : nodos)
    {
        dijkstra_con_camino(grafo, origen, distancias, predecesores);

        for (const auto &[destino, distancia] : distancias)
        {
            if (origen != destino && distancia != INF)
            {
                if (distancia > max_distancia)
                {
                    max_distancia = distancia;
                    pares_mas_distantes.clear();
                    pares_mas_distantes.emplace_back(origen, destino);
                }
                else if (distancia == max_distancia)
                {
                    pares_mas_distantes.emplace_back(origen, destino);
                }
            }
        }
    }

    if (max_distancia == -1)
    {
        std::cout << "No se encontraron pares de ciudades conectadas.\n";
        return;
    }

    std::cout << "Par(es) de ciudades más distantes con tiempo de viaje: " << max_distancia << "\n";

    for (const auto &[origen, destino] : pares_mas_distantes)
    {
        std::cout << "Desde " << origen << " hasta " << destino << ":\n";
        dijkstra_con_camino(grafo, origen, distancias, predecesores);
        auto camino = reconstruir_camino(destino, predecesores);
        std::cout << " Ruta: ";
        for (size_t i = 0; i < camino.size(); ++i)
        {
            std::cout << camino[i];
            if (i < camino.size() - 1)
                std::cout << " -> ";
        }
        std::cout << "\n";
    }
}

void encontrarParesMasCercanos(const Grafo &grafo)
{
    auto nodos = grafo.obtenerNodos();
    const int INF = std::numeric_limits<int>::max();

    int distanciaMinima = INF;
    std::vector<std::pair<std::string, std::string>> paresMinimos;

    std::unordered_map<std::string, std::unordered_map<std::string, int>> distanciasMap;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> predMap;

    for (const auto &origen : nodos)
    {
        std::unordered_map<std::string, int> dist;
        std::unordered_map<std::string, std::string> pred;

        dijkstra_con_camino(grafo, origen, dist, pred);
        distanciasMap[origen] = dist;
        predMap[origen] = pred;
    }

    for (const auto &x : nodos)
    {
        for (const auto &y : nodos)
        {
            if (x != y)
            {
                int d = INF;
                if (distanciasMap[x].count(y))
                    d = distanciasMap[x][y];
                if (d < distanciaMinima)
                {
                    distanciaMinima = d;
                    paresMinimos.clear();
                    paresMinimos.emplace_back(x, y);
                }
                else if (d == distanciaMinima)
                {
                    paresMinimos.emplace_back(x, y);
                }
            }
        }
    }

    if (distanciaMinima == INF)
    {
        std::cout << "No hay pares de ciudades conectadas.\n";
        return;
    }

    std::cout << "Pares de ciudades más cercanas con tiempo: " << distanciaMinima << "\n";

    for (auto &par : paresMinimos)
    {
        const std::string &origen = par.first;
        const std::string &destino = par.second;
        std::cout << "De " << origen << " a " << destino << ":\n";

        auto camino = reconstruir_camino(destino, predMap[origen]);
        std::cout << "Ruta: ";
        for (size_t i = 0; i < camino.size(); ++i)
        {
            std::cout << camino[i];
            if (i + 1 < camino.size())
                std::cout << " -> ";
        }
        std::cout << "\n";
    }
}

void listarCiudadesPorPromedioDistancia(const Grafo &grafo)
{
    const int INF = std::numeric_limits<int>::max();
    auto nodos = grafo.obtenerNodos();
    std::vector<std::pair<std::string, double>> promedios; // ciudad, promedio

    for (const auto &origen : nodos)
    {
        auto distancias = dijkstra(grafo, origen);
        int suma = 0;
        int count = 0;
        for (const auto &[destino, distancia] : distancias)
        {
            if (origen != destino && distancia < INF)
            {
                suma += distancia;
                count++;
            }
        }
        double promedio = (count > 0) ? (double)suma / count : INF;
        promedios.emplace_back(origen, promedio);
    }

    // Ordenar ascendente por promedio
    std::sort(promedios.begin(), promedios.end(), [](auto &a, auto &b)
              { return a.second < b.second; });

    std::cout << "\nCiudades ordenadas por tiempo promedio de viaje:\n";
    for (const auto &[ciudad, promedio] : promedios)
    {
        if (promedio == INF)
            std::cout << " - " << ciudad << ": no conecta con otras ciudades\n";
        else
            std::cout << " - " << ciudad << ": promedio = " << promedio << "\n";
    }
}
