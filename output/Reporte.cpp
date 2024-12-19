#include "Reporte.h"
#include <iostream>
using namespace std;

//Función verificar si una fecha está dentro del rango seleccionado
bool fechaEnRango(const string fecha, const string fechaInicio, const string fechaFin) {
	return fecha >= fechaInicio && fecha <= fechaFin;
}

//Reporte de pacientes atendidos entre rangos de fecha
void Reporte:: generarReportePacientesAtendidos(const vector<Paciente>& pacientes, const string& fechaInicio, const string& fechaFin) {
	cout << "Pacientes atendidos entre " << fechaInicio << " y " << fechaFin << ":\n";
	for (const auto& paciente : pacientes) {
		if (fechaEnRango(paciente.getFechaIngreso(), fechaInicio, fechaFin)) {
			paciente.mostrarDatos();
		}
	}
}

// Reporte de citas pendientes por médico
void Reporte::reporteCitasPendientes(const vector<Cita>& citas, int medicoID) {
	cout << "Citas pendientes para médico con ID " << ":\n";
	for (const auto& cita : citas) {
		if (cita.getMedicoID() == medicoID && cita.esActiva()) {
			cita.mostrarCita();
		}
	}
}
