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
	IndiceEstudiante(int indice = 65536, const string& matricula = "1234567", const string& name = " ") {
		this->indice = indice;
		setMatricula(matricula);
		setName(name);
	}

	void setMatricula(const string& matricula) {

		size_t length{ matricula.size() };
		length = (length < 8 ? length : 7);
		matricula.copy(this->matricula, length);
		this->matricula[length] = '\0'; 

	}
	
	void setName(const string& name) {

		size_t length{ name.size() };
		length = (length < 20 ? length : 19);
		name.copy(this->name, length);
		this->name[length] = '\0'; 

	}
	
	int getIndice() const {return indice;}
	string getMatricula() const {return matricula;}
	string getName() const {return name;}

private:
	int indice;
	char matricula[8];
	char name[20];
};


class Materias : public IndiceEstudiante {
public:
	
	Materias(IndiceEstudiante &student, const double PA = 0.0, const double POO = 0.0, const double GEO = 0.0, const double ING = 0.0) 
	{	
		this->indice = student.getIndice();
		setMatricula(student.getMatricula());

	}

	string getMatricula() const {return matricula;}

private:
	char PA[4] = "PA1";
	char POO[4] = "POO";
	char GEO[4] = "GEO";
	char ING[4] = "ING";
	char matricula[8];
	int indice;
};
