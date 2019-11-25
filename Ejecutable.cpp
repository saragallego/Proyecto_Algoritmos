#include "Paciente.hpp"
#include "Doctores.hpp"
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <fstream>
#include <stdlib.h>
using namespace std;

bool checkEspecialidadesRepetidas(string esp, vector<Doctores> vec){
    for(int i = 0; i < vec.size(); i++){
        if(esp == vec[i].getEspecialidad()){
            return false;
        }
    }
    return true;
}


void citasMedicas(){
    vector<string> nombres;
    nombres.push_back("Dr. Carlos Rodríguez");
    nombres.push_back("Dr. Juan Gómez");
    nombres.push_back("Dr. Pablo López");
    nombres.push_back("Dr. Santiago González");
    nombres.push_back("Dra. Laura García");
    nombres.push_back("Dra. Daniela Martínez");
    nombres.push_back("Dra. Sandra Ramírez");
    nombres.push_back("Dra. Paola Sánchez");
    nombres.push_back("Dr. Manuel Hernández");
    nombres.push_back("Dr. Julian Díaz");

    int myRand = 0;
    //CREACION PACIENTES
    cout << "\n\n\n\n\n";
    cout << "Ingrese los datos de los pacientes a los que se les agendará una cita médica." << endl;
    vector<Paciente> misPacientesVec;
    priority_queue<Paciente> misPacientesQueue;
    string name;
    int urg;
    string desc;
    bool more = true;
    while(more){
        cout << "\nIngrese el nombre del paciente\n";
        getline(cin, name);
        cout << "Ingrese el nivel de urgencia.\n";
        cin >> urg;
        cin.ignore();
        cout << "Ingrese la descripción de los síntomas. \n";
        getline(cin, desc);
        Paciente P(name, urg, desc);
        P.descripcion += " .";
        misPacientesQueue.push(P);
        string resp;
        cout << "\nDesea agregar más pacientes?" << endl;
        cin >> resp;
        cin.ignore();
        if(resp == "si"){
            more = true;
        }else{
            more = false;
        }
    }
    int pqSize = misPacientesQueue.size();
    for(int i = 0; i < pqSize; i++){
        misPacientesVec.push_back(misPacientesQueue.top());
        misPacientesQueue.pop();
    }

    // CREACION DOCTORES
    vector<Doctores> misDoctores;
    for(int i = 0; i < misPacientesVec.size(); i++){
        if(checkEspecialidadesRepetidas(misPacientesVec[i].getEspecialidadPaciente(), misDoctores)){
            Doctores D(nombres[nombres.size()-1],misPacientesVec[i].getEspecialidadPaciente());
            misDoctores.push_back(D);
            nombres.pop_back();
        }
    }
    cout << "\n\n\n\n\nLos Doctores solicitados son: \n\n";
    for(int i = 0; i < misDoctores.size(); i++){
        cout << misDoctores[i].getName() << ". Su especialidad es: "<< misDoctores[i].getEspecialidad() <<endl << endl;
    }


    //ASIGNACION CITAS POR ORDEN DE LLEGADA Y PRIORIDAD
    for(int i = 0; i < misPacientesVec.size(); i ++){
        string esp = misPacientesVec[i].getEspecialidadPaciente();
        for(int o = 0; o < misDoctores.size(); o++){
            if(esp == misDoctores[o].getEspecialidad()){
                misDoctores[o].asignarCita(misDoctores[o].proximaCitaDisp(), misPacientesVec[i]);
            }
        }
    }
    for(int i = 0; i < misDoctores.size(); i++){
        string nombreArchivo = misDoctores[i].getName();
        nombreArchivo+=".txt";
        ofstream file;
        file.open(nombreArchivo);
        file << misDoctores[i];
        file.close();
    }


    cout << "\n\nLos horarios de los doctores son: \n\n";
    for(int i = 0; i < misDoctores.size(); i++){
        cout << misDoctores[i] << endl << endl;
    }

    cout << "\nSe crearon correctamente los archivos con los horarios de los doctores.\n\n\n";

}

int main(){

    citasMedicas();


    return 0;
}
