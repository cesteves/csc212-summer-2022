#include <vector>
#include <iostream>
#include <list>

class HashTableChain{
    private:
        std::vector<std::list<int>>* _table;
        int _table_size;

    public:
        HashTableChain(int n);
        int hash(int k);
        void insert(int k);
        bool search(int k);
        void print_table();

};