#include "TVseries.hpp"
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;


TVSeriesAPP::TVSeriesAPP()
{
//Titles
  SeriesMap = unordered_map<string, TitleBasics>();     //from TitleBasics
  PersonMap = unordered_map<string, TitlePrincipals>(); //from TitlePrincipals
  EpisodesMap = unordered_map<string, TitleEpisode>();  //from TitleEpisode
//ToEpisode
  PeopleToEpisodeMap = unordered_multimap<string, TitlePrincipals>(); //from TitlePrincipals
//ToSeries
  EpisodeToSeriesMap = unordered_multimap<string, TitleEpisode>();  //from TitleEpisode
  PeopleNameToSeriesMap = unordered_multimap<string, string>();     //from TitlePrincipals
//ToPeople
  SeriesToPeopleMap = unordered_multimap<string, TitleBasics>();  //from TitlePrincipals
//ToGenres
  SeriesToGenresMap = unordered_multimap<string, TitleBasics>();  //from TitleBasics
}
/*
  PeopleToGenresMap = unordered_multimap<string, string>();

  SeriesToEpisodesMap = unordered_multimap<string, string>();
*/
TVSeriesAPP::~TVSeriesAPP()
{
//Titles
  SeriesMap.clear();
  PersonMap.clear();
  EpisodesMap.clear();
//ToEpisode
  PeopleToEpisodeMap.clear();
//ToSeries
  EpisodeToSeriesMap.clear();
  PeopleNameToSeriesMap.clear();
//ToPeople
  SeriesToPeopleMap.clear();
//ToGenres
  SeriesToGenresMap.clear();
}


void TVSeriesAPP::addTitleBasics(const TitleBasics& title)  //a TitleBasic is a Series
{
//Title
  SeriesMap[title.tconst] = title;  //add title to SeriesMap
//ToGenres
  for(size_t g = 0; g < title.genres.size(); g++)  //iterate through all genres of the title
  {
    SeriesToGenresMap.insert({title.genres[g], title});  //add title to SeriesToGenresMap
  }
}

void TVSeriesAPP::addTitleEpisodes(const TitleEpisode& episode) //a TitleEpisode is an Episode
{
//Title
  EpisodesMap[episode.tconst] = episode;  //add episode to EpisodesMap
//ToSeries
  EpisodeToSeriesMap.insert({episode.parentTconst, episode}); //add episode to EpisodeToSeriesMap
}

void TVSeriesAPP::addTitlePrincipal(const TitlePrincipals& principal) //a TitlePrincipal is a Person
{
//Title
  PersonMap[principal.nconst] = principal;  //add principal to PersonMap
//ToEpisode
  PeopleToEpisodeMap.insert({principal.tconst, principal}); //add principal to PeopleToEpisodeMap
//ToSeries
  auto episode = EpisodesMap.find(principal.tconst);  //find episode in EpisodesMap
  PeopleNameToSeriesMap.insert({episode->second.parentTconst, principal.primaryName});  //add principal's primaryName to PeopleNameToSeriesMap
//ToPeople
  SeriesToPeopleMap.insert({principal.nconst, getParentSeries(episode->second)});  //add principal to SeriesToPeopleMap
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



//PERGUNTA 1:

vector<string> TVSeriesAPP::getUniquePrincipals(const string& seriesTconst ) const
{
  vector<string> answer;
  //vector<TitleEpisode> help;

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

  auto pplNames = PeopleNameToSeriesMap.equal_range(seriesTconst);

  for(auto p = pplNames.first; p != pplNames.second; p++){
    if(find(answer.begin(), answer.end(), p->second) == answer.end()){
      answer.push_back(p->second);
    }
  }

  std::sort(answer.begin(), answer.end());

  return answer;
}



//PERGUNTA 2:

string TVSeriesAPP::getMostSeriesGenre() const
{
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

vector<string> TVSeriesAPP::principalsWithMultipleCategories(const string& seriesTconst ) const
{
  vector<string> answer;
  return answer;
}



//PERGUNTA 4:

vector<string> TVSeriesAPP::principalsInAllEpisodes(const string& seriesTconst) const
{
  vector<string> answer;  //create answer vector

  if (SeriesMap.find(seriesTconst) == SeriesMap.end())  //check if seriesTconst exists in SeriesMap
  {
    return answer;  //return empty vector if it doesn't
  }

  const auto epsRange = EpisodeToSeriesMap.equal_range(seriesTconst); //get all episodes of the series
  const auto pplNames = getUniquePrincipals(seriesTconst);            //get all people of the series

  for(auto p = 0; p < pplNames.size(); p++) //iterate through all people of the series
  {
    bool all = 1; //flag to check if person is in all episodes
    
    for(auto episode = epsRange.first; episode != epsRange.second; episode++) //iterate through all episodes of the series
    {
      bool found = 0; //flag to check if person is in the episode

      const auto pplRange = PeopleToEpisodeMap.equal_range(episode->second.tconst); //get all people of the episode

      for(auto person = pplRange.first; person != pplRange.second; person++)  //iterate through all people of the episode
      {//check if person is in the episode
        if(pplNames[p] == person->second.primaryName) //search person in the episode
        {//if person is in the episode:
          found = 1;  //set flag to true
          break;      //end search in the episode
        }
      }//end of search in the episode

      if(!found)  //if person is not in the episode:
      {
        all = 0;  //set flag to false
        break;    //end search in all episodes
      }
    }//end of search in all episodes

    if(all) //if person is in all episodes:
    {
      answer.push_back(pplNames[p]);  //add person to answer vector
    }
  }

  std::sort(answer.begin(), answer.end());  //sort answer vector

  return answer;  //return answer vector
}
 
//PERGUNTA 5:

int TVSeriesAPP::principalInMultipleGenres(vector<string> vGenres)
{
  if(vGenres.empty()) //check if vGenres is empty
  {
    return 0; //return 0 if it is
  }

  int count = 0;  //initialize count

  for(auto person: PersonMap) //iterate through all people
  {
    bool found = 0; //flag to check if person is InMultipleGenres

    auto seriesFromPerson = SeriesToPeopleMap.equal_range(person.first); //get all series of the person
/*                        /!\ UNDER CONSTRUCTION /!\
    for(auto series =)
    for(auto genre: vGenres)  //iterate through all genres
    {
      if(find(person.second.genres.begin(), person.second.genres.end(), genre) != person.second.genres.end())
      {
        found = 1;
        break;
      }
    }
*/
    if(found)
    {
      count++;
    }
  }

  return count;
}


//PERGUNTA 6:

string TVSeriesAPP::getPrincipalFromCharacter(const string& character) const
{
  string answer;
  return answer;
}



/*Other Functions*/ 

//Custom hash function for strings
size_t customHash(const string& str) {
  const int p = 31;       // A prime number
  const int m = 1e9 + 9;  // A large prime number

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
