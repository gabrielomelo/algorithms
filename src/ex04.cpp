//
// Created by gabriel on 02/01/18.
//
// Ordenação por intercalação
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#define MAX_NUM 1000

using namespace std;

int main() {

    int max_size;
    cin >> max_size;

    vector<int> arr;

    srand(time(NULL));
    for (int i = 0; i < max_size; i++)
        arr.push_back(rand() % MAX_NUM + 1);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << endl;

    return 0;
}


