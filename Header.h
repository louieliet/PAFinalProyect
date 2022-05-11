#include <iostream>
#include <string>
#include <fstream> 
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

int fig1402()
{
    ofstream outIndice{"indice.dat", ios::out};

    if(!outIndice){
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
};