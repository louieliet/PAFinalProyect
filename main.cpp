#include "Header.h"

int main(){

    vector<IndiceEstudiante> ilist;
    vector<Materias> mlist;
    ofstream Esc;
    ifstream Lec;
    int op;

    map<int,string> ind;
    map<int,string>::iterator i;

    ind[1] = "0241718";
    ind[5] = "0241718";
    ind[10] = "0243165";
    ind[2] = "0246521";

    for(i=ind.begin(); i != ind.end(); i++){
        
        string id = i->second;
        int indice = i->first;

        IndiceEstudiante imodelo(indice,id);
        Materias mmodelo(id,9.5,7.7,8.3,5.6);

        ilist.push_back(imodelo);
        mlist.push_back(mmodelo);

    }


    makeIndiceFile(Esc,ilist);
    makeMateriasFile(Esc,mlist);

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

    return 0;
}
