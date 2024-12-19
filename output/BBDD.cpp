#include "BBDD.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

//Guardar datos Médicos
void BBDD::guardarDatosMedicos(cons vector<Medico>& medicos) {
	ofstream archivo("medicosLVZ.csv");
	if (!archivo.is_open()) {
		cerr << "Error al abrir el archivo para guardar Médicos." << endl;
		return;
	}
	for (const auto& medico : medicos) {
		archivo << medico.getID() << "," << medico.getNombre() << "," << medico.getEspecialidad() << "\n";
	}
	archivo.close();
}

//Cargar datos de Médicos
void BBDD::cargarDatosMedicos(const vector<Medico>& medicos) {
	ifstream archivo(medicosLVZ.csv);
	if (!archivo.is_open()) {
		cerr << "Error al abrir el archivo para cargar médicos." << endl;
		return;
	}
	string linea;
	while (getline(archivo, linea)) {
		stringstream ss(linea);
		string idStr, nombre, especialidad;

		getline(ss, idStr, ',');
		getline(ss, nombre, ',');
		getline(ss, especialidad, ',');

		int id = stoi(idStr);
		medicos.emplace_back(nombre, id, especialidad);
	}
	archivo.close();
}

// Guardar datos de pacientes
void BBDD::guardarDatosPacientes(cns vector<Paciente>¬ pacientes) {
	ofstream archivo("pacientesLVZ.csv");
	if (!archivo.is_open()) {
		cerr << "Error al abrir el archivo para guardar pacientes." << endl;
		return;
	}
	for (const auto& paciente : pacientes) {
		archivo << paciente.getID() << "," << paciente.getNombre() << "," << paciente.getFechaIngreso() << "\n";
	}
	archivo.close();
}

// Cargar datos de pacientes
void BBDD::cargarDatosPacientes(vector<Paciente>& pacientes) {
	ifstream archivo("pacientesLVZ.csv");
	if (!archivo.is_open()) {
		cerr << "Error al abrir el archivo para cargar pacientes." << endl;
		return;
	}

	string linea;
	while (getline(archivo, linea)) {
		stringstream ss(linea);
		string idStr, nombre, fechaIngreso;

		getline(ss, idStr, ',');
		getline(ss, nombre, ',');
		getline(ss, fechaIngreso, ',');

		int id = stoi(idStr);
		pacientes.emplace_back(nombre, id, fechaIngreso);
	}
	archivo.close
}