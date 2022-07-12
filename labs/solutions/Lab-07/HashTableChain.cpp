#include "HashTableChain.h"

HashTableChain::HashTableChain(int n){
    this->_table = new std::vector<std::list<int>>(n, std::list<int>(0));
    this->_table_size = n;
}

int HashTableChain::hash(int k){
    return k;
}

void HashTableChain::insert(int k){
    int hash_key = hash(k) % this->_table_size;

    (*this->_table)[hash_key].push_front(k);
}

bool HashTableChain::search(int k){
    int hash_key = hash(k) % this->_table_size;

    for(std::list<int>::iterator it = (*this->_table)[hash_key].begin(); it != (*this->_table)[hash_key].end(); ++it){
        if(*it == k){
            return true;
        }
    }

    return false;
}

void HashTableChain::print_table(){
    for(int i = 0; i < this->_table_size; i++){
        if((*this->_table)[i].size() != 0){
            for(std::list<int>::iterator it = (*this->_table)[i].begin(); it != (*this->_table)[i].end(); ++it){
                std::cout << *it << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}