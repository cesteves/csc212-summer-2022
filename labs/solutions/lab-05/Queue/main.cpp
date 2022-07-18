#include "Queue.h"
#include <iostream>

int main(){
    Queue ll;

    ll.enqueue(1);
    ll.enqueue(2);
    ll.enqueue(3);
    ll.enqueue(4);

    std::cout << ll.to_string() << std::endl;

    ll.dequeue();

    std::cout << ll.to_string() << std::endl;

    ll.dequeue();

    std::cout << ll.to_string() << std::endl;
}