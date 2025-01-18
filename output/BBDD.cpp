#include "BBDD.h"
#include "Cita.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// Ruta base para los archivos CSV
const string BASE_PATH = "C:\\Users\\leona\\OneDrive\\Estudios LVZ\\MSMK Univertsity\\Units\\02_Year\\Unit20_AppliedProgramming_DesignPrinciples\\AB\\HospitalLVZ\\output\\";

// Guardar datos de Médicos
void BBDD::guardarDatosMedicos(const vector<Medico>& medicos) {
    ofstream archivo(BASE_PATH + "medicosLVZ.csv");
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
    ifstream archivo(BASE_PATH + "medicosLVZ.csv");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para cargar Medicos." << endl;
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

// Guardar datos de Pacientes
void BBDD::guardarDatosPacientes(const vector<Paciente>& pacientes) {
    ofstream archivo(BASE_PATH + "pacientesLVZ.csv");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para guardar Pacientes." << endl;
        return;
    }
    for (const auto& paciente : pacientes) {
        archivo << paciente.getID() << "," << paciente.getNombre() << "," << paciente.getFechaIngreso() << "\n";
    }
    archivo.close();
}

// Cargar datos de Pacientes
void BBDD::cargarDatosPacientes(vector<Paciente>& pacientes) {
    ifstream archivo(BASE_PATH + "pacientesLVZ.csv");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para cargar Pacientes." << endl;
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

// Guardar datos de Citas
void BBDD::guardarDatosCitas(const vector<Cita>& citas) {
    ofstream archivo(BASE_PATH + "citasLVZ.csv");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para guardar Citas." << endl;
        return;
    }
    for (const auto& cita : citas) {
        archivo << cita.getCitaID() << "," << cita.getPacienteID() << "," << cita.getMedicoID() << ","
                << cita.getFecha() << "," << cita.getEspecialidad() << "," << cita.getEstado() << "," << cita.getUrgencia() << "\n";
    }
    archivo.close();
}

// Cargar datos de Citas
void BBDD::cargarDatosCitas(vector<Cita>& citas) {
    ifstream archivo(BASE_PATH + "citasLVZ.csv");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para cargar Citas." << endl;
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

        citas.emplace_back(citaID, pacienteID, medicoID, fecha, especialidad, urgencia);

        if (estado == "cancelada") {
            citas.back().cancelarCita();
        }
    }
    archivo.close();
}
