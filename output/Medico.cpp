// Clase Médico

#include "Medico.h"
#include <iostream>
using namespace std;

// Constructor

Medico::Medico(string nombre, int ID, string especialidad) {
	this->nombre = nombre;
	this->ID = ID;
	this->especialidad = especialidad;
	this->disponibilidad = true;
}

void Medico::altaMedico(string nombre, int ID, string especialidad) {
	this->nombre = nombre;
	this->ID = ID;
	this->especialidad = especialidad;
	this->disponibilidad = true;
}

void Medico::bajaMedico() {
	cout << "medico " << nombre << " dado de baja con exito." << endl;
}

void Medico::asignarEspecialidad(string especialidadNueva) {
	especialidad = especialidadNueva;
}

void Medico::cambiarDisponibilidad(bool estado) {
	disponibilidad = estado;
    cout << "Disponibilidad del medico actualizada. Estado actual: " << (disponibilidad ? "Disponible" : "No disponible") << endl;
}

void Medico::setDisponibilidad(bool estado) {
	disponibilidad = estado;
}

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

void Medico::mostrarDatos() const {
	cout << "ID: " << ID << ", Nombre: " << nombre << ", Especialidad: " << especialidad << ", Disponible: " << (disponibilidad ? "Si" : "No") << endl;
}
