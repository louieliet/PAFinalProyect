#include "MainHeader.h"

int makeIndiceEmptyFile()
{
    ofstream outIndiceFile{"indice.dat", ios::out};

    if(!outIndiceFile){
        cerr << "El archivo no pudo ser abierto" << endl;
        exit(EXIT_FAILURE);
    }

    IndiceEstudiante estudiante;

    for (int i{ 0 }; i < 100; ++i) {
        outIndiceFile.write(
            reinterpret_cast<const char*>(&estudiante), sizeof(IndiceEstudiante));
    }

    return 0;
}

int makeIndices(vector<IndiceEstudiante> v1)
{
    fstream outIndiceFile{"indice.dat", ios::in | ios::out | ios::binary};

    if(!outIndiceFile){
        cerr << "El archivo no pudo ser abierto" << endl;
        exit(EXIT_FAILURE);
    }

    for(auto i:v1)
    {
        outIndiceFile.seekp(i.getIndice()-1 * sizeof(IndiceEstudiante));
        outIndiceFile.write(reinterpret_cast<const char*>(&i), sizeof(IndiceEstudiante));
    }
    
}