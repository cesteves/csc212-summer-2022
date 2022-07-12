#include "HashTableLinear.h"

HashTableLinear::HashTableLinear(int n){
    this->_table = new std::vector<int>(n, 0);
    this->_table_size = n;
}

int HashTableLinear::hash(int k){
    return k % this->_table_size;
}

void HashTableLinear::insert(int k){
    int hash_key = hash(k) % this->_table_size;

    while((*this->_table)[hash_key] != 0){
        hash_key++;
    }

    (*this->_table)[hash_key] = k;
}

bool HashTableLinear::search(int k){
    int hash_key = hash(k) % this->_table_size;

    while((*this->_table)[hash_key % this->_table_size] != k && (*this->_table)[hash_key % this->_table_size] != 0){
         hash_key++;
    }

    return (*this->_table)[hash_key];
}

void HashTableLinear::print_table(){
    for(int i = 0; i < this->_table_size; i++){
        std::cout << (*this->_table)[i] << std::endl;
    }
    std::cout << std::endl;
}