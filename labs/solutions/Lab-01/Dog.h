// Dog.h
#include "Animal.h"

class Dog : public Animal{
    public:
        Dog(float initial_hunger, int age) : Animal(initial_hunger, age){};
        void Speak() { std::cout << "Woof!" << std::endl; }
};