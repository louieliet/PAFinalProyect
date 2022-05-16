#include "Header.h"

int main(){

    IndiceEstudiante s1(1, "0241718", "Emiliano");
    IndiceEstudiante s2(13, "0241719", "Lizbeth");
    IndiceEstudiante s3(50, "0241720", "Ariana");
    IndiceEstudiante s4(2, "0241721", "Angel");
    IndiceEstudiante s5(33, "0241722", "Ricardo");
    IndiceEstudiante s6(80, "0241723", "Ana");
    IndiceEstudiante s7(27, "0241724", "Gio");
    IndiceEstudiante s8(40, "0241725", "Regina");
    IndiceEstudiante s9(60, "0241726", "Juan Pablo");
    IndiceEstudiante s10(59, "0241727", "Carlos");
    
    Materias m1(   1,     "0241718",    7.5,    8.1 ,   6,      9.3);
    Materias m2(   13,    "0241719",    8.6,    9.2,    8.2,    9.4);
    Materias m3(   50,    "0241720",    8.7,    9.2,    6.9,    9.3);
    Materias m4(   2,     "0241721",    7.6,    8.4,    8.7,    7.4);
    Materias m5(   33,    "0241722",    9.9,    7.1,    7.5,    10);
    Materias m6(   80,    "0241723",    8.5,    9.8,    9.7,    7.8);
    Materias m7(   27,    "0241724",    9.8,    9.4,    8.3,    7.3);
    Materias m8(   40,    "0241725",    7.8,    7.6,    8.2,    9.9);
    Materias m9(   60,    "0241726",    8.9,    8.5,    9.2,    9.3);
    Materias m10(  59,    "0241727",    9.4,    10,     7.2,    7.8);

    Materia PA(1,"PA1","ProgramacionAvanzada");
    Materia POO(2,"POO","ProgramacionOrientadaObjeto");
    Materia MAT(3,"MAT","Matematicas");
    Materia ING(4,"ING","Ingles"); 
    

    vector<IndiceEstudiante> i_list = {s1,s2,s3,s4,s5,s6,s7,s8,s9,s10};
    vector<Materias> m_list = {m1,m2,m3,m4,m5,m6,m7,m8,m9,m10};
    vector<Materia> mu_list = {PA,POO,MAT,ING};

    menu(i_list, m_list, mu_list);

    return 0;

}
