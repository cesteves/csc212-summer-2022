// Animal.h
#pragma once
#include <iostream>

class Animal{
    private:
    	float hunger;
    	int age;

    public:
      Animal(float initial_hunger, int age);
    	void Eat(float sustenance);
    	float GetHunger();
    	int GetAge();
    	virtual void Speak() = 0;
};