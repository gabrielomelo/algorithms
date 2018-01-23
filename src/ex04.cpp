//
// Created by gabriel on 02/01/18.
//
// Ordenação por intercalação
//

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_SIZE 1000

using namespace std;

void init_array(vector<int>& array); // init an array with random numbers


class Entity {
public:
    void name() {
        cout << "Entidade" << endl;
        return;
    }
};


int main(int argc, char** argv) {

    if(argc <= 1){
        cout << "O número de argumentos é insuficiente,\n"
                "digite o número de digitos a serem ordenados,\n"
                "seguidos dos valores de minimo e maximos dos numeros."
             << endl;
        return 1;
    }
    char arr[] = "Gabriel";

    Entity* en = new Entity();

    Entity emdois;
    emdois.name();
    en->name();

    cout << arr << endl;


    //heap alocation

    int* mem = new int[100];
    mem[3] = 35;
    cout << mem[3] << endl;


    int* mem2 = (int*) malloc(sizeof(int));

    *mem2 = 33333;

    cout << *mem2 << endl;

    delete mem;
    free(mem2);

    //cin.get();



}

void init_array(vector<int>& array){
    for (short i = 0; i < MAX_SIZE; i++)
        array.push_back(rand() % 1000 + 1);
}