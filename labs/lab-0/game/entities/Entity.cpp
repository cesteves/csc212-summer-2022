#include "Entity.hpp"
#include "../items/Item.hpp"

Entity::Entity(std::string name, int health, int damage){
    this->name = name;
    this->health = health;
    this->damage = damage;
}

std::string Entity::getName() {
	return this->name;
}

int Entity::getHealth() {
	return this->health;
}

void Entity::getInfo(){
    std::cout << this->name <<
        "\nHealth: " << this->health << std::endl;
}

Item* Entity::takeDamage(int amount){
    this->health -= amount;

	if (this->health <= 0) {
		std::cout << this->name << " slain!\n";
		return Item::generateRandomItem();
	}

	return nullptr;
}

void Entity::heal(int amount) {
	this->health += amount;
}

Item* Entity::attack(Entity* target){

	std::cout << this->name << " attacks " << target->getName() << " for " << this->damage << "!\n~~~~~\n";

    return target->takeDamage(this->damage);
}

void Entity::displayInventory(){
	this->inventory.displayInventory();
}

void Entity::addItem(Item* item){
	this->inventory.addItem(item);
}

void Entity::useItem(std::string name, Entity* target) {
	this->inventory.useItem(name, target);
}

void Entity::useItem(int index, Entity* target) {
	this->inventory.useItem(index, target);
}

int Entity::getInventorySize() {
	return this->inventory.getSize();
}