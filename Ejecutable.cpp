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
    nombres.push_back("Dr. Carlos");
    nombres.push_back("Dr. Juan");
    nombres.push_back("Dr. Pablo");
    nombres.push_back("Dr. Santiago");
    nombres.push_back("Dra. Laura");
    nombres.push_back("Dra. Daniela");
    nombres.push_back("Dra. Sandra");
    nombres.push_back("Dra. Paola");
    nombres.push_back("Dr. Manuel");
    nombres.push_back("Dr. Julian");

    int myRand = 0;
    //CREACION PACIENTES
    cout << "\n\n\n\n\n";
    cout << "ingrese datos de pacientes a los cuales se les agendara cita." << endl;
    vector<Paciente> misPacientesVec;
    priority_queue<Paciente> misPacientesQueue;
    string name;
    int urg;
    string desc;
    bool more = true;
    while(more){
        cin.ignore();
        cout << "\nIngrese el nombre del paciente\n";
        getline(cin, name);
        cout << "Ingrese el nivel de urgencia.\n";
        cin >> urg;
        cin.ignore();
        cout << "Ingrese la descripcion de los sintomas. \n";
        getline(cin, desc);
        Paciente P(name, urg, desc);
        P.descripcion += " .";
        misPacientesQueue.push(P);
        string resp;
        cout << "\ndesea agregar mas pacientes?" << endl;
        cin >> resp;
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
    cout << "\n\nLos Doctores solicitados son: \n\n\n";
    for(int i = 0; i < misDoctores.size(); i++){
        cout << misDoctores[i].getName() << " y su especialidad es: "<< misDoctores[i].getEspecialidad() <<endl << endl;
    }
    

    //ASIGNACION CITAS POR ORDEN DE LLEGADA
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

    
    cout << "\n\nLos horarios de los doctores ahora son: \n\n\n";
    for(int i = 0; i < misDoctores.size(); i++){
        cout << misDoctores[i] << endl << endl;
    }
    
    cout << "\nSe crearon correctamente los archivos con los horarios de los doctores.\n\n\n"; 

}

int main(){
    
    citasMedicas();


    return 0;
}
