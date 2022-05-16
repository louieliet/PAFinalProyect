#include "MainHeader.h"

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

//Make files:

int MakeIndiceFile(vector<IndiceEstudiante> list){

    fstream outFile{"indice.dat", ios::in | ios::out | ios::binary};

    if(!outFile){
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    for( auto i : list ){
        outFile.seekp( (i.getIndice() - 1) * sizeof(IndiceEstudiante) );
        outFile.write( reinterpret_cast<const char*>(&i), sizeof(IndiceEstudiante) );
    }
    
    return 0;
}

int MakeMateriasFile(vector<Materias> list){

    fstream outFile{"materias.dat", ios::in | ios::out | ios::binary};

    if(!outFile){
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    for( auto i : list ){
        outFile.seekp( (i.getIndice() - 1) * sizeof(Materias) );
        outFile.write( reinterpret_cast<const char*>(&i), sizeof(Materias) );
    }
    
    return 0;
}

int MakeMateriaFile(vector<Materia> list){

    fstream outFile{"materia.dat", ios::in | ios::out | ios::binary};

    if(!outFile){
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    for( auto i : list ){
        outFile.seekp( (i.getIndice() - 1) * sizeof(Materia) );
        outFile.write( reinterpret_cast<const char*>(&i), sizeof(Materia) );
    }
    
    return 0;
}


//Make empty files:

int MakeEmptyIndiceFile(){

    ofstream file{ "indice.dat", ios::out | ios::binary };

    if (!file) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }
    IndiceEstudiante out;

    for(int i=0; i<100; ++i){
        file.write(reinterpret_cast<const char*>(&out), sizeof(IndiceEstudiante));
    }

    return 0;
}

int MakeEmptyMateriasFile(){

    ofstream file{ "materias.dat", ios::out | ios::binary };

    if (!file) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }
    
    Materias out;

    for(int i=0; i<100; ++i){
        file.write(reinterpret_cast<const char*>(&out), sizeof(Materias));
    }

    return 0;
}

int MakeEmptyMateriaFile(){

    ofstream file{ "materia.dat", ios::out | ios::binary };

    if (!file) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    Materia out;

    for(int i=0; i<4; ++i){
        file.write(reinterpret_cast<const char*>(&out), sizeof(Materia));
    }

    return 0;
}

int Calificaciones(){

    char* op;
    cout << "Deme su matricula: " << endl;
    cin >> op;



    return 0;
}


int menu(vector<IndiceEstudiante> list, vector<Materias> materias, vector<Materia> materia){

    int op;
    bool running = true;

    while(running){

        cout << setw(20) << "-- Menu --" << endl;
        cout <<  "1. Crear los archivos " << endl;
        cout <<  "2. Calificaciones individuales " << endl;
        cout <<  "3. Promedio de calificaciones por estudiante " << endl;
        cout <<  "4. Calificacion mas alta por materia " << endl;
        cout <<  "5. Salir " << endl;

        cin >> op;

        switch (op)
        {
        case 1:
            system("cls");
            MakeEmptyIndiceFile();
            MakeEmptyMateriasFile();
            MakeEmptyMateriaFile();
            cout << "Creando archivos..." << endl;
            cout << "Archivos creados, llenado archivos..." << endl;
            MakeIndiceFile(list);
            MakeMateriasFile(materias);
            //MakeMateriaFile(materia);
            cout << "Archivos llenados con exito" << endl;
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            running = false;
            break;
        
        default:
            break;
        }
    }
    
    
    return 0;
}

