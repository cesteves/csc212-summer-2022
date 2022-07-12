#include <vector>
#include <iostream>
class HashTableDouble{
    private:
        std::vector<int>* _table;
        int _table_size;

    public:
        HashTableDouble(int n);
        int hash(int k, int collisions);
        int hash1(int k);
        int hash2(int k);
        void insert(int k);
        bool search(int k);
        void print_table();

};