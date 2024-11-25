// Clase Reporte


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Reporte {
	public: 
	// Reporte de pacientes atendidos entre rango de fechas
	void generarReportePacientesAtendidos(vector<Paciente>& pacientes, string fechaIncio, string fechaFin) {
		cout << "Pacientes atendidos entre " << fechaIncio << " y " << fechaFin << ":\n";
		for (auto &paciente : pacientes) {
			paciente.mostrarDatos();
		}
	}
	
	// Reportes de citas pendientes por médico
	void reporteCitasPendientes(vector<Cita>& citas, int medicoID) {
		cout << "Citas pendientes para el médico con ID " << medicoID << ":\n";
		for (auto &cita : citas) {
			cita.mostrarCita();
		}
	}
};