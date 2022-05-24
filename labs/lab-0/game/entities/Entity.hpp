#pragma once
#include <iostream>
#include <string>
#include "../items/Inventory.hpp"

class Entity{
    private:
        std::string name;
		int health;
        int damage;
		Inventory inventory;
    public:
        Entity(std::string name, int health, int damage);

		std::string getName();
		int getHealth();
        void getInfo();

        Item* takeDamage(int amount);
		void heal(int amount);
        Item* attack(Entity* target);

        void displayInventory();
        void addItem(Item* item);
		void useItem(std::string name, Entity* target);
		void useItem(int index, Entity* target);
		int getInventorySize();
};