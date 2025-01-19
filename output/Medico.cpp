// Clase Médico
#include "Medico.h"
#include <iostream>
using namespace std;

// Constructor
Medico::Medico(string nombre, int ID, string especialidad)
    : nombre(nombre), ID(ID), especialidad(especialidad), disponible(true) {}

// Métodos de modificación
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
    disponible = estado;
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
    return disponible;
}

// Mostrar datos
void Medico::mostrarDatos() const {
    cout << "ID: " << ID << ", Nombre: " << nombre
         << ", Especialidad: " << especialidad
         << ", Disponible: " << (disponible ? "Sí" : "No") << endl;
}

