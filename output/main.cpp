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
            int ID = obtenerIDValido();

            cout << "Ingrese Nombre del Paciente: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nombre);

            cout << "Ingrese Fecha de Ingreso (YYYY-MM-DD): ";
            cin >> fechaIngreso;
            while (!esFechaValida(fechaIngreso)) {
                cout << "Error: Formato de fecha inválido. Ingrese nuevamente (YYYY-MM-DD): ";
                cin >> fechaIngreso;
            }

            pacientes.emplace_back(nombre, ID, fechaIngreso);
            cout << "Paciente agregado con éxito.\n";
            bbdd.guardarDatosPacientes(pacientes);
        } else if (opcion == 2) { // Baja de paciente
            int ID = obtenerIDValido();
            auto it = find_if(pacientes.begin(), pacientes.end(), [ID](const Paciente& p) {
                return p.getID() == ID;
            });

            if (it != pacientes.end()) {
                pacientes.erase(it);
                cout << "Paciente eliminado con éxito.\n";
                bbdd.guardarDatosPacientes(pacientes);
            } else {
                cout << "Paciente no encontrado.\n";
            }
        } else if (opcion == 3) { // Modificar paciente
            int ID = obtenerIDValido();
            auto it = find_if(pacientes.begin(), pacientes.end(), [ID](const Paciente& p) {
                return p.getID() == ID;
            });

            if (it != pacientes.end()) {
                string nuevoNombre, nuevaFechaIngreso;
                cout << "Ingrese Nuevo Nombre: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, nuevoNombre);

                cout << "Ingrese Nueva Fecha de Ingreso (YYYY-MM-DD): ";
                cin >> nuevaFechaIngreso;
                while (!esFechaValida(nuevaFechaIngreso)) {
                    cout << "Error: Formato de fecha inválido. Ingrese nuevamente (YYYY-MM-DD): ";
                    cin >> nuevaFechaIngreso;
                }

                it->modificarDatos(nuevoNombre, nuevaFechaIngreso);
                cout << "Datos del paciente actualizados con éxito.\n";
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
            cout << "Opción no válida. Intente de nuevo.\n";
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
            int ID = obtenerIDValido();

            cout << "Ingrese Nombre del Medico: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nombre);

            cout << "Ingrese Especialidad: ";
            getline(cin, especialidad);

            medicos.emplace_back(nombre, ID, especialidad);
            cout << "Medico agregado con éxito.\n";
            bbdd.guardarDatosMedicos(medicos);
        } else if (opcion == 2) { // Baja de médico
            int ID = obtenerIDValido();
            auto it = find_if(medicos.begin(), medicos.end(), [ID](const Medico& m) {
                return m.getID() == ID;
            });

            if (it != medicos.end()) {
                medicos.erase(it);
                cout << "Medico eliminado con éxito.\n";
                bbdd.guardarDatosMedicos(medicos);
            } else {
                cout << "Medico no encontrado.\n";
            }
        } else if (opcion == 3) { // Modificar médico
            int ID = obtenerIDValido();
            auto it = find_if(medicos.begin(), medicos.end(), [ID](const Medico& m) {
                return m.getID() == ID;
            });

            if (it != medicos.end()) {
                string nuevaEspecialidad;
                cout << "Ingrese Nueva Especialidad: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, nuevaEspecialidad);

                it->asignarEspecialidad(nuevaEspecialidad);
                cout << "Datos del medico actualizados con éxito.\n";
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
            cout << "Opción no válida. Intente de nuevo.\n";
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

        if (opcion == 1) {
            // Lógica para asignar citas
        } else if (opcion == 2) {
            // Lógica para cancelar citas
        } else if (opcion == 3) {
            // Mostrar citas
        } else if (opcion != 0) {
            cout << "Opción no válida. Intente de nuevo.\n";
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
                cout << "Funcionalidad de Reportes aun en desarrollo.\n";
                break;
            case 5:
                bbdd.guardarDatosPacientes(pacientes);
                bbdd.guardarDatosMedicos(medicos);
                bbdd.guardarDatosCitas(citas);
                cout << "Datos guardados con éxito.\n";
                break;
            case 6:
                bbdd.cargarDatosPacientes(pacientes);
                bbdd.cargarDatosMedicos(medicos);
                bbdd.cargarDatosCitas(citas);
                cout << "Datos cargados con éxito.\n";
                break;
            case 0:
                cout << "Saliendo del sistema...\n";
                bbdd.guardarDatosPacientes(pacientes);
                bbdd.guardarDatosMedicos(medicos);
                bbdd.guardarDatosCitas(citas);
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}
