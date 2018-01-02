/**
 * Ordenação de array por inserção
 * */

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#define MAX_POS 10
#define MAX_NUM 10

using namespace std;

int main() {

    //Criando o vetor dinâmico e definindo o tipo dele
    vector<int> arr;
    srand(time(NULL));
    for (int i = 0; i < MAX_POS; i++)
        arr.push_back(rand() % MAX_NUM + 1); //Está com o +1 porque o modulo retorna o lim até o MAX_NUM

    //Ordenando o array
    for (int j = 1, i; arr.size() > j; j++) {
        int key = arr[j];
        i = j - 1;
        while(i > 0 && arr[i] > key){
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }

    for (int k = 0; arr.size() > k; k++)
        cout << arr[k] << endl;

    return 0;
}
