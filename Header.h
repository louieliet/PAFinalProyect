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

void outputLine(ostream& output, const IndiceEstudiante& record) {
    output << left << setw(10) << record.getIndice()
        << setw(16) << record.getMatricula()
        << right << fixed
        << showpoint << endl;
}


int outIndices()
{
    ifstream inIndices{"indice.dat", ios::in | ios::binary};

    if(!inIndices)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    cout << left << setw(10) << "Indice" << setw(16) << "Matricula" 
        << setw(10) << right;

    IndiceEstudiante molde;

    inIndices.read(reinterpret_cast<char*>(&molde),sizeof(IndiceEstudiante));

    while(inIndices){
        if(molde.getIndice() != 0)
        {
            outputLine(cout,molde);
        }

        inIndices.read(reinterpret_cast<char*>(&molde),sizeof(IndiceEstudiante));
    }

    return 0;
}