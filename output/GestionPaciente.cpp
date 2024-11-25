// Clase Paciente --> con el archivo main interno para probar la funcion del menú.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Paciente {
private:
    string nombre;
    int ID;
    string telefono;
    string email;
    string fechaIngreso;
    vector<string> historialClinico;

public:
    // Constructor
    Paciente(string nombre, int ID, string telefono, string fechaIngreso, string email) {
        this->nombre = nombre;
        this->ID = ID;
        this->telefono = telefono;
        this->fechaIngreso = fechaIngreso;
        this->email = email;
    }

    // Alta de paciente
    void altaPaciente(string nombre, int ID, string telefono, string fechaIngreso, string email) {
        this->nombre = nombre;
        this->ID = ID;
        this->telefono = telefono;
        this->fechaIngreso = fechaIngreso;
        this->email = email;
    }

    // Baja de Paciente
    void bajaPaciente() {
        cout << "Paciente " << nombre << " dado de baja con éxito." << endl;
    }

    // Modificación de datos personales
    void modificarDatos(string nuevoNombre, string nuevoTelefono, string nuevaFechaIngreso, string nuevoEmail) {
        nombre = nuevoNombre;
        telefono = nuevoTelefono;
        fechaIngreso = nuevaFechaIngreso;
        email = nuevoEmail;
        cout << "Datos del Paciente modificados con éxito." << nombre << endl;
    }

    // Buscar Paciente por ID
    bool buscarPaciente(int id) {
        return this->ID == id;
    }

    // Buscar Paciente por Nombre
    bool buscarPaciente(string nombreBusqueda) {
        return this->nombre == nombreBusqueda;
    }

    // Registro historial clínico
    void registrarHistorial(string entrada) {
        historialClinico.push_back(entrada);
    }

    // Mostrar datos del paciente
    void mostrarDatos() {
        cout << "ID: " << ID << ", Nombre: " << nombre << ", Teléfono: " << telefono
             << ", Fecha de ingreso: " << fechaIngreso << ", Email: " << email << endl;
    }

    // Obtener el ID del paciente
    int getID() {
        return ID;
    }
};

// Función para el menú
void mostrarMenu() {
    cout << "Seleccione una opción:" << endl;
    cout << "1. Alta nuevo Paciente" << endl;
    cout << "2. Baja de Paciente" << endl;
    cout << "3. Modificar datos de Paciente" << endl;
    cout << "4. Buscar Paciente" << endl;
    cout << "5. Salir" << endl;
}

int main() {
    vector<Paciente> pacientes;
    int opcion;
    string nombre, telefono, fechaIngreso, email;
    int ID;
    bool encontrado;  // Mover la declaración de las variables fuera del switch
    bool pacienteModificado;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: // Alta de paciente
                cout << "Introduzca el nombre del paciente: ";
                cin.ignore(); // Limpia el buffer de entrada
                getline(cin, nombre);
                cout << "Introduzca el ID del paciente: ";
                cin >> ID;
                cout << "Introduzca el telefono del paciente: ";
                cin.ignore();
                getline(cin, telefono);
                cout << "Introduzca la fecha de ingreso (dd/mm/yyyy): ";
                getline(cin, fechaIngreso);
                cout << "Introduzca el email del paciente: ";
                getline(cin, email);

                pacientes.push_back(Paciente(nombre, ID, telefono, fechaIngreso, email));  // Añadir paciente con email
                cout << "Paciente dado de alta con éxito." << endl;
                break;

            case 2: // Baja de paciente
                cout << "Introduzca ID del paciente a dar de baja: ";
                cin >> ID;

                // Buscar el paciente por ID y eliminarlo
                encontrado = false;
                for (auto it = pacientes.begin(); it != pacientes.end(); ++it) {
                    if (it->getID() == ID) {
                        it->bajaPaciente();
                        pacientes.erase(it); // Eliminar paciente del vector
                        encontrado = true;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "Paciente no encontrado." << endl;
                }
                break;

            case 3: // Modificar datos de paciente
                cout << "Introduce el ID del paciente a modificar: ";
                cin >> ID;

                // Buscar el paciente por ID y modificar sus datos
                pacienteModificado = false;
                for (auto& paciente : pacientes) {
                    if (paciente.getID() == ID) {
                        cout << "Introduzca el nuevo nombre: ";
                        cin.ignore();
                        getline(cin, nombre);
                        cout << "Introduzca el nuevo teléfono: ";
                        getline(cin, telefono);
                        cout << "Introduzca la nueva fecha de ingreso: ";
                        getline(cin, fechaIngreso);
                        cout << "Introduzca el nuevo email: ";
                        getline(cin, email);  // Pedir el nuevo email

                        paciente.modificarDatos(nombre, telefono, fechaIngreso, email);
                        pacienteModificado = true;
                        break;
                    }
                }

                if (!pacienteModificado) {
                    cout << "Paciente no encontrado." << endl;
                }
                break;

            case 4: // Buscar paciente
                int criterioBusqueda;
                cout << "Buscar por: 1. ID 2. Nombre" << endl;
                cin >> criterioBusqueda;

                if (criterioBusqueda == 1) {
                    cout << "Introduce el ID del paciente: ";
                    cin >> ID;

                    encontrado = false;
                    for (auto& paciente : pacientes) {
                        if (paciente.buscarPaciente(ID)) {
                            paciente.mostrarDatos();
                            encontrado = true;
                            break;
                        }
                    }

                    if (!encontrado) {
                        cout << "Paciente no encontrado." << endl;
                    }
                } else if (criterioBusqueda == 2) {
                    cout << "Introduce el nombre del paciente: ";
                    cin.ignore();  // Para limpiar el buffer de entrada
                    getline(cin, nombre);

                    encontrado = false;
                    for (auto& paciente : pacientes) {
                        if (paciente.buscarPaciente(nombre)) {
                            paciente.mostrarDatos();
                            encontrado = true;
                            break;
                        }
                    }

                    if (!encontrado) {
                        cout << "Paciente no encontrado." << endl;
                    }
                } else {
                    cout << "Opción no válida." << endl;
                }
                break;

            case 5: // Salir
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opción no válida. Intenta de nuevo." << endl;
                break;
        }

    } while (opcion != 5);

    return 0;
}
