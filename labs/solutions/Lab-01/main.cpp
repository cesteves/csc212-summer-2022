#include "Cat.h"
#include "Dog.h"
#include "Bird.h"
#include "Hamster.h"
#include "Snake.h"

#include <string>

int main(int argc, char*argv[]){
    /*
        // GitHub Sample
        ./prog 4 30 40 50 60
        argc = 6
        argv[0] = ./prog
        argv[1] = 4
        argv[2] = 30
        argv[3] = 40
        argv[4] = 50
        argv[5] = 60

        // This Code
        ./prog 4 30 40 50 60
        argc = 6
        argv[0] = ./prog
        argv[1] = 2
        argv[2] = 30
        argv[3] = 3
        argv[4] = 50
        argv[5] = 7
    */

    int num_animals = std::stoi(argv[1]);

    Animal** arr = new Animal*[num_animals];

    std::string user_input;

    for(int i = 0; i < num_animals; i++){
        std::cout << "Enter an animal: ";
        std::getline(std::cin, user_input);

        if(user_input == "Dog"){
            // Dog* new_dog = new Dog(std::stof(argv[i+2]), std::stoi(argv[i+3]));
            // Animal* new_dog = new Dog(std::stof(argv[i+2]), std::stoi(argv[i+3]));
            // arr[i] = new_dog;
            arr[i] = new Dog(std::stof(argv[2*i + 2]), std::stoi(argv[2*i + 3]));
        }else if(user_input == "Cat"){
            arr[i] = new Cat(std::stof(argv[2*i + 2]), std::stoi(argv[2*i + 3]));
        }else if(user_input == "Bird"){
            arr[i] = new Bird(std::stof(argv[2*i + 2]), std::stoi(argv[2*i + 3]));
        }else if(user_input == "Hamster"){
            arr[i] = new Hamster(std::stof(argv[2*i + 2]), std::stoi(argv[2*i + 3]));
        }else if(user_input == "Snake"){
            arr[i] = new Snake(std::stof(argv[2*i + 2]), std::stoi(argv[2*i + 3]));
        }
    }

    for(int i = 0; i < num_animals; i++){
        arr[i]->Speak();
        std::cout << arr[i]->GetHunger() << " " << arr[i]->GetAge() << std::endl;
    }


    // Cat cat1(50, 8);	// object constructed during compile-time
    // Dog* dog1 = new Dog(40, 5);	// object constructed during run-time. 'dog1' is a pointer.
    // Bird* bird1 = new Bird(10, 13);
    // Hamster* ham1 = new Hamster(20, 1);
    // Snake* snake1 = new Snake(30, 9);

    // std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    // std::cout << "Dog hunger: " << dog1->GetHunger() << std::endl;
    // std::cout << "Bird hunger: " << bird1->GetHunger() << std::endl;
    // std::cout << "Hamster hunger: " << ham1->GetHunger() << std::endl;
    // std::cout << "Snake hunger: " << snake1->GetHunger() << std::endl;

    // std::cout << "Cat age: " << cat1.GetAge() << std::endl;
    // std::cout << "Dog age: " << dog1->GetAge() << std::endl;
    // std::cout << "Bird age: " << bird1->GetAge() << std::endl;
    // std::cout << "Hamster age: " << ham1->GetAge() << std::endl;
    // std::cout << "Snake age: " << snake1->GetAge() << std::endl;
}