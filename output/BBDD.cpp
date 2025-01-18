#include "BBDD.h"
#include "Cita.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// Guardar datos de Médicos
void BBDD::guardarDatosMedicos(const vector<Medico>& medicos) {
    ofstream archivo("medicosLVZ.csv");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para guardar Medicos." << endl;
        return;
    }
    for (const auto& medico : medicos) {
        archivo << medico.getID() << "," << medico.getNombre() << "," << medico.getEspecialidad() << "," << medico.isDisponible() << "\n";
    }
    archivo.close();
}

// Cargar datos de Médicos
void BBDD::cargarDatosMedicos(vector<Medico>& medicos) {
    ifstream archivo("medicosLVZ.csv");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para cargar medicos." << endl;
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string idStr, nombre, especialidad, disponibilidadStr;

        getline(ss, idStr, ',');
        getline(ss, nombre, ',');
        getline(ss, especialidad, ',');
        getline(ss, disponibilidadStr, ',');

        int id = stoi(idStr);
        bool disponibilidad = (disponibilidadStr == "1");
        medicos.emplace_back(nombre, id, especialidad);
        medicos.back().cambiarDisponibilidad(disponibilidad);
    }
    archivo.close();
}

// Guardar datos de pacientes
void BBDD::guardarDatosPacientes(const vector<Paciente>& pacientes) {
    ofstream archivo("pacientesLVZ.csv");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para guardar pacientes." << endl;
        return;
    }
    for (const auto& paciente : pacientes) {
        archivo << paciente.getID() << "," << paciente.getNombre() << "," << paciente.getFechaIngreso() << "\n";
    }
    archivo.close();
}

// Cargar datos de pacientes
void BBDD::cargarDatosPacientes(vector<Paciente>& pacientes) {
    ifstream archivo("pacientesLVZ.csv");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para cargar pacientes." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string idStr, nombre, fechaIngreso;

        getline(ss, idStr, ',');
        getline(ss, nombre, ',');
        getline(ss, fechaIngreso, ',');

        int id = stoi(idStr);
        pacientes.emplace_back(nombre, id, fechaIngreso);
    }
    archivo.close();
}

// Guardar datos de citas
void BBDD::guardarDatosCitas(const vector<Cita>& citas) {
    ofstream archivo("citasLVZ.csv");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para guardar citas." << endl;
        return;
    }
    for (const auto& cita : citas) {
        archivo << cita.getCitaID() << "," << cita.getPacienteID() << "," << cita.getMedicoID() << ","
                << cita.getFecha() << "," << cita.getEspecialidad() << "," << cita.getEstado() << "," << cita.getUrgencia() << "\n";
    }
    archivo.close();
}

// Cargar datos de citas
void BBDD::cargarDatosCitas(vector<Cita>& citas) {
    ifstream archivo("citasLVZ.csv");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para cargar citas." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string citaIDStr, pacienteIDStr, medicoIDStr, fecha, especialidad, estado, urgencia;

        getline(ss, citaIDStr, ',');
        getline(ss, pacienteIDStr, ',');
        getline(ss, medicoIDStr, ',');
        getline(ss, fecha, ',');
        getline(ss, especialidad, ',');
        getline(ss, estado, ',');
        getline(ss, urgencia, ',');

        int citaID = stoi(citaIDStr);
        int pacienteID = stoi(pacienteIDStr);
        int medicoID = stoi(medicoIDStr);

        // Crear objeto Cita con 6 argumentos
        citas.emplace_back(citaID, pacienteID, medicoID, fecha, especialidad, urgencia);

        // Ajustar el estado de la cita si está cancelada
        if (estado == "cancelada") {
            citas.back().cancelarCita();
        }
    }
    archivo.close();
}
