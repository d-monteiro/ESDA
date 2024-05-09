#include "TVseries.hpp"
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

TVSeriesAPP::TVSeriesAPP(){
  SeriesMap = unordered_map<string, TitleBasics>();
  PersonMap = unordered_map<string, TitlePrincipals>();
  EpisodesMap = unordered_map<string, TitleEpisode>();
  PeopleToEpisodeMap = unordered_multimap<string, TitlePrincipals>();
  EpisodeToSeriesMap = unordered_multimap<string, TitleEpisode>();
  PeopleNameToSeriesMap = unordered_multimap<string, string>();
}
   
TVSeriesAPP::~TVSeriesAPP(){
  SeriesMap.clear();
  PersonMap.clear();
  EpisodesMap.clear();
  PeopleToEpisodeMap.clear();
  EpisodeToSeriesMap.clear();
  PeopleNameToSeriesMap.clear();
}


void TVSeriesAPP::addTitleBasics(const TitleBasics& title){
  SeriesMap[title.tconst] = title;
}

void TVSeriesAPP::addTitleEpisodes(const TitleEpisode& episode){
  EpisodesMap[episode.tconst] = episode;
  EpisodeToSeriesMap.insert({episode.parentTconst, episode});
}


void TVSeriesAPP::addTitlePrincipal(const TitlePrincipals& principal){
  PersonMap[principal.nconst] = principal;
  PeopleToEpisodeMap.insert({principal.tconst, principal});

  auto episode = EpisodesMap.find(principal.tconst);
  PeopleNameToSeriesMap.insert({episode->second.parentTconst, principal.primaryName});
}

void TVSeriesAPP::addPersonToEpisode(const string& episodeTconst, const TitlePrincipals& person){
  PeopleToEpisodeMap.insert({person.tconst, person});
}



TitleBasics TVSeriesAPP::getSeries(const string& tconst) const{
  return SeriesMap.at(tconst);
}

TitlePrincipals TVSeriesAPP::getPerson(const string& tconst) const{
  return PersonMap.at(tconst);
}

TitleEpisode TVSeriesAPP::getEpisode(const string& tconst){
  return EpisodesMap[tconst];
}

TitleBasics TVSeriesAPP::getParentSeries(const TitleEpisode& episode){
  return SeriesMap[episode.parentTconst];
}



//Pergunta 1:

vector<string> TVSeriesAPP::getUniquePrincipals(const string& seriesTconst ) const{
  vector<string> answer;
  vector<TitleEpisode> help;

  // Check if seriesTconst exists in SeriesMap
  if (SeriesMap.find(seriesTconst) == SeriesMap.end()){
    return answer;
  }
 /*
  auto SeriesRange = EpisodeToSeriesMap.equal_range(seriesTconst);

  for(auto& episode = SeriesRange.first; episode != SeriesRange.second; ++episode){
    auto EpsRange = PeopleToEpisodeMap.equal_range(episode->second.tconst);

    for(auto it = EpsRange.first; it != EpsRange.second; ++it){
      /*
      // Check if nconst exists in PersonMap
      if (PersonMap.find(it->second.nconst) == PersonMap.end()){
        continue;
      }
      *//*
      string name = PersonMap.at(it->second.nconst).primaryName;
      if(find(answer.begin(), answer.end(), name) == answer.end()){
        answer.push_back(name);
      }
    }
  }*/

  auto it = PeopleNameToSeriesMap.equal_range(seriesTconst);

  for(auto p = it.first; p != it.second; p++){
    if(find(answer.begin(), answer.end(), p->second) == answer.end()){
      answer.push_back(p->second);
    }
  }

  std::sort(answer.begin(), answer.end());

  return answer;
}



//PERGUNTA 2:

string TVSeriesAPP::getMostSeriesGenre() const{
  unordered_map<string, int> genreCount;

  for (const auto& series : SeriesMap){
    for (const auto& genre : series.second.genres){
      genreCount[genre]++;
    }
  }

  return max_element(genreCount.begin(), genreCount.end(), 
    [](const auto& a, const auto& b){
      if (a.second != b.second) return a.second < b.second;
      else return a.first.size() > b.first.size();
    })->first;
}


//PERGUNTA 3: 

vector<string> TVSeriesAPP::principalsWithMultipleCategories(const string& seriesTconst ) const{

}



//PERGUNTA 4

vector<string> TVSeriesAPP::principalsInAllEpisodes(const string& seriesTconst) const{
  vector<string> answer;

  // Check if seriesTconst exists in SeriesMap
  if (SeriesMap.find(seriesTconst) == SeriesMap.end()){
    return answer;
  }

  const auto epsRange = EpisodeToSeriesMap.equal_range(seriesTconst);
  const auto pplNameRange = PeopleNameToSeriesMap.equal_range(seriesTconst);

  for(auto personName = pplNameRange.first; personName != pplNameRange.second; personName++)
  {
    bool all = 1;
    
    for(auto episode = epsRange.first; episode != epsRange.second; episode++)
    {
      const auto pplRange = PeopleToEpisodeMap.equal_range(episode->second.tconst);

      if(personName->first == episode->second.tconst){
        all = 0;
      }
    }

    if(all){answer.push_back(personName->second);}
  }

  std::sort(answer.begin(), answer.end());

  return answer;
}
 
//PERGUNTA 5:

int TVSeriesAPP::principalInMultipleGenres(vector<string> vGenres){

}


//PERGUNTA 6: 

string TVSeriesAPP::getPrincipalFromCharacter(const string& character) const{

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
ostream& operator<<(ostream& os, const TitleBasics& series){
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
ostream& operator<<(ostream& os, const TitlePrincipals& Person){
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
ostream& operator<<(ostream& os, const TitleEpisode& episode){
  os << "Episode details: " << endl;
  os << "tconst: " << episode.tconst << endl;
  os << "parentTconst: " << episode.parentTconst << endl;
  os << "seasonNumber: " << episode.seasonNumber << endl;
  os << "episodeNumber: " << episode.episodeNumber << endl;

  return os;
}
