#include "Cita.h"
#include <iostream>
using namespace std;

Cita::Cita(int citaID, int pacienteID, int medicoID, string fecha, string urgencia) {
	this->citaID = citaID;
	this->pacienteID = pacienteID;
	this->medicoID = medicoID;
	this->fecha = fecha;
	this->urgencia = urgencia;
	this->estado = "activa";
}

void Cita::modificarCita(string nuevaFecha, string nuevaUrgencia) {
	fecha = nuevaFecha;
	urgencia = nuevaUrgencia;
	cout << "Cita modificada para: " << fecha << " con urgencia " << urgencia << endl;
}

void Cita::cancelarCita() {
	estado = "cancelada";
}

void Cita::mostrarCita() {
	cout << "Cita ID: " << CitaID << ", Fecha: " << fecha << ", urgencia: " << urgencia << ", Estado: " << endl;
}

bool Cita::esActiva() const {
	return estado == "activa";
}

int Cita::getCitaID() const {
	return citaID;
}

int Cita::getPacienteID() const {
	return pacienteID;
}

int Cita::getMedicoID() const {
	return medicoID;
}

string Cita::getEstado() const {
	return estado;
}