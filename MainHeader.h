#include <iostream>
#include <fstream>  
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
using namespace std;

class IndiceEstudiante {
public:
	IndiceEstudiante(int indice = 65536, const string& matricula = "1234567") {
		this->indice = indice;
		setMatricula(matricula);

	}
	void setMatricula(const string& matricula) {

		size_t length{ matricula.size() };
		length = (length < 8 ? length : 7);
		matricula.copy(this->matricula, length);
		this->matricula[length] = '\0'; 

	}

	int getIndice() const {return indice;}
	string getMatricula() const {return matricula;}

private:
	int indice;
	char matricula[8];
	
};


class Materias
{
public:
	Materias(const string& materia = "NUL", double calif = 0.0)
	{
		this-> calif = calif;
		setMateria(materia);
	}
	void setMateria(const string& materia){

		size_t length{ materia.size() };
		length = (length < 3 ? length : 2);
		materia.copy(this->materia, length);
		this->materia[length] = '\0'; 
	}
private:
	char materia[3];
	double calif;
};
