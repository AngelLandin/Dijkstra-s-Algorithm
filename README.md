
# 🚗 Algoritmo de Dijkstra — Rutas más Cortas en un Grafo Real

## 🎯 Objetivo
Implementar el **algoritmo de Dijkstra** para encontrar las rutas más cortas en un grafo con **al menos 7 nodos**, donde los **pesos representan las distancias reales** entre ubicaciones obtenidas con **Google Maps**.

---

## 🧩 Descripción del Proyecto

Este proyecto implementa un grafo **no dirigido** en C++ utilizando una **lista de adyacencia**, donde cada nodo representa una ubicación real y cada arista indica la distancia (en metros o kilómetros) entre ellas.  
El programa permite:

- Seleccionar un **nodo origen**.  
- Calcular las **distancias mínimas** a todos los demás nodos.  
- Mostrar la **ruta más corta y la distancia total** hacia los destinos seleccionados.  

La estructura y los resultados se muestran en consola.

---

## ⚙️ Estructura del Proyecto

El código se encuentra separado en dos archivos:
📁 Proyecto_Dijkstra/
│
├── 📄 GrafoDijkstra.h # Definición de la clase y métodos
├── 📄 GrafoDijkstra.cpp # Implementación del algoritmo y función main()
├── 📄 README.md # Documentación del proyecto
└── 📁 img/ # Carpeta de imágenes
└── grafo.png # Imagen del grafo (distancias reales)
---

## 🗺️ Diseño del Grafo

Se seleccionaron **8 ubicaciones (A–H)** cercanas entre sí y se midieron las distancias reales mediante la herramienta  
**“Medir distancia” de Google Maps**.  
Estas distancias fueron asignadas como **pesos** a las aristas del grafo.

Ejemplo de conexiones:
| Conexión | Distancia (m) |
|-----------|----------------|
| A — C | 175 |
| C — F | 20 |
| F — G | 200 |
| A — B | 210 |
| C — E | 160 |
| E — D | 50 |
| D — B | 135 |
| D — H | 200 |
| E — G | 140 |
| G — H | 60 |

---
## 🖼️ Representación del Grafo

A continuación se muestra el diagrama del grafo utilizado, con los nodos (A–H) y las distancias medidas con Google Maps:

![Grafo del Proyecto](img/grafo.jpeg)
![Grafo del Proyecto](img/grafo_mapa.jpeg)


## 🧠 Algoritmo de Dijkstra

El algoritmo de Dijkstra se utiliza para determinar las **distancias mínimas** desde un nodo origen a todos los demás nodos del grafo.  
Se basa en el principio de **relajación**, que actualiza las distancias si se encuentra un camino más corto hacia un nodo vecino.

### 🔍 Proceso General:
1. Se inicializan todas las distancias con un valor infinito (`INF`).
2. La distancia del nodo origen se establece en `0`.
3. Se usa una **cola de prioridad (min-heap)** para seleccionar el nodo con la distancia mínima actual.
4. Se recorren sus vecinos y se actualizan las distancias si se encuentra un camino más corto.
5. Se repite el proceso hasta visitar todos los nodos.

---

## 🧱 Estructura de Datos Utilizada

- **Lista de Adyacencia:**  
  Implementada mediante `map<string, vector<pair<int, string>>>`  
  Permite representar el grafo de manera eficiente en memoria.
  
- **Cola de Prioridad (Min-Heap):**  
  Implementada con `priority_queue<Arista, vector<Arista>, greater<Arista>>`  
  Se utiliza para seleccionar el nodo con menor distancia pendiente por visitar.

---

## 🧮 Métodos Principales

| Método | Descripción |
|--------|--------------|
| `add_edge(u, v, weight)` | Agrega una conexión bidireccional entre los nodos `u` y `v`. |
| `print_graph()` | Muestra la estructura del grafo con sus conexiones y pesos. |
| `dijkstra(start)` | Aplica el algoritmo de Dijkstra desde el nodo `start` y devuelve las distancias mínimas. |
| `print_shortest_path(dest, distances, prev)` | Muestra la ruta óptima y la distancia total hacia el destino `dest`. |

---

## 💻 Ejecución del Programa

Al ejecutar el programa principal (`main()`), se muestran los siguientes resultados:

1. **Estructura del Grafo Inicial.**  
2. **Distancias mínimas** desde el nodo origen (`A`) hacia todos los demás.  
3. **Camino óptimo** y **distancia total** hacia tres destinos diferentes:  
   - `H` (destino final)  
   - `E`  
   - `B`  

Ejemplo de salida:


---

## 🧪 Pruebas Realizadas

- Se probaron distancias **grandes y pequeñas** para verificar la robustez del algoritmo.  
- Se verificó que el algoritmo manejara correctamente **nodos inalcanzables**.  
- Se comprobó la **consistencia de las rutas mínimas** en diferentes configuraciones de grafo.

---

## 📹 Video Explicativo

🎥 **Enlace al video en YouTube:**  
👉 [Agregar aquí el enlace del video de demostración](https://youtu.be/)

---

## 👩‍💻 Autores

| Nombre completo | Matrícula |
|-----------------|------------|
| **Ángel Landín López** | A00574700 |
| **Ángeles Araiza García** | A00574806 |
| **Carlos Andrés Gloria Cortes** | A00574714 |
| **Mónica Isabel Torres García** | A00573457 |

---

## 📚 Referencias

- Dijkstra, E. W. (1959). *A Note on Two Problems in Connexion with Graphs*.  
  Numerische Mathematik, 1, 269–271.  
- Documentación de C++ STL (`<map>`, `<vector>`, `<queue>`).  
- [Google Maps – Medir distancia](https://www.google.com/maps)

---






