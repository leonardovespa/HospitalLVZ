//Clase Paciente

#include "Paciente.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// Constructor
Paciente::Paciente(string nombre, int ID, string fechaIngreso, bool cronico)
    : nombre(nombre), ID(ID), fechaIngreso(fechaIngreso), cronico(cronico) {}

// Métodos de modificación
void Paciente::modificar(int atributo, const string& nuevoValor) {
    switch (atributo) {
        case 1: // Modificar Nombre
            nombre = nuevoValor;
            break;
        case 2: // Modificar Fecha de Ingreso
            fechaIngreso = nuevoValor;
            break;
        default:
            throw invalid_argument("Atributo no valido para modificar.");
    }
}

void Paciente::modificar(int atributo, int nuevoValor) {
    if (atributo == 3) { // Modificar ID
        ID = nuevoValor;
    } else {
        throw invalid_argument("Atributo no valido para modificar.");
    }
}

void Paciente::modificarNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
}

void Paciente::modificarFechaIngreso(const string& nuevaFechaIngreso) {
    fechaIngreso = nuevaFechaIngreso;
}

void Paciente::modificarID(int nuevoID) {
    ID = nuevoID;
}

void Paciente::modificarCronico(bool esCronico) {
    cronico = esCronico;
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

bool Paciente::esCronico() const {
    return cronico;
}

// Mostrar datos
void Paciente::mostrarDatos() const {
    cout << "ID: " << ID << ", Nombre: " << nombre << ", Fecha de ingreso: " << fechaIngreso;
    if (cronico) {
        cout << " (Enfermedad Cronica)";
    }
    cout << endl;
}
