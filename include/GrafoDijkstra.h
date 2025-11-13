#ifndef GRAFODIJKSTRA_H
#define GRAFODIJKSTRA_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

// Define un alias para una arista: (peso/distancia, nodo_destino)
typedef pair<int, string> Arista;

class GrafoDijkstra {
private:
    // Lista de Adyacencia: {nodo_origen: [(distancia_1, nodo_destino_1), ...]}
    map<string, vector<Arista>> adj;

public:
    // Constante estática pública para representar "infinito"
    static const int INF;

    // Métodos
    void add_edge(const string& u, const string& v, int weight);
    void print_graph() const;
    map<string, int> dijkstra(const string& start_node, map<string, string>& previous_nodes);
    void print_shortest_path(const string& dest, const map<string, int>& distances, const map<string, string>& previous_nodes) const;
};

#endif // GRAFODIJKSTRA_H