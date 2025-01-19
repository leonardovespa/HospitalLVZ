#ifndef MEDICO_H
#define MEDICO_H

#include <string>
using namespace std;

class Medico {
private:
    string nombre;
    int ID;
    string especialidad;
    bool disponibilidad;

public:
    // Constructor
    Medico(string nombre, int ID, string especialidad);

    // Métodos para modificar atributos
    void modificar(int atributo, const string& nuevoValor); // Sobrecarga para string
    void modificar(int atributo, int nuevoValor);           // Sobrecarga para int

    // Métodos individuales de modificación
    void modificarNombre(const string& nuevoNombre);
    void modificarEspecialidad(const string& nuevaEspecialidad);
    void modificarID(int nuevoID);
    void cambiarDisponibilidad(bool estado);

    // Getters
    int getID() const;
    string getNombre() const;
    string getEspecialidad() const;
    bool isDisponible() const;

    // Mostrar datos
    void mostrarDatos() const;
};

#endif // MEDICO_H

