#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits>

#include "Grafo.h"
#include "Algoritmos.h"
#include "utils.h"

/**
 * @brief Programa principal que carga un grafo desde un archivo CSV y ofrece un menú
 *        para realizar consultas sobre ciudades y rutas utilizando algoritmos de grafos.
 * 
 * El programa permite:
 * - Mostrar todas las ciudades cargadas.
 * - Consultar la mejor ciudad para distribuir equipo (menor suma de distancias).
 * - Consultar la mejor ciudad para enviar ayuda a una ciudad específica (camino más corto).
 * - Mostrar el par de ciudades más distantes.
 * - Encontrar pares de ciudades menos distantes.
 * - Listar ciudades ordenadas por tiempo promedio de viaje a otras ciudades.
 * 
 * El usuario interactúa mediante un menú en consola.
 * 
 * @return int Código de salida (0 si termina normalmente).
 */ 
int main()
{
    Grafo grafo;
    std::string archivo;

    std::cout << "Ingrese el nombre del archivo CSV: ";
    std::cin >> archivo;

    cargarGrafoDesdeCSV(archivo, grafo);
    std::cout << "Se cargaron " << grafo.obtenerNodos().size() << " ciudades.\n";

    int opcion;
    do
    {
        std::cout << "\n==== MENÚ ====\n";
        std::cout << "1. Mostrar ciudades\n";
        std::cout << "2. Consulta 1: Mejor ciudad para distribuir equipo\n";
        std::cout << "3. Consulta 2: Mejor ciudad para enviar ayuda a una ciudad específica\n";
        std::cout << "4. Consulta 3: Par de ciudades más distantes\n";
        std::cout << "5. Consulta 4: Encontrar pares de ciudades menos distantes\n";
        std::cout << "6. Consulta 5: Listar ciudades por tiempo promedio de viaje\n";
        std::cout << "7. Salir\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            std::cout << "\nCiudades en el grafo:\n";
            auto nodos = grafo.obtenerNodos();
            for (const auto &nodo : nodos)
                std::cout << " - " << nodo << "\n";
            break;
        }
        case 2:
        {
            std::cout << "\nConsulta 1: Calculando ciudad más efectiva para distribuir equipo...\n";

            auto nodos = grafo.obtenerNodos();
            const int INF = std::numeric_limits<int>::max();
            std::unordered_map<std::string, int> sumaPorCiudad;
            int mejorSuma = INF;

            for (const auto &origen : nodos)
            {
                auto distancias = dijkstra(grafo, origen);
                int suma = 0;

                for (const auto &[destino, distancia] : distancias)
                {
                    if (origen != destino && distancia < INF)
                        suma += distancia;
                }

                sumaPorCiudad[origen] = suma;
                if (suma < mejorSuma)
                    mejorSuma = suma;
            }

            std::cout << "\nCiudad(es) ideal(es) para ubicar equipo:\n";
            for (const auto &[ciudad, suma] : sumaPorCiudad)
            {
                if (suma == mejorSuma)
                {
                    std::cout << " - " << ciudad << " (tiempo total: " << suma << ")\n";
                }
            }

            break;
        }
        case 3:
        {
            std::string origen, destino;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpiar buffer

            std::cout << "Ingrese el nombre de la ciudad ORIGEN: ";
            std::getline(std::cin, origen);

            std::cout << "Ingrese el nombre de la ciudad DESTINO: ";
            std::getline(std::cin, destino);

            auto nodos = grafo.obtenerNodos();
            const int INF = std::numeric_limits<int>::max();

            // Validar si ambas ciudades existen
            if (std::find(nodos.begin(), nodos.end(), origen) == nodos.end())
            {
                std::cout << "La ciudad origen \"" << origen << "\" no existe en el grafo.\n";
                break;
            }
            if (std::find(nodos.begin(), nodos.end(), destino) == nodos.end())
            {
                std::cout << "La ciudad destino \"" << destino << "\" no existe en el grafo.\n";
                break;
            }

            std::unordered_map<std::string, int> dist;
            std::unordered_map<std::string, std::string> pred;

            dijkstra_con_camino(grafo, origen, dist, pred);

            if (dist.find(destino) == dist.end() || dist[destino] == INF)
            {
                std::cout << "No hay ruta desde " << origen << " hacia " << destino << ".\n";
            }
            else
            {
                std::cout << "\nRuta más rápida desde " << origen << " hasta " << destino << ":\n";
                auto camino = reconstruir_camino(destino, pred);

                std::cout << " - Tiempo total: " << dist[destino] << "\n";
                std::cout << " - Ruta: ";
                for (size_t i = 0; i < camino.size(); ++i)
                {
                    std::cout << camino[i];
                    if (i < camino.size() - 1)
                        std::cout << " -> ";
                }
                std::cout << "\n";
            }
            break;
        }
        case 4:
        {
            std::cout << "\nConsulta 3: Par de ciudades más distantes:\n";
            ciudades_mas_distantes(grafo);
            break;
        }
        case 5:
        {
            std::cout << "\nConsulta 4: Encontrando pares de ciudades menos distantes...\n";
            encontrarParesMasCercanos(grafo);
            break;
        }
        case 6:
        {
            listarCiudadesPorPromedioDistancia(grafo);
            break;
        }
        case 7:
        {
            std::cout << "Saliendo...\n";
            break;
        }
        default:
            std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 7);
    return 0;
}
