#include <iostream>
#include <string>
#include <fstream> 
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

class IndiceEstudiante
{
public:
    IndiceEstudiante(int indice=0, const string& = " ")
    {
        this -> indice = indice;
        this -> matricula = " ";
    }
    void setMatricula(const string& matricula)
    {   
        this->matricula = matricula;
    }
    void setIndice(const int indice)
    {   
        this->indice = indice;
    }
private:
    int indice;
    string matricula;
    
};