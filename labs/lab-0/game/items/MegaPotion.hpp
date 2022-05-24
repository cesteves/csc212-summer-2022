#pragma once

#include "Item.hpp"

class MegaPotion : public Item
{
public:
	MegaPotion();
	void activate(Entity* target);
private:
	//Note: This will not work prior to C++11!
	//This assignment would need to be done in the constructor.
	//int amount;
};

