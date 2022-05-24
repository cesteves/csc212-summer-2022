#include <iostream>
#include <cstdlib>
#include <ctime>
#include "./entities/Entity.hpp"
#include "./items/Potion.hpp"
#include "./items/MegaPotion.hpp"
#include "./items/Grenade.hpp"

void battle_demo();

int main(){
	srand((unsigned int)time(NULL));

	battle_demo();
}

// This function showcases a mock combat loop between a hero and 3 enemies.
// The outcome of the battle can be determined by changing the strength of the hero/enemies, # of enemies,
// or by adjusting the power of items.
// If the stats & item power is balanced, the outcome of the fight is determined by RNG item drops.
void battle_demo(){
	 Entity hero = Entity("Hero", 20, 5);

	std::vector<Entity*> enemies;
	enemies.push_back(new Entity("Enemy 1", 10, 2));
	enemies.push_back(new Entity("Enemy 2", 10, 2));
	enemies.push_back(new Entity("Enemy 3", 25, 5));

	int turnCounter = 1;

	while (hero.getHealth() > 0 && enemies.size() > 0) {
		std::cout << "Turn " << turnCounter << "\n---------------------------------------\n";
		hero.getInfo();
		hero.displayInventory();

		if (hero.getInventorySize() > 0) {
			hero.useItem(0, &hero);
		}

		Item* temp = hero.attack(enemies.at(0));
		if (temp != nullptr) {
			hero.addItem(temp);
			enemies.erase(enemies.begin());
		}
		// Signed: -2^(31) - 1 through 2^31
		// Unsigned: 2^(32) - 1
		for (unsigned int i = 0; i < enemies.size(); i++) {
			enemies.at(i)->getInfo();
			enemies.at(i)->attack(&hero);
		}
		turnCounter++;
	}

	if (hero.getHealth() > 0) {
		std::cout << "You Win!\n";
	}
	else {
		std::cout << "You Lose!\n";
	}

}