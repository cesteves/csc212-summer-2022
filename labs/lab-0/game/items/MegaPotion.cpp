#include "MegaPotion.hpp"

MegaPotion::MegaPotion() : Item("Mega Potion", 50) {
}

void MegaPotion::activate(Entity* target) {
	target->heal(this->power);
}