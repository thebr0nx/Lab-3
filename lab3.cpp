#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

struct Asignatura {
    char codigo_asignatura[8];   // 7 chars + null terminator
    char nombre_asignatura[21];  // 20 chars + null terminator
};

// Función para rellenar los campos char[] asegurando longitud y terminador nulo
void setStringField(char* dest, const std::string& src, size_t maxLen) {
    std::strncpy(dest, src.c_str(), maxLen);
    dest[maxLen] = '\0'; // asegurar terminador nulo
}

int main() {
    // Lista de ejemplo de asignaturas de un departamento (puedes modificar o ampliar)
    std::vector<Asignatura> asignaturas = {
        { "", "" },
        { "", "" },
        { "", "" }
    };

    // Ejemplo de llenado de asignaturas (puedes modificar estos datos por los de tu departamento)
    setStringField(asignaturas[0].codigo_asignatura, "INF1001", 7);
    setStringField(asignaturas[0].nombre_asignatura, "Programacion I", 20);

    setStringField(asignaturas[1].codigo_asignatura, "INF1002", 7);
    setStringField(asignaturas[1].nombre_asignatura, "Estructuras de Datos", 20);

    setStringField(asignaturas[2].codigo_asignatura, "INF1003", 7);
    setStringField(asignaturas[2].nombre_asignatura, "Bases de Datos", 20);

    std::ofstream archivo("asignaturas.txt");
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
        return 1;
    }

    // Escribir encabezados (opcional)
    archivo << std::left << std::setw(8) << "CODIGO" << std::setw(21) << "NOMBRE" << std::endl;
    archivo << std::string(28, '-') << std::endl;

    // Escribir cada asignatura al archivo, formato fijo para cada campo
    for (const auto& asignatura : asignaturas) {
        archivo << std::left
                << std::setw(8) << asignatura.codigo_asignatura
                << std::setw(21) << asignatura.nombre_asignatura
                << std::endl;
    }

    archivo.close();
    std::cout << "Archivo 'asignaturas.txt' creado correctamente." << std::endl;
    return 0;
}
