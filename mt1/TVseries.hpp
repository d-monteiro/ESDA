#include <vector>
#include <string>

#define N_GENRES 5


using namespace std;

const string vGenres[N_GENRES] = {"Action", "Comedy", "Drama", "Animation", "Crime"};

/* CLASSES */

class TVSeries; /** @brief Class to represent a TV series. */
class User; /** @brief Class to represent a user. */
class TVSeriesManagement; /** @brief Class to represent all TV series. */
class UserManagement; /** @brief Class to represent all registered users. */


class TVSeries {
    private:
        /* ATTRIBUTES */
        string title; /** @brief Series title. */
        int numberOfSeasons; /** @brief Current number of seasons of the series. */
        vector<int> episodesPerSeason; /** @brief Vector with the current number of episodes per season of the series (i.e., the number of episodes of season 1 is at index 0). */
        string genre; /** @brief Series genre. */
        float rating; /** @brief Series rating. */
        bool finished; /** @brief Flag to indicate if it is a completed series. */

    public:
        /* METHODS */

        /* --- Constructor --- */

        /** 
         *  @brief Constructor (parameterized) - Create an object of the class TVSeries.
         *  @param seriesTitle Series title.
         *  @param seasons Number of seasons of the series.
         *  @param episodesPerSeason Vector with the number of episodes per season.
         *  @param seriesGenre Series genre.
         *  @param isFinished TRUE if the series is complete.
         *  @note  Initialize each attribute with the corresponding argument.
         */
        TVSeries(string seriesTitle, int seasons, vector<int> episodesPerSeason, string seriesGenre, float seriesRating, bool isFinished);

        /* --- Get Methods --- */
        
        /** 
         *  @brief  Get the series title.
         *  @return 'title' attribute.
         */
        string getTitle() const;

        /** 
         *  @brief  Get the number of seasons of the series.
         *  @return 'numberOfSeasons' attribute.
         */
        int getNumberOfSeasons() const;
        
        /** 
         *  @brief  Get the number of episodes per season of the series.
         *  @return 'episodesPerSeason' attribute.
         */
        vector<int> getEpisodesPerSeason() const;
        
        /** 
         *  @brief  Get the series genre.
         *  @return 'genre' attribute.
         */
        string getGenre() const;
        
        /** 
         *  @brief  Get the series rating.
         *  @return 'rating' attribute.
         */
        float getRating() const;
        
        /** 
         *  @brief  Get the flag to indicate if the series is or not complete.
         *  @return 'finished' attribute.
         */
        bool isFinished() const;

        /* --- Other Methods --- */

        /** 
         *  @brief  Display the information of a TV series.
         *  @return void
         */
        void displaySeriesInfo() const;

        /** 
         *  @brief  Update the series rating with the user rating average.
         *  @param  vectorUser Vector with the users.
         *  @return rating | -1 if an error occurs
         *  @note   Get the rating given by each of the users in 'vectorUser' that have watched this series and calculate the average rating.
         *  @return rating | 0 if no one has rating the series
         */
        float updateRating(const vector<User*>& vectorUser);
};

class User {
    private:
        /* ATTRIBUTES */
        string username; /** @brief Username. */
        string name; /** @brief Name of the user. */
        string country; /** @brief Country of the user. */
        vector<string> favoriteGenres; /** @brief Vector with the favorite genres of the user. */
        vector<TVSeries*> watchedSeries; /** @brief Vector with all the series watched by the user. */
        vector<int> ratings; /** @brief Rating of each watched series (i.e., the rating of the series at index 0 in 'watchedSeries' is at index 0). */
        vector<int> episodesWatched; /** @brief Number of episodes watched of each watched series (i.e., the number of watched episodes of the series at index 0 in 'watchedSeries' is at index 0). */

    public:
        /* METHODS */

        /* --- Constructor --- */

        /** 
         *  @brief Constructor (parameterized) - Create an object of the class User.
         *  @param uname Username.
         *  @param completeName Name of the user.
         *  @param userCountry Country of the user.
         *  @param genres Vector with the user's preferred genres.
         *  @note  Initialize each attribute with the corresponding argument.
         */
        User(string uname, string completeName, string userCountry, vector<string> genres);

        /* --- Get Methods --- */
        
        /** 
         *  @brief  Get the user's username.
         *  @return 'username' attribute.
         */
        string getUsername() const;

        /** 
         *  @brief  Get the user's name.
         *  @return 'name' attribute.
         */
        string getName() const;

        /** 
         *  @brief  Get the user's favorite genres.
         *  @return 'favoriteGenres' attribute.
         */
        vector<string> getFavoriteGenres() const;

        /** 
         *  @brief  Get the series watched by the user.
         *  @return 'watchedSeries' attribute.
         */
        vector<TVSeries*> getWatchedSeries() const;

        /** 
         *  @brief  Get the user's ratings.
         *  @return 'ratings' attribute.
         */
        vector<int> getRatings() const;

        /** 
         *  @brief  Get the number of episodes watched by the user.
         *  @return 'episodesWatched' attribute.
         */
        vector<int> getEpisodesWatched() const;

        /* --- Other Methods --- */

        /** 
         *  @brief  Add a new favorite genre.
         *  @param  genreIdx Index of the genre to add to 'favoriteGenres'.
         *  @return 0 if the new genre is added successfully | 1 if the new genre already exists |
         *  @return -1 if the new genre is not valid (not in 'vGenres')
         */
        int addFavoriteGenre(int genreIdx);

        /** 
         *  @brief  Add a new watched series.
         *  @param  series Pointer to the new series to add to 'watchedSeries'.
         *  @return 0 if the new series is added successfully | -1 if the parameter is invalid | 1 if the new series already exists
         */
        int addWatchedSeries(TVSeries* series);

        /** 
         *  @brief  Add the number of episodes watched to a watched series.
         *  @param  series Pointer to the series in 'watchedSeries' to update the number of episodes watched.
         *  @param  n Updated number of episodes watched to place in 'episodesWatched'.
         *  @return 0 if the number of episodes watched is updated successfully |
         *  @return -1 if the parameters are invalid | -2 if the series does not exist in the watched series vector
         *  @note   If n is zero, the user's number of episodes watched of that series should be incremented by 1.
         *  @note   If n > 0, the user's number of episodes watched of that series is updated to the value of 'n'.
         */
        int addEpisodesWatched(TVSeries* series, int n);

        /** 
         *  @brief  Add a new rating to a watched series.
         *  @param  series Pointer to the series in 'watchedSeries' to add the new rating to.
         *  @param  rating New rating to add to 'ratings'.
         *  @return 0 if the rating is updated successfully |
         *  @return -1 if the parameters are invalid | -2 if the series does not exist in the watched series vector
         */
        int addRating(TVSeries* series, float rating);

        /** 
         *  @brief  Display the information of a user.
         *  @return void
         *  @note   Info to print: username, name, country, favorite genres, and TV series watched with the corresponding number of episodes watched.
         */
        void displayUserInfo(ostream& os) const;
};

class TVSeriesManagement {
    private:
        /* ATTRIBUTES */
        vector<TVSeries*> vectorTVSeries; /** @brief Vector with all the TV series. */
    public:
        /* METHODS */

        /* --- Constructor --- */

        /** 
         *  @brief Constructor (default) - Create an object of the class TVSeriesManagement.
         *  @note  Make sure the vector 'vectorTVSeries' is empty.
         */
        TVSeriesManagement();

        /* --- Get Methods --- */
        
        /** 
         *  @brief  Get the vector with all the TV series.
         *  @return 'vectorTVSeries' attribute.
         */
        vector<TVSeries*> getVectorTVSeries() const;

        /* --- Other Methods --- */

        /** 
         *  @brief  Add a new series.
         *  @param  series New series to be added.
         *  @return 0 if the series is added successfully | -1 if the parameter is invalid | 1 if the series already exists in the vector
         */
        int TVSeriesInsert(TVSeries* series);

        /** 
         *  @brief  Remove a series.
         *  @param  title Title of the series to be removed.
         *  @return 0 if the series is removed successfully | -1 if the series does not exist in the vector
         */
        int TVSeriesDelete(string title);
};

class UserManagement {
    private:
        /* ATTRIBUTES */
        vector<User*> vectorUsers; /** @brief Vector with all the registered users. */

    public:
        /* METHODS */

        /** 
         *  @brief Constructor (default) - Create an object of the class UserManagement.
         *  @note  Make sure the vector 'vectorUsers' is empty.
         */
        UserManagement();

        /* --- Get Methods --- */
        
        /** 
         *  @brief  Get the vector with all the registered users.
         *  @return 'vectorUsers' attribute.
         */
        vector<User*> getVectorUsers() const;

        /* --- Other Methods --- */

        /** 
         *  @brief  Add a new registered user to the vector.
         *  @param  newUser User to be added.
         *  @return void
         */
        void addUser(User* newUser);

        /** 
         *  @brief  Update the series watched by the registered users by reading a text file.
         *  @param  filename Filename of the text file containing the watched series information.
         *  @param  manager Object with all the series in the platform.
         *  @return 0 if successful | -1 if an error occurs
         *  @note   Each line of the file contains the required information in the following format: series_title,username,number_of_episodes_watched
         *  @note   Other functions implemented in this library can be used to implement this method.
         *  @note   Check:
         *  @note    -> user exists  : NO  - create it and add it to 'vectorUsers' (the name and country of the user are stored as "Unknown")
         *  @note    -> series exists: NO  - continue | YES - stored number of episodes of the series
         */ 
        int updateWatched(string filename, TVSeriesManagement& manager);
};