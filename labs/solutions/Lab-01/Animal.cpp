// Animal.cpp
#include "Animal.h"

Animal::Animal(float initial_hunger, int age){
    this->hunger = initial_hunger;
    this->age = age;
}

float Animal::GetHunger(){
    return this->hunger;
}

int Animal::GetAge(){
    return this->age;
}

void Animal::Eat(float sustenance){
    this->hunger += sustenance;
}