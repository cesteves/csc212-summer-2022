#include <vector>
#include <iostream>
class HashTableLinear{
    private:
        std::vector<int>* _table;
        int _table_size;

    public:
        HashTableLinear(int n);
        int hash(int k);
        void insert(int k);
        bool search(int k);
        void print_table();

};