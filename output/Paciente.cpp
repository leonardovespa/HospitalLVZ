// Clase Paciente
#include "Paciente.h"
#include <iostream>
using namespace std;

// Constructor actualizado
Paciente::Paciente(string nombre, int ID, string fechaIngreso, bool cronico)
    : nombre(nombre), ID(ID), fechaIngreso(fechaIngreso), cronico(cronico) {}

// Modificar datos del paciente (nombre y fecha de ingreso)
void Paciente::modificarDatos(string nuevoNombre, string nuevaFechaIngreso) {
    nombre = nuevoNombre;
    fechaIngreso = nuevaFechaIngreso;
}

// Modificar solo el nombre
void Paciente::modificarNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
}

// Modificar solo la fecha de ingreso
void Paciente::modificarFechaIngreso(const string& nuevaFechaIngreso) {
    fechaIngreso = nuevaFechaIngreso;
}

// Modificar si el paciente tiene una enfermedad crónica
void Paciente::modificarCronico(bool nuevoEstado) {
    cronico = nuevoEstado;
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
