#ifndef CITA_H
#define CITA_H
#include <string>
using namespace std;

class Cita {
    private:
    int  citaID;
    int pacienteID;
    int medicoID;
    string fecha;
    string especialidad;
    string urgencia;
    string estado;

    public:
    Cita(int citaID, int pacienteID, int medicoID, const string& fecha, const string& especialidad, const string& urgencia);
    
    // Obtener información de la cita

    int getCitaID() const;
    int getPacienteID() const;
    int getMedicoID() const;
    string getFecha() const;
    string getEspecialidad() const;
    string getUrgencia() const;
    string getEstado() const;

    //Métodos para gestionar la cita

    void modificarCita(string nuevaFecha, string nuevaUrgencia);
    void cancelarCita();
    void mostrarCita() const;
    bool esActiva() const;
};

#endif