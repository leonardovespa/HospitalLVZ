#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>
#include <limits>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"
#include "Reporte.h"
#include "BBDD.h"

using namespace std;

// Validar formato de fecha
bool esFechaValida(const string& fecha) {
    const regex formatoFecha("^\\d{4}-\\d{2}-\\d{2}$"); // Formato YYYY-MM-DD
    return regex_match(fecha, formatoFecha);
}

// Validar que el ID sea un número entero válido
int obtenerIDValido() {
    int ID;
    while (true) {
        cout << "Ingrese ID: ";
        cin >> ID;

        if (cin.fail()) { // Verificar si la entrada fue válida
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: ID inválido. Ingrese un número entero.\n";
        } else {
            return ID;
        }
    }
}

// Mostrar menú principal
void mostrarMenu() {
    cout << "\n=== Sistema HospitalLVZ ===\n";
    cout << "1. Gestionar Pacientes\n";
    cout << "2. Gestionar Medicos\n";
    cout << "3. Gestionar Citas\n";
    cout << "4. Generar Reportes\n";
    cout << "5. Guardar Datos\n";
    cout << "6. Cargar Datos\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
}

// Gestionar pacientes
void gestionarPacientes(vector<Paciente>& pacientes, BBDD& bbdd) {
    // Código sin cambios
}

// Gestionar médicos
void gestionarMedicos(vector<Medico>& medicos, BBDD& bbdd) {
    // Código sin cambios
}

// Gestionar citas
void gestionarCitas(vector<Cita>& citas, vector<Paciente>& pacientes, vector<Medico>& medicos, BBDD& bbdd) {
    int opcion;
    do {
        cout << "\n--- Gestion de Citas ---\n";
        cout << "1. Asignar Cita\n";
        cout << "2. Cancelar Cita\n";
        cout << "3. Mostrar Citas\n";
        cout << "0. Volver al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) { // Asignar cita
            int pacienteID, medicoID;
            string fecha, urgencia;

            // Buscar paciente
            cout << "Ingrese el ID del paciente: ";
            pacienteID = obtenerIDValido();
            auto pacienteIt = find_if(pacientes.begin(), pacientes.end(), [pacienteID](const Paciente& p) {
                return p.getID() == pacienteID;
            });

            if (pacienteIt == pacientes.end()) {
                cout << "Error: Paciente no encontrado.\n";
                continue;
            }

            // Buscar médico
            cout << "Ingrese el ID del médico: ";
            medicoID = obtenerIDValido();
            auto medicoIt = find_if(medicos.begin(), medicos.end(), [medicoID](const Medico& m) {
                return m.getID() == medicoID;
            });

            if (medicoIt == medicos.end()) {
                cout << "Error: Medico no encontrado.\n";
                continue;
            }

            if (!medicoIt->isDisponible()) {
                cout << "El medico no está disponible.\n";
                continue;
            }

            // Ingresar fecha de la cita
            cout << "Ingrese la fecha de la cita (YYYY-MM-DD): ";
            cin >> fecha;
            while (!esFechaValida(fecha)) {
                cout << "Error: Formato de fecha inválido. Ingrese nuevamente (YYYY-MM-DD): ";
                cin >> fecha;
            }

            // Ingresar urgencia
            cout << "Ingrese el nivel de urgencia (Alta/Media/Baja): ";
            cin.ignore();
            getline(cin, urgencia);

            // Crear y agregar la cita
            int citaID = citas.empty() ? 1 : citas.back().getCitaID() + 1;
            citas.emplace_back(citaID, pacienteID, medicoID, fecha, medicoIt->getEspecialidad(), urgencia);
            medicoIt->cambiarDisponibilidad(false); // Marcar al médico como no disponible
            cout << "Cita asignada con exito.\n";

        } else if (opcion == 2) { // Cancelar cita
            int citaID;
            cout << "Ingrese el ID de la cita a cancelar: ";
            citaID = obtenerIDValido();

            auto citaIt = find_if(citas.begin(), citas.end(), [citaID](const Cita& c) {
                return c.getCitaID() == citaID;
            });

            if (citaIt != citas.end()) {
                auto medicoIt = find_if(medicos.begin(), medicos.end(), [citaIt](const Medico& m) {
                    return m.getID() == citaIt->getMedicoID();
                });

                if (medicoIt != medicos.end()) {
                    medicoIt->cambiarDisponibilidad(true); // Marcar al médico como disponible
                }
                citaIt->cancelarCita();
                cout << "Cita cancelada con exito.\n";
            } else {
                cout << "Cita no encontrada.\n";
            }

        } else if (opcion == 3) { // Mostrar citas
            cout << "\n--- Lista de Citas ---\n";
            for (const auto& cita : citas) {
                cita.mostrarCita();
            }
        } else if (opcion != 0) {
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

// Función principal
int main() {
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<Cita> citas;
    BBDD bbdd;

    bbdd.cargarDatosPacientes(pacientes);
    bbdd.cargarDatosMedicos(medicos);

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                gestionarPacientes(pacientes, bbdd);
                break;
            case 2:
                gestionarMedicos(medicos, bbdd);
                break;
            case 3:
                gestionarCitas(citas, pacientes, medicos, bbdd);
                break;
            case 4:
                cout << "Funcionalidad de Reportes aun en desarrollo.\n";
                break;
            case 5:
                bbdd.guardarDatosPacientes(pacientes);
                bbdd.guardarDatosMedicos(medicos);
                cout << "Datos guardados con exito.\n";
                break;
            case 6:
                bbdd.cargarDatosPacientes(pacientes);
                cout << "Datos de pacientes actualizados." << endl;

                bbdd.cargarDatosMedicos(medicos);
                cout << "Disponibilidad de medicos actualizada." << endl;

                bbdd.cargarDatosCitas(citas);
                cout << "Citas actualizadas." << endl;

                cout << "Datos cargados con exito." << endl;
    break;

            case 0:
                cout << "Saliendo del sistema...\n";
                bbdd.guardarDatosPacientes(pacientes);
                bbdd.guardarDatosMedicos(medicos);
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}
