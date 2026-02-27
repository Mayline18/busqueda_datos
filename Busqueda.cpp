#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Cargando datos...\n";
    ifstream file("datos.txt");
    if (!file.is_open()) {
        cout << "No se pudo abrir datos.txt\n";
        return 1;
    }

    vector<int> lista;
    lista.reserve(10000000);

    int num;
    while (file >> num) lista.push_back(num);
    file.close();

    cout << "Datos cargados: " << lista.size() << "\n";
    cout << "Construyendo tabla hash...\n";

    unordered_set<int> tabla_hash;
    tabla_hash.reserve(lista.size());
    for (int v : lista) tabla_hash.insert(v);

    cout << "Estructuras listas\n";

    // ?? Aumentamos búsquedas para medir bien (100,000)
    const int BUSQUEDAS = 1000;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-50000000, 50000000);

    vector<int> valores;
    valores.reserve(BUSQUEDAS);
    for (int i = 0; i < BUSQUEDAS; i++) valores.push_back(dist(gen));

    // Volatile para evitar optimización agresiva
    volatile long long contador_lista = 0;
    volatile long long contador_hash = 0;

    // -------- Medir lista (O(n)) --------
    auto inicio = high_resolution_clock::now();

    for (int v : valores) {
        for (int x : lista) {
            if (x == v) {
                contador_lista++;
                break;
            }
        }
    }

    auto fin = high_resolution_clock::now();
    auto total_lista_us = duration_cast<microseconds>(fin - inicio).count();
    double prom_lista_us = (double)total_lista_us / BUSQUEDAS;

    // -------- Medir hash (O(1)) --------
    inicio = high_resolution_clock::now();

    for (int v : valores) {
        if (tabla_hash.find(v) != tabla_hash.end()) {
            contador_hash++;
        }
    }

    fin = high_resolution_clock::now();
    auto total_hash_us = duration_cast<microseconds>(fin - inicio).count();
    double prom_hash_us = (double)total_hash_us / BUSQUEDAS;

    cout << "\nRESULTADOS (promedio por busqueda)\n";
    cout << "Lista: " << prom_lista_us << " us\n";
    cout << "Tabla Hash: " << prom_hash_us << " us\n";

    // Para evitar que el compilador quite el trabajo
    cout << "\nConteos (solo para validacion):\n";
    cout << "Encontrados en lista: " << contador_lista << "\n";
    cout << "Encontrados en hash : " << contador_hash << "\n";

    return 0;
}
