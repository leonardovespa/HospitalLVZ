#ifndef MEDICO_H
#define MEDICO_H

#include <string>
using namespace std;

class Medico {
private:
    string nombre;
    int ID;
    string especialidad;
    bool disponible;

public:
    Medico(string nombre, int ID, string especialidad);

    // Métodos de modificación
    void modificarNombre(const string& nuevoNombre);
    void modificarEspecialidad(const string& nuevaEspecialidad);
    void modificarID(int nuevoID);
    void cambiarDisponibilidad(bool disponibilidad);

    // Mostrar datos
    void mostrarDatos() const;

    // Getters
    string getNombre() const;
    int getID() const;
    string getEspecialidad() const;
    bool isDisponible() const;
};

#endif
