//MainHeader.h -> En este archivo estarán únicamente las clases que utilizaremos

//Incluimos las librerías de c++ que utilizaremos

#include <iostream>
#include <fstream>  
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <wchar.h>
#include <locale.h>

using namespace std;

//IndiceEstudiante:

	//La clase IndiceEstudiante tendrá 3 atributos, que serán el indice del alumno que él escoja, su id y su nombre.
	//A su vez, tendrá 5 métodos y su constructor, que por predeterminado crea un alumno con indice 65536, id 1234567 y un nombre vacío, esto
	//nos ayudará a detectar alumnos que no existan o estén vaciós en el archivo de indice.dat

	//Las funciones set convierten los datos strings que nosotros introducimos en el constructor; en char arrays, es decir, en forma de cadenas de caractéres.
	//Las funciones get nos dan lo que vale cada cosa pedida, ya sea el índice, el id o el nombre.

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

//Materias:

	//La clase Materias tendrá 10 atributos, que nos servirán para establecer el índice y id del alumno, así como las claves de las materias y la calificación
	//de estas del alumno.

	//A su vez, tendrá 7 funciones y su constrcutor, que de igual forma, establecemos todos los parámetros en datos fijos que para nosotros serán los predeterminados para identificar
	//alumnos vacíos en los archivos

	//La función set tiene el mismo objetivo que los setters de IndiceEstudiante.
	//Las funciones get tienen el mismo objetivo que los getters de IndiceEstudiante.


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
	double getc1() const{ return calif1;}
	double getc2() const{ return calif2;}
	double getc3() const{ return calif3;}
	double getc4() const{ return calif4;}
	
private:
	int indice;
	char matricula[8];
	char c1[4] = "PA1";
	double calif1;
	char c2[4]= "POO";
	double calif2;
	char c3[4]= "MAT";
	double calif3;
	char c4[4]= "ING";
	double calif4;
	

};

//Materia:
	//La clase materia tendrá 3 atributos, que serán el indice de dónde se encuentra la materia en el archivo, la clave de la materia y su nombre completo.
	//De igual forma, definimos predeterminados en el constructor

	//Los setters y getters tienen el mimo objetivo que las dos anteriores clases.
class Materia {
public:
	Materia(int indice = 65536, const string& id = "NON", const string& name = "NONE") 
	{
		this->indice = indice;
		setClave(id);
		setNombre(name);
		
	}
	void setClave(const string& clave) {

		size_t length{ clave.size() };
		length = (length < 4 ? length : 3);
		clave.copy(this->clave, length);
		this->clave[length] = '\0'; 

	}
	void setNombre(const string& nombre) {

		size_t length{ nombre.size() };
		length = (length < 15 ? length : 14);
		nombre.copy(this->nombre, length);
		this->nombre[length] = '\0'; 

	}

	int getIndice() const {return indice;}
	string getName() const {return nombre;}
	
private:
	int indice;
	char clave[4];
	char nombre[15];

};



