#include "Reporte.h"
#include <iostream>
using namespace std;

// Función auxiliar para verificar si una fecha está dentro de un rango
bool fechaEnRango(const string& fecha, const string& fechaInicio, const string& fechaFin) {
    return fecha >= fechaInicio && fecha <= fechaFin;
}

// Reporte de pacientes atendidos entre rangos de fecha
void Reporte::generarReportePacientesAtendidos(const vector<Paciente>& pacientes, const string& fechaInicio, const string& fechaFin) {
    cout << "Pacientes atendidos entre " << fechaInicio << " y " << fechaFin << ":\n";
    for (const auto& paciente : pacientes) {
        if (fechaEnRango(paciente.getFechaIngreso(), fechaInicio, fechaFin)) {
            paciente.mostrarDatos();
        }
    }
}

// Reporte de citas pendientes por médico o especialidad
void Reporte::reporteCitasPendientes(const vector<Cita>& citas, const vector<Medico>& medicos, int medicoID, const string& especialidad) {
    if (medicoID != -1) {
        cout << "Citas pendientes para medico con ID " << medicoID << ":\n";
        for (const auto& cita : citas) {
            if (cita.getMedicoID() == medicoID && cita.esActiva()) {
                cita.mostrarCita();
            }
        }
    } else if (!especialidad.empty()) {
        cout << "Citas pendientes para especialidad: " << especialidad << ":\n";
        for (const auto& medico : medicos) {
            if (medico.getEspecialidad() == especialidad) {
                for (const auto& cita : citas) {
                    if (cita.getMedicoID() == medico.getID() && cita.esActiva()) {
                        cita.mostrarCita();
                    }
                }
            }
        }
    } else {
        cout << "Debe proporcionar un ID de medico o una especialidad valida.\n";
    }
}

// Reporte de pacientes con enfermedades crónicas
void Reporte::reportePacientesCronicos(const vector<Paciente>& pacientes) {
    cout << "\nPacientes con enfermedades cronicas:\n";
    for (const auto& paciente : pacientes) {
        if (paciente.esCronico()) {
            paciente.mostrarDatos();
        }
    }
}