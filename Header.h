#include "MainHeader.h"


double califRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

/*int menu(){
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
}*/


void CrearArchivoIndice(){

    fstream outFile{"indice.dat", ios::in | ios::out | ios::binary};
    if(!outFile){
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Enter indice(1 to 100, 0 to end input)\n? ";

    int indice;
    string matricula;
    string name;

    cin >> indice;

    while (indice > 0 && indice <= 100) {

        cout << "Enter name and id\n? ";
        cin >> name;
        cin >> matricula;

        IndiceEstudiante client{ indice, matricula, name};

        outFile.seekp((client.getIndice() - 1) * sizeof(IndiceEstudiante));          
        outFile.write(reinterpret_cast<const char*>(&client), sizeof(IndiceEstudiante));

        cout << "Enter account number\n? ";
        cin >> indice;
    }


}

void MakeEmptyIndiceFile(ofstream &es){

    es.open("indice.dat",ios::out);

    IndiceEstudiante out;

    for(int i=0; i<100; i++){
        es.write(reinterpret_cast<const char*>(&out), sizeof(IndiceEstudiante));
    }
}

