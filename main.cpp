#include "Header.h"

int main(){

    vector<IndiceEstudiante> list;

    map<int,string> ind;
    map<int,string>::iterator i;
    ind[1] = "0241718";
    ind[5] = "0241718";
    ind[10] = "0243165";
    ind[2] = "0246521";
    

    for(i=ind.begin(); i != ind.end(); i++){
        
        string id = i->second;
        int indice = i->first;

        IndiceEstudiante modelo(indice,id);

        list.push_back(modelo);

    }

    ofstream Esc;
    ifstream Lec;
    int op;

    agregar(Esc,list);

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
        
    }while(op!=3);
    return 0;
}
