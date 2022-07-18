#include "Node.h"

Node::Node(){
    this->data = 0;
    this->priority = 0;
    this->next = nullptr;
}

Node::Node(int data, int priority){
    this->data = data;
    this->priority = priority;
    this->next = nullptr;
}

Node::Node(int data, int priority, Node* next){
    this->data = data;
    this->priority = priority;
    this->next = next;
}