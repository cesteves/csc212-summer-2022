#include "Node.h"
#include <string>

class LinkedList{
    private:
        Node* head;
        unsigned int _size = 0;

    public:
        LinkedList();

        void push_front(int data);
        void push_back(int data);
        void insert(int data, unsigned int idx);
        void del(int data);
        bool contains(int data);
        int size();
        std::string to_string();
};