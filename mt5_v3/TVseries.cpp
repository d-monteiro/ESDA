#include "TVseries.hpp"
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;



/**  Constructor */

TVSeriesAPP::TVSeriesAPP()
{
//Titles
  SeriesMap = unordered_map<string, TitleBasics>();     //from TitleBasics
  PersonMap = unordered_map<string, TitlePrincipals>(); //from TitlePrincipals
  EpisodesMap = unordered_map<string, TitleEpisode>();  //from TitleEpisode

//ToEpisode
  PeopleToEpisodeMap = unordered_multimap<string, TitlePrincipals>();           //from TitlePrincipals
//ToSeries
  EpisodeToSeriesMap = unordered_multimap<string, TitleEpisode>();              //from TitleEpisode
  PeopleNameToSeriesMap = unordered_multimap<string, string>();                 //from TitlePrincipals
//ToPeople
  SeriesToPeopleMap = unordered_multimap<string, TitleBasics>();                //from TitlePrincipals
  CharacterToPeopleMap = unordered_map<string, unordered_map<string, int>>();   //from Characters
//ToGenres
  SeriesToGenresMap = unordered_multimap<string, TitleBasics>();                //from TitleBasics
}



/**  Destructor */

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
  CharacterToPeopleMap.clear();
//ToGenres
  SeriesToGenresMap.clear();
}



/**  Add Methods */

void TVSeriesAPP::addTitleBasics(const TitleBasics& title)  //a TitleBasic is a Series
{
  SeriesMap[title.tconst] = title;  //add title to SeriesMap

  for(size_t g = 0; g < title.genres.size(); g++)  //iterate through all genres of the title
  {
    SeriesToGenresMap.insert({title.genres[g], title});  //add title to SeriesToGenresMap
  }
}

void TVSeriesAPP::addTitleEpisodes(const TitleEpisode& episode) //a TitleEpisode is an Episode
{
  EpisodesMap[episode.tconst] = episode;  //add episode to EpisodesMap
  EpisodeToSeriesMap.insert({episode.parentTconst, episode}); //add episode to EpisodeToSeriesMap
}

void TVSeriesAPP::addTitlePrincipal(const TitlePrincipals& principal) //a TitlePrincipal is a Person
{
  PersonMap[principal.nconst] = principal;  //add principal to PersonMap
  PeopleToEpisodeMap.insert({principal.tconst, principal}); //add principal to PeopleToEpisodeMap

  auto episode = EpisodesMap.find(principal.tconst);  //find episode in EpisodesMap

  PeopleNameToSeriesMap.insert({episode->second.parentTconst, principal.primaryName});  //add principal's primaryName to PeopleNameToSeriesMap
  SeriesToPeopleMap.insert({principal.nconst, getParentSeries(episode->second)});  //add principal to SeriesToPeopleMap

  // Iterate over each character the principal has played
  for (const auto& character : principal.characters){
    // If the character is not yet in the map, add it
    if (CharacterToPeopleMap.find(character) == CharacterToPeopleMap.end()){
      CharacterToPeopleMap[character] = unordered_map<string, int>();
    }
    // If the principal has not yet been associated with this character, add them
    if (CharacterToPeopleMap[character].find(principal.primaryName) == CharacterToPeopleMap[character].end()){
      CharacterToPeopleMap[character][principal.primaryName] = 0;
    }
    // Increment the count of how many times the principal has played this character
    CharacterToPeopleMap[character][principal.primaryName]++;
  }
}



/** Get Methods */

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
  vector<string> answer;  // Create answer vector

  // Check if seriesTconst exists in SeriesMap
  if (SeriesMap.find(seriesTconst) == SeriesMap.end()){
    return answer;
  }

  auto people = PeopleNameToSeriesMap.equal_range(seriesTconst);

  for(auto p = people.first; p != people.second; p++){ // Iterate through all people of the series
    if(find(answer.begin(), answer.end(), p->second) == answer.end()){ // If person is not in the answer vector
      answer.push_back(p->second); // Add person
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

  return max_element(genreCount.begin(), genreCount.end(),     // Use max_element to find the genre with the highest count
    [](const auto& a, const auto& b){                          // Lambda function to compare genres
      if (a.second != b.second) return a.second < b.second;    // If the count is different, return the genre with the highest count
      else return a.first.size() > b.first.size();             // If the count is the same, return the genre with the highest size
    })->first;                                                 // Return the genre
}



//PERGUNTA 3:

vector<string> TVSeriesAPP::principalsWithMultipleCategories(const string& seriesTconst ) const
{
  vector<string> answer; // Create answer vector
  unordered_multimap<string, TitlePrincipals> CatCount; // Create auxiliary map to count Categories

  // Check if seriesTconst exists in SeriesMap
  if (SeriesMap.find(seriesTconst) == SeriesMap.end()){
    return answer;
  }

  //Encontra todas as pessoas que desempenharam diferentes categorias no trabalho 
  //desenvolvido nos episódios em que entraram de determinada série de ID 
  //seriesTconst. Retorna o vetor com o nome das pessoas (primaryName) encontradas, 
  //organizado alfabeticamente. Em caso de erro, retorna um vetor vazio.


  auto people = PeopleToEpisodeMap.equal_range(seriesTconst); // Get all people of the series

  for(auto p = people.first; p != people.second; p++){ // Iterate through all people of the series

  }

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

  sort(answer.begin(), answer.end());  //sort answer vector

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

  for(auto person : PersonMap) //iterate through all people
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

  // Print the map for debugging
  for (const auto& characterPair : CharacterToPeopleMap) {
    cout << "Character: " << characterPair.first << endl;
    for (const auto& personPair : characterPair.second) {
      cout << "  Person: " << personPair.first << ", Count: " << personPair.second << endl;
    }
  }
  cout<<endl<<endl;

  string answer;

  if(character.empty()) return answer;  // Check for faulty parameters

for (const auto& pair : CharacterToPeopleMap) {
  cout << "Key: " << pair.first << '\n';
}
cout << "Searching for: " << "\"Raul\""<< '\n';

auto it = CharacterToPeopleMap.find("\"Raul\"");
if (it != CharacterToPeopleMap.end()) {
    return max_element(it->second.begin(), it->second.end(), 
      [](const auto& a, const auto& b) return a.second < b.second;
    );
}
/*
// Initialize maximum count and corresponding actor
int maxCount = 0;
string maxActorId;
for (auto it = people.first; it != people.second; ++it) {
  const auto& actorCountPair = *it;
  // If this actor has appeared more times, or the same number of times but is lexicographically smaller
  if (actorCountPair.second > maxCount || 
      (actorCountPair.second == maxCount && actorCountPair.first < maxActorId)) {
    maxActorId = actorCountPair.first;
    maxCount = actorCountPair.second;
  }
}

*/
}



/** Other Functions */ 

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