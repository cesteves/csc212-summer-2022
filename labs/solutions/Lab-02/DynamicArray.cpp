#include "DynamicArray.h"
#include <cstring>

DynamicArray::DynamicArray()
    : m_length(0), m_capacity(0), m_scaling_factor(2.0), m_data(nullptr) {
}

DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity) {
    //..............
    // TODO
    //..............
    this->m_length = 0;
    this->m_capacity = capacity;
    this->m_scaling_factor = scaling_factor;
    this->m_data = new int[this->m_capacity];
}


DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value) {
    //..............
    // TODO
    //..............
    this->m_length = length;
    this->m_capacity = length;
    this->m_scaling_factor = scaling_factor;
    this->m_data = new int[this->m_capacity];

    for(unsigned int i = 0; i < this->m_capacity; i++){
        m_data[i] = default_value;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    // use the assignment operator
    (*this) = other;
}

DynamicArray::~DynamicArray() {
    delete[] m_data;
}

unsigned int DynamicArray::getLength() {
    return m_length;
}

unsigned int DynamicArray::getCapacity() {
    return m_capacity;
}

double DynamicArray::getScalingFactor() {
    return m_scaling_factor;
}

void DynamicArray::setScalingFactor(double value) {
    m_scaling_factor = value;
}

std::string DynamicArray::toString() {
    std::string str("{");
    //..............
    // TODO
    //..............

    for(unsigned int i = 0; i < this->m_length; i++){
        str += std::to_string(this->m_data[i]) + " ";
    }

    str += "}";

    return str;
}

// Helper function to grow/shrink based on the argument given.
void DynamicArray::resize(bool grow){
    double scale;
    if(grow){
        scale = this->m_scaling_factor;
    }else{
        scale = 0.5;
    }

    this->m_capacity *= scale;
    int* temp = new int[this->m_capacity];

    for(unsigned int i = 0; i < this->m_length; i++){
        temp[i] = this->m_data[i];
    }

    delete[] this->m_data;

    this->m_data = temp;
}

void DynamicArray::append(int value) {
    //..............
    // TODO
    //..............

    // Need to resize?
    if(this->m_length == this->m_capacity){
        this->resize(true);
    }

    this->m_data[this->m_length] = value;
    this->m_length++;
}

void DynamicArray::prepend(int value) {
    //..............
    // TODO
    //..............

    // Need to resize?
    if(this->m_length == this->m_capacity){
        this->resize(true);
    }

    for(unsigned int i = this->m_length; i > 0; i--){
        this->m_data[i] = this->m_data[i - 1];
    }

    this->m_data[0] = value;
    this->m_length++;
}

bool DynamicArray::findFirstOf(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    //..............

    for(unsigned int i = 0; i < this->m_length; i++){
        if(this->m_data[i] == value){
            found = true;
            *index = i;
            break;
        }
    }

    return found;
}

bool DynamicArray::findLastOf(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    //..............
    for(unsigned int i = this->m_length; i > 0 ; i--){
        if(this->m_data[i] == value){
            found = true;
            *index = i;
            break;
        }
    }

    return found;
}

void DynamicArray::removeLast() {
    //..............
    // TODO
    //..............
    this->m_data[this->m_length-1] = 0;
    this->m_length--;

    if((float)this->m_length/(float)this->m_capacity < 0.35){
        this->resize(false);
    }

}

void DynamicArray::removeFirst() {
    //..............
    // TODO
    //..............

    for(int i = 0; i < this->m_length; i++){
        this->m_data[i] = this->m_data[i+1];
    }

    this->m_data[this->m_length-1] = 0;
    this->m_length--;

    if((float)this->m_length/(float)this->m_capacity < 0.35){
        this->resize(false);
    }
}

void DynamicArray::clear() {
    //..............
    // TODO
    //..............
    this->m_length = 0;
    this->m_capacity = 0;
    delete[] this->m_data;
    this->m_data = nullptr;
}

int& DynamicArray::operator[](unsigned int index) {
    return m_data[index];
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other) {
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_scaling_factor = other.m_scaling_factor;
    m_data = new int[m_capacity];
    std::memcpy(m_data, other.m_data, sizeof(int) * m_length);
    // this allows statements such as (a = b = c) assuming a, b, and c are all the DynamicArray type
    return (*this);
}