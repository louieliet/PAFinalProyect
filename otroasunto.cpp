// Fig. 14.10: Fig14_10.cpp

// Creating a randomly accessed file.

#include <iostream>

#include <fstream>  

#include <cstdlib> 

#include "ClientData.h" // ClientData class definition

#include "indice.h"

using namespace std;



int fig1410() {

    

    ofstream outIndice{ "indice.dat", ios::out | ios::binary };



    // exit program if ofstream could not open file

    if (!outIndice) {

        cerr << "File could not be opened." << endl;

        exit(EXIT_FAILURE);

    }



    IndiceEstudiante indiceEstudiante; // constructor zeros out each data member

    cout << sizeof(IndiceEstudiante) << endl;



    // output 100 blank records to file

    for (int i{ 0 }; i < 100; ++i) {

        outIndice.write(

            reinterpret_cast<const char*>(&indiceEstudiante), sizeof(IndiceEstudiante));

    }

   string matricula;

    int indice;

    // Leer el indice para el estudiante



    // Comprobar que es correcto y leer la matricula

    cout << "Escriba su indice ";

    cin >> indice; // leer el indice



   // student enters information, which is copied into file

    while (indice > 0 && indice <= 100) {

        // leemos la matricula

        cout << "Escriba su matrícula ";

        cin >> matricula;

        



        // creamos el objeto de clase IndiceEstudiante

        IndiceEstudiante estudiante{ indice, matricula};



        // buscar posición en el archivo indice.dat   

        outIndice.seekp(

            (estudiante.getIndice() - 1) * sizeof(IndiceEstudiante));





        // write user-specified information in file                  

        outIndice.write(

            reinterpret_cast<const char*>(&estudiante), sizeof(IndiceEstudiante));



        // Entramos otro estudiante

        cout << "Escriba el indice? ";

        cin >> indice;

    }



    return 0;

}



