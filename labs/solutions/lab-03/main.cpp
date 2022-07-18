#include "linked-list.h"
#include <iostream>

int main(){
    int* tmp;

    std::cout << "Hello\\World\n";
    std::cout << "Hello, World" << std::endl;

    LinkedList ll;

    ll.push_front(5);
    ll.push_front(10);
    ll.push_front(15);
    std::cout << ll.to_string() << std::endl;
    ll.push_back(100);
    ll.push_back(101);
    ll.push_back(102);
    std::cout << ll.to_string() << std::endl;

    ll.insert(20, 1);
    ll.insert(1, 0);
    ll.insert(2, 8);
    std::cout << ll.to_string() << std::endl;

    ll.remove(101);
    std::cout << ll.to_string() << std::endl;

    std::cout << ll.contains(102) << std::endl;
    std::cout << ll.contains(1092) << std::endl;

    std::cout << ll.get_size() << std::endl;

    std::cout << ll.to_string() << std::endl;
}