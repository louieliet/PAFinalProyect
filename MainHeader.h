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
	IndiceEstudiante(int indice = 65536, const string& matricula) {
		this->indice = indice;
		setMatricula(matricula);

	}
	void setMatricula(const string& matricula) {
		// copy at most 7 characters from string to matricula
		size_t length{ matricula.size() };
		length = (length < 8 ? length : 7);
		matricula.copy(this->matricula, length);
		this->matricula[length] = '\0'; // append null character to lastName

	}

	int getIndice() const { return indice; }

	string getMatricula() const { return matricula; }

private:
	char matricula[8];
	int indice;
};


class Materias
{
private:
	char nombre[15];
	int calificacion;

public:

};