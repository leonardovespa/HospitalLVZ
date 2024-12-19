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
    Medico(string nombre, int ID, string especialidad);
    void altaMedico(string nombre, int ID, string especialidad);
    void bajaMedico();
    void asignarEspecialidad(string especialidadNueva);
    void cambiarDisponibilidad(bool estado);
    void mostrarDatos();
    int getID() const;
    string getNombre() const;
    string getEspecialidad() const;
    bool isDisponible() const;
};

#endif