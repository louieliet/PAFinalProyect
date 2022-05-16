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


class Materias {
public:
	Materias(int indice = 65536, const string& matricula = "1234567", const double pa = 0.0, const double poo = 0.0, const double mat = 0.0, const double ing=0.0) {
		this->indice = indice;
		setMatricula(matricula);
		calif1 = pa;
		calif2 = poo;
		calif3 = mat;
		calif4 = ing;
		
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
	char c1[4] = "PA1";
	double calif1;
	char c2[4]= "POO";
	double calif2;
	char c3[4]= "Mat";
	double calif3;
	char c4[4]= "ING";
	double calif4;
	

};

