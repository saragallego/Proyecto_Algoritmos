#include "Doctores.hpp"
#include "citaDia.hpp"

Doctores::Doctores(string newName, string newEspecialidad){
    nombre = newName;
    especialidad = newEspecialidad;
    Paciente Vacio(" ",0, " ");
    citaDia libre(true, Vacio);
    for(int i =0; i <7; i++){
        disponibilidadSemanal.push_back(libre);
    }
}

string Doctores::getName(){
    return nombre;
}

string Doctores::getEspecialidad(){
    return especialidad;
}

