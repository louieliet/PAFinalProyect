#include "MainHeader.h"


double califRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int menu(){
    int x;
    cout << "1. Ver Personas" << endl;
    cout << "2. Buscar Persona" << endl;
    cout << "3. Salir" << endl;
    cin >> x;
    return x;

}

void verRegistros(ifstream &Lec){
    string id;
    int indice;

    Lec.open("indice.dat",ios::in);
    Lec >> indice;
    cout << "-- Registro -- " << endl;
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
    Lec.open("indice.dat",ios::in);
    system("cls");
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

void makeIndiceFile(ofstream &es, vector<IndiceEstudiante> list){
    
    es.open("indice.dat",ios::out);

    for(auto i:list){
        es << setw(20) << i.getName() << setw(10) <<i.getIndice() << setw(10) << i.getMatricula() << endl;
    }
    es.close();
}

void makeMateriasFile(ofstream &es, vector<Materias> list){
    
    es.open("materias.dat",ios::out);

    for(auto i:list){
        i.getCalifs(es);
    }
    es.close();
}