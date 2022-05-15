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
	double getCalifPA() const {
		auto it = boleta.find("PA");
		return it->second;
	}
	
	double getCalifPOO() const {
		auto it = boleta.find("POO");
		return it->second;
	}
	
	double getCalifGEO() const {
		auto it = boleta.find("GEO");
		return it->second;
	}
	
	double getCalifING() const {
		auto it = boleta.find("ING");
		return it->second;
	}
	

private:
	map<char*,double> boleta;
	char PA[4] = "PA";
	char POO[4] = "POO";
	char GEO[4] = "GEO";
	char ING[4] = "ING";
	char matricula[8];
};
