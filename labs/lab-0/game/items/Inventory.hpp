#pragma once

#include <iostream>
#include <vector>

// Forward declaration.
// Cannot include 'Item', as 'Item' includes 'Entity' & that would cause a circular dependency (compiler would crash with many, many errors.)
// This allows 'Entity' to *know* that 'Item' exists, but *not* how to use it.
class Item;
class Entity;

class Inventory
{
private:
	std::vector<Item*> inventory;
public:
	void displayInventory();
	void addItem(Item* item);
	void useItem(std::string name, Entity* target);
	void useItem(int index, Entity* target);
	int getSize();
};