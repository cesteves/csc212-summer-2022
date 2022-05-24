#pragma once

#include "Item.hpp"

class Potion : public Item
{
private:
	// Note: This will not work prior to C++11!
	// This assignment would need to be done in the constructor.
	//int amount = 10;

public:
	Potion();
	void activate(Entity* target);
};

