#ifndef REPORTE_H
#define REPORTE_H

#include "Paciente.h"
#include "Cita.h"
#include "Medico.h"
#include <vector>
#include <string>
using namespace std;

class Reporte {
public:
    // Reporte de pacientes atendidos en un rango de fechas
    void generarReportePacientesAtendidos(const vector<Paciente>& pacientes, const string& fechaInicio, const string& fechaFin);

    // Reporte de citas pendientes por médico o especialidad
    void reporteCitasPendientes(const vector<Cita>& citas, const vector<Medico>& medicos, const string& criterio);

    // Reporte de pacientes con enfermedades crónicas
    void reportePacientesCronicos(const vector<Paciente>& pacientes);
};

#endif
