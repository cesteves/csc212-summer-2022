#include <iostream>
#include "DynamicArray.h"
int main(){
    // Review this weekend
    // DynamicArray* tmp = new DynamicArray();

    DynamicArray cap(2.0, 5);
    // DynamicArray fill(2.0, 10, 5);

    //std::cout << tmp->toString() << std::endl;
    std::cout << cap.toString() << std::endl;
    // std::cout << fill.toString() << std::endl;

/*
    cap.append(6);
    std::cout << cap.toString() << "\t" << cap.getLength() << "\t" << cap.getCapacity() << std::endl;
    cap.prepend(2);
    std::cout << cap.toString() << "\t" << cap.getLength() << "\t" << cap.getCapacity() << std::endl;
    cap.append(3);
    std::cout << cap.toString() << "\t" << cap.getLength() << "\t" << cap.getCapacity() << std::endl;
    cap.prepend(4);
    std::cout << cap.toString() << "\t" << cap.getLength() << "\t" << cap.getCapacity() << std::endl;
    cap.append(5);
    std::cout << cap.toString() << "\t" << cap.getLength() << "\t" << cap.getCapacity() << std::endl;
    cap.prepend(6);
    std::cout << cap.toString() << "\t" << cap.getLength() << "\t" << cap.getCapacity() << std::endl;

    bool found;
    unsigned int index = 999;

    found = cap.findLastOf(6, &index);

    std::cout << found << "\t" << index << std::endl;

*/

    cap.append(1);
    cap.append(2);
    cap.append(3);
    cap.append(4);
    cap.append(5);
    std::cout << cap.toString() << "\t" << cap.getLength() << "\t" << cap.getCapacity() << std::endl;
    cap.append(6);
    std::cout << cap.toString() << "\t" << cap.getLength() << "\t" << cap.getCapacity() << std::endl;
    cap.removeFirst();
    std::cout << cap.toString() << "\t" << cap.getLength() << "\t" << cap.getCapacity() << std::endl;
    cap.removeFirst();
    std::cout << cap.toString() << "\t" << cap.getLength() << "\t" << cap.getCapacity() << std::endl;
    cap.removeFirst();
    std::cout << cap.toString() << "\t" << cap.getLength() << "\t" << cap.getCapacity() << std::endl;
    cap.removeFirst();
    std::cout << cap.toString() << "\t" << cap.getLength() << "\t" << cap.getCapacity() << std::endl;
}