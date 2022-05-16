#include "MainHeader.h"

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

//Read files:
double calculateProm(const Materias& student){

    double prom;

    double c1 = student.getc1();
    double c2 = student.getc2();
    double c3 = student.getc3();
    double c4= student.getc4();

    prom = (c1+c2+c3+c4)/4;

    return prom;

}

void outputLine(ostream& output, const Materias& record) {
    
    output << left <<setw(9) << "ID";
	output << setw(5)<<"PA1";
	output << setw(5)<<"POO";
	output << setw(5)<<"MAT";
	output << setw(5) << "ING"
    << endl;
	
    output << left << setw(9) << record.getMatricula()
        << setw(5) << record.getc1()
        << setw(5) << record.getc2()
        << setw(5) << record.getc3()
        << setw(5) << record.getc4() << endl;
}

void outputProm(ostream& output, const Materias& record) {
    
    output << left <<setw(9) << "ID";
	output << setw(5)<< "PROMEDIO" << endl;
	
    output << left << setw(9) << record.getMatricula()
        << setw(5) << calculateProm(record) << endl;
}


int CalificacionesIndividuales(vector<Materias> list){

    ifstream file{"materias.dat", ios::in | ios::binary};

    if (!file) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    int op, flag;
    cout << "Deme el indice" << endl;
	cin>> op;
    flag = 0;
		
    for( auto i : list)
    {
        if(i.getIndice() == op){
            file.seekg((op-1)*sizeof(Materias));
            file.read(reinterpret_cast<char*>(&i),sizeof(Materias));
            outputLine(cout,i);  
            flag = 1;  
        }
    }
    if(flag == 0){
        cout << "Eror, ese estudiante no existe" << endl;
    }

    return 0;
}

int Promedio(vector<Materias> list){

    ifstream file{"materias.dat", ios::in | ios::binary};

    if (!file) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    int op, flag;
    cout << "Deme el indice" << endl;
	cin>> op;
    flag = 0;
		
    for( auto i : list)
    {
        if(i.getIndice() == op){
            file.seekg((op-1)*sizeof(Materias));
            file.read(reinterpret_cast<char*>(&i),sizeof(Materias));
            outputProm(cout,i);  
            flag = 1;  
        }
    }
    if(flag == 0){
        cout << "Eror, ese estudiante no existe" << endl;
    }

    return 0;
    


}

//Main menu:
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
            MakeMateriaFile(materia);
            cout << "Archivos llenados con exito" << endl;
            break;
        case 2:
            system("cls"); 
            CalificacionesIndividuales(materias);
            break;
        case 3:
            system("cls");
            Promedio(materias);
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

