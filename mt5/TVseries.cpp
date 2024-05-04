#include "TVseries.hpp"
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>

TVSeriesAPP::TVSeriesAPP() {

}
   
TVSeriesAPP::~TVSeriesAPP() {
    
}


void TVSeriesAPP::addTitleBasics(const TitleBasics& title) {
    
 }
void TVSeriesAPP::addTitleEpisodes(const TitleEpisode& episode) {
  
}


void TVSeriesAPP::addTitlePrincipal(const TitlePrincipals& principal) {

    
}



//Pergunta 1:

vector<string> TVSeriesAPP::getUniquePrincipals(const string& seriesTconst ) const {
    
    

    return {};
}

//PERGUNTA 2:



string TVSeriesAPP::getMostSeriesGenre() const {
   

    return "";
}


//PERGUNTA 3: 

string TVSeriesAPP::getPrincipalFromCharacter(const string& character) const {

    return "";
}



//PERGUNTA 4

vector<string> TVSeriesAPP::principalsWithMultipleCategories(const string& seriesTconst ) const {

  return {};
}
 
//PERGUNTA 5:

int TVSeriesAPP::principalInMultipleGenres(vector<string> vGenres) {


return -1;
}


//PERGUNTA 6: 
vector<string> TVSeriesAPP::principalsInAllEpisodes(const string& seriesTconst) const {

    return {};
}















/*Other Functions**/ 
//Custom hash function for strings
size_t customHash(const string& str) {
    const int p = 31; // A prime number
    const int m = 1e9 + 9; // A large prime number

    size_t hash_value = 0;
    size_t p_pow = 1;
    
    // Hash calculation
    for (char c : str) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
