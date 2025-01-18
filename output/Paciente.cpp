// Clase Paciente
#include "Paciente.h"
#include <iostream>
using namespace std;

// Constructor actualizado
Paciente::Paciente(string nombre, int ID, string fechaIngreso, bool cronico)
    : nombre(nombre), ID(ID), fechaIngreso(fechaIngreso), cronico(cronico) {}

// Modificar datos del paciente
void Paciente::modificarDatos(string nuevoNombre, string nuevaFechaIngreso) {
    nombre = nuevoNombre;
    fechaIngreso = nuevaFechaIngreso;
}

// Mostrar datos del paciente
void Paciente::mostrarDatos() const {
    cout << "ID: " << ID << ", Nombre: " << nombre << ", Fecha de ingreso: " << fechaIngreso;
    if (cronico) {
        cout << " (Enfermedad Crónica)";
    }
    cout << endl;
}

// Verificar si el paciente es crónico
bool Paciente::esCronico() const {
    return cronico;
}

// Getters
int Paciente::getID() const {
    return ID;
}

string Paciente::getNombre() const {
    return nombre;
}

string Paciente::getFechaIngreso() const {
    return fechaIngreso;
}
