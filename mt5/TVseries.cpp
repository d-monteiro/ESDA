#include "TVseries.hpp"
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>

TVSeriesAPP::TVSeriesAPP(){
  SeriesMap = unordered_map<string, Series>();
  CrewMap = unordered_map<string, Crew>();
  EpisodesMap = unordered_map<string, Episode>();
}
   
TVSeriesAPP::~TVSeriesAPP(){
  SeriesMap.clear();
  CrewMap.clear();
  EpisodesMap.clear();
}

void TVSeriesAPP::addSeries(const Series& title) {
  SeriesMap[title.tconst] = title;
}

void TVSeriesAPP::addEpisode(const Episode& episode){
  EpisodesMap[episode.tconst] = episode;
}

void TVSeriesAPP::addCrew(const Crew& principal){ 
  CrewMap[principal.tconst] = principal;   
}

Series TVSeriesAPP::getCrew(const string& tconst) {
  return SeriesMap[tconst];
}

Episode TVSeriesAPP::getEpisode(const string& tconst) {
  return EpisodesMap[tconst];
}

Series TVSeriesAPP::getParentSeries(const Episode& episode) {
  return SeriesMap[episode.parentTconst];
}



//PERGUNTA 1:

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



//PERGUNTA 4:

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