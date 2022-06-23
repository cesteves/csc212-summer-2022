#include "LinkedList.h"
#include <iostream>

int main(){
    LinkedList ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);

    std::cout << ll.contains(2) << std::endl;
    std::cout << ll.contains(7) << std::endl;

    // Insert beginning test
    ll.insert(99,0);
    std::cout << ll.to_string() << std::endl;
    std::cout << ll.size() << std::endl;

    // Insert end test
    ll.insert(100,7);
    std::cout << ll.to_string() << std::endl;
    std::cout << ll.size() << std::endl;

    // Insert middle test
    ll.insert(99,4);
    std::cout << ll.to_string() << std::endl;
    std::cout << ll.size() << std::endl;

    // Delete valid head test
    ll.del(99);
    std::cout << ll.to_string() << std::endl;
    std::cout << ll.size() << std::endl;

    // Delete valid middle test
    ll.del(4);
    std::cout << ll.to_string() << std::endl;
    std::cout << ll.size() << std::endl;

    // Delete valid "tail" test
    ll.del(100);
    std::cout << ll.to_string() << std::endl;
    std::cout << ll.size() << std::endl;

    // Delete invalid data test
    ll.del(101);
    std::cout << ll.to_string() << std::endl;
    std::cout << ll.size() << std::endl;

    // push_front after head deletion test
    ll.push_front(102);
    std::cout << ll.to_string() << std::endl;
    std::cout << ll.size() << std::endl;
}