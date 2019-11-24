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
            string Dias[] = {"lunes", "martes","miercoles","jueves","viernes","sabado","domingo"};
            os << "Nombre del doctor: " << myDoc.getName() << endl;
            os << "Especialidad del doctor: " << myDoc.getEspecialidad() << endl;
            for(int i = 0; i < 7; i++){
                os << "\nEn el dia " << Dias[i] << ":\n";
                if(myDoc.getDispDia(i) == true){
                    os << "\tEstá libre. " << endl;
                }else{
                    os << "\tNo está libre." << endl;
                }
                if(myDoc.getDispDia(i) == false){
                    os << "\t\tOcupado con el paciente: \n\t\t\t" << myDoc.disponibilidadSemanal[i].myPaciente.nombre << "\n\t\tcon nivel de urgencia: " << myDoc.disponibilidadSemanal[i].myPaciente.nivelUrgencia;
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