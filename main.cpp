#include "source.h"

int main() {

    ofstream outStudentFile{"studentfile.txt", ios::out};

    if (!outStudentFile) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    };

    Student s1(123,"Emi","Ing",10);
    Student s2(456, "Liz", "Ing", 20);
    vector<Student> list;
    list.push_back(s1);
    list.push_back(s2);
    
    for(auto i: list){
        i.outStudent(outStudentFile);
    }

    return 0;
}
