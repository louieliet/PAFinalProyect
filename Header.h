//Header.h -> En este archivo estarán todas nuestras funciones que utilizaremos para que el código corra
//de manera óptima.


//Incluimos el MainHeader.h, que es donde están las 3 clases necesarias para el código.
#include "MainHeader.h"


//Make empty files:

    //Creamos los archivos: "indice.dat","materias.dat" y "materia.dat" . Decimos que son vacíos pero en realidad no lo son, tienen los atributos predeterminados de las respectivas clases 
    //para que, con la función de Make(archivo)File() pueda llenarlos respecto al tamaño de cada atributo.

    //Las funciones lo primero que hacen, es crear un objeto ofstream para que pueda escrirbir sobre el archivo, si el archivo no se puede abrir, manda la excepción o error de que
    //no se pudo abrir, posterior a esto, crea, en el caso de Indice y Materias, 100 records, en el caso de Materia, 4 records; que son los lugares predeterminados que incluye el archivo, 
    //para que luego sean reemplazados por datos de estudiantes reales.


int MakeEmptyIndiceFile(){

    ofstream file{ "indice.dat", ios::out | ios::binary };

    if (!file) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }
    IndiceEstudiante out;

    for(int i=0; i<MAX_STUDENTS; ++i){
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

    for(int i=0; i<MAX_STUDENTS; ++i){
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

    for(int i=0; i<MAX_CLASSES; ++i){
        file.write(reinterpret_cast<const char*>(&out), sizeof(Materia));
    }

    return 0;
}

//Make files:

    //Cada función, primero con un objeto fstream, lee el archivo correspondiente, para poder escribir sobre él en las posiciones que indique el índice, pues es nuestro valor
    //auxilar para saber dónde está ubicado cada alumno en los archivos, en el caso de Materia, para saber en qué posición se encuentra el nombre y clave de la materia. Dichas posiciones
    //fueron creadas en las funciones de MakeEmptyFile.

int MakeIndiceFile(vector<IndiceEstudiante> list){

    fstream outFile{"indice.dat", ios::in | ios::out | ios::binary};

    if(!outFile){
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < MAX_STUDENTS; i++){
        outFile.seekp((list[i].getIndice()-1) * sizeof(IndiceEstudiante));
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

//Calculate Average:

    //La función calculateProm() recibe un objeto de tipo Materia por referencia, que utilizará para guardar cada calificación de dicho en diferentes variables 
    //de tipo double, que posterior a esto, calcularán el promedio de ese alumno.

double calculateProm(const Materias& student){

    double prom;

    double c1 = student.getc1();
    double c2 = student.getc2();
    double c3 = student.getc3();
    double c4= student.getc4();

    prom = (c1+c2+c3+c4)/4;

    return prom;

}

//output functions:

    //Las dunciones outputx() recibien por referencia diferentes objetos de las clases Materias e IndiceEstudiante para poder imprimir en consola, los datos del
    //alumno que se introduzca. Mediante funciones como set(w), le damos un formato en consola.


void outputLine(ostream& output, const Materias& record, const IndiceEstudiante& list) {
    
    output << left <<setw(20) << "Nombre";
    output << left <<setw(20) << "ID";
	output << setw(5)<<"PA1";
	output << setw(5)<<"POO";
	output << setw(5)<<"MAT";
	output << setw(5) << "ING"
    << endl;
	
    output << left << setw(20) << list.getName()
        << setw(20) << record.getMatricula()
        << setw(5) << record.getc1()
        << setw(5) << record.getc2()
        << setw(5) << record.getc3()
        << setw(5) << record.getc4() << endl;
}

void outputProm(ostream& output, const Materias& record, const IndiceEstudiante& list) {
    
    output << left <<setw(20) << "Nombre";
    output << left <<setw(20) << "Matricula";
	output << setw(5)<< "PROMEDIO" << endl;
	
    output << left << setw(20) << list.getName()
        << setw(20) << list.getMatricula()
        << setw(5) << calculateProm(record) << endl;
}

//Califcaciones por Persona:

    //La función CalificacionesIndividuales() recibe dos vecotres, uno de tipo IndiceEstudiante y otro de tipo Materias.
    //Primero crea dos objetos de tipo ifstream que le servirá para leer dos archivos, en este caso, el de materias.dat e indice.dat
    //Si no puede abrir los archivos, manda diferentes errores, dependiendo de cuál no se haya podido abrir.
    //Posterior a este, introducimos el indice que el estudiante escogió, que utilizará el método para, mediante 2 for's, posicionarse en el índice correcto donde se encuentra
    //el alumno en los dos archivos, mediante la función seekg(), a esta última le pasamos la posición "op-1" multiplicada por el tamaño de la clase IndiceEstudiante, hacemos lo mismo
    //para el segundo archivo, donde se encuentran los demás datos; con el mismo procedimiento.

    //Una vez que se coloca en la posición, lee los datos reinterpretándolos en tipo char* (cadena de caractéres), en el tamaño de sus respectivas
    //clases. Luego, con la función que ya habíamos defido de output, imprime en consola el estudiante hayado.

    //Los for's funcionan de la siguiente forma:
        //Para cada item en las respectivas listas, de cada clase, va a buscar el indice, si lo obtiene, hace lo ya mencionado, y cambiamos el valor de flag, que nos indicará
        //si el estudiante fue hayado, en caso de que este valor no se modifique, significa que no fue hayado, por lo que en otro if, introducimos el error.

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

//Promedio del alumno:

    //La función Promedio() va a recibir igualmente un vector de cada tipo de clase (Indice Estudiante y Materias). El funcionamiento de esta función
    //es muy similar al de CalificacionesIndividuales(), con la diferencia de que, si encuentra al estudiante, llama a la función outputProm(), que recibe al 
    //alumno hayado en los diferentes archivos para imprimirlo en consola.


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

//Alumnos más altos por materia:
    //La función CalifCompair() recibe dos vectores, uno de tipo IndiceEstudiante y otro de tipo Materias. Crea diferentes variables donde, según el tipo,
    //guardará los datos del alumno más alto por persona.
    
    //las variables de tipo double se inicializan en un valor negativo exagerado para que, mediante los ifs dentro de los dos fors, se pueda actualizar el valor de la calificación 
    //más alta en dicha.

    //Los for's funcionan de la siguiente forma:
        //Para cada item en las listas, que son los vectores de cada clase; recorre los objetos de dicha, y mediante los ifs para cada materia, que, si la calificación es mayor a nuestro
        //valor negativo exagerado y si el indice entre las dos listas coincide, guardarmos las variables de cada materia con sus datos, así, ese bloque de código una vez que termine
        //de recorrer los vectores, guardará los datos del alumno más alto por materia en las respectivas variables que creamos antes.

    //Una vez que guardamos los datos del alumno más alto por materia en las variables, mediante un pequeño bloque de código donde asignamos formatos, imprimimos todos
    //esos datos, especificando cada uno de ellos.

int CalifCompair(vector<IndiceEstudiante> list2,vector<Materias> list){
	
    double maxpa  = -999;
	double maxpoo = -999;
	double maxmat = -999;
	double maxing = -999;

    string maxpan = " ";
	string maxpoon = " ";
	string maxmatn = " ";
	string maxingn = " ";

    string maxpaid ;
	string maxpooid;
	string maxmatid;
	string maxingid;
   

    for( auto i : list){
        for ( auto j : list2){
            if((i.getc1())>maxpa && j.getIndice() == i.getIndice()){ 
                maxpa = i.getc1();
                maxpan = j.getName();
                maxpaid = i.getMatricula();
            }
			if((i.getc2())>maxpoo && j.getIndice() == i.getIndice()){ 
                maxpoo = i.getc2();
                maxpoon = j.getName();
                maxpooid = i.getMatricula();
            }
			if((i.getc3())>maxmat && j.getIndice() == i.getIndice()){ 
                maxmat = i.getc3();
                maxmatn = j.getName();
                maxmatid = i.getMatricula();
            }
			if((i.getc4())>maxing && j.getIndice() == i.getIndice()){ 
                maxing = i.getc4();
                maxingn=j.getName();
                maxingid = i.getMatricula();
            }
        }
    }

    cout << left << setw(20) << "Materia" << setw(20) << "Nombre" << setw(20) << "ID" << setw(20) << "Calificacion" << endl;
    cout << left << setw(20) << "ProgramacionAv" << setw(20) << maxpan <<  setw(20) << maxpaid << setw(20) << maxpa << endl;
    cout << left << setw(20) << "ProgramacionOr" << setw(20) << maxpoon <<  setw(20) << maxpooid << setw(20) << maxpoo << endl;
    cout << left << setw(20) << "Matematicas" << setw(20) << maxmatn <<  setw(20) << maxmatid << setw(20) << maxmat << endl;
    cout << left << setw(20) << "Ingles" << setw(20) << maxingn <<  setw(20) << maxingid << setw(20) << maxing << endl;

}

//Main menu:

    //La función menu() recibe un vector de cada clase de nuesro MainHeader.h, que le servirán para poder pasar todos los datos de los objetos que incluyan dichos, a las funciones correspondientes.
    //La finalidad de menu() es imprimir en consola un menú donde el usuario pueda decidir la operación que desea hacer, mediante una leída de la opción que desea, un switch
    //manda a llamar a la fución de la opción que decidió el usuario.

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
            cout << "Introduzca una opción válida" << endl;
            break;
        }
    }
    
    return 0;
}

