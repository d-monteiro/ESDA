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

/** @brief Class to represent a TVSeries */
class TitleBasics{
public:
  /* ATTRIBUTES */
  string tconst;          /** @brief alphanumeric unique identifier of the title */
  string titleType;       /** @brief the type/format of the title (e.g. movie, short, tvseries, tvepisode, video, etc) */
  string primaryTitle;    /** @brief the more popular title / the title used by the filmmakers on promotional materials at the point of release */
  string originalTitle;   /** @brief original title, in the original language */
  bool isAdult;           /** @brief 0: non-adult title; 1: adult title */
  int startYear;          /** @brief represents the release year of a title. In the case of TV Series, it is the series start year */
  int endYear;            /** @brief TV Series end year. ‘\N’ for all other title types */
  int runtimeMinutes;     /** @brief primary runtime of the title, in minutes */
  vector<string> genres;  /** @brief includes up to three genres associated with the title */

  friend ostream& operator<<(ostream& os, const TitleBasics& series);
};

/** @brief Class to represent the Crew or a Cast associated to an episode */
class TitlePrincipals{
public:
  /* ATTRIBUTES */
  string tconst;              /** @brief alphanumeric unique identifier of the episode */ 
  int ordering;               /** @brief a number to uniquely identify rows for a given titleId */
  string nconst;              /** @brief alphanumeric unique identifier of the name/person */
  string primaryName;         /** @brief name by which the person is most often credited */
  int birthYear;              /** @brief  in YYYY format */
  string category;            /** @brief  the category of job that person was in */
  string job;                 /** @brief the specific job title if applicable, else '\N' */
  vector<string> characters;  /** @brief the name of the character played if applicable, else '\N' */
  
  friend ostream& operator<<(ostream& os, const TitlePrincipals& Person);
};

/** @brief Class to represent each episode  */
class TitleEpisode{
public:
  /* ATTRIBUTES */
  string tconst;        /** @brief alphanumeric identifier of episode */
  string parentTconst;  /** @brief alphanumeric identifier of the parent TV Series */
  int seasonNumber;     /** @brief season number the episode belongs to */
  int episodeNumber;    /** @brief episode number of the tconst in the TV series */
  
  friend ostream& operator<<(ostream& os, const TitleEpisode& episode);
};



/** @brief Class to represent a APP TVSeries Management */
class TVSeriesAPP{
private:
//Titles

  /**
   * @brief Map to store the Series objects
   * @param string Series's tconst
   * @param TitleBasics Series object
  */
  unordered_map<string, TitleBasics> SeriesMap;

  /**
   * @brief Map to store the Person objects
   * @param string Person's nconst
   * @param TitlePrincipals Person object
  */
  unordered_map<string, TitlePrincipals> PersonMap;

  /**
   * @brief Map to store the Episodes objects
   * @param string Episode's tconst
   * @param TitleEpisode Episode object
  */
  unordered_map<string, TitleEpisode> EpisodesMap;


//ToEpisodes

  /**
   * @brief Map Person objects to a given Episode
   * @param string Episode's tconst
   * @param TitlePrincipals Person object
  */
  unordered_multimap<string, TitlePrincipals> PeopleToEpisodeMap;


//ToSeries

  /**
   * @brief Map Episode objects to a given Series
   * @param string Series's tconst
   * @param TitleEpisode Episode object
  */
  unordered_multimap<string, TitleEpisode> EpisodeToSeriesMap;

  /**
   * @brief Map Person objects' primaryName to a given Series
   * @param string1 Series's tconst
   * @param string2 Person's primaryName
   * @warning ALLOWS MULTIPLE INSTANCES OF THE SAME NAME FOR A SINGLE SERIES!
  */
  unordered_multimap<string, string> PeopleNameToSeriesMap;

  /**
   * @brief Map Person objects' primaryName to a given Series
   * @param string1 Series's tconst
   * @param string2 Person's Object
   * @warning ALLOWS MULTIPLE INSTANCES OF THE SAME NAME FOR A SINGLE SERIES!
  */
  unordered_multimap<string, TitlePrincipals> PeopleToSeriesMap;


//ToPeople

  /**
   * @brief Map Series objects to a given Person (nconst)
   * @param string Person's nconst
   * @param TitleBasics Series object
   * @warning ALLOWS MULTIPLE INSTANCES OF THE SAME SERIES FOR A SINGLE PERSON!
  */
  unordered_multimap<string, TitleBasics> SeriesToPeopleMap;

//Characters

  /**
   * @brief Map Person objects to their respective characters
   * @param string Character name
   * @param TitlePrincipals Person object
  */
  unordered_multimap<string, TitlePrincipals> PersonToCharacterMap;


public:

  /* --- Constructor --- */
  TVSeriesAPP();

  /* --- Destructor --- */
  ~TVSeriesAPP();


  /* --- Add Methods --- */

  /** @brief add TtitleBasic to TVSeriesAPP */
  void addTitleBasics(const TitleBasics& title);

  /** @brief add TitleEpisode to TVSeriesAPP  */
  void addTitleEpisodes(const TitleEpisode& episode);

  /** @brief add TitlePrincipals to TVSeriesAPP */
  void addTitlePrincipal(const TitlePrincipals& principal);


  /* --- Get Methods --- */

  /** @brief get TitleBasics given a tconst */
  TitleBasics getSeries(const string& tconst) const;

  /** @brief get TitlePrincipals given a tconst */
  TitlePrincipals getPerson(const string& nconst) const;

  /** @brief get TitleEpisodes given a tconst */
  TitleEpisode getEpisode(const string& tconst);

  /** @brief get Parent Series given an episode */
  TitleBasics getParentSeries(const TitleEpisode& episode);


  /* --- Answer Methods --- */
  
  //PERGUNTA 1
  vector<string> getUniquePrincipals(const string& seriesTconst ) const;

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
ostream& operator<<(ostream& os, const TitleBasics& series);

/** @brief Operator Overloading to display Person object */
ostream& operator<<(ostream& os, const TitlePrincipals& Person);

/** @brief Operator Overloading to display Episode object */
ostream& operator<<(ostream& os, const TitleEpisode& episode);

#endif