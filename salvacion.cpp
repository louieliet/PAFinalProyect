#include <iostream>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <fstream>  
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

using namespace std;

int menu(){
    int x;
    cout << "1. Agregar Persona" << endl;
    cout << "2. Ver Personas" << endl;
    cout << "3. Buscar Persona" << endl;
    cin >> x;
    return x;

}

void agregar(ofstream &es){
    string id;
    int indice;
    es.open("example.txt",ios::out | ios::app);
    cout << "Indice" << endl;
    cin >> indice;
    cout << "ID" << endl;
    cin >> id;
    es << setw(2) << indice << setw(10) << id << endl;
    es.close();
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

int main(){
    ofstream Esc;
    ifstream Lec;
    int op;
    do{
        op = menu();
        switch (op)
        {
        case 1:
            agregar(Esc);
            break;
        case 2:
            verRegistros(Lec);
            break;
        case 3:
            search(Lec);
            break;
        default:
            break;
        }
    }while(op!=4);
    return 0;
}