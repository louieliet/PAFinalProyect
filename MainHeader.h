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
		length = (length < 25 ? length : 24);
		name.copy(this->name, length);
		this->name[length] = '\0'; 

	}
	
	int getIndice() const {return indice;}
	string getMatricula() const {return matricula;}
	string getName() const {return name;}

private:
	int indice;
	char matricula[8];
	char name[25];
};


class Materias {
public:
	
	Materias(const string& matricula, const double PA, const double POO, const double GEO, const double ING)
	{	
		setMatricula(matricula);
		boleta[this->PA] = PA;
		boleta[this->POO] = POO;
		boleta[this->GEO] = GEO;
		boleta[this->ING] = ING;

	}

	void setMatricula(const string& matricula) {

		size_t length{ matricula.size() };
		length = (length < 8 ? length : 7);
		matricula.copy(this->matricula, length);
		this->matricula[length] = '\0'; 
	}
	string getMatricula() const {return matricula;}

	void getCalifs(ofstream &out) const{

		for(auto it = boleta.begin(); it != boleta.end(); it++){
			
			string materia = it->first;
			double calif = it->second;

			out << setw(2) << 
				matricula << setw(17) << 
				materia << setw(17) << 
				calif << setw(17) << endl;

    	}
	}

private:
	map<char*,double> boleta;
	char PA[4] = "PA1";
	char POO[4] = "POO";
	char GEO[4] = "GEO";
	char ING[4] = "ING";
	char matricula[8];
};
