#include "MainHeader.h"

int menu(){
    int x;
    cout << "1. Ver Personas" << endl;
    cout << "2. Buscar Persona" << endl;
    cin >> x;
    return x;

}

void verRegistros(ifstream &Lec){
    string id;
    int indice;

    Lec.open("example.txt",ios::in);
    Lec >> indice;
    while (!Lec.eof()){
        Lec >> id;
        cout << "Indice: " << indice << endl;
        cout << "ID: " << id << endl;
        Lec >> indice;
    }
    Lec.close();

}

void search(ifstream &Lec){
    string id;
    int indice, indicesearched;
    bool finded;
    Lec.open("example.txt",ios::in);
    cout << "Introduzca el indice" << endl;
    cin >> indicesearched;
    Lec>>indice;
    while(!Lec.eof() && !finded){
        Lec>>id;
        if(indice == indicesearched){
            cout << "ID:" << id << endl;
            finded = true;
        }
        Lec>>indice;

    }
    Lec.close();

    if(!finded)
        cout << "No se encontró" << endl;
}

void agregar(ofstream &es, vector<IndiceEstudiante> list){
    
    es.open("example.txt",ios::out | ios::app);

    for(auto i:list){
        es << setw(2) << i.getIndice() << setw(10) << i.getMatricula() << endl;
    }
    es.close();
}