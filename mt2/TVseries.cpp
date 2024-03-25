#include <vector>
#include <string>
#include <queue>
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "TVseries.hpp"

using namespace std;


// implementation of class TVSeries

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
    cout << "Displaying TV series info:" << endl;
    cout << "-----Title: " << title << endl;
    cout << "-----Number of Seasons: " << numberOfSeasons << endl;
    cout << "-----Episodes per Season:" << endl;
    for (size_t i = 0; i < episodesPerSeason.size(); ++i) {
        cout << "-----Season " << (i + 1) << ": " << episodesPerSeason[i] << " episodes" << endl;
    }
    cout << "-----Genre: " << genre << endl;
    cout << "-----Rating: " << rating << endl;
    cout << "-----Finished: " << (finished ? "Yes" : "No") << endl;
}


float TVSeries::updateRating(const vector<User*>& vectorUser)
{
    if (vectorUser.empty()) {
        cout << "Error: No users provided." << endl;
        return -1; // Return -1 in case of error
    }

    float totalRating = 0;
    int numRatings = 0;

    // Iterate through each user
    for ( User* user : vectorUser) {
        // Check if the user watched this series
        vector<TVSeries*> &watchedSeries = user->getWatchedSeries();
        auto it = find(watchedSeries.begin(), watchedSeries.end(), this);
        if (it != watchedSeries.end()) {
            // User watched this series, get the rating
            int index = distance(watchedSeries.begin(), it);
            totalRating += user->getRatings()[index];
            numRatings++;
        }
    }

    // Calculate the average rating
    if (numRatings > 0) {
        rating = totalRating / numRatings;
        return rating;
    } else {
        cout << "Error: No users have rated this series." << endl;
        return 0; // Return 0 
    }
}

// implementation of class User

User::User(string uname, string completeName, string userCountry, vector<string> genres) :
    username(uname), name(completeName), country(userCountry), favoriteGenres(genres) {};

string User::getUsername() const { return username; }

string User::getName() const { return name; }

vector<string> User::getFavoriteGenres() const { return favoriteGenres; }

vector<TVSeries*>& User::getWatchedSeries() { return watchedSeries; }

vector<int>& User::getRatings()  { return ratings; }

vector<int>& User::getEpisodesWatched()  { return episodesWatched; }

queue<TVSeries*>& User::getWishSeries()   { return wishSeries; }

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
    cout << "Genre already exists in favorite genres." << endl;
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
        cout << "Series is already in watched series." << endl;
        return 1; // Series already exists, no need to insert
    }

    // Series is not in watchedSeries, so insert it
    watchedSeries.push_back(series);
    episodesWatched.push_back(0); // Initialize episodesWatched for the new series
    ratings.push_back(0);
  //  cout << "New watched series inserted." << endl;
    return 0; // Successfully inserted
}
int User::addWishSeries(TVSeries* series)
{
    // Check if the series pointer is valid
    if (series == nullptr) {
        cout << "Error: Invalid series pointer." << endl;
        return -1; // Return -1 to indicate an error
    }

    // Check if the series is already in watchedSeries
    queue<TVSeries*> aux;
    bool teste=false;
    while(!wishSeries.empty())
    {
        if (wishSeries.front()==series)
        {
            teste=true;
        }
        aux.push(wishSeries.front());
        wishSeries.pop();
    }
    while(!aux.empty())
    {
        wishSeries.push(aux.front());
        aux.pop();
    }
    if (teste) return -1;
    // Series is not in wishSeries, so insert it
    wishSeries.push(series);
 
   // cout << "New wish series inserted." << endl;
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
        cout << "Error: Series not found in watched series." << endl;
        return -2;
    }
}

void User::displayUserInfo(ostream& os) const
{
    os << "Displaying user info:" << endl;
    os << "-----Username: " << username << endl;
    os << "-----Name: " << name << endl;
    os << "-----Country: " << country << endl;
    os << "-----Favorite Genres:" << endl;
    for (auto ir = favoriteGenres.begin(); ir != favoriteGenres.end(); ++ir){
        os << "------ " << *ir << endl;
    }
    os << "-----Watched Series:" << endl;
    for (size_t i = 0; i < watchedSeries.size(); ++i) {
        os << "------ " << watchedSeries[i]->getTitle() << ", Episodes Watched: " << episodesWatched[i] << endl;
    }
    cout << endl;
}

int User::addRating(TVSeries* series, float rating)
{
   // Check if the series pointer is valid
    if (series == nullptr) {
       // cout << "Error: Invalid series pointer." << endl;
        return -1; // Return -1 to indicate an error
    }

    // Find the index of the series in the watchedSeries vector
    auto it = find(watchedSeries.begin(), watchedSeries.end(), series);
    if (it != watchedSeries.end()) {
        // Calculate the index of the series
        size_t index = distance(watchedSeries.begin(), it);

        // Check if the rating vector has enough space
        if (index >= this->ratings.size()) {
            // Resize the rating vector to accommodate the new rating
            this->ratings.resize(index + 1, 0);
        }

        // Add the rating to the corresponding index
        this->ratings[index] = rating;
        return 0; // Successfully added rating
    } else {
       // cout << "Error: Series not found in watched series." << endl;
        return -2; // Return -1 to indicate series not found
    } 
}

// implementation of class TVSeriesManagement

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



int TVSeriesManagement::TVSeriesInsert(TVSeries* series)
{
    // Check if the series pointer is valid
    if (series == nullptr) {
        cout << "Error: Invalid series pointer." << endl;
        return -1; // Return -1 to indicate an error
    }
  if (vectorTVSeries.size()==0)
  {
    vectorTVSeries.push_back(series);
    return 0;
  }
    auto it = find(vectorTVSeries.begin(), vectorTVSeries.end(), series);


    if (it == vectorTVSeries.end()) {
        vectorTVSeries.push_back(series);
      
        return 0;
    } else { return 1;}

    return -1; // Series not found
}


// implementation of class UserManagement

UserManagement::UserManagement(){};

vector<User*> UserManagement::getVectorUsers() const { return vectorUsers; }

void UserManagement::addUser(User* newUser)
{
    vectorUsers.push_back(newUser);
}

// implementation of class TVSeriesManagementList

TVSeriesManagementList::TVSeriesManagementList(){};

list<TVSeries*> TVSeriesManagementList::getListTVSeries() const { return listTVSeries; }

int TVSeriesManagementList::TVSeriesInsert(TVSeries* series)
{
    // Check if the series pointer is valid
    if (series == nullptr) {
        cout << "Error: Invalid series pointer." << endl;
        return -1; // Return -1 to indicate an error
    }
  if (listTVSeries.size()==0)
  {
    listTVSeries.push_back(series);
    return 0;
  }
    auto it = find(listTVSeries.begin(), listTVSeries.end(), series);


    if (it == listTVSeries.end()) {
        listTVSeries.push_back(series);
      
        return 0;
    } else { return 1;}

    return -1; // Series not found
}

// implementation of class UserManagementList

UserManagementList::UserManagementList(){};

list<User*> UserManagementList::getListUsers() const { return listUsers; }

void UserManagementList::addUser(User* newUser)
{
    listUsers.push_back(newUser);
}







/**************************/
/*     A implementar      */
/**************************/








list<TVSeries*> TVSeriesManagementList::seriesByCategory(string cat) const
{
//question 1

    list<TVSeries*> l;  //list to be returned
    
    bool checkcat = 0;  //state if "cat" is valid

    for(size_t i = 0; i < vGenres->size(); i++)
    {
        if(cat == vGenres[i])   //verify if "cat" is valid
        {
            checkcat = 1;
            break;
        }
    }
    
    if(!checkcat) return l; //if "cat" is invalid: return empty

    for(auto it = listTVSeries.begin(); it != listTVSeries.end(); it++)
    {//"it" points to a "TVSeries pointer"
        if(cat == (*it)->getGenre())  //we compare "cat" with "getGenre" function call from the "TVSeries" pointed by the "(TVSeries) pointer" pointed by "it"
        {
            l.push_back(*it);   //list of "TVSeries pointers"; we push the "(TVSeries) pointer" pointed by "it"
        }
    }
    return l;   //finally, return l
}






list<User*> UserManagementList::seeAll(TVSeries* series)
{
//question 2

    list<User*> l;  //List to be returned
    int sum = 0;    //Sum of all the episodes of the given series

    if(series == nullptr) return l; //If "series" is invalid: return empty
    
    for(size_t i = 0; i < series->getEpisodesPerSeason().size(); ++i){  //Iterate through all the seasons ("i")
        sum += series->getEpisodesPerSeason()[i];   //To sum all the episodes
    }

    for(list<User*>::const_iterator it = listUsers.begin(); it != listUsers.end(); it++){   //Iterate through the list of users to get the series watched
    for(size_t i = 0; i<(*it)->getWatchedSeries().size(); ++i){ //Iterate through all the watched series of the user in search for the parameter "series"
        if(((*it)->getWatchedSeries()[i] == series) && (sum == (*it)->getEpisodesWatched()[i])){    //If the series and the number of episodes match: append the user to list l
            l.push_back(*it);   //Appending the user that saw the whole of the series
        }
    }}

    return l;   //Return the filled list
}






int User::numberOfEpisodesToSee(string title, list<TVSeries*> listTVSeries )
{
//question 3
 
    int sum = 0;                                    //Sum of all the episodes to see
    queue<TVSeries*> wishSeriesCheck = wishSeries;  //Copy of wishSeries to check if the series exists in the queue
    bool exists = 0;                                //Flag to indicate if series exists
    
    if(title.empty()) return -1;    //If parameter invalid: return -1
    
    while (!wishSeriesCheck.empty()){   //Iterate through the queue of wished series
    TVSeries* series = wishSeriesCheck.front(); //get a pointer for the first TVSeries in queue
    wishSeriesCheck.pop();                      //pop that TVSeries to check the next one
    if(series->getTitle() == title) exists = 1; //If exists: exists flag to TRUE
    }
    
    if(!exists) return -1;  //If not: return -1
    
    queue<TVSeries*> wishSeriesCopy = wishSeries;   //Copy of wishSeries to determine nº of episodes to see

    while (!wishSeriesCopy.empty()){    //Iterate through the queue of wished series
        TVSeries* series = wishSeriesCopy.front();  //get a pointer for the first TVSeries in queue
        wishSeriesCopy.pop();                       //Pop that TVSeries to check the next one

        if(series->getTitle() == title) break;  //If series is reached: break out of loop
        for(size_t i = 0; i < series->getEpisodesPerSeason().size(); ++i){  //Iterate through all the seasons
            sum += series->getEpisodesPerSeason()[i];   //To sum all the episodes
        }
    }
    
    return sum; //Return nº of episodes to see
}






int TVSeriesManagementList::TVSeriesDelete(string title, UserManagementList& userManagementlist)
{
//question 4

    for(auto it = listTVSeries.begin(); it != listTVSeries.end(); it++) //search for TVSeries
    {
        if(title == (*it)->getTitle())  //we compare "title" with "getTitle" function call from the "TVSeries" pointed by the "(TVSeries) pointer" pointed by "it"
        {
            for(auto u : userManagementlist.getListUsers()) //for each User "u" in userManagementlist.listUsers (private)
            {
                vector<TVSeries*>& ws = u->getWatchedSeries();  //get access (via alias) to each User.watchedSeries (private)
                vector<int>& ew = u->getEpisodesWatched();      //get access (via alias) each User.episodesWatched (private)
                vector<int>& rt = u->getRatings();              //get access (via alias) each User.ratings (private)
                queue<TVSeries*>& wl = u->getWishSeries();      //get access (via alias) each User.wishSeries (private)

                auto iws = find(ws.begin(), ws.end(), *it); //get TVSeries position in each User.watchedSeries
                if(iws != ws.end())
                {
                    ws.erase(iws);                      //remove the TVSeries from each User.watchedSeries
                    auto i = distance(ws.begin(), iws); //get TVSeries position index in User.watchedSeries
                    ew.erase(ew.begin() + i);           //remove the TVSeries from each User.ratings
                    rt.erase(rt.begin() + i);           //remove the TVSeries from each User.episodesWatched
                }

                TVSeries* aux = NULL;   //create a temporary aux for elements from User.wishSeries
                size_t s = wl.size();   //use a variable so the "for condition" is constant
                for(size_t t = 0; t < s; t++) //search the TVSeries from each User.wishSeries
                {
                    aux = wl.front();   //get element in first position from User.wishSeries
                    wl.pop();           //remove element in first position from User.wishSeries
                    
                    if(aux == *it)      //if element in first position we just removed was the TVSeries we wanted to remove:
                    {
                        continue;       //we skip the reinsertion process
                    }

                    wl.push(aux);       //reinsert the element in User.wishSeries
                }
            }
            delete *it;             //delete the object TVSeries pointed by the pointer pointed by "it"
            listTVSeries.erase(it); //remove the pointer that was pointing to the deleted TVSeries

            return 0;
        }
    }

    return -1;  //if TVSeries to be searched does not exist: return -1
}






list<TVSeries*> TVSeriesManagementList::suggestsSeries(string username,string userWhoSuggests, list<User*> userlist ) const
{
//question 5
    
    list<TVSeries*> l;                  //List to be returned
    bool exists = 0;                    //Flag to indicate if user who suggests exists
    bool userExists = 0;                //Flag to indicate if user exists
    int indexOfUserWhoSuggests = 0;     //Index variable of user who suggests
    int indexOfUserWhomSuggested = 0;   //Index variable of user to whom series are suggested
    
    if(username.empty()) return l;  //If username does not exist: return empty string

    for(auto it = userlist.begin(); it != userlist.end(); it++){    //Iterate through all the users
        if(username == (*it)->getUsername()){   //If a match is found
            indexOfUserWhomSuggested = (int)distance(userlist.begin(),it);  //Get its index
            userExists = 1; //Update exists flag
        }
    } 
    
    if(!userExists) return l;   //If not: return empty string
    if(indexOfUserWhomSuggested == (int)distance(userlist.begin(),userlist.end())) return l;    //If not: return empty string
    
    for(auto it = userlist.begin(); it != userlist.end(); it++){    //Iterate through all the users
        if(userWhoSuggests == (*it)->getUsername()){    //If a match is found
            indexOfUserWhoSuggests = (int)distance(userlist.begin(),it);    //Get its index
            exists = 1; //Update exists flag
        }
    }
    
    
    if(!exists){    //If the user who suggests does not exist, check criteria nº 2/3/4
        
        auto ite = userlist.begin();            //Iterator of user's list
        advance(ite,indexOfUserWhomSuggested);  //Advance to position of user to whom series are suggested
        
        //criteria nº2 && criteria nº4
        for(size_t i = 0; i < (*ite)->getFavoriteGenres().size(); ++i){ //Iterate through all the genres of user
        for(auto seriesptr = listTVSeries.begin(); seriesptr != listTVSeries.end(); ++seriesptr){   //Iterate through all the TV series
            if((*seriesptr)->getGenre() == (*ite)->getFavoriteGenres()[i]) l.push_back(*seriesptr);
            //If genre of series == one of the favorite genres of the user: append series to suggestion list
        }}
        
        //criteria nº3
        for(size_t i = 0; i < (*ite)->getWatchedSeries().size(); ++i){  //Iterate through all the series seen by the user
        auto seriesptr = l.begin();
        while(seriesptr != l.end()){    //Iterate through all the TV series in the suggestion list
            if((*seriesptr) == (*ite)->getWatchedSeries()[i]) seriesptr = l.erase(seriesptr);
            //If series(in suggestion list) == series seen by the user: erase it from suggestion list
            else ++seriesptr;   //If not: check next series
        }}
        
        return l;   //return suggestion list
    }
    
    //Else: check criteria nº 1/2/3
    
        auto userPtr = userlist.begin();            //Iterator of user's list
        advance(userPtr,indexOfUserWhomSuggested);  //Advance to position of user to whom series are suggested
        
        auto suggesterPtr = userlist.begin();           //Iterator of user's list
        advance(suggesterPtr,indexOfUserWhoSuggests);   //Advance to position of user who suggests
        
        //criteria nº1 && criteria nº2
        for(size_t i = 0; i < (*suggesterPtr)->getWatchedSeries().size(); ++i){ //Iterate through all the series seen by suggester (criteria nº1)
        for(size_t ii = 0; ii < (*userPtr)->getFavoriteGenres().size(); ++ii){  //Iterate through all the genres of user to whom series are suggested (criteria nº2)
            if(((*suggesterPtr)->getWatchedSeries()[i])->getGenre() == (*userPtr)->getFavoriteGenres()[ii]){
                l.push_back((*suggesterPtr)->getWatchedSeries()[i]);    //Append series suggestion list
            }   //If genre of series seen by user == one of the favorite genres of the user: append series to suggestion list
        }}
        
        //criteria nº3
        for(size_t i = 0; i < (*userPtr)->getWatchedSeries().size(); ++i){  //Iterate through all the series seen by the user
        auto seriesptr = l.begin();
        while(seriesptr != l.end()){    //Iterate through all the TV series in the suggestion list
            if((*seriesptr) == (*userPtr)->getWatchedSeries()[i]) seriesptr = l.erase(seriesptr);
            //If series(in suggestion list) == series seen by the user: erase it from suggestion list
            else ++seriesptr;   //If not: check next series
        }}
    
    return l;   //return suggestion list
}
