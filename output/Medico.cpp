// Clase Medico

#include "Medico.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// Constructor
Medico::Medico(string nombre, int ID, string especialidad)
    : nombre(nombre), ID(ID), especialidad(especialidad), disponibilidad(true) {}

// Métodos de modificación
void Medico::modificar(int atributo, const string& nuevoValor) {
    switch (atributo) {
        case 1: // Modificar Nombre
            nombre = nuevoValor;
            break;
        case 2: // Modificar Especialidad
            especialidad = nuevoValor;
            break;
        default:
            throw invalid_argument("Atributo no valido para modificar.");
    }
}

void Medico::modificar(int atributo, int nuevoValor) {
    if (atributo == 3) { // Modificar ID
        ID = nuevoValor;
    } else {
        throw invalid_argument("Atributo no valido para modificar.");
    }
}

void Medico::modificarNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
}

void Medico::modificarEspecialidad(const string& nuevaEspecialidad) {
    especialidad = nuevaEspecialidad;
}

void Medico::modificarID(int nuevoID) {
    ID = nuevoID;
}

void Medico::cambiarDisponibilidad(bool estado) {
    disponibilidad = estado;
}

// Getters
int Medico::getID() const {
    return ID;
}

string Medico::getNombre() const {
    return nombre;
}

string Medico::getEspecialidad() const {
    return especialidad;
}

bool Medico::isDisponible() const {
    return disponibilidad;
}

// Mostrar datos
void Medico::mostrarDatos() const {
    cout << "ID: " << ID << ", Nombre: " << nombre << ", Especialidad: " << especialidad
         << ", Disponible: " << (disponibilidad ? "Si" : "No") << endl;
}
