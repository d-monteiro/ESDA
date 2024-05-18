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
//Stats
  APPGenres = unordered_set<string>();                                        //from TitleBasics

//Titles
  SeriesMap = unordered_map<string, TitleBasics>();                           //from TitleBasics
  PersonMap = unordered_map<string, TitlePrincipals>();                       //from TitlePrincipals
  EpisodesMap = unordered_map<string, TitleEpisode>();                        //from TitleEpisode

//ToEpisode
  PeopleToEpisodeMap = unordered_multimap<string, TitlePrincipals>();         //from TitlePrincipals
  
//ToSeries
  EpisodeToSeriesMap = unordered_multimap<string, TitleEpisode>();            //from TitleEpisode
  PeopleToSeriesMap = unordered_multimap<string, TitlePrincipals>();          //from TitlePrincipals

//ToPeople
  GenresToPeopleMap = unordered_map<string, unordered_set<string>>();         //from TitlePrincipals
  CharacterToPeopleMap = unordered_map<string, unordered_map<string, int>>(); //from TitlePrincipals

//ToGenres
  GenresCountMap = unordered_map<string, int>();                   //from TitleBasics
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
  GenresToPeopleMap.clear();
  CharacterToPeopleMap.clear();
  
//ToGenres
  GenresCountMap.clear();
}


/* --- Add Methods --- */

void TVSeriesAPP::addTitleBasics(const TitleBasics& title)  //a TitleBasic is a Series
{
//Title
  SeriesMap[title.tconst] = title;  //add title to SeriesMap

//ToGenre
  for(const auto genre : title.genres)  //iterate through all genres of the series
  {
    GenresCountMap[genre]++;  //add genre to SeriesToGenresMap
    APPGenres.insert(genre);  //add genre to APPGenres
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

  PeopleToSeriesMap.insert({episode->second.parentTconst, principal});  //add principal to PeopleToSeriesMap
  
//ToPeople
  TitleBasics series = getParentSeries(episode->second);  //get the series of the episode

  for(auto genre : series.genres)  //iterate through all genres of the series
  {
    GenresToPeopleMap[principal.nconst].insert(genre);  //add the series's genres to GenresToPeopleMap
  }

  for (const auto& character : principal.characters) {
    CharacterToPeopleMap[character][principal.nconst]++;
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



/* --- Custom Hash Methods --- */

/** @brief Hash function to hash TitlePrincipals objects, using the default hash (std::hash) for strings on the nconst */
struct hashPerson
{
  size_t operator()(const TitlePrincipals& person) const
  {
    return hash<string>()(person.nconst);
  }
};

/** @brief Comparison function that allows the comparison between TitlePrincipals objects, comparing them by comparing their nconsts */
struct equalPerson
{
  bool operator()(const TitlePrincipals& person1, const TitlePrincipals& person2) const
  {
    return person1.nconst == person2.nconst;
  }
};



/* --- Answer Methods --- */


//PERGUNTA 1:
vector<string> TVSeriesAPP::getUniquePrincipals(const string& seriesTconst ) const
{
  // Check if seriesTconst exists in SeriesMap
  if (SeriesMap.find(seriesTconst) == SeriesMap.end()){
    return {};
  }
  
  unordered_set<string> uniquePrincipals; // Create a set to store unique principals

  auto people = PeopleToSeriesMap.equal_range(seriesTconst);

  for(auto p = people.first; p != people.second; p++){ // Iterate through all people of the series
    uniquePrincipals.insert(p->second.primaryName); // Add person to the set
  }

  vector<string> answer(uniquePrincipals.begin(), uniquePrincipals.end()); // Convert set to vector
  sort(answer.begin(), answer.end()); // Sort answer vector

  return answer;
}



//PERGUNTA 2:
string TVSeriesAPP::getMostSeriesGenre() const
{
  pair<string, int> MostSeriesGenre = {"", 0};  // Create pair to store the most common genre

  for(const auto& genre : APPGenres){ // Iterate through all genres of the APP
    if(GenresCountMap.at(genre) > MostSeriesGenre.second || (GenresCountMap.at(genre) == MostSeriesGenre.second && genre.size() > MostSeriesGenre.first.size())){
      MostSeriesGenre = {genre, GenresCountMap.at(genre)}; // Update most common genre
    }
  }

  return MostSeriesGenre.first;
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
  if (SeriesMap.find(seriesTconst) == SeriesMap.end())  //check if seriesTconst exists in SeriesMap
  {
    return {};  //return empty vector if it doesn't
  }

  vector<string> answer;  //create answer vector

  const auto epsRange = EpisodeToSeriesMap.equal_range(seriesTconst); //get all episodes of the series
  
  int numTotalEps = distance(epsRange.first, epsRange.second);  //get total number of episodes (InAllEpisodes requirement)

  unordered_set<TitlePrincipals, hashPerson> pplNconst; //set to store unique principals' names
  unordered_map<string, set<string>> EpisodesToPeople;  //map to store all episodes of each person
  
  auto people = PeopleToSeriesMap.equal_range(seriesTconst);  //get all people of the series
  
  for(auto p = people.first; p != people.second; p++) //iterate through all people of the series
  {
    pplNconst.insert(p->second);                                  //add person to pplNames set
    EpisodesToPeople[p->second.nconst].insert(p->second.tconst);  //add episode to person's episodes
  }

  for(const auto person : pplNconst)  //iterate through all people of the series
  {
    if(EpisodesToPeople[person.nconst].size() == numTotalEps)  //if person is InAllEpisodes:
    {
      answer.push_back(person.primaryName); //add person to answer vector
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

  vector<string> vGen(vGenres.begin(), vGenres.end());  //create vector with all genres of vGenres
  sort(vGen.begin(), vGen.end());

  for(auto person : PersonMap)  //iterate through all people
  {
    vector<string> personGenres(GenresToPeopleMap[person.first].begin(), GenresToPeopleMap[person.first].end());
    sort(personGenres.begin(), personGenres.end());

    if(includes(personGenres.begin(), personGenres.end(), vGen.begin(), vGen.end())) //if it does:
    {
      count++;  //increment count
    }
  }//end iteration through people

  return count; //return count
}



//PERGUNTA 6:
string TVSeriesAPP::getPrincipalFromCharacter(const string& character) const
{
  //Encontra a pessoa que representou mais vezes determinada personagem (character) 
  //nos episódios. No caso de a contagem resultar em empate, é selecionada a que se 
  //encontra alfabeticamente à frente. Retorna o nome da pessoa (primaryName) 
  //encontrada, ou uma string vazia em caso de erro.

  string answer;

  if(character.empty()) return answer;  // Check for faulty parameters

  int maxCount = 0;
  string maxActorId;

  for(const auto& entry : CharacterToPeopleMap){
    if(entry.first.find(character) != string::npos){  // Check if the character is a substring of the key
      for(const auto& actorCountPair : entry.second){
        // If this actor has appeared more times, or the same number of times but is lexicographically smaller
        if(actorCountPair.second > maxCount || 
          (actorCountPair.second == maxCount && actorCountPair.first < maxActorId)){
          maxActorId = actorCountPair.first;
          maxCount = actorCountPair.second;
        }
      }
    }
  }

  if (!maxActorId.empty()) {
    answer = PersonMap.find(maxActorId)->second.primaryName;
  }

  return answer;
}




/* --- Operator Overloading Functions --- */

//Overloading the == operator for Person
bool operator==(const TitlePrincipals& person1, const TitlePrincipals& person2){
  return person1.nconst == person2.nconst;
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
