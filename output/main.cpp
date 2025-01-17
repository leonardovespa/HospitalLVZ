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

void gestionarPacientes(vector<Paciente>& pacientes, BBDD& bbdd) {
    int opcion;
    do {
        cout << "\n--- Gestion de Pacientes ---\n";
        cout << "1. Alta de Paciente\n";
        cout << "2. Baja de Paciente\n";
        cout << "3. Modificar Datos\n";
        cout << "4. Mostrar Pacientes\n";
        cout << "0. Volver al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre, fechaIngreso;
            int ID;
            cout << "Ingrese Nombre: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nombre);

            bool idDuplicado;
            do {
                idDuplicado = false;
                cout << "Ingrese ID: ";
                cin >> ID;

                for (const auto& paciente : pacientes) {
                    if (paciente.getID() == ID) {
                        idDuplicado = true;
                        cout << "Error: El ID ingresado ya existe. Por favor, ingrese un nuevo ID.\n";
                        break;
                    }
                }
            } while (idDuplicado);

            cout << "Ingrese Fecha de Ingreso (YYYY-MM-DD): ";
            cin >> fechaIngreso;
            while (!esFechaValida(fechaIngreso)) {
                cout << "Error: Formato de fecha invalido. Por favor, ingrese una nueva fecha en formato YYYY-MM-DD: ";
                cin >> fechaIngreso;
            }

            pacientes.emplace_back(nombre, ID, fechaIngreso);
            cout << "Paciente agregado con exito.\n";
            bbdd.guardarDatosPacientes(pacientes); // Guardar cambios
        } else if (opcion == 2) {
            int ID;
            cout << "Ingrese el ID del paciente a eliminar: ";
            cin >> ID;
            auto it = find_if(pacientes.begin(), pacientes.end(), [ID](const Paciente& p) { return p.getID() == ID; });
            if (it != pacientes.end()) {
                pacientes.erase(it);
                cout << "Paciente eliminado con exito.\n";
                bbdd.guardarDatosPacientes(pacientes); // Guardar cambios
            } else {
                cout << "Paciente no encontrado.\n";
            }
        } else if (opcion == 3) {
            int ID;
            cout << "Ingrese el ID del paciente a modificar: ";
            cin >> ID;
            auto it = find_if(pacientes.begin(), pacientes.end(), [ID](const Paciente& p) { return p.getID() == ID; });
            if (it != pacientes.end()) {
                string nuevoNombre, nuevaFechaIngreso;
                cout << "Ingrese Nuevo Nombre: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, nuevoNombre);
                cout << "Ingrese nueva Fecha de Ingreso (YYYY-MM-DD): ";
                cin >> nuevaFechaIngreso;
                while (!esFechaValida(nuevaFechaIngreso)) {
                    cout << "Error: Formato de fecha invalido. Por favor, ingrese una nueva fecha en formato YYYY-MM-DD: ";
                    cin >> nuevaFechaIngreso;
                }
                it->modificarDatos(nuevoNombre, nuevaFechaIngreso);
                bbdd.guardarDatosPacientes(pacientes); // Guardar cambios
            } else {
                cout << "Paciente no encontrado.\n";
            }
        } else if (opcion == 4) {
            cout << "\n--- Lista de Pacientes ---\n";
            for (const auto& p : pacientes) {
                p.mostrarDatos();
            }
        } else if (opcion != 0) {
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

void gestionarMedicos(vector<Medico>& medicos, BBDD& bbdd) {
    int opcion;
    do {
        cout << "\n--- Gestion de Medicos ---\n";
        cout << "1. Alta de Medico\n";
        cout << "2. Baja de Medico\n";
        cout << "3. Modificar Especialidad\n";
        cout << "4. Mostrar Medicos\n";
        cout << "0. Volver al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre, especialidad;
            int ID;
            cout << "Ingrese Nombre: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nombre);

            bool idDuplicado;
            do {
                idDuplicado = false;
                cout << "Ingrese ID: ";
                cin >> ID;

                for (const auto& medico : medicos) {
                    if (medico.getID() == ID) {
                        idDuplicado = true;
                        cout << "Error: El ID ingresado ya existe. Por favor, ingrese un nuevo ID.\n";
                        break;
                    }
                }
            } while (idDuplicado);

            cout << "Ingrese Especialidad: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, especialidad);

            medicos.emplace_back(nombre, ID, especialidad);
            cout << "Medico agregado con exito.\n";
            bbdd.guardarDatosMedicos(medicos); // Guardar cambios
        } else if (opcion == 2) {
            int ID;
            cout << "Ingrese el ID del medico a eliminar: ";
            cin >> ID;
            auto it = find_if(medicos.begin(), medicos.end(), [ID](const Medico& m) { return m.getID() == ID; });
            if (it != medicos.end()) {
                medicos.erase(it);
                cout << "Medico eliminado con exito.\n";
                bbdd.guardarDatosMedicos(medicos); // Guardar cambios
            } else {
                cout << "Medico no encontrado.\n";
            }
        } else if (opcion == 3) {
            int ID;
            cout << "Ingrese el ID del medico a modificar: ";
            cin >> ID;
            auto it = find_if(medicos.begin(), medicos.end(), [ID](const Medico& m) { return m.getID() == ID; });
            if (it != medicos.end()) {
                string nuevaEspecialidad;
                cout << "Ingrese Nueva Especialidad: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, nuevaEspecialidad);
                it->asignarEspecialidad(nuevaEspecialidad);
                bbdd.guardarDatosMedicos(medicos); // Guardar cambios
            } else {
                cout << "Medico no encontrado.\n";
            }
        } else if (opcion == 4) {
            cout << "\n--- Lista de Medicos ---\n";
            for (const auto& m : medicos) {
                m.mostrarDatos();
            }
        } else if (opcion != 0) {
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

int main() {
    vector<Paciente> pacientes;
    vector<Medico> medicos;
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
                cout << "Funcionalidad de Citas aun en desarrollo.\n";
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
                bbdd.cargarDatosMedicos(medicos);
                cout << "Datos cargados con exito.\n";
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
