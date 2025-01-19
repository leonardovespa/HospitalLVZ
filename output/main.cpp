#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>
#include <limits>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <filesystem>
#include <stdexcept>
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
            cout << "Error: ID invalido. Ingrese un numero entero.\n";
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
    cout << "5. Generar Backup manualmente\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
}

// Gestionar pacientes
void gestionarPacientes(vector<Paciente>& pacientes, BBDD& bbdd) {
    int opcion;
    do {
        cout << "\n--- Gestion de Pacientes ---\n";
        cout << "1. Alta de Paciente\n";
        cout << "2. Baja de Paciente\n";
        cout << "3. Modificar Datos de Paciente\n";
        cout << "4. Mostrar Pacientes\n";
        cout << "0. Volver al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) { // Alta de paciente
            string nombre, fechaIngreso;
            cout<<"(Solo caracteres numericos): ";
            int ID = obtenerIDValido();

            cout << "Ingrese Nombre del Paciente: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nombre);

            cout << "Ingrese Fecha de Ingreso (YYYY-MM-DD): ";
            cin >> fechaIngreso;
            while (!esFechaValida(fechaIngreso)) {
                cout << "Error: Formato de fecha invalido. Ingrese nuevamente (YYYY-MM-DD): ";
                cin >> fechaIngreso;
            }

            cout << "¿El paciente tiene una enfermedad cronica? (1: Si, 0: No): ";
            int cronicoFlag;
            cin >> cronicoFlag;
            bool cronico = (cronicoFlag == 1);

            pacientes.emplace_back(nombre, ID, fechaIngreso, cronico);
            cout << "Paciente agregado con exito.\n";
            bbdd.guardarDatosPacientes(pacientes);

        } else if (opcion == 2) { // Baja de paciente
            cout<<"(Solo caracteres numericos): ";
            int ID = obtenerIDValido();
            auto it = find_if(pacientes.begin(), pacientes.end(), [ID](const Paciente& p) {
                return p.getID() == ID;
            });

            if (it != pacientes.end()) {
                pacientes.erase(it);
                cout << "Paciente eliminado con exito.\n";
                bbdd.guardarDatosPacientes(pacientes);
            } else {
                cout << "Paciente no encontrado.\n";
            }

        } else if (opcion == 3) { // Modificar paciente
            cout<<"(Solo caracteres numericos): ";
            int ID = obtenerIDValido();
            auto it = find_if(pacientes.begin(), pacientes.end(), [ID](const Paciente& p) {
                return p.getID() == ID;
            });

            if (it != pacientes.end()) {
                int subOpcion;
                do {
                    cout << "\n--- Modificar Paciente ---\n";
                    cout << "1. Modificar Nombre\n";
                    cout << "2. Modificar Fecha de Ingreso\n";
                    cout << "3. Modificar ID\n";
                    cout << "0. Volver\n";
                    cout << "Seleccione una opcion: ";
                    cin >> subOpcion;

                    if (subOpcion == 1 || subOpcion == 2) {
                        string nuevoValor;
                        cout << "Ingrese el nuevo valor: ";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(cin, nuevoValor);
                        it->modificar(subOpcion, nuevoValor);
                        cout << "Dato actualizado con exito.\n";
                    } else if (subOpcion == 3) {
                        cout<<"(Solo caracteres numericos): ";
                        int nuevoValor = obtenerIDValido();
                        it->modificar(subOpcion, nuevoValor);
                        cout << "ID actualizado con exito.\n";
                    } else if (subOpcion != 0) {
                        cout << "Opcion no valida.\n";
                    }
                } while (subOpcion != 0);

                bbdd.guardarDatosPacientes(pacientes);
            } else {
                cout << "Paciente no encontrado.\n";
            }
        } else if (opcion == 4) { // Mostrar pacientes
            cout << "\n--- Lista de Pacientes ---\n";
            for (const auto& p : pacientes) {
                p.mostrarDatos();
            }
        } else if (opcion != 0) {
            cout << "Opción no valida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

// Gestionar médicos
void gestionarMedicos(vector<Medico>& medicos, BBDD& bbdd) {
    int opcion;
    do {
        cout << "\n--- Gestion de Medicos ---\n";
        cout << "1. Alta de Medico\n";
        cout << "2. Baja de Medico\n";
        cout << "3. Modificar Datos del Medico\n";
        cout << "4. Mostrar Medicos\n";
        cout << "0. Volver al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) { // Alta de médico
            string nombre, especialidad;
            cout<<"(Solo caracteres numericos): ";
            int ID = obtenerIDValido();

            cout << "Ingrese Nombre del Medico: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nombre);

            cout << "Ingrese Especialidad: ";
            getline(cin, especialidad);

            medicos.emplace_back(nombre, ID, especialidad);
            cout << "Medico agregado con exito.\n";
            bbdd.guardarDatosMedicos(medicos); // Guardar en archivo

        } else if (opcion == 2) { // Baja de médico
            cout<<"(Solo caracteres numericos): ";
            int ID = obtenerIDValido();
            auto it = find_if(medicos.begin(), medicos.end(), [ID](const Medico& m) {
                return m.getID() == ID;
            });

            if (it != medicos.end()) {
                medicos.erase(it);
                cout << "Medico eliminado con exito.\n";
                bbdd.guardarDatosMedicos(medicos); // Guardar cambios
            } else {
                cout << "Medico no encontrado.\n";
            }

        } else if (opcion == 3) { // Modificar médico
            cout<<"(Solo caracteres numericos): ";
            int ID = obtenerIDValido();
            auto it = find_if(medicos.begin(), medicos.end(), [ID](const Medico& m) {
                return m.getID() == ID;
            });

            if (it != medicos.end()) {
                int subOpcion;
                do {
                    cout << "\n--- Modificar Medico ---\n";
                    cout << "1. Modificar Nombre\n";
                    cout << "2. Modificar Especialidad\n";
                    cout << "3. Modificar ID\n";
                    cout << "0. Volver\n";
                    cout << "Seleccione una opcion: ";
                    cin >> subOpcion;

                    if (subOpcion == 1 || subOpcion == 2) {
                        string nuevoValor;
                        cout << "Ingrese el nuevo valor: ";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(cin, nuevoValor);
                        it->modificar(subOpcion, nuevoValor);
                        cout << "Dato actualizado con exito.\n";
                    } else if (subOpcion == 3) {
                        cout<<"(Solo caracteres numericos): ";
                        int nuevoValor = obtenerIDValido();
                        it->modificar(subOpcion, nuevoValor);
                        cout << "ID actualizado con exito.\n";
                    } else if (subOpcion != 0) {
                        cout << "Opcion no valida.\n";
                    }
                } while (subOpcion != 0);

                bbdd.guardarDatosMedicos(medicos);
            } else {
                cout << "Medico no encontrado.\n";
            }
        } else if (opcion == 4) { // Mostrar médicos
            cout << "\n--- Lista de Medicos ---\n";
            for (const auto& m : medicos) {
                m.mostrarDatos();
            }
        } else if (opcion != 0) {
            cout << "Opción no valida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
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

        if (opcion == 1) { // Asignar Cita
            int pacienteID, medicoID;
            string fecha, urgencia;

            // Buscar paciente
            cout << "Ingrese el ID del paciente (Solo caracteres numericos): ";
            pacienteID = obtenerIDValido();
            auto pacienteIt = find_if(pacientes.begin(), pacientes.end(), [pacienteID](const Paciente& p) {
                return p.getID() == pacienteID;
            });

            if (pacienteIt == pacientes.end()) {
                cout << "Error: Paciente no encontrado.\n";
                continue;
            }

            // Mostrar lista de médicos
            cout << "\n--- Lista de Medicos ---\n";
            for (const auto& m : medicos) {
                m.mostrarDatos();
            }

            // Solicitar ID del médico
            cout << "Ingrese el ID del medico (Solo caracteres numericos): ";
            medicoID = obtenerIDValido();
            auto medicoIt = find_if(medicos.begin(), medicos.end(), [medicoID](const Medico& m) {
                return m.getID() == medicoID;
            });

            if (medicoIt == medicos.end()) {
                cout << "Error: Medico no encontrado.\n";
                continue;
            }

            // Solicitar fecha de la cita
            cout << "Ingrese la fecha de la cita (YYYY-MM-DD): ";
            cin >> fecha;
            while (!esFechaValida(fecha)) {
                cout << "Error: Formato de fecha invalido. Ingrese nuevamente (YYYY-MM-DD): ";
                cin >> fecha;
            }

            // Verificar disponibilidad del médico en la fecha seleccionada
            bool disponible = true;
            for (const auto& cita : citas) {
                if (cita.getMedicoID() == medicoID && cita.getFecha() == fecha) {
                    disponible = false;
                    break;
                }
            }

            if (!disponible) {
                cout << "El médico no esta disponible en la fecha seleccionada.\n";
                continue;
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

            // Guardar las citas en el archivo
            bbdd.guardarDatosCitas(citas);

        } else if (opcion == 2) { // Cancelar Cita
            int citaID;
            cout << "Ingrese el ID de la cita a cancelar (Solo caracteres numericos): ";
            citaID = obtenerIDValido();

            auto citaIt = find_if(citas.begin(), citas.end(), [citaID](const Cita& c) {
                return c.getCitaID() == citaID;
            });

            if (citaIt != citas.end()) {
                auto medicoIt = find_if(medicos.begin(), medicos.end(), [citaIt](const Medico& m) {
                    return m.getID() == citaIt->getMedicoID();
                });

                citaIt->cancelarCita();
                cout << "Cita cancelada con exito.\n";

                // Guardar las citas actualizadas en el archivo
                bbdd.guardarDatosCitas(citas);
            } else {
                cout << "Cita no encontrada.\n";
            }

        } else if (opcion == 3) { // Mostrar Citas
            cout << "\n--- Lista de Citas ---\n";
            for (const auto& cita : citas) {
                cita.mostrarCita();
            }
        } else if (opcion != 0) {
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

// Generar reportes
void generarReportes(vector<Paciente>& pacientes, vector<Cita>& citas, vector<Medico>& medicos) {
    Reporte reporte;
    int opcionReporte;
    do {
        cout << "\n--- Generacion de Reportes ---\n";
        cout << "1. Listado de pacientes atendidos en un rango de fechas\n";
        cout << "2. Citas pendientes por Medico o especialidad\n";
        cout << "3. Reporte de pacientes con enfermedades cronicas\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcionReporte;

        if (opcionReporte == 1) {
            string fechaInicio, fechaFin;
            cout << "Ingrese la fecha de inicio (YYYY-MM-DD): ";
            cin >> fechaInicio;
            cout << "Ingrese la fecha de fin (YYYY-MM-DD): ";
            cin >> fechaFin;
            reporte.generarReportePacientesAtendidos(pacientes, fechaInicio, fechaFin);

        } else if (opcionReporte == 2) {
            int criterioOpcion;
            cout << "Seleccione el criterio:\n";
            cout << "1. Por ID de Medico (Solo caracteres numericos)\n";
            cout << "2. Por especialidad\n";
            cin >> criterioOpcion;

            if (criterioOpcion == 1) {
                int medicoID = obtenerIDValido(); // Valida que el ID sea un número
                reporte.reporteCitasPendientes(citas, medicos, medicoID);
            } else if (criterioOpcion == 2) {
                string especialidad;
                cout << "Ingrese la especialidad: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                getline(cin, especialidad); // Permite entradas con letras y espacios
                reporte.reporteCitasPendientes(citas, medicos, -1, especialidad);
            } else {
                cout << "Opcion no valida. Intente de nuevo.\n";
            }

        } else if (opcionReporte == 3) {
            reporte.reportePacientesCronicos(pacientes);

        } else if (opcionReporte != 0) {
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcionReporte != 0);
}

// Función principal
int main() {
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<Cita> citas;
    BBDD bbdd;

    bbdd.verificarYRealizarBackupAutomatico();

    //Limpiar datos previos antes de realizar una nueva carga

    pacientes.clear();
    medicos.clear();
    citas.clear();

    bbdd.cargarDatosPacientes(pacientes);
    bbdd.cargarDatosMedicos(medicos);
    bbdd.cargarDatosCitas(citas);

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
                generarReportes(pacientes, citas, medicos);
                break;
             case 5:
                bbdd.realizarBackup(); // Backup manual
                break;    
            case 0:
                cout << "Saliendo del sistema...\n";
                bbdd.guardarDatosPacientes(pacientes);
                bbdd.guardarDatosMedicos(medicos);
                bbdd.guardarDatosCitas(citas);
                break;
            default:
                cout << "Opción no valida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}