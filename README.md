# PAFinalProyect
Programación Avanzada Final Proyect


Archivo estudiante:
  Clases que describan las clases que tiene el alumno, la materia, la matrícula, la info del estudiante
  Debe ser como una base de datos
  
  (Jetbrains -> IntelligIDEA)
  
  Number, Matriula(characters array), Name(same == char array), Department(char array), Total Credits(int)
  
  Buscar que se pueda buscar de forma no secuencial cualquier estudiante
  foreing key -> llave para referirse a la primary key de la tabla main
  
producto cartesiano, imitarlo

ID: 
Name:
deptname: 
salary:

ID:
courseid:
secid:
semester:
year:


1x2 = (10101, Susana, comp. sci, 6500, 76766, bio-101, 1, summer, 2009)

class student -> student info
class takes -> classes they take
class course -> table info

Para el martes, diseñar las clases
archivos de acceso aleatorios, diseñar el tamaño de los atributos

input -> Emi(estudiante, takes, materia)

output -> id emi lleva programación avanzada


14.8 creating a random access file
learning.oreilly

binary file

// Control escolar

Estudiantes
Datos
Archivos (de acceso aleatorio)

Random ac. files

captiulo 14, control de cuentas bancarias

Grupo de Programación Avanzada
13 estudiantes


Clase que tenga dos atributos: 1. Matricula[] 2. Indice (int) (tiene que ir de 0-99, el estudiante
puede tener el indicie que desee, no tiene que ser secuencial)

la clase debe tener los getters y setters, y debe ser const
  array = {1,2,3,4,5,6,7,8,9}


  reinterpret_cast<>()  reinterpreta esto() como esto <>

  indice.data{matricula char[4], int}

  0 00 0 00  000 

  100 veces (esto me da la matricula y el indice, con el que voy a encontrar al alumno en otro archivo)

  Example:

  class IndiceEstudiante
  {
    public:
      IndiceEstudiante(int=0, const string& = " ");
      this->indice=indice;
      this->matricula=setMatricula(" ");

      void setMatricula ()
      {
        bla bla bla
      }
  }

  Segundo archivo:

  class Materias
  {
    materia, calificacion
  }

  Tercer archivo:

  class Materia
  {
    nombre, clave
  }


  Dame matricula: buscamos el indice en el otro archivo, buscamos el registro 5, donde dirá el nombre completo y calificación de 
  todas las materias y su clave de materia, y en el otro archivo buscamos el nombre completo de la materia

  indice -> indice.dat

  textpad