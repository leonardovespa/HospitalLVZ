#include <iostream>
#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"
#include "Reporte.h"
#include "BBDD.h"
#include <algorithm>
using namespace std;

void mostrarMenu() {
    cout << "\n=== Sistema HospitalLVZ ===\n";
    cout << "1. Gestionar Pacientes\n";
    cout << "2. Gestionar Médicos\n";
    cout << "3. Gestionar Citas\n";
    cout << "4. Generar Reportes\n";
    cout << "5. Guardar Datos\n";
    cout << "6. Cargar Datos\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opción: ";
}

void gestionarPacientes(vector<Paciente>& pacientes) {
    int opcion;
    do {
        cout << "\n--- Gestión de Pacientes ---\n";
        cout << "1. Alta de Paciente\n";
        cout << "2. Baja de Paciente\n";
        cout << "3. Modificar Datos\n";
        cout << "4. Mostrar Pacientes\n";
        cout << "0. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre, fechaIngreso;
            int ID;
            cout << "Ingrese Nombre: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nombre);
            cout << "Ingrese ID: ";
            cin >> ID;
            cout << "Ingrese Fecha de Ingreso (YYYY-MM-DD): ";
            cin >> fechaIngreso;
            pacientes.emplace_back(nombre, ID, fechaIngreso);
            cout << "paciente agregado con éxito.\n";
        } else if (opcion == 2) {
            int ID;
            cout << "Ingrese el ID del paciente a eliminar: ";
            cin >> ID;
            auto it = find_if(pacientes.begin(), pacientes.end(), [ID](const Paciente& p) { return p.getID() == ID; });
            if (it != pacientes.end()) {
                pacientes.erase(it);
                cout << "Paciente eliminado con éxito.\n";
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
                it->modificarDatos(nuevoNombre, nuevaFechaIngreso);
            } else {
                cout << "Paciente no encontrado.\n";
            }

        } else if (opcion == 4) {
            cout << "\n--- Lista de Pacientes ---\n";
            for (const auto& p : pacientes) {
                p.mostrarDatos();
            }
        } else if (opcion != 0) {
            cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

void gestionarMedicos(vector<Medico>& medicos) {
    int opcion;
    do {
        cout << "\n--- Gestión de Médicos\n";
        cout << "1. Alta de Médico\n";
        cout << "2. Baja de Médico\n";
        cout << "3. Modificar Especialidad\n";
        cout << "4. Mostrar Médicos\n";
        cout << "0. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre, especialidad;
            int ID;
            cout << "Ingrese Nombre: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nombre);
            cout << "Ingrese ID: ";
            cin >> ID;
            cout << "Ingrese Especialidad: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, especialidad);
            medicos.emplace_back(nombre, ID, especialidad);
            cout << "Médico agregado con éxito.\n";
        } else if (opcion == 2) {
            int ID;
            cout << "Ingrese el ID de médico a eliminar: ";
            cin >> ID;
            auto it = find_if(medicos.begin(), medicos.end(), [ID](const Medico& m) { return m.getID() == ID; });
            if (it != medicos.end()) {
                medicos.erase(it);
                cout << "Médico eliminado con éxito\n";
            } else {
                cout << "Médico no encontrado.\n";
            }
        } else if (opcion ==3) {
            int ID;
            cout << "Ingrese el ID del médico a modificar: ";
            cin >> ID;
            auto it = find_if(medicos.begin(), medicos.end(), [ID](const Medico& m) { return m.getID() == ID; });
            if (it != medicos.end()) {
                string nuevaEspecialidad;
                cout << "Ingrese Nueva Especialidad: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, nuevaEspecialidad);
                it->asignarEspecialidad(nuevaEspecialidad);
            } else {
                cout << "Médico no encontrado.\n";
            }
        } else if (opcion == 4) {
            cout << "\n--- Lista de Médicos---\n";
            for (const auto& m : medicos) {
                m.mostrarDatos();
            }
        } else if (opcion != 0) {
            cout << "Opción no válida. Intente de nuevo.\n";
            }
    } while (opcion != 0);
}

// lógica para las clases Cita, Reportes y BBDD

int main() {
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<Cita> citas;
    Reporte reporte;
    BBDD bbdd;

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
            gestionarPacientes(pacientes);
            break;

            case 2:
            gestionarMedicos(medicos);
            break;

            case 3:
            cout << "Funcionalidad de Reportes aún en desarrollo.\n";
            break;

            case 4:
            cout << "Funcionalidad de Reportes aún en desarrollo.\n";
            break;

            case 5:
            bbdd.guardarDatosMedicos(medicos);
            cout << "Datos guardados con éxito.\n";
            break;

            case 6:
            bbdd.cargarDatosMedicos(medicos);
            cout << "Datos cargados con éxito.\n";
            break;

            case 0:
            cout << "Saliendo del sistema...\n";

            default:
            cout << "Opción no válida. Intente de nuevo.\n";
            break;
        }
    } while (opcion !=0);

    return 0;
}
