#include "Doctores.hpp"

Doctores::Doctores(string newName, string newEspecialidad){
    nombre = newName;
    especialidad = newEspecialidad;
    Paciente Vacio(" ",0, " ");
    citaDia libre(true, Vacio);
    for(int i = 0; i <7; i++){
        disponibilidadSemanal.push_back(libre);
    }
}

ostream& operator<<(ostream& os, Doctores& myDoc){
            string Dias[] = {"Lunes", "Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};
            os << "Nombre del doctor: " << myDoc.getName() << endl;
            os << "Especialidad del doctor: " << myDoc.getEspecialidad() << endl;
            os << "Horario del doctor: " << endl;
            for(int i = 0; i < 7; i++){
                os << "\nEl dia " << Dias[i] << ": ";
                if(myDoc.getDispDia(i) == true){
                    os << "Está libre. " << endl;
                }else{
                    os << "No está libre." << endl;
                }
                if(myDoc.getDispDia(i) == false){
                    os << "\n\t\tOcupado con el paciente: \n\t\t\t" << myDoc.disponibilidadSemanal[i].myPaciente.nombre << "\n\t\tCon Nivel de Urgencia: " << myDoc.disponibilidadSemanal[i].myPaciente.nivelUrgencia << endl;
                }
            }
    return os;
}

string Doctores::getName(){
    return nombre;
}

string Doctores::getEspecialidad(){
    return especialidad;
}

bool Doctores::getDispDia(int dia){
    return disponibilidadSemanal[dia].disponibilidad;
}

void Doctores::asignarCita(int dia, Paciente P){
    disponibilidadSemanal[dia].disponibilidad = false;
    disponibilidadSemanal[dia].myPaciente = P;
}

int Doctores::proximaCitaDisp(){
    for(int i = 0; i < 7; i++){
        if(getDispDia(i) == true){
            return i;
        }
    }
    return -1;
}
