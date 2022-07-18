#include "PQueue.h"
#include <iostream>

PQueue::PQueue(){
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0;
}

// Not needed for PQueue - we can only add elements where they belong in line!
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

void PQueue::dequeue(){
    // Catch the case of dequeueing an empty list
    if(!this->head){
        return;
    }

    Node* temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->_size--;
}

// Not needed for PQueue - we can only add elements where they belong in line!
/*
void LinkedList::push_back(int data){
    if(!this->head){
        this->head = new Node(data);
        this->tail = this->head;
    }else{
        this->tail->next = new Node(data);
        this->tail = this->tail->next;
    }
    this->_size++;
}
*/

// We can rework insert to be our enqueue, using the incoming priority to compare to the existing values.

void PQueue::enqueue(int data, int priority){
    // Special case: First element being added
    if(!this->head){
        this->head = new Node(data, priority);
    // Special case: Insert into front of the queue
    }else if(priority > this->head->priority){
        Node* newNode = new Node(data, priority, this->head);
        this->head = newNode;
        return;
        // Insert anywhere else
    }else{
        // Start temp pointer at head
        Node* front = this->head;
        Node* back = nullptr;

        // Traverse Linked List until we arrive at the last element
        while(front && front->priority >= priority){
            back = front;
            front = front->next;
        }

        back->next = new Node(data, priority, front);

    }

    this->_size++;
}


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

bool PQueue::contains(int data){
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

int PQueue::size(){
    return this->_size;
}

std::string PQueue::to_string(){
    std::string str = "";

    Node* temp = this->head;

    while(temp != nullptr){
        str += std::to_string(temp->data) + " ";
        temp = temp->next;
    }

    return str;
}