#ifndef _Doctores_hpp_
#define _Doctores_hpp_
#include <iostream>
#include <vector>
#include "Paciente.hpp"
#include "citaDia.hpp"
using namespace std;

class Doctores{
    private:
        string nombre;
        string especialidad;
        vector<citaDia> disponibilidadSemanal;//vector de longitud 7, que representa los dias de la semana, cada uno tiene un valor booleano que muestra si esta disponible o no.
    public:
        Doctores(string newName, string newEspecialidad);//constructor parametrizado objeto doctores
        string getName();
        string getEspecialidad();

};
#endif




// << no sirve, arreglar
