//Clase Paciente

#include "Paciente.h"
#include <iostream>
using namespace std;

// Constructor actualizado
Paciente::Paciente(string nombre, int ID, string fechaIngreso, bool cronico)
    : nombre(nombre), ID(ID), fechaIngreso(fechaIngreso), cronico(cronico) {}

// Modificar datos completos del paciente
void Paciente::modificarDatos(const string& nuevoNombre, const string& nuevaFechaIngreso, bool esCronico) {
    nombre = nuevoNombre;
    fechaIngreso = nuevaFechaIngreso;
    cronico = esCronico;
}

// Modificar solo el nombre del paciente
void Paciente::modificarNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
}

// Modificar solo la fecha de ingreso del paciente
void Paciente::modificarFechaIngreso(const string& nuevaFechaIngreso) {
    fechaIngreso = nuevaFechaIngreso;
}

// Modificar el estado crónico del paciente
void Paciente::modificarCronico(bool esCronico) {
    cronico = esCronico;
}

// Mostrar datos del paciente
void Paciente::mostrarDatos() const {
    cout << "ID: " << ID << ", Nombre: " << nombre << ", Fecha de ingreso: " << fechaIngreso;
    if (cronico) {
        cout << " (Enfermedad Crónica)";
    }
    cout << endl;
}

// Obtener el ID del paciente
int Paciente::getID() const {
    return ID;
}

// Obtener el nombre del paciente
string Paciente::getNombre() const {
    return nombre;
}

// Obtener la fecha de ingreso del paciente
string Paciente::getFechaIngreso() const {
    return fechaIngreso;
}

// Verificar si el paciente tiene una enfermedad crónica
bool Paciente::esCronico() const {
    return cronico;
}
