// Clase Cita


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cita {
	private:
	int citaID;
	int pacienteID;
	int medicoID:
	string fecha;
	string urgencia;
	string estado;
	
	public:
	cita(int citaID, int pacienteID, int medicoID, string fecha, string urgencia) {
		this->citaID = citaID;
		this->pacienteID = pacienteID;
		this->medicoID = medicoID;
		this->fecha = fecha;
		this->urgencia = urgencia;
		this->estado = "activa";
	}
	
	// Modificar Cita
	void modificarCita(string nuevaFecha, string nuevaUrgencia) {
		fecha = nuevaFecha;
		urgencia = nuevaUrgencia;
		cout << "Cita modificada para: " << fecha << " con urgencia " << urgencia << endl;
	}
	
	// Cancelar cita
	void cancelarCita() {
		estado = "cancelada";
		cout << "Cita cancelada para el paciente " << pacienteID << " con mñedico " << medicoID << endl;
	}
	
	// Mostrar datos de la cita
	void mostrarCita() {
		cout << "Cita ID: " << citaID << ", Fecha: " << fecha << ", urgencia: " << urgencia << ", Estado: " << estado << endl;
	}
};