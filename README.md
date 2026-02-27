# Búsqueda eficiente sobre grandes volúmenes de datos

Este proyecto implementa y compara el rendimiento de distintas estructuras de datos para realizar búsquedas sobre un conjunto grande de información.
Se generaron 10,000,000 de números aleatorios dentro del rango:

-50,000,000 a 50,000,000

Los datos fueron almacenados en un archivo de texto y posteriormente cargados en memoria para construir distintas estructuras de datos y medir su eficiencia de búsqueda.

Tecnologías usadas

* Lenguaje: C++
* Compilador: g++ (MSYS2 MinGW64)
* Librerías:
  * `<vector>`
  * `<unordered_set>`
  * `<chrono>`
  * `<random>`
  * `<fstream>`

Metodología del experimento

1. Se generaron 10,000,000 números aleatorios.
2. Se almacenaron en `datos.txt`.
3. Se cargaron en memoria.
4. Se construyeron dos estructuras:

   * Lista (vector)
   * Tabla hash (`unordered_set`)
5. Se realizaron 1000 búsquedas aleatorias
6. Se midió el tiempo promedio de búsqueda.

Resultados

| Estructura | Tiempo promedio | Memoria    | Complejidad |
| ---------- | --------------- | ---------- | ----------- |
| Lista      | 4.706 ms        | Baja/Media | O(n)        |
| Tabla Hash | 0.000094 ms     | Alta       | O(1)        |

Análisis

Lista

La lista requiere recorrer elemento por elemento hasta encontrar el valor buscado o llegar al final.
Esto implica una complejidad O(n), por lo que el tiempo crece proporcionalmente al tamaño del conjunto.

Tabla Hash

La tabla hash permite acceder directamente a la posición donde debería estar el valor, gracias a una función hash.
Esto produce una complejidad promedio O(1), lo que la hace extremadamente eficiente incluso con grandes volúmenes de datos.

Conclusión

La estructura más eficiente fue la tabla hash, superando ampliamente a la lista.

Resultados experimentales:

* Lista: 4705.81 µs
* Hash: 0.094 µs

La tabla hash fue aproximadamente:

50,000 veces más rápida

Esto demuestra que, para grandes volúmenes de datos, elegir una estructura adecuada es fundamental para el rendimiento del sistema.

Cómo ejecutar

Compilar

g++ Busqueda.cpp -O2 -o buscar

Ejecutar

./buscar

Nota
El archivo datos.txt no se incluye debido a su tamaño (10,000,000 registros).  
Para generarlo, ejecute:

g++ generate_data.cpp -o generar
./generar
