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


int CrearArchivoIndice(){

    fstream outFile{"indice.dat", ios::in | ios::out | ios::binary};

    if(!outFile){
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    IndiceEstudiante s1(1,"0241718","EmilianoMontesGomez");
    IndiceEstudiante s2(2,"0241719","LizbethTrujilloSalgado");
    IndiceEstudiante s3(50,"0241720","ArianaRodriguezCastaneda");

    vector<IndiceEstudiante> list = {s1,s2,s3};

    for( auto i : list ){
        outFile.seekp( (i.getIndice() - 1) * sizeof(IndiceEstudiante) );
        outFile.write( reinterpret_cast<const char*>(&i), sizeof(IndiceEstudiante) );
    }
    
    return 0;
}

void MakeEmptyIndiceFile(){

    ofstream file{ "indice.dat", ios::out | ios::binary };

    if (!file) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }
    IndiceEstudiante out;

    for(int i=0; i<100; ++i){
        file.write(reinterpret_cast<const char*>(&out), sizeof(IndiceEstudiante));
    }
}

