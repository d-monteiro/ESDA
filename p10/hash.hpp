// Adapted from https://www.educba.com/c-plus-plus-hash-table/
#include <iostream>
#include <list>
#include <time.h>
#include <string>

using namespace std;

class HashMapTable{
    private:
        int table_size; // size of the hash table
        list<string> *table; // Pointer to an array containing the keys
    public:
        HashMapTable(int ts); // class constructor
        int hashFunction(string key); // hash function to compute the index using table_size and key length
        void insertElement(string key, int func); // inserting the key in the hash table (0 or 1 for hash function)
        void deleteElement(string key, int func); // deleting the key in the hash table
        void displayHashTable(); // displaying the full hash table
        int search_value(string key, int func); //finding value in hash table through key
        int hashFunctionkrm(string key); // a new hash function to compute the index
        int count_words_starting_char(char c); //counts words starting with a given letter (can be both upper or lowercase - counts as the same letter)


};