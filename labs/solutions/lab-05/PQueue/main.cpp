#include "PQueue.h"
#include <iostream>

int main(){
    PQueue ll;

    ll.enqueue(1, 1);
    ll.enqueue(2, 2);
    ll.enqueue(3, 2);
    ll.enqueue(4, 4);
    ll.enqueue(5, 1);

    std::cout << ll.to_string() << std::endl;

    ll.dequeue();

    std::cout << ll.to_string() << std::endl;

    ll.dequeue();

    std::cout << ll.to_string() << std::endl;
}