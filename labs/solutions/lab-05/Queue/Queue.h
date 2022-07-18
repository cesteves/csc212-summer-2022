#include "Node.h"
#include <string>

class Queue{
    private:
        Node* head;
        Node* tail;
        unsigned int _size = 0;

    public:
        Queue();

        void dequeue();
        void enqueue(int data);
        //void push_front(int data);
        //void push_back(int data);
        //void insert(int data, unsigned int idx);
        //void del(int data);
        bool contains(int data);
        int size();
        std::string to_string();
};