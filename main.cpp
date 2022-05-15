#include "Header.h"

int main(){


    IndiceEstudiante s1(1,"0241718","EmilianoMontesGomez");
    IndiceEstudiante s2(2,"0241719","LizbethTrujilloSalgado");
    IndiceEstudiante s3(50,"0241720","ArianaRodriguezCastaneda");

    vector<IndiceEstudiante> list = {s1,s2,s3};

    menu(list);


    return 0;

}