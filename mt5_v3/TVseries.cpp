#include "TVseries.hpp"
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>
#include <set>

using namespace std;


/* --- Constructor --- */

TVSeriesAPP::TVSeriesAPP()
{
//Titles
  SeriesMap = unordered_map<string, TitleBasics>();     //from TitleBasics
  PersonMap = unordered_map<string, TitlePrincipals>(); //from TitlePrincipals
  EpisodesMap = unordered_map<string, TitleEpisode>();  //from TitleEpisode

//ToEpisode
  PeopleToEpisodeMap = unordered_multimap<string, TitlePrincipals>(); //from TitlePrincipals
//ToSeries
  EpisodeToSeriesMap = unordered_multimap<string, TitleEpisode>();    //from TitleEpisode
  PeopleToSeriesMap = unordered_multimap<string, TitlePrincipals>();  //from TitlePrincipals
//ToPeople
  SeriesToPeopleMap = unordered_multimap<string, TitleBasics>();      //from TitlePrincipals
  CharacterToPeopleMap = unordered_multimap<string, string>();        //from TitlePrincipals
}


/* --- Destructor --- */

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
  PeopleToSeriesMap.clear();

//ToPeople
  SeriesToPeopleMap.clear();
  CharacterToPeopleMap.clear();
}


/* --- Add Methods --- */

void TVSeriesAPP::addTitleBasics(const TitleBasics& title)  //a TitleBasic is a Series
{
//Title
  SeriesMap[title.tconst] = title;  //add title to SeriesMap
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
  PeopleToSeriesMap.insert({episode->second.parentTconst, principal});  //add principal to PeopleToSeriesMap
//ToPeople
  SeriesToPeopleMap.insert({principal.nconst, getParentSeries(episode->second)});  //add principal to SeriesToPeopleMap
  for(auto character : principal.characters)  //iterate through all characters of principal
  {
    CharacterToPeopleMap.insert({principal.nconst, character}); //add principal to CharacterToPeopleMap
  }
}


/* --- Get Methods --- */

TitleBasics TVSeriesAPP::getSeries(const string& tconst) const{
  return SeriesMap.at(tconst);
}

TitlePrincipals TVSeriesAPP::getPerson(const string& nconst) const{
  return PersonMap.at(nconst);
}

TitleEpisode TVSeriesAPP::getEpisode(const string& tconst){
  return EpisodesMap[tconst];
}

TitleBasics TVSeriesAPP::getParentSeries(const TitleEpisode& episode){
  return SeriesMap[episode.parentTconst];
}



/* --- Answer Methods --- */


//PERGUNTA 1:
vector<string> TVSeriesAPP::getUniquePrincipals(const string& seriesTconst ) const
{
  vector<string> answer; // Create answer vector

  // Check if seriesTconst exists in SeriesMap
  if (SeriesMap.find(seriesTconst) == SeriesMap.end()){
    return answer;
  }
  
  auto people = PeopleToSeriesMap.equal_range(seriesTconst);

  for(auto p = people.first; p != people.second; p++){ // Iterate through all people of the series
    if(find(answer.begin(), answer.end(), p->second.primaryName) == answer.end()){ // If person is not in the answer vector
      answer.push_back(p->second.primaryName); // Add person
    }
  }

  sort(answer.begin(), answer.end()); // Sort answer vector

  return answer;
}



//PERGUNTA 2:
string TVSeriesAPP::getMostSeriesGenre() const
{
  unordered_map<string, int> genreCount; // Create auxiliary map to count genres

  for(const auto& series : SeriesMap){ // Iterate through all series
    for(const auto& genre : series.second.genres){ // And through all genres of each series
      genreCount[genre]++; // Increment genre count
    }
  }

  if(genreCount.empty()) //check if genreCount is empty
  {
    return ""; //return empty string if it is
  }

  return max_element(genreCount.begin(), genreCount.end(),     // Use max_element to find the genre with the highest count
    [](const auto& a, const auto& b){                          // Lambda function to compare genres
      if (a.second != b.second) return a.second < b.second;    // If the count is different, return the genre with the highest count
      else return a.first.size() > b.first.size();             // If the count is the same, return the genre with the highest size
    })->first;                                                 // Return the genre
}



//PERGUNTA 3:
vector<string> TVSeriesAPP::principalsWithMultipleCategories(const string& seriesTconst ) const
{
  //Encontra todas as pessoas que desempenharam diferentes categorias no trabalho 
  //desenvolvido nos episódios em que entraram de determinada série de ID 
  //seriesTconst. Retorna o vetor com o nome das pessoas (primaryName) encontradas, 
  //organizado alfabeticamente. Em caso de erro, retorna um vetor vazio.

  vector<string> answer; // Create answer vector
  unordered_map<string, set<string>> CatCount; // Create auxiliary map to count Categories

  // Check if seriesTconst exists in SeriesMap
  if (SeriesMap.find(seriesTconst) == SeriesMap.end()){
    return answer;
  }
  
  auto people = PeopleToSeriesMap.equal_range(seriesTconst); // Get all people of the series

  for(auto p = people.first; p != people.second; p++){ // Iterate through all people of the series
    CatCount[p->second.nconst].insert(p->second.category); // Add category to the set of categories for this person
  }

  for(auto& person : CatCount){ // Iterate over all people
    if(person.second.size() > 1){ // If person has more than one category
      answer.push_back(getPerson(person.first).primaryName); // Add person to the answer
    }
  }

    sort(answer.begin(), answer.end()); // Sort the answer alphabetically

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

  for(size_t p = 0; p < pplNames.size(); p++) //iterate through all people of the series
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

  sort(answer.begin(), answer.end()); //sort answer vector

  return answer;  //return answer vector
}



//PERGUNTA 5:
int TVSeriesAPP::principalInMultipleGenres(vector<string> vGenres)
{
//Determina o número de pessoas que entraram em séries com géneros correspondentes 
//aos géneros em vGenres, retornando-o.

  if(vGenres.empty()) //check if vGenres is empty
  {
    return 0; //return 0 if it is
  }

  int count = 0;  //initialize count

  auto vGen = vGenres;
  sort(vGen.begin(), vGen.end());

  for(auto person : PersonMap)  //iterate through all people
  {
    bool found = 0; //flag to check if person is InMultipleGenres

    auto seriesFromPerson = SeriesToPeopleMap.equal_range(person.first); //get all series of the person

    for(auto series = seriesFromPerson.first; series != seriesFromPerson.second; series++)  //iterate through all series with that person
    {
      auto seriesGen = series->second.genres;
      sort(seriesGen.begin(), seriesGen.end());

      if(includes(seriesGen.begin(), seriesGen.end(), vGen.begin(), vGen.end()))  //check if the genres of series correspond to vGenres
      {//if it does:
        found = 1;  //set flag to true
        break;      //stop search throughout
      }
    }

    if(found) //if person's series has the genres:
    {
      count++;  //increment count
    }
  }//end iteration through people

  return count; //return count
}



//PERGUNTA 6:
string TVSeriesAPP::getPrincipalFromCharacter(const string& character) const
{
  if(character.empty()) //check if character is empty
  {
    return "";  //return empty string if it is
  }

  unordered_map<string, int> personRoleCount; //create auxiliary map to count roles

  for(const auto person : PersonMap)  //iterate through all people
  {
    personRoleCount[person.second.primaryName] = 0; //initialize personRoleCount for each person with 0

    const auto characterRange = CharacterToPeopleMap.equal_range(person.first); //get all characters of the person

    for(auto personCharacter = characterRange.first; personCharacter != characterRange.second; personCharacter++) //iterate through all characters of the person (if any)
    {
      if(personCharacter->second.find(character) != string::npos) //check if the character is in the person's characters
      {
        personRoleCount[person.second.primaryName]++;  //increment personRoleCount for that person  
      }
    }
  }

  if(personRoleCount.empty()) //check if roleCount is empty
  {
    return ""; //return empty string if it is
  }

  return max_element(personRoleCount.begin(), personRoleCount.end(),  //use max_element to find the person with the highest count
    [](const auto& a, const auto& b){                               //lambda function to compare people by count
      if(a.second != b.second) return a.second < b.second;        //if the count is different, return the person with the highest count
      else return a.first > b.first;                              //if the count is the same, return the person with the lowest name
    })->first;                                                  //return the person's primaryName
}



/* --- Other Functions --- */

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
