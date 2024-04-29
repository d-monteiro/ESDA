#include "hash.hpp"

void comparetime_hash(string arr1[]){
    //ALINEA D)
}

int main(){




    // array of all the keys to be inserted in hash table
    string arr[] = {"Luis", "Miguel", "Joana", "Catarina", "Afonso", "Luana", "Carlos", "leandro"};
    int n = sizeof(arr)/sizeof(arr[0]);
  //  int n=arr->size();

    // table_size of hash table as 6
    HashMapTable ht(n);
    for (int i = 0; i< n; i++)
    ht.insertElement(arr[i], 0);
   

    // deleting element Miguel from the hash table
    ht.deleteElement("Miguel",0);
    // displaying the final data of hash table
    ht.displayHashTable(); 

    
    //testing search value
    string value = "Joana";
    cout<< "Searching for value "<< value << " and returning position "<< ht.search_value(value, 0) << endl;
    value = "João"; 
    cout<< "Searching for value "<< value << " and returning position "<< ht.search_value(value, 0) << endl;
    
    //testing new hash function

    // table_size of hash table as 6
    HashMapTable ht2(n);
    for (int i = 0; i< n; i++)
    ht2.insertElement(arr[i], 1);
    // deleting element 34 from the hash table
    ht2.deleteElement("Luis",1);
    // displaying the final data of hash table
    ht2.displayHashTable();
    
        //testing search value
    value = "Joana";
    cout<< "Searching for value "<< value << " and returning position "<< ht2.search_value(value, 0) << endl;
    value = "João"; 
    cout<< "Searching for value "<< value << " and returning position "<< ht2.search_value(value, 0) << endl;
    
    //testing times for both hash functions
    comparetime_hash(arr);



    //testing count chars
    char c = 'b';
    cout<< "Searching for char "<< c << " and found "<< ht2.count_words_starting_char(c) << " words beginning with it"<<  endl;
    c = 'c';
    cout<< "Searching for char "<< c << " and found "<< ht2.count_words_starting_char(c) << " words beginning with it"<<  endl;
    
    
    return 0;


}