//
// Created by gabriel on 20/12/17.
//

//include fundamentals library's
#include <cmath>
#include <iostream>
#include <string>

//pullllll the trigger......
int main() {
    std::string s = "shjkdhdj";
    std::cout << s << std::endl;

    short int list[10];
    for (int i = 0; i < 10; i++)
        list[i] = rand()%10 + 1;
    for (int j = 0; j < 10; ++j)
        std::cout << list[j] << std::endl;

    return 0;
}