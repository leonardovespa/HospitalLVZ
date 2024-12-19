// Clase Paciente

#include "Paciente.h"
#include <iostream>
using namespace std;

Paciente::Paciente(string nombre, int ID, string fechaIngreso) {
	this->nombre = nombre;
	this->ID = ID;
	this->fechaIngreso = fechaIngreso;
}

void Paciente::altaPaciente(string nombre, int ID, string fechaIngreso) {
	this->nombre = nombre;
	this->ID = ID;
	this->fechaIngreso = fechaIngreso;
	cout << "Paciente " << nombre << " dado de alta con éxito." << endl;
}

void Paciente::bajaPaciente() {
	cout << "Paciente " << nombre << " dado de baja con éxito." << endl;
}

void Paciente::modificarDatos(string nuevoNombre, string nuevaFechaIngreso) {

}

bool Paciente::buscarPaciente(int id) {
	return this->ID == id;
}

void Paciente::registrarHistorial(string entrada) {
	historialClinico.push_back(entrada);
}

void Paciente::mostrarDatos() const {
	cout << "ID: " << ID << ", Nombre: " << nombre << ", Fecha de ingreso: " << fechaIngreso << endl;
}

int Paciente::getID() const {
	return ID;
}

string Paciente::getNombre() const {
	return nombre;
}

string Paciente::getFechaIngreso() const {
	return fechaIngreso;
}