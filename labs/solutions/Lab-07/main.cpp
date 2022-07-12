#include "HashTableLinear.h"
#include "HashTableDouble.h"
#include "HashTableChain.h"

void testHTDouble();
void testHTChain();
void testHTLinear();

int main(){
    testHTDouble();
    testHTChain();
    testHTLinear();
}

void testHTDouble(){
    HashTableDouble my_table(5);

    my_table.insert(1);
    my_table.insert(13);
    my_table.insert(14);
    my_table.insert(16);

    std::cout << "Double Hashing Table" << std::endl;
    my_table.print_table();

    std::cout << "Search for " << 13 << " result: " << my_table.search(13) << std::endl;
    std::cout << "Search for " << 4 << " result: " << my_table.search(4) << std::endl;
}

void testHTChain(){
    HashTableChain my_table(5);

    my_table.insert(1);
    my_table.insert(13);
    my_table.insert(14);
    my_table.insert(16);

    std::cout << "Separate Chaining Table" << std::endl;
    my_table.print_table();

    std::cout << "Search for " << 13 << " result: " << my_table.search(13) << std::endl;
    std::cout << "Search for " << 4 << " result: " << my_table.search(4) << std::endl;
}

void testHTLinear(){
    HashTableLinear my_table(5);

    my_table.insert(1);
    my_table.insert(13);
    my_table.insert(14);
    my_table.insert(16);

    std::cout << "Linear Probing Table" << std::endl;
    my_table.print_table();

    std::cout << "Search for " << 13 << " result: " << my_table.search(13) << std::endl;
    std::cout << "Search for " << 4 << " result: " << my_table.search(4) << std::endl;
}