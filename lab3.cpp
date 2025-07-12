#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Asignatura {
    char codigo[8];  // 7 caracteres + 1 para el terminador nulo
    char nombre[21]; // 20 caracteres + 1 para el terminador nulo
};

int main() {
    // Ejemplo de asignaturas, puedes agregar o modificar según necesites
    Asignatura asignaturas[] = {
        {"INF1001", "Programacion I"},
        {"INF1002", "Matematica I"},
        {"INF1003", "Algoritmos"},
        {"INF1004", "Fisica Basica"},
        {"INF1005", "Estructuras"},
    };
    int cantidad = sizeof(asignaturas) / sizeof(asignaturas[0]);

    ofstream archivo("asignaturas.txt");
    if (!archivo) {
        cerr << "No se pudo crear el archivo." << endl;
        return 1;
    }

    archivo << left;
    for (int i = 0; i < cantidad; ++i) {
        archivo 
            << setw(7) << asignaturas[i].codigo << " " 
            << setw(20) << asignaturas[i].nombre << endl;
    }

    archivo.close();
    cout << "Archivo 'asignaturas.txt' generado correctamente." << endl;
    return 0;
}
