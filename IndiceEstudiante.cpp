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
    IndiceEstudiante(int indice = 0, const std::string & matricula = "12345678") {
        this -> indice = indice;
        setMatricula(matricula);
    }
    void setMatricula(const std::string & matricula) {
        size_t length {matricula.size()};
        length = (length < 8 ? length : 7);
        matricula.copy(this -> matricula, length);
        this -> matricula[length] = '\0'; 
    }
    int getIndice() const {return indice;}
private: 
    char matricula[8];
    int indice;
};