#ifndef TVSERIES_HPP
#define TVSERIES_HPP

#include <vector>
#include <string>
#include <list>
#include <queue>

#define N_GENRES 5


using namespace std;

const string vGenres[N_GENRES] = {"Action", "Comedy", "Drama", "Animation", "Crime"};

/* CLASSES */

class TVSeries; /** @brief Class to represent a TV series. */
class User; /** @brief Class to represent a user. */
class TVSeriesManagement; /** @brief Class to represent all TV series in a vector. */
class UserManagement; /** @brief Class to represent all registered users in a vetor. */
class TVSeriesManagementList; /** @brief Class to represent all TV series in a list. */
class UserManagementList; /** @brief Class to represent all registered users in a list. */
class NodeUser; /** @brief Class to represent a node in a tree BST */
class UserManagementTree; /** @brief Class to represent a tree BST with all registered users */
class HashTable; /** @brief Class to represent a HASH Table with all country stats */
class UserManagementGraph; /** @brief Class to represent a graph with all registered users. */


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

        bool operator<(const TVSeries& tv) const;
 
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
        queue<TVSeries*> wishSeries; /** @brief Series that we want to see, in order of arrive, placed in a queue. */
        int length; /** @brief Distance to a given node*/
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
         *  @brief  Get the user's country.
         *  @return 'country' attribute.
         */
        string getCountry() const;

        /** 
         *  @brief  Get the user's favorite genres.
         *  @return 'favoriteGenres' attribute.
         */
        vector<string> getFavoriteGenres() const;

        /** 
         *  @brief  Get the series watched by the user.
         *  @return 'watchedSeries' attribute.
         */
        vector<TVSeries*>& getWatchedSeries() ;

        /** 
         *  @brief  Get the user's ratings.
         *  @return 'ratings' attribute.
         */
        vector<int>& getRatings() ;

        /** 
         *  @brief  Get the number of episodes watched by the user.
         *  @return 'episodesWatched' attribute.
         */
        vector<int>& getEpisodesWatched() ;

            /** 
         *  @brief  Get the series the user wants to watch
         *  @return 'wishSeries' attribute.
         */
        queue<TVSeries*>& getWishSeries() ;

          /** 
         *  @brief  Get the user's length.
         *  @return 'username' attribute.
         */
        int getLength() const;

        /* --- Other Methods --- */

         /** 
         *  @brief  Set the user's length.
         *  @param  n integer to replace the atribute length.
         *  @return -1 if the new n is not valid(n<0).
         */
        int setLength(int n) ;

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
         *  @brief  Add a new wish series.
         *  @param  series Pointer to the new series to add to 'wishSeries'.
         *  @return 0 if the new series is added successfully | -1 if the parameter is invalid | 1 if the new series already exists
         */
        int addWishSeries(TVSeries* series);
        /** 
         *  @brief  Display the information of a user.
         *  @return void
         *  @note   Info to print: username, name, country, favorite genres, and TV series watched with the corresponding number of episodes watched.
         */
        void displayUserInfo(ostream& os) const;

        /** 
         *  @brief  Number of episodes that need to see before getting to a certain series.
         *  @return Returns the number of episodes | returns -1 in case of error and if the series does not exist in the queue of wish
         */
        int numberOfEpisodesToSee(string title, list<TVSeries*> listTVSeries );
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
        int updateWatched(string filename, TVSeriesManagementList& manager);

                       /** 
         *  @brief  priority queue with series for the rating of the series (only series with a minimum number of users who have seen the series can be there)
         *  @param  listTV list of all series.
         *  @param  min minimum number of users who watched the series.
         *  @note   To consider that a user has seen a series they must have seen at least two episode.
         *  @return priority_queue | In case of error returns an empty priority_queue
 
         */ 
        priority_queue<TVSeries> queueTVSeries(list<TVSeries*> listTV, int min);

         /** 
         *  @brief  priority queue with series for the rating of the series of a certain category
         *  @param  pq priority queue with all series.
         *  @param  cat category
         *  @return priority_queue | In case of error returns an empty priority_queue
 
         */ 
        priority_queue<TVSeries> queueTVSeriesCategory(priority_queue<TVSeries>& pq, string cat);
};


class UserManagementList {
    private:
        /* ATTRIBUTES */
        list<User*> listUsers; /** @brief List with all the registered users. */

    public:
        /* METHODS */

        /** 
         *  @brief Constructor (default) - Create an object of the class UserManagementList.
         *  @note  Make sure the list 'listUsers' is empty.
         */
        UserManagementList();

        /* --- Get Methods --- */
        
        /** 
         *  @brief  Get the list with all the registered users.
         *  @return 'ListUsers' attribute.
         */
        list<User*> getListUsers() const;

        /* --- Other Methods --- */

        /** 
         *  @brief  Add a new registered user to the list.
         *  @param  newUser User to be added.
         *  @return void
         */
        void addUser(User* newUser);

        /** 
         *  @brief  Create a list of all users who have watched all episodes of a given series
         *  @param  series serie.
         *  @return List | In case of error returns an empty list
         */ 
        list<User*> seeAll(TVSeries* series);

  

};


class TVSeriesManagementList {
    private:
        /* ATTRIBUTES */
        list<TVSeries*> listTVSeries; /** @brief List with all the TV series. */
    public:
        /* METHODS */

        /* --- Constructor --- */

        /** 
         *  @brief Constructor (default) - Create an object of the class TVSeriesManagementList.
         *  @note  Make sure the list 'listTVSeries' is empty.
         */
        TVSeriesManagementList();

        /* --- Get Methods --- */
        
        /** 
         *  @brief  Get the list with all the TV series.
         *  @return 'listTVSeries' attribute.
         */
        list<TVSeries*> getListTVSeries() const;

        /* --- Other Methods --- */

        /** 
         *  @brief  Add a new series.
         *  @param  series New series to be added.
         *  @return 0 if the series is added successfully | -1 if the parameter is invalid | 1 if the series already exists in the list
         */
        int TVSeriesInsert(TVSeries* series);

        /** 
         *  @brief  Remove a series.
         *  @param  title Title of the series to be removed.
         *  @return 0 if the series is removed successfully | -1 if the series does not exist in the list
         *  @note Remove the series from the watchedSeries vector in users and also remove from the episodesWatched, ratings and wishSeries vectors
         */
        int TVSeriesDelete(string title , UserManagementList& userManagementlist);

        
        /** 
         *  @brief  Create a list with all series in a given category.
         *  @param  cat category desired.
         *  @return list | In case of error returns an empty list
 */ 
        list<TVSeries*> seriesByCategory(string cat) const;

            /** 
         *  @brief  Creates a list of series for a specific user (username). This list is suggested by another user (userWhoSuggests).
         *  @param  username user to whom it is suggested.
         *  @param  userWhoSuggests user who suggests.
         *  @note   Criteria for the suggestion:
         *  @note   1) userWhoSuggests can only suggest series that have seen;
         *  @note   2) userWhoSuggests can only suggest series of categories that are from the username's favorite categories
         *  @note   3) userWhoSuggests can only suggest series that the username has not seen yet;
         *  @note   4) if userWhoSuggests does not exist, the total list of series is used to suggest to the user;
         *  @return list | In case of error returns an empty list
 */ 
        list<TVSeries*> suggestsSeries(string username,string userWhoSuggests, list<User*> userlist) const;
};

class NodeUser {
public:
    User* user;
    NodeUser* left;
    NodeUser* right;

    // Constructor
    NodeUser(User* user); 
};

class UserManagementTree {
    private:
        /* ATTRIBUTES */
        NodeUser* root; /** @brief pointer to the root of the tree. */

        /* METHODS */
        
         /** 
         *  @brief Auxiliary function to insert a nodeUser into the tree
         */
        NodeUser* insertNode(NodeUser* root, User* user);

        /** 
         *  @brief Auxiliary function to find the minimum node of a subtree 
         */
        NodeUser* findMinNode(NodeUser* node);

        /** 
         *  @brief Auxiliary function to delete a node from the tree 
         */
        NodeUser* deleteNode(NodeUser* root, string user);

        /** 
         *  @brief Auxiliary function to print the nodes in order
         */
        void inorderTraversal(NodeUser* root);
    public:
        /* METHODS */

        /** 
         *  @brief Constructor (default) - Create an object of the class UserManagementList.
         *  @note  Make sure the root points to null.
         */
        UserManagementTree(); 

        /* --- Get Methods --- */
        
        /** 
         *  @brief  Get the first node (root).
         *  @return 'root' attribute.
         */
        NodeUser* getRoot() const;

        /* --- Other Methods --- */

        /** 
         *  @brief  Add a new registered user to the tree.
         *  @param  newUser User to be added.
         *  @return void
         */
         void addUser(User* newUser); 

        /** 
         *  @brief  Remove a registered user from the tree.
         *  @param  user User to be remove.
         *  @return void
         */ 
        void remove(string user);

         /** 
         *  @brief  Public method to print user in order of username
         *  @return void
         */ 
        void inorder(); 
        /** 
         *  @brief  vector with the statistics of users in a given category
         *  @param  root node to search.
         *  @param  cat category.
         *  @param  perc minimum percentage of episodes watched(0-100).
         *  @note   Statistics:
         *  @note   1) first position of the vector: total number of users who watched at least one episode of a series in a given category(cat);
         *  @note   2) second position of the vector: total number of users who watched a given percentage(perc) of the total episodes of a series in a given category(cat);
         *  @note   3) third position of the vector: total number of users who have seen a certain percentage(perc) of episodes of a series in a certain category(cat) and who have that category(cat) as their favorite;
         *  @return vector | In case of error returns an empty vector
 
         */ 
        vector<int> usersCategoryStatistics(NodeUser* root,string cat,int perc);

              /** 
         *  @brief  vector with users initialized by a a given initial letter
         *  @param  root node to search.
         *  @param  ch char to search.
         *  @return vector | In case of error returns an empty vector
 
         */ 
        vector<User*> usersInitialLetter(NodeUser* root,char ch);

         /** 
         *  @brief  list with users which don't usually finish series. (users who have more than 2 series in which they have not seen all the episodes)
         *  @param  root node to search.
         *  @return list | In case of error returns an empty list
         */ 
        list<User*> usersNotFan(NodeUser* root);


};
struct CountryStats
{
    /**
     *  @brief Name of the country.
     */
    string country;

    /**
     *  @brief Number of users from that country
     **/
    int nUsers;

    /**
     *  @brief Number of (different) series seen in this country.
     */
    int nTVSeries;

    /**
     *  @brief Average number of series watched by user in this country.
     */
    float averageTVseries;

    /**
     *  @brief vector with the number of series viewed by category in this country.
     */
    vector<int> nGenre;

   

    CountryStats(string country_,int nUsers_, int nTVSeries_, float averageTVseries_, vector<int> nGenre_)
    {
        country = country_;
        nUsers = nUsers_;
        nTVSeries = nTVSeries_;
        averageTVseries = averageTVseries_;
        nGenre = nGenre_;
    
    }
};

class HashTable
{
    private:
        /* ATTRIBUTES */
        
        /**
         *  @brief Hash Table Size.
         */
        int tableSize;

        /**
         *  @brief Hash table (vector of pointers to elements of type 'CountryStats').
         */
        vector<CountryStats*> table;

        /**
         *  @brief Number of CountryStats (effective number of elements) in the hash table.
         */
        int totalCountryStats;

    public:
      
        /* CONSTRUTOR */

        /**
         *  @brief Constructor (parameterized).
         *  @param ts hash table size
         *  @note  Initializes the attribute with the corresponding argument and creates the vector representing the hash table.
         *  @note  The argument value must be valid.
         */
        HashTable(int ts);


        /* DESTRUCTOR */

        /**
         *  @brief Destructor.
         *  @note  Removes the hash table from memory (delete table elements).
         */
        ~HashTable();


        /* GET METHODS */

        /**
         *  @brief  Get the hash table size.
         *  @param  none
         *  @return 'tableSize'
         */
        int getTableSize() const;
        /**
         *  @brief  Get the number of elements in the hash table.
         *  @param  none
         *  @return 'totalCountryStats'
         */
        int getTotalCountryStats() const;


        /**
         *  @brief  Get the hash table.
         *  @param  none
         *  @return 'table'
         */
        vector<CountryStats*> getTable() const;
        

        /* OTHER METHODS */

        /**
         *  @brief  Determine the index of a given key.
         *  @param  key element key
         *  @return calculated index or -1 in case of error
         *  @note   Hash function: returns the hash (h) -> sum of h(i-1)+key[i], with i>=0 and i<key.length() (h(-1)=7).
         *  @note   The index to return corresponds to hashtableSize.
         *  @note   The argument value must be valid.
         */
        int hashFunction(string key);

        /**
         *  @brief  Determine the index of a given key for collision resolution.
         *  @param  key element key
         *  @param  i degree of collision
         *  @return calculated index or -1 in case of error
         *  @note   Quadratic polling function: returns the hash (h) -> h+23*i^2.
         *  @note   The index to return corresponds to hashtableSize.
         *  @note   The argument value must be valid.
         */
        int probingFunction(string key, int i);
        
        /**
         *  @brief  Insert a new element into the hash table.
         *  @param  as element to insert
         *  @return index of the inserted element || -1 if the element already exists or in case of an error
         *  @note   The key of the element to be inserted corresponds to the 'country' field.
         *  @note   Update the value of the number of effective elements in the hash table.
         *  @note   In the event of a collision, the element can be inserted into a free position or into a position from which an element was previously deleted (marked with the 'deleted' key).
         */
        int insertCountryStats(CountryStats & countryS);

        /**
         *  @brief  Remove an element from the hash table.
         *  @param  user key of the element to remove
         *  @return 0 on success || 1 if the key does not exist || -1 in case of error
         *  @note   The argument value must be valid.
         *  @note   Update the value of the number of effective elements in the hash table.
         *  @note   When removing the element, save in that position an element with the key 'deleted' and remaining null fields.
         */
        int deleteAccountStats(string user);

        /**
         *  @brief  Search for certain element in the hash table.
         *  @param  user key of the element to search
         *  @return element index || -1 if it does not exist or in case of error
         *  @note   The argument value must be valid.
         */
        int searchCountryStats(string country);

        /**
         *  @brief  Build the hash table based on the Users vector.
         *  @param  UserManagement user vector
         *  @return 0 on success || -1 on erroro
         */
        int importFromVector( UserManagement  &userManager);

        /**
         *  @brief  Show hash table contents.
         *  @param  none
         *  @return void
         */
        void show(void);
};

class UserManagementGraph {
    private:
        /* ATTRIBUTES */
        size_t totalUsers; /** @brief Total number of nodes in the graph. */
        vector<User*> userNodes; /** @brief Vector with the users (nodes) in the graph. */
        vector<list<User*>> network; /** @brief Adjacency list to represent connections between the users (each list has destination users). */

    public:
        /* METHODS */

        /* --- Constructor --- */

        /** 
         *  @brief Constructor (default) - Create an object of the class UserManagementGraph.
         *  @note  Initialize 'totalUsers' with zero and make sure the vector is empty.
         */
        UserManagementGraph();
        
        /* --- Get Methods --- */
        
        /** 
         *  @brief  Get the total number of graph nodes.
         *  @return 'totalUSers' attribute.
         */
        size_t getTotal() const;

        /** 
         *  @brief  Get the vector with all nodes.
         *  @return 'userNodes' attribute.
         */
        vector<User*> getUserNodes() const;

        /** 
         *  @brief  Get the adjacency list.
         *  @return 'network' attribute.
         */
        vector<list<User*>> getNetwork() const;

        /* --- Other Methods --- */

        /**
         *  @brief  Add a new node to the graph.
         *  @param  userPtr pointer to the user object to be added
         *  @return 0 if the new node is added successfully | 1 if the node already exists | -1 if an error occurs
         *  @note   The total number of nodes must be updated, as well as the size of the adjacency list.
         */
        int addUserNode(User* userPtr);

        /**
         *  @brief  Find the position of a user in the graph nodes' vector.
         *  @param  userPtr pointer to the user object to be found
         *  @return Position of the node in the vector (0 to n-1, being n the vector size) | -1 if the node does not exist | -2 if an error occurs
         */
        int userNodePosition(User* userPtr);

        /**
         *  @brief  Add a new follower to a user.
         *  @param  userA node where the edge starts
         *  @param  userB node where the edge ends
         *  @return 0 if the new edge is added successfully | 1 if the edge already exists | -1 if an error occurs
         *  @note   A new follower means that a new edge is to be added from A to B (A follows B) with default weight equal to 1.
         *  @note   If neither userA nor userB are in the graph, they must be added first.
         */
	    int addFollower(User* userA, User* userB);

        /**
         *  @brief  Remove a follower.
         *  @param  userA node where the edge starts
         *  @param  userB node where the edge ends
         *  @return 0 if the edge is removed successfully | 1 if the edge does not exist | -1 if an error occurs
         *  @note   Remove the edge from A to B (A stops following B).
         *  @note   Check if userA and userB are in the graph.
         */
        int removeFollower(User* userA, User* userB);

        /**
         *  @brief  Determine which user follows the most users.
         *  @return Vector with the users following the most users (It is a vector because there can be ties) | Empty vector if an error occurs
         *  @note   The return type is a vector in case some users have equal number of followings.
         */
        vector<User*> mostFollowing();

        /**
         *  @brief  Determine which series is most watched by the users that a user follows.
         *  @param  userPtr pointer to the user object to search
         *  @return The most watched series | NULL if an error occurs
         *  @note   If there are 2 or more series with the same number of episodes watched, the second criterion is the largest number of users watching the series.
         *  @note   If there are 2 or more series with the same number of episodes watched, the second criterion is the largest number of users watching the series.
         *  @note   The 3rd criterion in case of a tie in the previous ones is the title of the highest series alphabetically.
         *  @note   The return type is a vector in case some series have been equally most watched.
         */
        TVSeries* followingMostWatchedSeries(User* userPtr);

        /**
         *  @brief  Find the distance from one node to another graph node..
         *  @param  userSrc source node
         *  @param  userDst Destiny node
         *  @return Integer with the distance from userSrc to userDst | -1 if an error occurs | -2 If there is no path
         *  @note   Check if userSrc and userDst are in the graph and consider "infinite value" to be 0xFFFF.
         */
        int shortestPaths(User* userSrc, User* userDst);

        /**
         *  @brief  Print the graph (vertices and edges).
         *  @return void
         */
        void printGraph();

};



#endif