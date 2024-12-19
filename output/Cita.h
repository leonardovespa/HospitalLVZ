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
    string urgencia;
    string estado;

    public:
    Cita(int citaID, int pacienteID, string fecha, string urgencia);
    void modificarCita(string nuevaFecha, string nuevaUrgencia);
    void cancelarCita();
    void mostrarCita();
    bool esActiva() const;
    int getCitaID() const;
    int getPacienteID() const;
    int getMedicoID() const;
    string getEstado() const;
};

#endif