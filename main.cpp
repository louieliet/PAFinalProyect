#include "classes.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

    ofstream outStudentFile{"studentfile.txt", ios::out};

    if (!outStudentFile) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    };

    string name, dept;
    int tuition, credits;

    cin >> name >> dept >> tuition >> credits;

    Student st1(tuition,dept,name,credits);

    while (true) {
      outStudentFile << st1.getMatricula() << ' ' << st1.getDepart() << ' ' << st1.getName() << st1.getCredits() << endl;
      break;
   }
    return 0;
}