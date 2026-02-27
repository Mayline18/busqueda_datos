#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main() {
    const int N = 10000000;
    const int MIN = -50000000;
    const int MAX =  50000000;

    ofstream file("datos.txt");
    if (!file.is_open()) {
        cout << "Error al crear el archivo\n";
        return 1;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(MIN, MAX);

    for (int i = 0; i < N; i++) {
        file << dist(gen) << "\n";
    }

    file.close();
    cout << "Archivo datos.txt generado correctamente\n";
    return 0;
}
