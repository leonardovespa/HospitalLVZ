#include "BBDD.h"
#include "Cita.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <iomanip>
using namespace std;

// Ruta base para los archivos CSV
const string BASE_PATH = "C:\\Users\\leona\\OneDrive\\Estudios LVZ\\MSMK Univertsity\\Units\\02_Year\\Unit20_AppliedProgramming_DesignPrinciples\\AB\\HospitalLVZ\\output\\";

// Guardar datos de Medicos
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

// Cargar datos de Medicos
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
        archivo << paciente.getID() << "," << paciente.getNombre() << "," << paciente.getFechaIngreso() << "," << (paciente.esCronico() ? "1" : "0") << "\n";
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
        string idStr, nombre, fechaIngreso, cronicoStr;

        getline(ss, idStr, ',');
        getline(ss, nombre, ',');
        getline(ss, fechaIngreso, ',');
        getline(ss, cronicoStr, ',');

        int id = stoi(idStr);
        bool cronico = (cronicoStr == "1");
        pacientes.emplace_back(nombre, id, fechaIngreso, cronico);
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

// Verificar y realizar backup automatico
bool BBDD::verificarYRealizarBackupAutomatico() {
    const string backupPath = BASE_PATH + "backup/";
    const string lastBackupFile = backupPath + "lastBackup.txt";

    // Crear carpeta de backup si no existe
    if (!filesystem::exists(backupPath)) {
        filesystem::create_directory(backupPath);
    }

    // Obtener la fecha actual en formato YYYY-MM-DD
    auto now = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);
    stringstream fechaActual;
    fechaActual << put_time(localtime(&in_time_t), "%Y-%m-%d");

    // Leer la última fecha de backup
    string ultimaFechaBackup;
    ifstream archivo(lastBackupFile);
    if (archivo.is_open()) {
        getline(archivo, ultimaFechaBackup);
        archivo.close();
    }

    // Verificar si ya se realizó un backup hoy
    if (ultimaFechaBackup == fechaActual.str()) {
        cout << "El backup ya fue realizado hoy (" << ultimaFechaBackup << ")." << endl;
        return false;
    }

    // Realizar el backup y actualizar la fecha
    realizarBackup();
    ofstream archivoBackup(lastBackupFile);
    if (archivoBackup.is_open()) {
        archivoBackup << fechaActual.str();
        archivoBackup.close();
    }

    return true;
}

// Realizar backup
void BBDD::realizarBackup() const {
    try {
        const string backupPath = BASE_PATH + "backup/";
        auto now = chrono::system_clock::now();
        auto in_time_t = chrono::system_clock::to_time_t(now);
        stringstream timestamp;
        timestamp << put_time(localtime(&in_time_t), "%Y%m%d_%H%M%S");

        vector<string> archivos = {"pacientesLVZ.csv", "medicosLVZ.csv", "citasLVZ.csv"};
        for (const auto& archivo : archivos) {
            string origen = BASE_PATH + archivo;
            string destino = backupPath + archivo + "_" + timestamp.str();
            if (filesystem::exists(origen)) {
                filesystem::copy(origen, destino);
                cout << "Respaldo creado: " << destino << endl;
            } else {
                cout << "Archivo no encontrado para respaldar: " << origen << endl;
            }
        }
    } catch (const filesystem::filesystem_error& e) {
        cerr << "Error al realizar el backup: " << e.what() << endl;
    }
}
