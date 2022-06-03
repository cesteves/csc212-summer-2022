// Bird.h
#include "Animal.h"

class Bird : public Animal{
    public:
        Bird(float initial_hunger, int age) : Animal(initial_hunger, age){};
        void Speak() { std::cout << "Chirp!" << std::endl; }
};