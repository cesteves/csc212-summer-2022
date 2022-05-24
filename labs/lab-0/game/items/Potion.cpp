#include "Potion.hpp"

Potion::Potion() : Item("Potion", 20) {
}

void Potion::activate(Entity* target) {
	target->heal(this->power);
}