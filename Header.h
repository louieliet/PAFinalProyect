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

void outputLine(ostream& output, const Materias& record, const IndiceEstudiante& list) {
    
    output << left <<setw(20) << "Nombre";
	output << setw(5)<<"PA1";
	output << setw(5)<<"POO";
	output << setw(5)<<"MAT";
	output << setw(5) << "ING"
    << endl;
	
    output << left << setw(20) << list.getName()
        << setw(5) << record.getc1()
        << setw(5) << record.getc2()
        << setw(5) << record.getc3()
        << setw(5) << record.getc4() << endl;
}

void outputProm(ostream& output, const Materias& record, const IndiceEstudiante& list) {
    
    output << left <<setw(20) << "Nombre";
	output << setw(5)<< "PROMEDIO" << endl;
	
    output << left << setw(20) << list.getName()
        << setw(5) << calculateProm(record) << endl;
}

int CalificacionesIndividuales(vector<IndiceEstudiante> list2,vector<Materias> list){

    ifstream file1{"materias.dat", ios::in | ios::binary};
    ifstream file2{"indice.dat", ios::in | ios::binary};

    if (!file1) {
        cerr << "File 1 could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    if (!file2) {
        cerr << "File 2 could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    int op, flag;
    cout << "Deme el indice" << endl;
	cin>> op;
    flag = 0;


    for( auto j : list2 ){

        for( auto i : list){
            if(i.getIndice() == op){
                file2.seekg((op-1)*sizeof(IndiceEstudiante));
                file1.seekg((op-1)*sizeof(Materias));
                file1.read(reinterpret_cast<char*>(&i),sizeof(Materias));
                file2.read(reinterpret_cast<char*>(&j),sizeof(IndiceEstudiante));
                outputLine(cout,i,j);  
                flag = 1;  
            }
        }
        if(flag == 0){
            cout << "Eror, ese estudiante no existe" << endl;
        }
        if(flag = 1){
            break;
        }
    }


    return 0;
}

int Promedio(vector<IndiceEstudiante> list2, vector<Materias> list){

    ifstream file1{"materias.dat", ios::in | ios::binary};
    ifstream file2{"indice.dat", ios::in | ios::binary};

    if (!file1) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    if (!file2) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    int op, flag;
    cout << "Deme el indice" << endl;
	cin>> op;
    flag = 0;
		
    for( auto j : list2 ){

        for( auto i : list){
            if(i.getIndice() == op){
                file2.seekg((op-1)*sizeof(IndiceEstudiante));
                file1.seekg((op-1)*sizeof(Materias));
                file1.read(reinterpret_cast<char*>(&i),sizeof(Materias));
                file2.read(reinterpret_cast<char*>(&j),sizeof(IndiceEstudiante));
                outputProm(cout,i,j);  
                flag = 1;  
            }
        }
        if(flag == 0){
            cout << "Eror, ese estudiante no existe" << endl;
        }
        if(flag = 1){
            break;
        }
    }

    return 0;

}


int CalifCompair(vector<IndiceEstudiante> list2,vector<Materias> list){
	
    double maxpa  = -999;
	double maxpoo = -999;
	double maxmat = -999;
	double maxing = -999;
    string maxpan = " ";
	string maxpoon = " ";
	string maxmatn = " ";
	string maxingn = " ";
   

    for( auto i : list){
        for ( auto j : list2){
            if((i.getc1())>maxpa && j.getIndice() == i.getIndice()){ 
                maxpa = i.getc1();
                maxpan = j.getName();
            }
			 if((i.getc2())>maxpoo && j.getIndice() == i.getIndice()){ 
                maxpoo = i.getc2();
                maxpoon = j.getName();
            }
			 if((i.getc3())>maxmat && j.getIndice() == i.getIndice()){ 
                maxmat = i.getc3();
                maxmatn = j.getName();
            }
			 if((i.getc4())>maxing && j.getIndice() == i.getIndice()){ 
                maxing = i.getc4();
                maxingn=j.getName();
            }

        }
    }

    cout << left << setw(20) << "Materia" << setw(20) << "Nombre" <<  setw(20) << "Calificacion" << endl;
    cout << left << setw(20) << "ProgramacionAv" << setw(20) << maxpan <<  setw(20) << maxpa << endl;
    cout << left << setw(20) << "ProgramacionOr" << setw(20) << maxpoon <<  setw(20) << maxpoo << endl;
    cout << left << setw(20) << "Matematicas" << setw(20) << maxmatn <<  setw(20) << maxmat << endl;
    cout << left << setw(20) << "Ingles" << setw(20) << maxingn <<  setw(20) << maxing << endl;





}

//Main menu:

int menu(vector<IndiceEstudiante> list, vector<Materias> materias, vector<Materia> materia){

    int op;
    bool running = true;

    while(running){

        system("Pause");
        system("cls");
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
            CalificacionesIndividuales(list,materias);
            break;
        case 3:
            system("cls");
            Promedio(list,materias);
            break;
        case 4:
			system("cls");
			CalifCompair(list,materias);
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

