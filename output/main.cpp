#include <iostream>
#include "Paciente.cpp" // Incluye la definición de la clase Paciente

using namespace std;

int main() {
    // Crear un objeto de la clase Paciente
    Paciente paciente("Leonardo Vespa", 45, "2024-11-25");

    // Mostrar los datos del paciente
    paciente.mostrarDatos();

    // Modificar datos del paciente
    paciente.modificarDatos("Luis Gómez", "2024-12-01");

    // Mostrar los datos modificados
    paciente.mostrarDatos();

    return 0; // Indicar que el programa finalizó correctamente
};
