#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
using namespace std;

class Paciente {
private:
    string nombre;
    int ID;
    string fechaIngreso;
    bool cronico; // Indica si el paciente tiene una enfermedad crónica

public:
    Paciente(string nombre, int ID, string fechaIngreso, bool cronico = false);

    void modificarDatos(string nuevoNombre, string nuevaFechaIngreso);
    void mostrarDatos() const;
    bool esCronico() const; // Método para verificar si es crónico

    // Getters
    int getID() const;
    string getNombre() const;
    string getFechaIngreso() const;
};

#endif
