// Hamster.h
#include "Animal.h"

class Hamster : public Animal{
    public:
        Hamster(float initial_hunger, int age) : Animal(initial_hunger, age){};
        void Speak() { std::cout << "Squeak!" << std::endl; }
};