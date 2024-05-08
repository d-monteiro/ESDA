#include "TVseries.hpp"
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

TVSeriesAPP::TVSeriesAPP(){
  SeriesMap = unordered_map<string, Series>();
  PersonMap = unordered_map<string, Person>();
  EpisodesMap = unordered_map<string, Episode>();
  PeopleToEpisodeMap = unordered_multimap<string, Person>();
}
   
TVSeriesAPP::~TVSeriesAPP(){
  SeriesMap.clear();
  PersonMap.clear();
  EpisodesMap.clear();
  PeopleToEpisodeMap.clear();
}

void TVSeriesAPP::addTitleBasic(const Series& title) {
  SeriesMap[title.tconst] = title;
}

void TVSeriesAPP::addTitleEpisode(const Episode& episode){
  EpisodesMap[episode.tconst] = episode;
}

void TVSeriesAPP::addTitlePrincipals(const Person& principal){ 
  PersonMap[principal.nconst] = principal;
  PeopleToEpisodeMap.insert({principal.tconst, principal});
}

void TVSeriesAPP::addPersonToEpisode(const string& episodeTconst, const Person& person){
  PeopleToEpisodeMap.insert({person.tconst, person});
}



Series TVSeriesAPP::getSeries(const string& tconst) const{
  return SeriesMap.at(tconst);
}

Person TVSeriesAPP::getPerson(const string& tconst) const{
  return PersonMap.at(tconst);
}

Episode TVSeriesAPP::getEpisode(const string& tconst){
  return EpisodesMap[tconst];
}

Series TVSeriesAPP::getParentSeries(const Episode& episode){
  return SeriesMap[episode.parentTconst];
}



//PERGUNTA 1:

vector<string> TVSeriesAPP::getUniquePrincipals(const string& seriesTconst ){
  unordered_set<string> uniqueNames;

  for(auto i = EpisodesMap.begin(); i != EpisodesMap.end(); ++i){
    if(i->second.parentTconst == seriesTconst) {
      auto range = PeopleToEpisodeMap.equal_range(i->second.tconst);

      for(auto it = range.first; it != range.second; ++it){
        string name = PersonMap.at(it->second.nconst).primaryName;
        uniqueNames.insert(name);
      }
    }
  }

  vector<string> answer(uniqueNames.begin(), uniqueNames.end());
  sort(answer.begin(), answer.end());

  return answer;
}



//PERGUNTA 2:

string TVSeriesAPP::getMostSeriesGenre() const{
  unordered_map<string, int> genreCount;
cout<<SeriesMap.size()<<endl;
int i = 0;
  for (const auto& series : SeriesMap){
    for (const auto& genre : series.second.genres){
      genreCount[genre]++;
      i++;
    }
  }
cout<<i<<endl;
  for (const auto& genre : genreCount){
    cout << genre.first << ": " << genre.second << endl;
  }

  return max_element(genreCount.begin(), genreCount.end(), 
    [](const auto& a, const auto& b){
      if (a.second != b.second) return a.second < b.second;
      else return a.first.size() > b.first.size();
    })->first;
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
    os << genre << " ";
  }
  os << endl;

  return os;
}

//Overloading the << operator for Person
ostream& operator<<(ostream& os, const Person& Person){
  os << "Person details: " << endl;
  os << "tconst: " << Person.tconst << endl;
  os << "ordering: " << Person.ordering << endl;
  os << "nconst: " << Person.nconst << endl;
  os << "primaryName: " << Person.primaryName << endl;
  os << "birthYear: " << Person.birthYear << endl;
  os << "category: " << Person.category << endl;
  os << "job: " << Person.job << endl;
  for(const auto& character : Person.characters){
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