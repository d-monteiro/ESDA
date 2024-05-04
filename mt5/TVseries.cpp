#include "TVseries.hpp"
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

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

Series TVSeriesAPP::getSeries(const string& tconst) const{
  return SeriesMap.at(tconst);
}

Crew TVSeriesAPP::getCrew(const string& tconst) const{
  return CrewMap.at(tconst);
}

Episode TVSeriesAPP::getEpisode(const string& tconst){
  return EpisodesMap[tconst];
}

Series TVSeriesAPP::getParentSeries(const Episode& episode){
  return SeriesMap[episode.parentTconst];
}



//PERGUNTA 1:

vector<string> TVSeriesAPP::getUniquePrincipals(const string& seriesTconst ){
  cout<<getSeries(seriesTconst)<<endl;

  return {};
}



//PERGUNTA 2:

string TVSeriesAPP::getMostSeriesGenre() const{
   

  return "";
}



//PERGUNTA 3:

string TVSeriesAPP::getPrincipalFromCharacter(const string& character) const{

  return "";
}



//PERGUNTA 4:

vector<string> TVSeriesAPP::principalsWithMultipleCategories(const string& seriesTconst ) const{

  return {};
}



//PERGUNTA 5:

int TVSeriesAPP::principalInMultipleGenres(vector<string> vGenres){


  return -1;
}



//PERGUNTA 6:

vector<string> TVSeriesAPP::principalsInAllEpisodes(const string& seriesTconst) const{

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

//Overloading the << operator for Series
ostream& operator<<(ostream& os, const Series& series){
  os << "Series details: " << endl;
  os << "tconst: " << series.tconst << endl;
  os << "titleType: " << series.titleType << endl;
  os << "primaryTitle: " << series.primaryTitle << endl;
  os << "originalTitle: " << series.originalTitle << endl;
  os << "isAdult: " << (series.isAdult ? "Yes" : "No") << endl;
  os << "startYear: " << series.startYear << endl;
  os << "endYear: " << series.endYear << endl;
  os << "runtimeMinutes: " << series.runtimeMinutes << endl;
  os << "genres: ";
  for(const auto& genre : series.genres){
    os << genre << ", ";
  }
  os << endl;

  return os;
}

//Overloading the << operator for Crew
ostream& operator<<(ostream& os, const Crew& crew){
  os << "Crew details: " << endl;
  os << "tconst: " << crew.tconst << endl;
  os << "ordering: " << crew.ordering << endl;
  os << "nconst: " << crew.nconst << endl;
  os << "primaryName: " << crew.primaryName << endl;
  os << "birthYear: " << crew.birthYear << endl;
  os << "category: " << crew.category << endl;
  os << "job: " << crew.job << endl;
  for(const auto& character : crew.characters){
    os << "character: " << character << endl;
  }

  return os;
}

//Overloading the << operator for Episode
ostream& operator<<(ostream& os, const Episode& episode){
  os << "Episode details: " << endl;
  os << "tconst: " << episode.tconst << endl;
  os << "parentTconst: " << episode.parentTconst << endl;
  os << "seasonNumber: " << episode.seasonNumber << endl;
  os << "episodeNumber: " << episode.episodeNumber << endl;

  return os;
}