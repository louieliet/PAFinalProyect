#include "Header.h"

int main(){


    IndiceEstudiante s1(1,"0241718","EmilianoMontesGomez");
    IndiceEstudiante s2(2,"0241719","LizbethTrujilloSalgado");
    IndiceEstudiante s3(50,"0241720","ArianaRodriguezCastaneda");

    Materias m1(1, "0241718", 10,10,10,10);
    Materias m2(2,"0241719", 5,5,5,5);
    Materias m3(50,"0241720", 8,8,8,8);

    Materia PA(1,"PA1","ProgramacionAvanzada");
    Materia POO(2,"POO","ProgramacionOrientadaObjeto");
    Materia MAT(3,"MAT","Matematicas");
    Materia ING(4,"ING","Ingles"); 
    

    vector<IndiceEstudiante> i_list = {s1,s2,s3};
    vector<Materias> m_list = {m1,m2,m3};
    vector<Materia> mu_list = {PA,POO,MAT,ING};

    menu(i_list, m_list, mu_list);

    return 0;

}