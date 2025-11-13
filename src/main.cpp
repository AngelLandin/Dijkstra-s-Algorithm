#include "GrafoDijkstra.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;


// --- Ejecución del Programa ---
int main() {
    GrafoDijkstra g;
    string ORIGEN = "A";
    string DESTINO_FINAL = "H";
    
    // 1. Adición de Aristas (8 Nodos: A-H)
    // Basado en el diagrama de grafo proporcionado:
    
    // Tramo superior
    g.add_edge("A", "C", 175);
    g.add_edge("C", "F", 20);
    g.add_edge("F", "G", 200);

    // Tramo vertical derecho
    g.add_edge("A", "B", 210);

    // Tramo central
    g.add_edge("C", "E", 160);

    // Tramo inferior
    g.add_edge("E", "D", 50);
    g.add_edge("D", "B", 135);
    g.add_edge("D", "H", 200);

    // Tramo izquierdo
    g.add_edge("E", "G", 140);
    g.add_edge("G", "H", 60);


    // Muestra el grafo inicial
    g.print_graph();

    // 2. Ejecuta Dijkstra desde el origen A
    map<string, string> previous_nodes;
    map<string, int> distances = g.dijkstra(ORIGEN, previous_nodes);

    cout << "### 📍 Resultados de Dijkstra (Origen: " << ORIGEN << ") ###" << endl;

    // 4. Muestra: Distancia mínima a cada nodo
    cout << "\n**Distancia Mínima a Cada Nodo:**" << endl;
    for (const auto& pair : distances) {
        string dist_str = (pair.second == GrafoDijkstra::INF) ? "Inalcanzable" : to_string(pair.second) + "m";
        cout << "  - Nodo " << pair.first << ": " << dist_str << endl;
    }

    // 4. Muestra: Camino óptimo para el destino final H y otros dos nodos
    cout << "\n**Rutas Más Cortas (Camino Óptimo y Distancia Total):**" << endl;
    
    // 1. Destino Final H
    g.print_shortest_path(DESTINO_FINAL, distances, previous_nodes);
    
    // 2. Destino intermedio E
    g.print_shortest_path("E", distances, previous_nodes);

    // 3. Destino intermedio B
    g.print_shortest_path("B", distances, previous_nodes);

    cout << "\n--- Demostración finalizada ---" << endl;
    return 0;
}