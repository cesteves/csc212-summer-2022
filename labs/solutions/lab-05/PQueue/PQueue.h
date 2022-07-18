#include "Node.h"
#include <string>

class PQueue{
    private:
        Node* head;
        Node* tail;
        unsigned int _size = 0;

    public:
        PQueue();

        void dequeue();
        void enqueue(int data, int priority);
        //void push_front(int data);
        //void push_back(int data);
        //void insert(int data, unsigned int idx);
        //void del(int data);
        bool contains(int data);
        int size();
        std::string to_string();
};