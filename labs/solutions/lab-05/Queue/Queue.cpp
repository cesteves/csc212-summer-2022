#include "Queue.h"
#include <iostream>

Queue::Queue(){
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0;
}

// Not needed for Queue - we can only add elements to the back of the line!
/*
void LinkedList::push_front(int data){
    //Simply create a new node, assign its ‘next’ to head, and assign head to the new node!
    // This will work, but its a bit clunky. We have 4 assignments instead of the 2 by using the other constructor!
    // Node* temp = new Node();
    // temp->data = data;
    // temp->next = this->head;

    // Much better implementation, only 2 assignments made & 1 line of code!
    Node* temp = new Node(data, this->head);
    this->head = temp;
    this->_size++;

    if(this->_size == 1){
        this->tail = this->head;
    }
}
*/

void Queue::dequeue(){
    // Catch the case of dequeueing an empty list
    if(!this->head){
        return;
    }

    Node* temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->_size--;
}

// push_back w/ tail pointer is the same as enqueue =D
void Queue::enqueue(int data){
    // Special case: If this is the first element, create the Node and assign both "head" * "tail" to point to it.
    if(!this->head){
        this->head = new Node(data);
        this->tail = this->head;
    }else{
        // Create a new Node @ the end of the list & advance tail
        this->tail->next = new Node(data);
        this->tail = this->tail->next;
    }
    this->_size++;
}

// Not needed for Queue - we can only add elements to the back of the line!
/*
void LinkedList::insert(int data, unsigned int idx){
    unsigned int curr_idx = 0;

    // Special case: Insert into beginning of list
    if(idx == 0){
        this->push_front(data);
        return;
    }

    // Special case: User input idx >= size
    if(idx >= this->_size){
        this->push_back(data);
        return;
    }

    // Start temp pointer at head
    Node* temp = this->head;

    // Traverse Linked List until we arrive at the last element
    while(curr_idx != idx-1){
        temp = temp->next;
        curr_idx++;
    }

    Node* new_node = new Node(data, temp->next);
    temp->next =  new_node;
    this->_size++;
}
*/

// Not needed for Queue - we can only remove elements from the front of the line!
/*
void LinkedList::del(int data){
    // Start temp pointer at head
    Node* curr = this->head;
    Node* prev = nullptr;

    // Special case: Deleting head
    if(curr->data == data){
        prev = curr;
        this->head = curr->next;
        delete prev;
        this->_size--;
    }else{
        // Traverse Linked List until we arrive at 'data' OR the end of the list
        while(curr != nullptr && curr->data != data){
            prev = curr;
            curr = curr->next;
        }

        // If we did not found 'data'
        if(curr){
            // If we're about to delete the tail of the list
            if(curr == tail){
                tail = prev;
            }
            prev->next = curr->next;
            delete curr;
            this->_size--;
        }
    }
}
*/

bool Queue::contains(int data){
    // Start temp pointer at head
    Node* temp = this->head;

    // Traverse Linked List until we arrive at the end OR we find 'data'
    while(temp != nullptr && temp->data != data){
        temp = temp->next;
    }

    // Check if we stopped looping because we found 'data'
    if(temp){
        return true;
    }

    // We reached the end of the list & did not find 'data'
    return false;
}

int Queue::size(){
    return this->_size;
}

std::string Queue::to_string(){
    std::string str = "";

    Node* temp = this->head;

    while(temp != nullptr){
        str += std::to_string(temp->data) + " ";
        temp = temp->next;
    }

    return str;
}