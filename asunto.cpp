#pragma once

#include <string>

class IndiceEstudiante {

public:

	IndiceEstudiante(int indice = 0, const std::string & matricula= "12345678") {

		this->indice = indice;

		setMatricula(matricula);

	}

	void setMatricula(const std::string & matricula) {

		// copy at most 7 characters from string to matricula

		size_t length{ matricula.size() };

		length = (length < 8 ? length : 7);

		matricula.copy(this->matricula, length);

		this->matricula[length] = '\0'; // append null character to lastName

	}

	int getIndice() const { return indice; }

private:

	char matricula[8];

	int indice;

};



