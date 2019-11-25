#include "Paciente.hpp"
#include <vector>

Paciente::Paciente(){
    nombre = " ";
    nivelUrgencia = 0;
    descripcion = " ";
}//constructor

ostream& operator<<(ostream& os, Paciente& myPaciente){
    os << "Nombre: " <<myPaciente.nombre << endl;
    os << "Nivel de Urgencia: "<<myPaciente.nivelUrgencia << endl;
    os << "Descripcion de los síntomas: "<<myPaciente.descripcion << endl;
    return os;
}//el operador '<<' sirve para la insercion de un objeto de este tipo

Paciente::Paciente(string Name, int Level, string Description){
    nombre = Name;
    nivelUrgencia = Level;
    descripcion = Description;
}//constructor parametrizado

bool Paciente::operator<(const Paciente B)const{
    if(nivelUrgencia < B.nivelUrgencia){
        return true;
    }else{
        return false;
    }
}//el operador '<' compara los niveles de urgencia de los pacientes

bool Paciente::operator>(const Paciente B){
    if(nivelUrgencia > B.nivelUrgencia){
        return true;
    }else{
        return false;
    }
}//el operador '>' compara los niveles de urgencia de los pacientes

void Paciente::operator=(const Paciente P){
    nombre = P.nombre;
    nivelUrgencia = P.nivelUrgencia;
    descripcion = P.descripcion;
}//el operadpr '=', sirve como operador de asignacion

string Paciente::getEspecialidadPaciente()const{
    string especialidades[7] = {"Oftalmología", "Cardiología", "Neurología", "Gastroenterología", "Traumatología","Neumología", "General"};
    int numDePalabras = 0;
    vector<string> Palabras;
    string word = "";
    int index = 0;
    string des = descripcion;
    if(des.at(des.size()-1) != ' '){
        des += " ";
    }
    for(int i = 0; i < des.size(); i++){
        char x = des.at(i);
        if(x == ' '){
            //cout << "\npalabra: "<<word;
            numDePalabras++;
            Palabras.push_back(word);
            word = "";
        }else if(x == ','){
            continue;
        }else{
            word = word + x;
        }
     }
     int vals[7] = {0,0,0,0,0,0,0};
     for(int i = 0; i < numDePalabras; i++){
         if(Palabras[i] == "ojos" || Palabras[i]=="ojo" ||Palabras[i]=="parpado" || Palabras[i]=="pupilas" || Palabras[i] == "iris" || Palabras[i]=="ceguera"){
             vals[0]++;
         }//oftalmologia
         else if(Palabras[i] == "corazon" || Palabras[i]=="desmayo" || Palabras[i]=="presion" || Palabras[i] == "taquicardia" || Palabras[i]=="pecho"){
             vals[1]++;
         }//cardiologia
         else if(Palabras[i] == "cabeza" || Palabras[i]=="cerebro" || Palabras[i]=="tics" || Palabras[i] == "mareo" || Palabras[i]=="temblor" || Palabras[i]=="migraña"){
             vals[2]++;
         }//neurologia
         else if(Palabras[i] == "estomago" || Palabras[i]=="diarrea" || Palabras[i]=="vomito" || Palabras[i] == "gastritis" || Palabras[i]=="apetito"){
            vals[3]++;
        }//gastroenterologia
        else if(Palabras[i] == "huesos" ||Palabras[i] == "hueso" || Palabras[i]=="musculo" || Palabras[i]=="golpe" || Palabras[i] == "fractura" || Palabras[i]=="lesion"){
            vals[4]++;
        }//traumatologoa
        else if(Palabras[i] == "pulmones" || Palabras[i]=="nariz" || Palabras[i]=="respirar" || Palabras[i] == "congestion" || Palabras[i]=="flema" || Palabras[i]=="tos"){
            vals[5]++;
        }//neumologia
        else if (Palabras[i]=="general"){
            vals[6]++;
        }//general
     }
     if(vals[0]>=vals[1] && vals[0]>=vals[2] && vals[0]>=vals[3] && vals[0]>=vals[4] && vals[0]>=vals[5] && vals[0]>=vals[6]){
         return especialidades[0];
     }else if(vals[1]>=vals[0] && vals[1]>=vals[2] && vals[1]>=vals[3] && vals[1]>=vals[4] && vals[1]>=vals[5] && vals[1]>=vals[6]){
         return especialidades[1];
     }else if(vals[2]>=vals[0] && vals[2]>=vals[1] && vals[2]>=vals[3] && vals[2]>=vals[4] && vals[2]>=vals[5] && vals[2]>=vals[6]){
         return especialidades[2];
     }else if(vals[3]>=vals[0] && vals[3]>=vals[1] && vals[3]>=vals[2] && vals[3]>=vals[4] && vals[3]>=vals[5] && vals[3]>=vals[6]){
         return especialidades[3];
     }else if(vals[4]>=vals[0] && vals[4]>=vals[1] && vals[4]>=vals[2] && vals[4]>=vals[3] && vals[4]>=vals[5] && vals[4]>=vals[6]){
         return especialidades[4];
     }else if(vals[5]>=vals[0] && vals[5]>=vals[1] && vals[5]>=vals[2] && vals[5]>=vals[3] && vals[5]>=vals[4] && vals[5]>=vals[6]){
         return especialidades[5];
     }else if(vals[6]>=vals[0] && vals[6]>=vals[1] && vals[6]>=vals[2] && vals[6]>=vals[3] && vals[6]>=vals[4] && vals[6]>=vals[5]){
         return especialidades[6];
     }


     return especialidades[6];
}//retorna la especialidad que necesita el paciente, dada su descripcion.
