#include "GrafoDijkstra.h"
#include <iostream>
#include <vector>
#include <climits> // Para INT_MAX
using namespace std;

// Métodos Requeridos: add_edge
void GrafoDijkstra::add_edge(const string& u, const string& v, int weight) {
    /*
    Agrega una arista bidireccional entre los nodos u y v con el peso dado,
    basada en el diagrama proporcionado (A-H).
    */
    if (adj.find(u) == adj.end()) adj[u] = {};
    if (adj.find(v) == adj.end()) adj[v] = {};
    
    // El grafo es no dirigido (bidireccional)
    adj[u].push_back({weight, v});
    adj[v].push_back({weight, u});
}

// Métodos Requeridos: print_graph
void GrafoDijkstra::print_graph() const {
    /* Muestra la estructura del grafo. */
    cout << "\n### 📝 Estructura del Grafo (8 Nodos: A-H) ###" << endl;
    cout << "(Basado en el diagrama con pesos en metros)" << endl;
    for (const auto& pair : adj) {
        cout << "Nodo " << pair.first << ": ";
        for (const auto& edge : pair.second) {
            cout << "(" << edge.second << ", " << edge.first << "m) ";
        }
        cout << endl;
    }
    cout << string(50, '-') << endl;
}

// Métodos Requeridos: dijkstra
map<string, int> GrafoDijkstra::dijkstra(const string& start_node, map<string, string>& previous_nodes) {
    /* Aplica el algoritmo de Dijkstra. */
    map<string, int> distances;
    
    for (const auto& pair : adj) {
        distances[pair.first] = INF;
        previous_nodes[pair.first] = "";
    }

    // Cola de prioridad (Min-Heap): (distancia, nodo)
    priority_queue<Arista, vector<Arista>, greater<Arista>> pq;

    distances[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        string u = pq.top().second;
        pq.pop();

        if (current_dist > distances[u]) {
            continue;
        }

        for (const auto& edge : adj[u]) {
            int weight = edge.first;
            string v = edge.second;
            
            // Relajación: Actualiza la distancia si se encuentra un camino más corto
            if (distances[u] != INF && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous_nodes[v] = u;
                pq.push({distances[v], v});
            }
        }
    }
    return distances;
}

// Métodos Requeridos: print_shortest_path
void GrafoDijkstra::print_shortest_path(const string& dest, const map<string, int>& distances, const map<string, string>& previous_nodes) const {
    /* Muestra la ruta más corta y la distancia total. */
    cout << "\n  - Destino " << dest << ":" << endl;
    
    if (distances.at(dest) == INF) {
        cout << "    -> **Inalcanzable**" << endl;
        cout << "    -> Distancia Total: Inalcanzable" << endl;
        return;
    }

    vector<string> path;
    string current = dest;
    while (current != "") {
        path.push_back(current);
        // Verifica que el nodo actual tenga un predecesor válido
        if (previous_nodes.find(current) == previous_nodes.end() || previous_nodes.at(current) == "") break;
        current = previous_nodes.at(current);
    }

    // Invierte el camino (va de destino a origen)
    reverse(path.begin(), path.end());

    cout << "    -> Ruta: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
    cout << "    -> **Distancia Total**: " << distances.at(dest) << "m" << endl;
}

// Definición de la constante estática INF
const int GrafoDijkstra::INF = numeric_limits<int>::max();