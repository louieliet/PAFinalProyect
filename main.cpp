#include "Header.h"

int main()
{
    vector<IndiceEstudiante> list;
    map<const string,int> ind;
    map<const string,int>::iterator i;

    ind["0243165"] = 1;
    ind["0246723"] = 2;
    ind["0241721"] = 3;
    ind["0241722"] = 4;
    ind["0241788"] = 5;
    ind["0241724"] = 6;
    ind["0241725"] = 7;
    ind["0241726"] = 8;
    ind["0241727"] = 9;
    ind["0241728"] = 10;
    ind["0241718"] = 11;

    for(i = ind.begin(); i != ind.end(); i++)
    {
        string matricula = i->first;
        int indice = i->second;

        IndiceEstudiante molde(indice,matricula);
        list.push_back(molde);

    }

    cout << "Create the Indice file" << endl;
    makeIndiceEmptyFile();
    cout << "Fill the Indice file " << endl;
    


}