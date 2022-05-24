#pragma once
#include "../entities/Entity.hpp"

class Item
{
private:
	std::string name;

protected:
	int power;

public:
	Item(std::string name, int power);
	std::string getName();
	static Item* generateItem(std::string name);
	static Item* generateRandomItem();
	virtual void activate(Entity* target) = 0;
};