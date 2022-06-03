// Cat.h
#include "Animal.h"

class Cat : public Animal{
    public:
        Cat(float initial_hunger, int age) : Animal(initial_hunger, age){};
        void Speak() { std::cout << "Meow!" << std::endl; }
};