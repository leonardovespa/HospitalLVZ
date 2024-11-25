// Clase Médico


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Medico {
	private:
	string nombre;
	int ID;
	string especialidad;
	bool disponibilidad;
	
	public:
	Medico(string nombre, int ID, string especialidad) {
		this->nombre = nombre;
		this->ID = ID;
		this->especialidad = especialidad;
		this->disponibilidad = true;
		
	}
	
	// Alta de Medico
	void altaMedico(string nombre, int ID, string especialidad) {
		this->nombre = nombre;
		this->ID = ID;
		this->especialidad = especialidad;
		this->disponibilidad = true;
		
	}
	
	// Baja de médico
	void bajaMedico() {
		cout << "Médico " << nombre << " dado de baja con éxito." << endl;
	}
	
	// Asignación de especialidad
	void asignarEspecialidad(string especialidadNueva) {
		especialidad = especialidadNueva;
		cout << "Especialidad asignada a " << nombre << ": " << especialidad << endl;
	}
	
	// Verificar disponibilidad
	bool mostrarDatos() {
		return disponibilidad;
	}
	
	// Mostrar datos del médico
	void mostrarDatos() {
		cout << "ID: " << ID << ", Nombre: " << nombre << ", Especialidad: " << especialidad << ", Disponible: " << (disponibilidad ? "Sí" : "No") << endl;
	}
};