#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

// Simple C++ implementation of a neural network
// Three Layers: Input >> Hidden >> Output.
// The current implementation has the ability to process 2 bits of data
// Vectors are used for future expansions

class Perceptron
{
	public :

		std::vector<float> input, weights; // aka result, with one result
		float output;

		Perceptron (int input_size)
		{
			for (int i = 0; i < (input_size); i++) this->weights.push_back(this->random(0, 1));
		}

		// Here, the vector input is organized {given, given}
		void train (std::vector<float> input, float target, float learning_rate)
		{
			this->input.clear();
			this->input = input;
			this->feed_forward();
			if (this->output == target) return;

			do {
				for (int i = 0; i < this->input.size(); i++) {
					this->weights[i] += this->get_error(target) * (this->input[i] * learning_rate); 
				}
				this->feed_forward();
			} while (this->output != target);
		}

		// Here the vector is organized {value, value, ..}
		float getResult(std::vector<float> input)
		{
			this->input.clear();
			this->input = input;
			this->feed_forward();
			return this->output;
		}

	private :

		float get_error(float target)
		{
			return target - this->output;
		}

		void feed_forward() 
		{
			// Multiply and make the sum (or agregation)
			float sum;
			for(int i = 0; i < this->input.size(); i++) {
				sum += this->input[i] * this->weights[i];
			}
			this->output = this->seg(sum);
		}

		float seg(float sum)
		{
			return (sum > 0)? 1 : 0;
		}

		float random(int min, int max)
		{
			return (float) (std::rand() % max + min);
		}
};


int main () 
{
	std::srand(std::time(NULL));
	Perceptron *p = new Perceptron(4);
	std::vector<int> res;

	p->train({1, 1, 0, 0, 0}, 0, 0.001);

	res.push_back(p->getResult({1, 1, 0, 0, 0}));

	for(int i = 0; i < res.size(); i++)
		std::cout << res[i] << std::endl;	

	delete p;
}
