#include "Doctores.hpp"

Doctores::Doctores(string newName, string newEspecialidad){
    nombre = newName;
    especialidad = newEspecialidad;
    Paciente Vacio(" ",0, " ");
    citaDia libre(true, Vacio);
    for(int i = 0; i <7; i++){
        disponibilidadSemanal.push_back(libre);
    }
}//constructor parametrizado

ostream& operator<<(ostream& os, Doctores& myDoc){
            string Dias[] = {"Lunes", "Martes","Miércoles","Jueves","Viernes","Sábado","Domingo"};
            os << "Nombre del doctor: " << myDoc.getName() << endl;
            os << "Especialidad del doctor: " << myDoc.getEspecialidad() << endl;
            os << "Horario del doctor: " << endl;
            for(int i = 0; i < 7; i++){
                os << "\nEl día " << Dias[i] << ": ";
                if(myDoc.getDispDia(i) == true){
                    os << "Está libre. " << endl;
                }else{
                    os << "No está libre." << endl;
                }
                if(myDoc.getDispDia(i) == false){
                    os << "\t\tOcupado con el paciente: \n\t\t" << myDoc.disponibilidadSemanal[i].myPaciente.nombre << "\n\t\tCon Nivel de Urgencia: " << myDoc.disponibilidadSemanal[i].myPaciente.nivelUrgencia << endl;
                }
            }
    return os;
}//el operador '<<' sirve para la insercion de objetos tipo Doctores

string Doctores::getName(){
    return nombre;
}//retorna el nombre del doctor

string Doctores::getEspecialidad(){
    return especialidad;
}//retorna la especialidad del doctor

bool Doctores::getDispDia(int dia){
    return disponibilidadSemanal[dia].disponibilidad;
}//retorna si el doctor esta libre o no ese dia

void Doctores::asignarCita(int dia, Paciente Pacientico){
    disponibilidadSemanal[dia].disponibilidad = false;
    disponibilidadSemanal[dia].myPaciente = Pacientico;
}//asigna un paciente a el dia dado dentro del horario del doctor y cambia la disponibilidad del dia

int Doctores::proximaCitaDisp(){
    for(int i = 0; i < 7; i++){
        if(getDispDia(i) == true){
            return i;
        }
    }
    return -1;
}//metodo que retorna entero que representa dia mas proximo de la semana en el cual el doctor tiene disponibilidad
