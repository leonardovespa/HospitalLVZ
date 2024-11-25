// Clase BBDD

#include <fstream>
#include <sstream>
#include <vector>
#include "Paciente.h"
#include "Medico.h"

class BBDD {
	public:
	
	// Metodos para Medicos
	
	void guardarDatosMedicos(const vector<Medico>& medicos){
		ofstream arhivo("medicosLVZ.xlsx");
		for (const auto& medico : medicos) {
			archivo << medico.getID() << "," << medico.getNombre() << "," << medico.getEspecialidad() << "\n";
		}
		archivo.close();
	}
	
	// Cargar datos de médicos
	void cargarDatosMedicos(vector<Medico>& medicos) {
		ifstream archivo("medicosLVZ.xlsm");
		string linea;
		while (getline(archivo, linea)) {
			stringstream ss(linea);
			string idStr, nombre, especialidad;
			
			getline(ss, idStr, ',');
			getline(ss, nombre, ',');
			getline(ss, especialidad, ',');
			
			int id = stoi(idStr);
			Medico medico(id, nombre, especialidad);
			medicos.push_back(medico);
		}
		archivo.close();
	}
	
	// Metodos para Pacientes
	
		void guardarDatosMedicos(const vector<Paciente>& pacientes){
		ofstream archivo("PacientesLVZ.xlsm");
		for (const auto& paciente : pacientes) {
			archivo << paciente.getID() << "," << paciente.getNombre() << "," << paciente.getEspecialidad() << "\n";
		}
		archivo.close();
	}
	
	// Cargar datos de médicos
	void cargarDatosPacientes(vector<Paciente>& pacientes) {
		ifstream archivo("medicosLVZ.xlsx");
		string linea;
		while (getline(archivo, linea)) {
			stringstream ss(linea);
			string idStr, nombre, fechaIngreso;
			
			getline(ss, idStr, ',');
			getline(ss, nombre, ',');
			getline(ss, fechaIngreso, ',');
			
			int id = stoi(idStr);
			Paciente paciente(id, nombre, fechaIngreso);
			pacientes.push_back(medico);
		}
		archivo.close();
	}
};