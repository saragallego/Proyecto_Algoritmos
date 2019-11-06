#include "Paciente.hpp"
using namespace std;

int main(){
    cout << endl << endl << endl;

    Paciente Paciente_1("sara", 4, "me duelen los ojos .");
    cout << "PACIENTE 1:\n" << Paciente_1 << endl;
    cout << "especialidad necesaria: " << Paciente_1.getEspecialidadPaciente() << endl;

    cout << endl;

    Paciente Paciente_2("lucas", 9, "siento algo en el cerebro .");
    cout << "PACIENTE 2:\n" << Paciente_2 << endl;
    cout << "especialidad necesaria: " << Paciente_2.getEspecialidadPaciente() << endl;

    cout << endl << endl << endl;


    //pruebas clase doctores


    return 0;
}
