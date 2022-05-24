#include "Grenade.hpp"

Grenade::Grenade() : Item("Grenade", 20) {

}

void Grenade::activate(Entity* target) {
	target->takeDamage(this->power);
}