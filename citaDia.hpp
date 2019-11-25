#ifndef _citaDia_hpp_
#define _citaDia_hpp_
#include <iostream>
#include "Paciente.hpp"
using namespace std;

/*

    CLASE QUE REPRESENTA LA DISPONIBILIDAD DIARIA DEL DIA LABORAL DE UN DOCTOR
        - Posee booleano que es true si esta disponible o false si esta ocupadp
        - De estar ocupado, el paciente es un paciente vacio  
        - Por necesidad solo se define un constructor parametrizado

*/

class citaDia{
    public:
        bool disponibilidad;
        Paciente myPaciente;
        
        citaDia(bool d, Paciente k);//contructor parametrizado
        
};
#endif
