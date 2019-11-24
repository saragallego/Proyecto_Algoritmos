#ifndef _Doctores_hpp_
#define _Doctores_hpp_
#include "Paciente.hpp"
#include "citaDia.hpp"
#include <iostream>
#include <vector>
using namespace std;
/*

    CLASE QUE REPRESENTA A UN DOCTOR, SUS DATOS Y SU DISPONIBILIDAD SEMANAL
        - Posee el nombre del doctor
        - Su especialidad
        - Un vector de tipo "citaDia" que representa la disponibilidad de una semana
*/
class Doctores{
    private:
        string nombre;
        string especialidad;
        vector<citaDia> disponibilidadSemanal;//vector de longitud 7, que representa los dias de la semana, cada uno tiene un valor booleano que muestra si esta disponible o no.
    public:
        Doctores(string newName, string newEspecialidad);//constructor parametrizado objeto doctores
        friend ostream& operator<<(ostream& os, Doctores& myDoc); // sobrecarga del operador de insercion
        string getName();//OUTPUT: el nombre de un objeto tipo Doctores
        string getEspecialidad();//OUTPUT: la especialidad de un objeto tipo Doctores.
        bool getDispDia(int dia);//INPUT: int que representa los dias de la semana (empezando desde el lunes) OUTPUT: la disponibilidad de un dia en especifico
        void asignarCita(int dia, Paciente P);//INPUT: un dia y un paciente. HACE:  cambia la disponibilidad del doctor en ese dia y asigna este paciente a el dia.
        int proximaCitaDisp();//OUTPUT:  el proximo dia libre
};
#endif
