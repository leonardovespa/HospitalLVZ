#include "Cita.h"
#include <iostream>
using namespace std;

Cita::Cita(int citaID, int pacienteID, int medicoID, const string& fecha, const string& especialidad, const string& urgencia) {
	this->citaID = citaID;
	this->pacienteID = pacienteID;
	this->medicoID = medicoID;
	this->fecha = fecha;
	this->especialidad = especialidad;
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

void Cita::mostrarCita() const {
	cout << "Cita ID: " << citaID
         << ", Paciente ID: " << pacienteID
		 << ", Medico ID: " << medicoID
		 << ", Fecha: " << fecha
		 << ", especialidad: " << especialidad
		 << ", Urgencia: " << urgencia
		 << ", Estado: " << estado << endl;	
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

string Cita::getFecha() const {
	return fecha;
}

string Cita::getEspecialidad() const {
	return especialidad;
}

string Cita::getUrgencia() const {
	return urgencia;
}

string Cita::getEstado() const {
	return estado;
}