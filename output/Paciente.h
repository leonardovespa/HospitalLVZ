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

    // Métodos para modificar atributos
    void modificar(int atributo, const string& nuevoValor); // Sobrecarga para string
    void modificar(int atributo, int nuevoValor);           // Sobrecarga para int

    // Métodos individuales de modificación
    void modificarNombre(const string& nuevoNombre);
    void modificarFechaIngreso(const string& nuevaFechaIngreso);
    void modificarID(int nuevoID);
    void modificarCronico(bool esCronico);

    // Getters
    int getID() const;
    string getNombre() const;
    string getFechaIngreso() const;
    bool esCronico() const;

    // Mostrar datos
    void mostrarDatos() const;
};

#endif
