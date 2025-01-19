#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
using namespace std;

class Paciente {
private:
    string nombre;
    int ID;
    string fechaIngreso;
    bool cronico;

public:
    // Constructor
    Paciente(string nombre, int ID, string fechaIngreso, bool cronico);

    // Métodos de modificación
    void modificarDatos(const string& nuevoNombre, const string& nuevaFechaIngreso, bool esCronico);
    void modificarNombre(const string& nuevoNombre);
    void modificarFechaIngreso(const string& nuevaFechaIngreso);
    void modificarCronico(bool esCronico);
    void modificarID(int nuevoID); // Nuevo método para modificar el ID

    // Métodos de visualización
    void mostrarDatos() const;

    // Getters
    int getID() const;
    string getNombre() const;
    string getFechaIngreso() const;
    bool esCronico() const;
};

#endif
