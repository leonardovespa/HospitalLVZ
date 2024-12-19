#ifndef REPORTE_H
#define REPORTE_H

#include "Paciente.h"
#include "Cita.h"
#include <vector>
#include <string>
using namespace std;

class Reporte {
    // Reporte de pacientes atendidos en rangos de fechas
    void generarReportePacientesAtendidos(const vector<Paciente>& pacientes, const string& fechaInicio, const string& fechafin);

    // Reporte de citas pendientes por médico
    void reporteCitasPendientes(const vector<Cita>& citas, int medicoID);

};

#endif