#ifndef BBDD_H
#define BBDD_H
#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

class BBDD {
    public:
    //Métodos para paciente
    void guardarDatosPacientes(const vector<Paciente>& pacientes);
    void cargarDatosPacientes(vector<Paciente>& pacientes);

    //Métodos para Médico
    void guardarDatosMedicos(const vector<Medico>& medicos);
    void cargarDatosMedicos(vector<Medico>& medicos);

    // Métodos para Cita
    void guardarDatosCitas(const vector<Cita>& citas);
    void cargarDatosCitas(vector<Cita>& citas);

    //Método para Backup
    void realizarBackup() const;
    bool verificarYRealizarBackupAutomatico();

};

#endif