#ifndef _citaDia_hpp_
#define _citaDia_hpp_
#include <iostream>
#include "Paciente.hpp"
using namespace std;

class citaDia{
    public:
        bool disponibilidad;
        Paciente myPaciente;

        citaDia(bool d, Paciente k);//contructor

};
#endif
