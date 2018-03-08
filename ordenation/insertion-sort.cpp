/**
 * Ordenação de array por inserção
 * */

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 1000

using namespace std;

int main() {

    //Criando o vetor dinâmico e definindo o tipo dele
    vector<int> arr;
    srand(time(NULL));

    int qtd;
    cin >> qtd;

    for (int i = 0; i < qtd; i++)
        arr.push_back(rand() % MAX_NUM + 1); //Está com o +1 porque o modulo retorna o lim até o MAX_NUM

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] <<endl;

    //Ordenando o array
    for (int j = 1, i, key; arr.size() > j; j++) {
        key = arr[j];
        i = j - 1;
        while(arr[i] > key){
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }

    cout << "array ordenado" << endl;
    for (int k = 0; arr.size() > k; k++)
        cout << arr[k] << endl;

    return 0;
}
