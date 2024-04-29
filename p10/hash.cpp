#include "hash.hpp"



HashMapTable::HashMapTable(int ts){ // Constructor -- creating the hash table
    this->table_size = ts;
    table = new list<string>[table_size];
}

int HashMapTable::hashFunction(string key) { // HASH function
    return (key.length() % table_size);
}

int HashMapTable::hashFunctionkrm(string key){
    int answer = 7;

    for (size_t i = 0; i < key.length(); ++i) {
        answer += key[i]; // hash(i) = hash(i-1) + key[i]
    }
    
    return answer % table_size;
}

void HashMapTable::insertElement(string key, int func){ // insert - push the keys in hash table
    if(func == 0){
        int index = hashFunction(key);
        table[index].push_back(key);

    } else if (func == 1){
        int index = hashFunctionkrm(key);
        table[index].push_back(key);
    }

    
}


int HashMapTable::search_value(string key, int func){ 
  if(key.empty()) return -1;    
    
  if(func == 0){
    for(auto index : table[hashFunction(key)])
      if(index == key) return hashFunction(key);
  }
 
  else if(func == 1){
    for(auto index : table[hashFunctionkrm(key)])
      if(index == key) return hashFunctionkrm(key);
  }
  
  return -1;
}


int HashMapTable::search_value(string key, int func){ 
  if(key.empty()) return -1;    
    
  if(func == 0){
    for(auto index : table[hashFunction(key)])
      if(index == key) return hashFunction(key);
  }
 
  else if(func == 1){
    for(auto index : table[hashFunctionkrm(key)])
      if(index == key) return hashFunctionkrm(key);
  }
  
  return -1;
}


void HashMapTable::displayHashTable() {
    //for (inti = 0; i<table_size; i++) {
    for (int i = 0; i<table_size; i++) {
        cout<<i;
        // traversing at the recent/ current index
        for (auto j : table[i])
            cout<< " ==> " << j;
            cout<<endl;
    }
    
}


int HashMapTable::count_words_starting_char(char c){
    //ALINEA E
} 





