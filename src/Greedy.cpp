#include "../include/Greedy.h"
#include <iostream>
#include <vector>
#include <climits> // Para INT_MAX
using namespace std;

Greedy::Greedy() {}

vector<int> Greedy::Dijkstra(vector<vector<int>> cost, int n, int s) {
    const int INF = INT_MAX / 2;
    vector<int> d(n, INF);       // Distancias iniciales
    vector<bool> selected(n, false); // Nodos visitados

    d[s] = 0; // Distancia del origen a sí mismo

    for (int k = 0; k < n - 1; k++) {
        int u = -1;
        int minDist = INF;

        // Buscar el nodo no visitado con la menor distancia
        for (int i = 0; i < n; i++) {
            if (!selected[i] && d[i] < minDist) {
                minDist = d[i];
                u = i;
            }
        }

        if (u == -1) break; // No hay más nodos alcanzables
        selected[u] = true; // Marcamos el nodo mínimo como visitado

        // Relajamos las aristas desde u
        for (int v = 0; v < n; v++) {
            if (!selected[v] && cost[u][v] != INF && d[u] + cost[u][v] < d[v]) {
                d[v] = d[u] + cost[u][v];
            }
        }
    }

    return d;
}
