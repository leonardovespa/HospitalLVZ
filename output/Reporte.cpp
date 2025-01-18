#include "Reporte.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Función para verificar si una fecha está dentro del rango seleccionado
bool fechaEnRango(const string& fecha, const string& fechaInicio, const string& fechaFin) {
    return fecha >= fechaInicio && fecha <= fechaFin;
}

// Reporte de pacientes atendidos en un rango de fechas
void Reporte::generarReportePacientesAtendidos(const vector<Paciente>& pacientes, const string& fechaInicio, const string& fechaFin) {
    cout << "Pacientes atendidos entre " << fechaInicio << " y " << fechaFin << ":\n";
    for (const auto& paciente : pacientes) {
        if (fechaEnRango(paciente.getFechaIngreso(), fechaInicio, fechaFin)) {
            paciente.mostrarDatos();
        }
    }
}

// Reporte de citas pendientes por médico o especialidad
void Reporte::reporteCitasPendientes(const vector<Cita>& citas, const vector<Medico>& medicos, const string& criterio) {
    cout << "Citas pendientes " << (isdigit(criterio[0]) ? "para el médico con ID " + criterio : "para la especialidad " + criterio) << ":\n";
    for (const auto& cita : citas) {
        if (cita.esActiva()) {
            if (isdigit(criterio[0])) { // Criterio es un ID
                if (to_string(cita.getMedicoID()) == criterio) {
                    cita.mostrarCita();
                }
            } else { // Criterio es una especialidad
                auto medicoIt = find_if(medicos.begin(), medicos.end(), [&](const Medico& m) {
                    return m.getID() == cita.getMedicoID() && m.getEspecialidad() == criterio;
                });
                if (medicoIt != medicos.end()) {
                    cita.mostrarCita();
                }
            }
        }
    }
}

// Reporte de pacientes con enfermedades crónicas
void Reporte::reportePacientesCronicos(const vector<Paciente>& pacientes) {
    cout << "Reporte de pacientes con enfermedades crónicas:\n";
    for (const auto& paciente : pacientes) {
        if (paciente.esCronico()) { // Suponiendo que Paciente tiene un método `esCronico`
            paciente.mostrarDatos();
        }
    }
}

