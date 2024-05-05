#ifndef TVSERIES_HPP
#define TVSERIES_HPP

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std; 

class Series; /** @brief Class to represent a TVSerie. */
class Person; /** @brief Class to represent the a Person or a Cast associated to a episode */
class Episode; /** @brief Class to represent each episode  */

class TVSeriesAPP; /** @brief Class to represent a APP TVSeries Management */



/** @brief Class to represent TitleBasics. */
class Series {
public:
  /* ATTRIBUTES */
  string tconst; /** @brief alphanumeric unique identifier of the title */
  string titleType; /** @brief the type/format of the title (e.g. movie, short, tvseries, tvepisode, video, etc) */
  string primaryTitle; /** @brief the more popular title / the title used by the filmmakers on promotional materials at the point of release */
  string originalTitle; /** @brief original title, in the original language */
  bool isAdult; /** @brief 0: non-adult title; 1: adult title */
  int startYear; /** @brief represents the release year of a title. In the case of TV Series, it is the series start year */
  int endYear; /** @brief TV Series end year. ‘\N’ for all other title types */
  int runtimeMinutes; /** @brief primary runtime of the title, in minutes */
  vector<string> genres; /** @brief includes up to three genres associated with the title */

  friend ostream& operator<<(ostream& os, const Series& series);
};

/** @brief Class to represent TitlePrincipals. */
class Person {
public:
  /* ATTRIBUTES */
  string tconst;  /** @brief alphanumeric unique identifier of the episode */ 
  int ordering; /** @brief a number to uniquely identify rows for a given titleId */
  string nconst; /** @brief alphanumeric unique identifier of the name/person */
  string primaryName; /** @brief name by which the person is most often credited */
  int birthYear; /** @brief  in YYYY format */
  string category; /** @brief  the category of job that person was in */
  string job; /** @brief the specific job title if applicable, else '\N' */
  vector<string> characters; /** @brief the name of the character played if applicable, else '\N' */
    
  friend ostream& operator<<(ostream& os, const Person& Person);
};

/** @brief Class to represent TitleEpisode.  */
class Episode {
public:
  /* ATTRIBUTES */
  string tconst; /** @brief alphanumeric identifier of episode */
  string parentTconst; /** @brief alphanumeric identifier of the parent TV Series */
  int seasonNumber; /** @brief season number the episode belongs to */
  int episodeNumber; /** @brief episode number of the tconst in the TV series */

  friend ostream& operator<<(ostream& os, const Episode& episode);
};




/** @brief Class to represent a APP TVSeries Management */
class TVSeriesAPP {
private:
  unordered_map<string, Series> SeriesMap; /** @brief Map to store the Series objects */
  unordered_map<string, Person> PersonMap; /** @brief Map to store the Person objects */
  unordered_map<string, Episode> EpisodesMap; /** @brief Map to store the Episodes objects */
  unordered_multimap<string, Person> PeopleToEpisodeMap; /** @brief Map Person objects to a given Episode */

public:
  /* --- Constructor --- */
  TVSeriesAPP();



  /* --- Destructor --- */
  ~TVSeriesAPP();



  /* --- Add Methods --- */

  /** @brief add TitleBasic to TVSeriesAPP */
  void addSeries(const Series& title);

  /** @brief add TitleEpisode to TVSeriesAPP  */
  void addEpisode(const Episode& episode);

  /** @brief add TitlePrincipals to TVSeriesAPP */
  void addPerson(const Person& principal);

  /** @brief add Person to a Series */
  void addPersonToEpisode(const string& episodeTconst, const Person& person);



  /* --- Get Methods --- */

  /** @brief get TitleBasics given a tconst */
  Series getSeries(const string& tconst) const;

  /** @brief get TitlePrincipals given a tconst */
  Person getPerson(const string& tconst) const;

  /** @brief get TitleEpisodes given a tconst */
  Episode getEpisode(const string& tconst);

  /** @brief get Parent Series given a episode */
  Series getParentSeries(const Episode& episode);



  /* --- Answer Methods --- */

  //PERGUNTA 1
  vector<string> getUniquePrincipals(const string& seriesTconst );

  //PERGUNTA 2
  string getMostSeriesGenre() const;

  //PERGUNTA 3
  vector<string> principalsWithMultipleCategories(const string& seriesTconst) const;

  //PERGUNTA 4
  vector<string> principalsInAllEpisodes(const string& seriesTconst) const;

  //PERGUNTA 5
  int principalInMultipleGenres(vector<string> vGenres);

  //PERGUNTA 6
  string getPrincipalFromCharacter(const string& character) const;
};



/** @brief Operator Overloading to display Series object */
ostream& operator<<(ostream& os, const Series& series);

/** @brief Operator Overloading to display Person object */
ostream& operator<<(ostream& os, const Person& Person);

/** @brief Operator Overloading to display Episode object */
ostream& operator<<(ostream& os, const Episode& episode);

#endif