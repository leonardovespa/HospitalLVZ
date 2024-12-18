#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <vector>
using namespace std;

class Paciente {
    private:
    string nombre;
    int ID;
    string fechaIngreso;
    vector<string> historialClinico;

    public:
    Paciente(string nombre, int ID, string fechaIngreso);
    void altaPaciente(string nombre, int ID, string fechaIngreso);
    void bajaPaciente();
    void modificarDatos(string nuevoNombre, string nuevaFechaIngreso);
    bool buscarPaciente(int id);
    void registrarHistorial(string entrada);
    void mostrarDatos();
    int getID() const;
    string getNombre() const;
    string getFechaIngreso() const;
};

#endif