#include "Inventory.hpp"
#include "Item.hpp"

void Inventory::displayInventory() {
	if (this->inventory.size() == 0) {
		std::cout << "Inventory is empty!" << std::endl;
		return;
	}

	for (std::vector<Item*>::iterator it = this->inventory.begin(); it != this->inventory.end(); ++it) {
		std::cout << (*it)->getName() << std::endl;
	}
}

void Inventory::addItem(Item* item) {
	std::cout << "Added " << item->getName() << " to inventory!\n";
	this->inventory.push_back(item);
}

void Inventory::useItem(std::string name, Entity* target) {
	for (unsigned int i = 0; i < this->inventory.size(); i++) {
		if (inventory.at(i)->getName() == name) {
			std::cout << "Used " << name << " on " << target->getName() <<"!\n";
			inventory.at(i)->activate(target);
			inventory.erase(inventory.begin() + i);
		}
	}
}

void Inventory::useItem(int index, Entity* target) {
	inventory.at(index)->activate(target);
	std::cout << "Used " << inventory.at(index)->getName() << " on " << target->getName() << "!\n";
	inventory.erase(inventory.begin() + index);
}

int Inventory::getSize() {
	return this->inventory.size();
}