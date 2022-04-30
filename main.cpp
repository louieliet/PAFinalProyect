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
    }

    Student s1(123, "Emi", "Ing", 10);

    for (int i = 0; i < 100; i++) {
        outStudentFile.write(reinterpret_cast < const char *> (& s1), sizeof(Student));
        }

    return 0;
}