// Clase Paciente

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Paciente {
	private:
	string nombre;
	int ID;
	string fechaIngreso,
	vector<string> historialClínico;
	
	public:
	// Constructor
	Paciente(string nombre, int ID, string fechaIngreso) {
		this->nombre = nombre;
		this->ID = ID;
		this->fechaIngreso = fechaIngreso;
	}
	
	// Alta de paciente
	void altaPaciente(string nombre, int ID, string fechaIngreso) {
		this->nombre = nombre;
		this->ID = ID;
		this->fechaIngreso = fechaIngreso;
	}
	
	// Baja de Paciente
	void bajaPaciente() {
		cout << "Paciente " << nombre << " dado de baja con éxito." << endl;
	}
	
	// Modificación de datos personales
	void modificarDatos(string nuevoNombre, string nuevaFechaIngreso) {
		nombre = nuevoNombre;
		fechaIngreso = nuevaFechaIngreso;
		cout << "Datos del Paciente modificado con éxito." << nombre << endl;
	}
	
	// Buscar Paciente
	bool buscarPaciente(int id) {
		return this->ID == id;
	}
	
	// Registro historial clínico
	void registrarHistorial(string entrada) {
		historialClinico.push_back(entrada);
	}
	
	// Mostrar datos del paciente
	void mostrarDatos() {
		cout << "ID: " << ID << ", Nombre: " << nombre << ", Fecha de ingreso: " << fechaIngreso << endl;
	}
};