#include "linked-list.h"
#include <iostream>

LinkedList::LinkedList(){
    this->head = nullptr;
    this->size = 0;
}
/*
LinkedList::~LinkedList(){
    if (this->head){
        delete this->head;
    }
    this->head = nullptr;
}*/

LinkedList::LinkedList(int data){
    this->head = new Node(data);
    this->size = 1;
}

LinkedList::~LinkedList(){
    /*
    Node* curr = this->head;
    Node* prev = nullptr;

    while(curr != nullptr){
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    */

    delete this->head;

    this->head = nullptr;
}

LinkedList::LinkedList(std::vector<int> vec){
    if(vec.size() == 0){
        this->head = nullptr;
        this->size = 0;
    }else{
        this->head = new Node(vec[0]);
        Node* temp = this->head;

        for(int i = 1; i < vec.size(); i++){
            temp->next = new Node(vec[i]);
            temp = temp->next;
            // ->    de-reference + dot operator
            //temp = (*temp).next;
        }
    }
    this->size = vec.size();
}

// O(1)
void LinkedList::push_front(int data){
    if(this->head == nullptr){
        this->head = new Node(data);
        // Assign tail
    }else{
        Node* tmp = new Node(data, this->head);
        //tmp->next = this->head;
        this->head = tmp;
    }
    this->size++;
}

// O(n)
void LinkedList::push_back(int data){
    if(this->head == nullptr){
        this->head = new Node(data);
        // Assign tail
    }else{
        Node* tmp = this->head;

        while(tmp->next != nullptr){
            tmp = tmp->next;
        }

        tmp->next = new Node(data);
    }

    this->size++;
}

void LinkedList::insert(int data, int idx){
    if(!this->head){    // this->head == nullptr
        this->head = new Node(data);
    }else if(idx == 0){
        this->push_front(data);
        return;
    }else if(this->size < idx){
        this->push_back(data);
        return;
    }else{
        Node* tmp = this->head;
        while(idx > 1){
            tmp = tmp->next;
            idx--;
        }
        Node* tmp2 = new Node(data, tmp->next);
        //tmp2->next = tmp->next;
        tmp->next = tmp2;
    }
    this->size++;
}

void LinkedList::remove(int data){
    Node* tmp = this->head;
    Node* prev = nullptr;

    while(tmp != nullptr && tmp->data != data){
        prev = tmp;
        tmp = tmp->next;
    }

    if(tmp != nullptr){
        //while(tmp != nullptr){
            prev->next = tmp->next;
            // Without this, the Node destructor will delete
            // every element in the list after 'temp'
            tmp->next = nullptr;
            delete tmp;

            this->size--;
            //tmp = prev->next;
           // return;
       //}
    }else{
        std::cout << data << " does not exist!" << std::endl;
    }
}

bool LinkedList::contains(int data){
    Node* tmp = this->head;

    while(tmp != nullptr){
        if(tmp->data == data){
            return true;
        }
        tmp = tmp->next;
    }

    return false;
}

int LinkedList::get_size(){
    return this->size;
}

std::string LinkedList::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while(tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}
