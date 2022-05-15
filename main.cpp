#include "Header.h"

int main(){

    ofstream Esc;
    ifstream Lec;
    int op;
    map<string,string> namesandids;
    vector<IndiceEstudiante> listaIndices;
    vector<Materias> listaMaterias;

    namesandids["Emiliano_Montes"] = "0241718";
    namesandids["Lizbeth_Trujillo"] = "0241719";
    namesandids["Ariana_Rodriguez"] = "0241720";

    for(auto i = namesandids.begin(); i != namesandids.end(); i++){

        string name = i->first;
        string id = i->second;
        int indice = rand() % 100;
        double calif1 = califRand(1,10);
        double calif2 = califRand(1,10);
        double calif3 = califRand(1,10);
        double calif4 = califRand(1,10);

        IndiceEstudiante modeloI(indice,id,name);
        listaIndices.push_back(modeloI);
        Materias modeloM(id,calif1,calif2,calif3,calif4);
        listaMaterias.push_back(modeloM);
            
    }


    MakeEmptyIndiceFile(Esc);
    CrearArchivoIndice();
    return 0;


    /*makeIndiceFile(Esc,listaIndices);
    makeMateriasFile(Esc,listaMaterias);

    do{
        op = menu();
        switch (op)
        {
        case 1:
            verRegistros(Lec);
            break;
        case 2:
            search(Lec);
            break;
        default:
            break;
        }
        
    } while(op!=3);
    */
    return 0;
}