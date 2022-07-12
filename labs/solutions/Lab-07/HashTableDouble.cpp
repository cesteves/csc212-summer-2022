#include "HashTableDouble.h"

HashTableDouble::HashTableDouble(int n){
    this->_table = new std::vector<int>(n, 0);
    this->_table_size = n;
}

int HashTableDouble::hash(int k, int collisions){
    int h1 = hash1(k);
    int h2 = hash2(k);

    return (h1 + (collisions * h2)) % this->_table_size;
}

int HashTableDouble::hash1(int k){
    return k;
}

int HashTableDouble::hash2(int k){
    return k + 3;
}

void HashTableDouble::insert(int k){
    int collisions = 0;
    int hash_key = hash(k, collisions);

    while((*this->_table)[hash_key] != 0){
        collisions++;
        hash_key = hash(k, collisions);
    }

    (*this->_table)[hash_key] = k;
}

bool HashTableDouble::search(int k){
    int collisions = 0;
    int hash_key = hash(k, collisions);

    while((*this->_table)[hash_key] != k && (*this->_table)[hash_key] != 0){
        collisions++;
        hash_key = hash(k, collisions);
    }

    return (*this->_table)[hash_key];
}

void HashTableDouble::print_table(){
    for(int i = 0; i < this->_table_size; i++){
        std::cout << (*this->_table)[i] << std::endl;
    }
    std::cout << std::endl;
}