// Snake.h
#include "Animal.h"

class Snake : public Animal{
    public:
        Snake(float initial_hunger, int age) : Animal(initial_hunger, age){};
        void Speak() { std::cout << "Hiss!" << std::endl; }
};