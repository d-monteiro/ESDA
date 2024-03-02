#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "TVseries.hpp"

using namespace std;

TVSeries::TVSeries(string seriesTitle, int seasons, vector<int> episodesPerSeason, string seriesGenre, float seriesRating, bool isFinished) :
    title(seriesTitle), numberOfSeasons(seasons), episodesPerSeason(episodesPerSeason), genre(seriesGenre), rating(seriesRating), finished(isFinished) {};

string TVSeries::getTitle() const { return title; }

int TVSeries::getNumberOfSeasons() const { return numberOfSeasons; }

vector<int> TVSeries::getEpisodesPerSeason() const { return episodesPerSeason; }

string TVSeries::getGenre() const { return genre; }

float TVSeries::getRating() const { return rating; }

bool TVSeries::isFinished() const { return finished; }

void TVSeries::displaySeriesInfo() const
{
   }

User::User(string uname, string completeName, string userCountry, vector<string> genres) :
    username(uname), name(completeName), country(userCountry), favoriteGenres(genres) {};

string User::getUsername() const { return username; }

string User::getName() const { return name; }

vector<string> User::getFavoriteGenres() const { return favoriteGenres; }

vector<TVSeries*> User::getWatchedSeries() const { return watchedSeries; }

vector<int> User::getRatings() const { return ratings; }

vector<int> User::getEpisodesWatched() const { return episodesWatched; }

int User::addFavoriteGenre(int genreIdx)
{
    // Check if the index of the genre exists in 'vGenres'
    if (!(genreIdx >= 0 && genreIdx < N_GENRES)) return -1;

    // Check if the genre already exists in the vector
    if (find(favoriteGenres.begin(), favoriteGenres.end(), vGenres[genreIdx]) == favoriteGenres.end()) {
        // Genre doesn't exist, so add it to the vector
        favoriteGenres.push_back(vGenres[genreIdx]);
    }

    // Genre already exists, do nothing
    //cout << "Genre already exists in favorite genres." << endl;
    return 1;
}

int User::addWatchedSeries(TVSeries* series)
{
    // Check if the series pointer is valid
    if (series == nullptr) {
        cout << "Error: Invalid series pointer." << endl;
        return -1; // Return -1 to indicate an error
    }

    // Check if the series is already in watchedSeries
    auto it = find(watchedSeries.begin(), watchedSeries.end(), series);
    if (it != watchedSeries.end()) {
       // cout << "Series is already in watched series." << endl;
        return 1; // Series already exists, no need to insert
    }

    // Series is not in watchedSeries, so insert it
    watchedSeries.push_back(series);
    episodesWatched.push_back(0); // Initialize episodesWatched for the new series
    ratings.push_back(0);
    //cout << "New watched series inserted." << endl;
    return 0; // Successfully inserted
}

int User::addEpisodesWatched(TVSeries* series, int n)
{
    // Check if the series pointer is valid
    if (series == nullptr) {
        cout << "Error: Invalid series pointer." << endl;
        return -1; // Exit the function if the series pointer is invalid
    }

    // Find the index of the series in the watchedSeries vector
    auto it = find(watchedSeries.begin(), watchedSeries.end(), series);
    if (it != watchedSeries.end()) {
        // Calculate the index of the series
        int index = distance(watchedSeries.begin(), it);

        // Check if the series has more episodes than the episodes watched
        vector <int> episodesperseason = series->getEpisodesPerSeason(); 
        int totalepisodes = 0;
        for (auto it = episodesperseason.begin(); it!=episodesperseason.end(); it++){
            totalepisodes += *it;
        }
        //cout << "Total episodes: " << totalepisodes;

        // ! Check if total episodes is smaller
        if (n > 0) {
            episodesWatched[index] = min(totalepisodes, n); // Update to the minimum of n or total episodes
        } else {
            // Increment the number of episodes watched by 1 if it's less than the total episodes
            if (episodesWatched[index] < totalepisodes) {
                episodesWatched[index]++;
            }
        }
        return 0;
    } else {
       // cout << "Error: Series not found in watched series." << endl;
        return -2;
    }
}

TVSeriesManagement::TVSeriesManagement(){};

vector<TVSeries*> TVSeriesManagement::getVectorTVSeries() const { return vectorTVSeries; }

int TVSeriesManagement::TVSeriesDelete(string title)
{
    for (auto it = vectorTVSeries.begin(); it != vectorTVSeries.end(); ++it) {
        if ((*it)->getTitle() == title) {
            delete *it; // Free the memory allocated for the TVSerie object
            vectorTVSeries.erase(it); // Remove the pointer from the vector
            return 0; // Series deleted successfully
        }
    }
    return -1; // Series not found
}

UserManagement::UserManagement(){};

vector<User*> UserManagement::getVectorUsers() const { return vectorUsers; }

void UserManagement::addUser(User* newUser)
{
    vectorUsers.push_back(newUser);
}

/**************************/
/*     A implementar      */
/**************************/

void User::displayUserInfo(ostream& os) const
{
//answer 1
//DM

    os<<"Displaying user info:"<<endl;
    os<<"-----Username: "<<username<<endl;
    os<<"-----Name: "<<name<<endl;
    os<<"-----Country: "<<country<<endl;

    os<<"-----Favorite Genres:"<<endl;
    for(size_t i=0;i<favoriteGenres.size();++i)
    {
        os<<"------ "<<favoriteGenres[i]<<endl;
    }
  
    os<<"-----Watched Series:"<<endl;
    for(size_t i=0;i<watchedSeries.size();++i)
    {
        os<<"------ "<<watchedSeries[i]->getTitle()<<", Episodes Watched: "<<episodesWatched[i]<<endl;
    }
}

int User::addRating(TVSeries* series, float rating)
{
//answer 2
//FS

//verificar parâmetros; if invalid (series name empty or rating out of bounds (assuming rating is between 0 and 10)): return -1
    if(*series == "" || rating < 0 || rating > 10) return -1;
//procurar a série na lista de séries já vistas
    vector<TVSeries*>::iterator it = find(watchedSeries.begin(), watchedSeries.end(), *series);
//verificar se a série já foi vista; ifnot: return -2
    if(it == watchedSeries.end()) return -2;
//atribuir o rating na posição correspondente à série
    //se for pra substituir
//    ratings[it - watchedSeries.begin()] = rating;
    //se for para adicionar
    ratings.insert(ratings.begin() + it - watchedSeries.begin(), rating);
//código de retorno: bem sucedido
    return 0;
}

float TVSeries::updateRating(const vector<User*>& vectorUser)
{
//answer 3
//DM


}

int TVSeriesManagement::TVSeriesInsert(TVSeries* series)
{
//answer 4
//FS

//verificar parâmetro; if invalid (series name empty): return -1
    if(*series == "") return -1;
//verificar se a série já existe; ifyes: return 1
    vector<TVSeries*>::iterator it = find(watchedSeries.begin(), watchedSeries.end(), *series);
    if(it == watchedSeries.end()) return 1;
//adicionar a série à lista
    watchedSeries.insert(watchedSeries.end(), *series);
//código de retorno: bem sucedido
    return 0;
}

int UserManagement::updateWatched(string filename, TVSeriesManagement& manager)
{
//answer 5
//FS

//verificar os parâmetros; if invalid (filename empty): return -1;
    if(filename == "") return -1;
//abrir ficheiro de texto
    ifstream fin(filename);
//verificar abertura bem sucedida do ficheiro; ifnot: return -1
    if(!fin) return -1;
//ler ficheiro
    string title_str, nseasons_str;
    while(getline(fin, title_str, ","))
    {
    //verificar existência de série; iffalse: return -2 ?
        vector<TVSeries*>::iterator it = find(manage.vectorTVSeries.begin(), manage.vectorTVSeries.end(), title_str);
        if(it == manage.vectorTVSeries.end()) return -2;
        else
        {
        //ler nº de seasons
            getline(fin, nseason_str, ",");
        //validar
            if(atoi(nseason_str) <= 0) return -1;
            else
            {
                string neps[atoi(nseason_str)];
                for(int i = 0; i < atoi(nseason_str); i++)
                {
                //read nº eps p/ season !!!UNFINISHED!!!
                    getline(fin, neps[i]);
                    //unfinished
                }
            }
        }
    }



}
