# Evidencias
# Evidencia Proyecto
**Autor:** Manuel Eduardo Contreras Flores (A01707142)

## Descripción
Este proyecto carga un archivo tipo tabla (CSV) con nombres de jugadores y sus estadísticas (PTS, REB, AST, STL, BLK). El programa permite elegir una estadística y mostrar a todos los jugadores ordenados de manera ascendente o descendente según ese valor.

Ejemplo:  
Archivo CSV: `sample_players_basket.csv`

## Funcionamiento actualizado:

### Paso 1: 
El programa lee automáticamente el archivo CSV y carga los jugadores en memoria.

### Paso 2: 
El usuario selecciona la opción del menú:
   - [1-5] Ordenar por PTS, REB, AST, STL, BLK.
   - [6] Registrar un nuevo jugador.
   - [7] **Buscar un jugador** (Nueva función).
   - [8] **Exportar lista actual a CSV** (Nueva función).
   - [0] Salir del programa.

### Paso 3 (Ordenamiento):
El programa ordena los jugadores usando **QuickSort sobre una lista doblemente ligada** y luego imprime la tabla ordenada.

---

### SICT0302B: Toma decisiones
**Selecciona y usa una estructura de datos adecuada al problema**
En este avance se optó por una **lista doblemente ligada (DLL)** para el proceso de ordenamiento porque:
- Permite recorrer los elementos en ambas direcciones (`prev` y `next`), lo cual facilita la lógica de partición en QuickSort sin necesidad de índices numéricos.
- **Eficiencia en memoria:** Al ordenar, el intercambio de nodos se logra ajustando punteros. Esto evita el movimiento masivo de datos que ocurriría en un vector al insertar o mover elementos en posiciones intermedias.

**Comparación de complejidad (Algoritmos y Estructuras):**
- **Vectores + QuickSort:** O(n log n) promedio. Sin embargo, si se requiriera insertar en medio, sería costoso O(n).
- **Lista doblemente ligada + QuickSort:** O(n log n) promedio. La inserción y borrado es O(1) si se tiene la referencia al nodo, o O(n) si se busca, pero nunca cuadrática.
- **Selection/Insertion sort:** O(n²), se descartaron por ser ineficientes para listas que pueden crecer.
- **Merge Sort:** O(n log n) estable, pero requiere memoria auxiliar O(n). QuickSort se realiza *in-place* sobre la lista.

---

### SICT0301B: Evalúa los componentes
**Hace un análisis de complejidad correcto y completo del programa:**

A continuación se desglosa la complejidad temporal (Big O) para cada funcionalidad, detallando explícitamente los tres escenarios:

**1. Carga y Construcción (`loadPlayers` + `buildDLL`):**
Se leen $n$ registros y se agregan a la lista usando un puntero `tail`.
- **Mejor caso:** O(n)
- **Caso promedio:** O(n)
- **Peor caso:** O(n)
- *Análisis:* La lectura es lineal y la inserción al final con `tail` es O(1) por elemento, resultando en O(n) total.

**2. Ordenamiento (QuickSort sobre DLL):**
Depende del pivote y el orden inicial de los datos.
- **Mejor caso:** O(n log n) (Particiones balanceadas).
- **Caso promedio:** O(n log n) (Datos aleatorios).
- **Peor caso:** O(n²) (Lista ya ordenada o inversamente ordenada).
- **Memoria:** O(log n) por la pila de recursión.

**3. Registro de nuevo jugador (`registrarJugador`):**
Implica buscar si el nombre existe (recorrido lineal) y luego insertar.
- **Mejor caso:** O(1) (El duplicado se detecta en el primer nodo).
- **Caso promedio:** O(n) (Se recorre la mitad de la lista).
- **Peor caso:** O(n) (No hay duplicados; se recorre toda la lista y se inserta al final).

**4. Búsqueda de jugador (`buscarJugador`):**
Búsqueda lineal por coincidencia de texto en el vector.
- **Mejor caso:** O(1) (Encontrado al inicio).
- **Caso promedio:** O(n) (Encontrado a la mitad o no existe).
- **Peor caso:** O(n) (No encontrado o está al final).

**5. Exportación de archivo (`saveAllPlayers`):**
Recorre la estructura completa para escribirla en un nuevo CSV.
- **Mejor caso:** O(n)
- **Caso promedio:** O(n)
- **Peor caso:** O(n)

**6. Visualización (`printTable`):**
Recorrido lineal para imprimir en consola.
- **Mejor caso:** O(n)
- **Caso promedio:** O(n)
- **Peor caso:** O(n)

**Complejidad final del programa:**
- **Mejor caso:** O(n log n)
- **Caso promedio** O(n log n)
- **Peor caso** O(n²)

---

### SICT0303B: Implementa acciones científicas
**Implementa mecanismos de lectura y escritura de archivos para guardar los datos de manera correcta:**

1.  **Lectura Robusta:**
    Se implementó un mecanismo de limpieza (`clean` y `splitCSV`) que elimina caracteres basura y espacios invisibles del CSV, y estandariza los valores numéricos (reemplazando comas por puntos) para asegurar una lectura correcta de las estadísticas.

2.  **Escritura (Persistencia y Reportes):**
    - **Modo Append:** Para el registro (Opción 6), se usa `std::ios::app` para añadir datos al final del archivo original de manera eficiente sin borrar el historial.
    - **Modo Write (Exportación):** Para la opción 8, se usa `std::ofstream` para crear un archivo nuevo (ej. `reporte.csv`) con los datos ya ordenados y limpios, permitiendo extraer la información procesada correctamente.
  


--- 

# Evidencia Problemas

* **Nombre:** Manuel Eduardo Contreras Flores
* **Matrícula:** A01707142

### Link a los videos: 
https://drive.google.com/drive/folders/1m54BfxH0-rim8HqrqAoUlfV-y-rbRjxK?usp=sharing


---

### Descripción General
Este repositorio contiene la evidencia práctica para las competencias **SICT0301**, **SICT0302** y **SICT0303**. Se seleccionaron y resolvieron tres problemas de la plataforma **LeetCode** para demostrar el dominio de:
1.  Algoritmos de Ordenamiento.
2.  Estructuras de Datos Lineales.
3.  Estructuras de Datos No Lineales.

* **Plataforma utilizada:** LeetCode
* **Enlace a mi perfil:** https://leetcode.com/u/mcontreras20/

---

## 1. Algoritmos de Ordenamiento

### Problema: [324. Wiggle Sort II] https://leetcode.com/problems/wiggle-sort-ii/description/
**Objetivo:** Reordenar un arreglo de enteros para que cumpla con la secuencia de onda: `nums[0] < nums[1] > nums[2] < ...`.

* **Estrategia (Toma de Decisiones):** Opté por transformar el arreglo desordenado en una estructura predecible utilizando un algoritmo de ordenamiento (**Introsort** vía `std::sort`). Una vez ordenados los datos, apliqué una técnica de **Intercalado Inverso** (Two Pointers) para distribuir la mitad pequeña en los índices pares (valles) y la mitad grande en los impares (picos), manejando así los duplicados de forma eficiente.

* **Análisis de Complejidad Temporal:**
    * **Mejor Caso:** $O(N \log N)$. Incluso si el arreglo está ordenado, el algoritmo debe verificar particiones.
    * **Caso Promedio:** $O(N \log N)$. Es el estándar para Introsort.
    * **Peor Caso:** $O(N \log N)$. Gracias a que `std::sort` usa **Introsort**, si detecta recursión profunda (riesgo de $O(N^2)$ de Quicksort), cambia automáticamente a Heapsort, garantizando siempre $N \log N$.

---

## 2. Estructuras Lineales

### Problema: [213. House Robber II] https://leetcode.com/problems/house-robber-ii/description/
**Objetivo:** Maximizar la ganancia al robar casas dispuestas en un círculo, con la restricción de no poder robar casas adyacentes.

* **Estrategia (Toma de Decisiones):**
    Al tratarse de una disposición circular, transformé el problema en dos escenarios lineales independientes (rompiendo el círculo en el primer o último elemento). Utilicé un **Vector** como estructura lineal fundamental para aplicar **Programación Dinámica**, almacenando los resultados óptimos paso a paso para evitar recálculos.

* **Análisis de Complejidad Temporal:**
    * **Mejor Caso:** $O(N)$.
    * **Caso Promedio:** $O(N)$.
    * **Peor Caso:** $O(N)$.
    * *Justificación:* El algoritmo es determinista; independientemente de los valores de dinero en las casas, se deben recorrer todas las posiciones del vector linealmente para llenar la tabla de programación dinámica.

---

## 3. Estructuras No Lineales

### Problema: [437. Path Sum III] https://leetcode.com/problems/path-sum-iii/
**Objetivo:** Contar el número de caminos en un Árbol Binario que sumen un valor objetivo (`targetSum`), donde los caminos van hacia abajo pero pueden empezar en cualquier nodo.

* **Estrategia (Toma de Decisiones):**
    Dado que es una estructura jerárquica no lineal, implementé una solución basada en **Doble Recursión (DFS)**. La función principal recorre todos los nodos para proponerlos como "inicio", y una función auxiliar profundiza en las ramas para verificar la suma. Esta estrategia cubre exhaustivamente todas las rutas posibles en el árbol.


* **Análisis de Complejidad Temporal:**
    * **Mejor Caso / Promedio (Árbol Balanceado):** $O(N \log N)$. La altura del árbol es logarítmica, por lo que las búsquedas recursivas son eficientes.
    * **Peor Caso (Árbol Desbalanceado/Lineal):** $O(N^2)$. Si el árbol es una línea recta (como una lista ligada), por cada nodo se recorren todos sus descendientes, resultando en un comportamiento cuadrático.

---


