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
}
   
TVSeriesAPP::~TVSeriesAPP(){
  SeriesMap.clear();
  PersonMap.clear();
  EpisodesMap.clear();
  PeopleToEpisodeMap.clear();
}


void TVSeriesAPP::addTitleBasics(const TitleBasics& title){
  SeriesMap[title.tconst] = title;
}

void TVSeriesAPP::addTitleEpisodes(const TitleEpisode& episode){
  EpisodesMap[episode.tconst] = episode;
}


void TVSeriesAPP::addTitlePrincipal(const TitlePrincipals& principal){
  PersonMap[principal.nconst] = principal;
  PeopleToEpisodeMap.insert({principal.tconst, principal});
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

  for(auto i = EpisodesMap.begin(); i != EpisodesMap.end(); ++i){
    if(i->second.parentTconst == seriesTconst) help.push_back(i->second);
  }

  for(const auto& episode : help){
    auto range = PeopleToEpisodeMap.equal_range(episode.tconst);

    for(auto it = range.first; it != range.second; ++it){
      string name = PersonMap.at(it->second.nconst).primaryName;
      if(find(answer.begin(), answer.end(), name) == answer.end()){
        answer.push_back(name);
      }
    }
  }

  sort(answer.begin(), answer.end());

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

string TVSeriesAPP::getPrincipalFromCharacter(const string& character) const{

    return "";
}



//PERGUNTA 4

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













