#include "Item.hpp"
#include "Potion.hpp"
#include "MegaPotion.hpp"
#include "Grenade.hpp"

Item::Item(std::string name, int power) {
	this->name = name;
	this->power = power;
}

std::string Item::getName() {
	return this->name;
}


// This is a factory design pattern. This allows us to create Items during the runtime of the program without them being predetermined
// at compile time.
// We create an `Item pointer` (Item *) in the location we wish to store "some item", then when it comes time to
// create an Item we can use one of the following two functions to either generate a specific Item OR a random Item.
// We can see this play out in the `Inventory` class.
// `Inventory` holds a vector of `Item *`. When an enemy is slain, an Item is randomly generated and stored in the Player's Inventory.
Item* Item::generateItem(std::string name) {
	if (name == "Potion") {
		return new Potion();
	}
	else if (name == "Mega Potion") {
		return new MegaPotion();
	}
	else if (name == "Grenade"){
		return new Grenade();
	}
	// An invalid item was requested.
	std::cout << "That item does not exist!\n";
	return nullptr;
}

Item* Item::generateRandomItem() {
	int choice = rand() % 100;

	if (choice < 50) {
		return new Potion();
	}
	else if (choice < 75) {
		return new MegaPotion();
	}
	else if (choice < 100){
		return new Grenade();
	}

	// Make sure the # being modded is the count of items.
	std::cout << "Error in modulo for generateRandomItem()!\n";
	return nullptr;
}