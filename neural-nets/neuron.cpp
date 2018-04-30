#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <array>
#include <vector>

using namespace std;

int random(int min, int max){
	srand(time(NULL));
	return (int) rand() % max - min;
}

float sigmoid(float sum) {
        return 1 / (1 + exp(-sum));
}

float feedForward(array<int, 5>& input, array<int, 5>& weight) {
	int sum = 0;
	for(int i = 0; i < input.size(); i++) {
		sum += input[i] * weight[i];
	}
	return sigmoid(sum);
}


float train(array<int, 5>& input, array<int, 5>& weight) {

}

int main() {

	// Iniciando o array

	array<int, 5> input = {1,1,0,0,0};
	array<int, 5> weights = 
		{
			random(0, 10),
			random(0, 10),
			random(0, 10),
			random(0, 10),
			random(0, 10)
		};

	train(input, weigh)
	cout << feedForward(input, weights) << endl;
	
	return 0;
}
