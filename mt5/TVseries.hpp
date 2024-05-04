#ifndef TVSERIES_HPP
#define TVSERIES_HPP

#include <string>
#include <vector>
#include <unordered_map> 

using namespace std; 

class Series; /** @brief Class to represent a TVSerie. */
class Crew; /** @brief Class to represent the a Crew or a Cast associated to a episode */
class Episode; /** @brief Class to represent each episode  */

class TVSeriesAPP; /** @brief Class to represent a APP TVSeries Management */



/** @brief Class to represent a TVSerie. */
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

};

/** @brief Class to represent the a Crew or a Cast associated to a episode */
class Crew {
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
    

};

/** @brief Class to represent each episode  */
class Episode {
public:
    /* ATTRIBUTES */
    string tconst; /** @brief alphanumeric identifier of episode */
    string parentTconst; /** @brief alphanumeric identifier of the parent TV Series */
    int seasonNumber; /** @brief season number the episode belongs to */
    int episodeNumber; /** @brief episode number of the tconst in the TV series */
};




/** @brief Class to represent a APP TVSeries Management */
class TVSeriesAPP {
private:
  unordered_map<string, Series> SeriesMap; /** @brief Map to store the Series objects */
  unordered_map<string, Crew> CrewMap; /** @brief Map to store the Crew objects */
  unordered_map<string, Episode> EpisodesMap; /** @brief Map to store the Episodes objects*/

public:
  /* --- Constructor --- */
  TVSeriesAPP();



  /* --- Destructor --- */
  ~TVSeriesAPP();



  /* --- Add Methods --- */

  /** @brief add TtitleBasic to TVSeriesAPP */
  void addSeries(const Series& title);

  /** @brief add TitleEpisode to TVSeriesAPP  */
  void addEpisode(const Episode& episode);

  /** @brief add TitlePrincipals to TVSeriesAPP */
  void addCrew(const Crew& principal);



  /* --- Get Methods --- */

  /** @brief get TitleBasics given a tconst */
  Series getCrew(const string& tconst);

  /** @brief get TitleEpisodes given a tconst */
  Episode getEpisode(const string& tconst);

  /** @brief get Parent Series given a episode */
  Series getParentSeries(const Episode& episode);



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

#endif