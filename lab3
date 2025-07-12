#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

// Estructura para almacenar los datos de una asignatura
struct Asignatura {
    char codigo_asignatura[8];  // 7 caracteres + null terminator
    char nombre_asignatura[21]; // 20 caracteres + null terminator
};

// Función para rellenar los campos con espacios y asegurarse del tamaño fijo
void copiar_campo(char* destino, const std::string& origen, size_t tam) {
    size_t i = 0;
    for (; i < origen.size() && i < tam; ++i) {
        destino[i] = origen[i];
    }
    for (; i < tam; ++i) {
        destino[i] = ' ';
    }
    destino[tam] = '\0';
}

int main() {
    // Vector de asignaturas de ejemplo (puedes modificar o agregar más)
    std::vector<Asignatura> asignaturas = {
        {"INF1001", "Introduccion a la Prog."},
        {"INF1002", "Estructuras de Datos"},
        {"INF1003", "Bases de Datos"},
        {"INF1004", "Sistemas Operativos"},
        {"INF1005", "Redes de Computadoras"}
    };

    // Ajustar los campos a tamaño fijo y rellenar con espacios
    for (auto& asig : asignaturas) {
        std::string cod(asig.codigo_asignatura);
        std::string nom(asig.nombre_asignatura);
        copiar_campo(asig.codigo_asignatura, cod, 7);
        copiar_campo(asig.nombre_asignatura, nom, 20);
    }

    // Abrir archivo para escritura
    std::ofstream archivo("asignaturas.txt");
    if (!archivo) {
        std::cerr << "No se pudo crear el archivo asignaturas.txt\n";
        return 1;
    }

    // Escribir encabezado
    archivo << std::left << std::setw(8) << "Codigo" 
            << std::setw(21) << "Nombre" << "\n";
    archivo << std::string(28, '=') << "\n";

    // Escribir los datos de las asignaturas
    for (const auto& asig : asignaturas) {
        archivo << std::left << std::setw(8) << asig.codigo_asignatura
                << std::setw(21) << asig.nombre_asignatura << "\n";
    }

    archivo.close();
    std::cout << "Archivo asignaturas.txt creado exitosamente.\n";
    return 0;
}
