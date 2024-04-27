#include <vector>
#include <string>
#include <queue>
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cctype>
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
bool TVSeries::operator <(const TVSeries& tv) const
    {
        // this will return true when second TVSeries
        // has greater rating. Suppose we have tv1.rating=5
        // and tv2.rating=5.5 then the object which
        // have max rating will be at the top(or
        // max priority)
         return this->rating < tv.rating;
    }
// implementation of class User

User::User(string uname, string completeName, string userCountry, vector<string> genres) :
    username(uname), name(completeName), country(userCountry), favoriteGenres(genres), length(0) {};

string User::getUsername() const { return username; }

string User::getName() const { return name; }

string User::getCountry() const { return country; }

vector<string> User::getFavoriteGenres() const { return favoriteGenres; }

vector<TVSeries*>& User::getWatchedSeries() { return watchedSeries; }

vector<int>& User::getRatings()  { return ratings; }

vector<int>& User::getEpisodesWatched()  { return episodesWatched; }

queue<TVSeries*>& User::getWishSeries()   { return wishSeries; }

int User::getLength() const { return length; }

int User::setLength(int n)
{ if (n<0) return -1;
  length=n; 
  return 0; 
}

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
   //     cout << "Series is already in watched series." << endl;
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


int User::numberOfEpisodesToSee(string title, list<TVSeries*> listTVSeries )
{
    if((title.empty())|| listTVSeries.empty())
    {
        return -1;
    }
    int total=0;
    queue<TVSeries*> aux;
    vector<int> nepisodes;
    int n=wishSeries.size();
    bool exist=false;
    for (int i=0;i<n;i++)
    {
        
        if(wishSeries.front()->getTitle()==title)
        {
        exist=true;
        break;
        }
        aux.push(wishSeries.front());
        nepisodes=wishSeries.front()->getEpisodesPerSeason();
        for (int j=0;j<(int)nepisodes.size();j++)
        {
          total+=nepisodes[j];
        }
        wishSeries.pop();
    }
    while(!wishSeries.empty())
    {
        aux.push(wishSeries.front());
        wishSeries.pop();
    }
    while(!aux.empty())
    {
        wishSeries.push(aux.front());
        aux.pop();
    }
    if (!exist) total=0;
    return total;
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

int UserManagement::updateWatched(string filename, TVSeriesManagementList& manager)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return -1;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string seriesName, username,eps;
        int episodesSeen;
        getline(ss, seriesName, ',');
        getline(ss, username, ',');
        getline(ss, eps, ',');
        episodesSeen = stoi(eps);
       // cout << seriesName << username << episodesSeen << endl;

        // Check if user exists, if not, create and add to vectorUser
        User* userPtr = nullptr;
        for (User* user : vectorUsers) {
            if (user->getUsername() == username) {
                userPtr = user;
                break;
            }
        }
        if (userPtr == nullptr) {
            // User does not exist, create and add to vectorUser
            vectorUsers.push_back(new User(username, "Unknown", "Unknown", {}));
            userPtr = vectorUsers.back();
        }
        // Check if the series exists
        bool seriesExists = false;
        for (const auto& seriesPtr : manager.getListTVSeries()) {
            
            if (seriesPtr->getTitle() == seriesName) {
                seriesExists = true;
                //add series to user. 
                userPtr->addWatchedSeries(seriesPtr);
                userPtr->addEpisodesWatched(seriesPtr, episodesSeen);
            }
        }

        if (!seriesExists) {
            cout << "TV series does not exist so it wasn't added to the user." << endl;
            continue;
        }
    }
    file.close();
    return 0;
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

list<TVSeries*> TVSeriesManagementList::seriesByCategory(string cat) const
{
  list<TVSeries*> ltv;
  if (cat.empty())
  return ltv;
  for( auto it=listTVSeries.begin();it!=listTVSeries.end();it++)
  {
 
    if ((*it)->getGenre()==cat)
    ltv.push_back((*it));
  }
  return ltv;

}


int TVSeriesManagementList::TVSeriesDelete(string title, UserManagementList& userManagementlist)
{
    if (title.empty())
    return -1;
    int nUser=0,nWatched=0;
    list<User*> listUsers=userManagementlist.getListUsers();
   // vector<TVSeries*>& watechedSeries;
    for(auto it=listTVSeries.begin();it!=listTVSeries.end();it++)
    {
        if ((*it)->getTitle()==title)
        {
            nUser=listUsers.size();
            for (auto itU=listUsers.begin();itU!=listUsers.end();itU++)
            {
                vector<TVSeries*>& watechedSeries=(*itU)->getWatchedSeries();
                nWatched=watechedSeries.size();
                for (int i=0; i<nWatched;i++)
                {
                    cout << watechedSeries[i]->getTitle()<<endl;
                    if(watechedSeries[i]->getTitle()==title)
                    {
                        
                        watechedSeries.erase(watechedSeries.begin()+i);
                        
                        vector<int>& vepisodes=(*itU)->getEpisodesWatched();
                        vepisodes.erase(vepisodes.begin()+i);
                        vector<int>& vrating=(*itU)->getRatings();
                        vrating.erase(vrating.begin()+i);
                    }
                }
            }
            delete(*it);
            listTVSeries.erase(it);
            return 0;
        }
    }
    return -1;
}

// implementation of class UserManagementList

UserManagementList::UserManagementList(){};

list<User*> UserManagementList::getListUsers() const { return listUsers; }

void UserManagementList::addUser(User* newUser)
{
    listUsers.push_back(newUser);
}

list<User*> UserManagementList::seeAll(TVSeries* series)
{
    list<User*> lUser;
    if (series==nullptr)
    {
        return lUser;
    }
    vector<TVSeries*> vWateched;
    vector<int> vepisodes;
    int total=0;
    vector<int> nepisodes;
    nepisodes=series->getEpisodesPerSeason();
    for (int j=0;j<(int)nepisodes.size();j++)
    {
        total+=nepisodes[j];
    }
    for(auto it=listUsers.begin();it!=listUsers.end();it++)
    {
        vWateched=(*it)->getWatchedSeries();
        for (int i=0;i<(int)vWateched.size();i++)
        {
            if ((vWateched[i]==series) && ((*it)->getEpisodesWatched()[i]==total))
            {
                lUser.push_back(*it);

            }
        }
    }
    return lUser;
}

list<TVSeries*> TVSeriesManagementList::suggestsSeries(string username,string userWhoSuggests, list<User*> userlist ) const
{
    list<TVSeries*> lTVSeries;
    if (username.empty()|| userlist.empty() )
    {
        return lTVSeries;
    }
    bool exist=false;
    auto itU=userlist.begin();
    for (itU=userlist.begin();itU!=userlist.end();itU++)
    {
        if((*itU)->getUsername()==username)
        {exist=true;
        break;}
    }
 
     
    if (!exist)
    {
        return lTVSeries;
    }
   vector<string> vcatU=(*itU)->getFavoriteGenres();
    vector<TVSeries*> vTVSeries=(*itU)->getWatchedSeries();
    vector<TVSeries*> vWhoTVSeries;
    exist=false;
    auto itWho=userlist.begin();
for (itWho=userlist.begin();itWho!=userlist.end();itWho++)
    {
        if((*itWho)->getUsername()==userWhoSuggests)
        {exist=true;
        break;}
    }

    if (!exist)
    {
        for(auto it=listTVSeries.begin();it!=listTVSeries.end();it++)
        {
            if ((find(vTVSeries.begin(),vTVSeries.end(),*it)==vTVSeries.end()) && (find(vcatU.begin(),vcatU.end(),(*it)->getGenre())!=vcatU.end()))
            {
                lTVSeries.push_back(*it);
            }
        }
    } else
    {
        vWhoTVSeries=(*itWho)->getWatchedSeries();
          for(auto it=vWhoTVSeries.begin();it!=vWhoTVSeries.end();it++)
        {
            if ((find(vTVSeries.begin(),vTVSeries.end(),*it)==vTVSeries.end()) && (find(vcatU.begin(),vcatU.end(),(*it)->getGenre())!=vcatU.end()))
            {
                lTVSeries.push_back(*it);
            }
        }
    }
   
    return lTVSeries;
}


// implementation of class NodeUser
NodeUser::NodeUser(User* user){
    this->user=user;
    left=nullptr;
    right=nullptr;
} 

// implementation of class UserManagementTree
UserManagementTree::UserManagementTree() {
    root=nullptr;
}

NodeUser* UserManagementTree::insertNode(NodeUser* root, User* newUser) {
        // If the tree is empty, create a new node and return it
        if (root == nullptr) {
            return new NodeUser(newUser);
        }

        // Compares username to decide where to insert the node
        if (newUser->getUsername() < root->user->getUsername()) {
            root->left = insertNode(root->left, newUser);
        } else if (newUser->getUsername() > root->user->getUsername()) {
            root->right = insertNode(root->right, newUser);
        }

        return root;
    }
    
NodeUser* UserManagementTree::findMinNode(NodeUser* node) {
    NodeUser* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
    }

NodeUser* UserManagementTree::deleteNode(NodeUser* root, string user) {
    // Base case: empty tree
    if (root == nullptr) {
        return root;
    }

    // If the username to be deleted is smaller than the username of the current node, search the left subtree
    if (user < root->user->getUsername()) {
        root->left = deleteNode(root->left, user);
    }
    // If the username to be deleted is greater than the username of the current node, search the right subtree
    else if (user > root->user->getUsername()) {
        root->right = deleteNode(root->right, user);
    }
    // If the user is the same as the year of the current node, this is the node to be deleted
       else {
        // Case 1: node without children or with only one child
        if (root->left == nullptr) {
                NodeUser* temp = root->right;
                delete root;
                return temp;
        } else if (root->right == nullptr) {
                NodeUser* temp = root->left;
                delete root;
                return temp;
            }

        // Case 2: node with two children
        // Finds the minimum node of the right subtree (the successor)
        NodeUser* temp = findMinNode(root->right);
        // Copy successor to this node
        root->user = temp->user;
        // Exclui o sucessor
        root->right = deleteNode(root->right, temp->user->getUsername());
        }
    return root;
}

void UserManagementTree::inorderTraversal(NodeUser* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->user->getUsername() << " " << root->user->getName() << endl;
        inorderTraversal(root->right);
    }
}

NodeUser* UserManagementTree::getRoot() const
{
    return root;
}

void UserManagementTree::addUser(User* newUser) {
    root = insertNode(root, newUser);
}

void UserManagementTree::remove(string user) {
        root = deleteNode(root, user);
    }

void UserManagementTree::inorder() {
        inorderTraversal(root);
    }

priority_queue<TVSeries> UserManagement::queueTVSeriesCategory(priority_queue<TVSeries>& pq, string cat) {

  /*  priority_queue<TVSeries> pqnew;
    if (pq.empty() || cat.empty()) {
        return pqnew;
    }
    priority_queue<TVSeries> aux=pq;
    while(!aux.empty()) {
        if(aux.top().getGenre()==cat)
        {
            pqnew.push(aux.top());
        }

        aux.pop();
    }
    return pqnew;
    */priority_queue<TVSeries> pqnew;
       if (pq.empty() || cat.empty()) {
        return pqnew;
    }
    //priority_queue<TVSeries> aux=pq;
    while(!pq.empty()) {
        if(pq.top().getGenre()==cat)
        {
            pqnew.push(pq.top());
        }

        pq.pop();
    }
    return pqnew;
}


priority_queue<TVSeries> UserManagement::queueTVSeries(list<TVSeries*> listTV,int min) {
    priority_queue<TVSeries> q;
    if (listTV.empty()){
        return q;
    }
    int nUser=0;
    for (auto it=listTV.begin();it!=listTV.end();it++)
    {
        nUser=0;
   
        for ( int i=0;i<(int)vectorUsers.size();i++)
        {
           vector<TVSeries*> wtv=vectorUsers[i]->getWatchedSeries();
           vector<int> etv=vectorUsers[i]->getEpisodesWatched(); 
         
           for (auto j=0;j<wtv.size();j++)
           {
                if ((wtv[j]->getTitle()==(*it)->getTitle()) && (etv[j]>=2)) {
                    nUser++;
                 
                }
           }
    
        }
         if (nUser>=min) {
            q.push(**it);
        }
    }

    
    return q;
}

vector<User*> UserManagementTree::usersInitialLetter(NodeUser* root,char ch) {
    vector<User*> v;
    if (root==nullptr) {
        return v;
    }
    vector<User*> vleft;
    if (toupper(root->user->getUsername()[0])>=toupper(ch)) {
        vleft=usersInitialLetter(root->left,toupper(ch));
    }
    vector<User*> vright;
    if (toupper(root->user->getUsername()[0])<=toupper(ch)) {
        vright=usersInitialLetter(root->right,toupper(ch));
    }

    if  (toupper(root->user->getUsername()[0])==toupper(ch)) {
        v.push_back(root->user);
    }
 
    v.insert(v.end(),vleft.begin(),vleft.end());
    v.insert(v.end(),vright.begin(),vright.end());

    return v;
 }

list<User*> UserManagementTree::usersNotFan(NodeUser* root) {

    list<User*> lt;
    if (root==nullptr) {
        return lt;
    }

    list<User*> ltleft;
    ltleft= usersNotFan(root->left);
    list<User*> ltright;
    ltright= usersNotFan(root->right);

    vector<TVSeries*> wtv=root->user->getWatchedSeries();
    vector<int> etv=root->user->getEpisodesWatched();
    int total=0;
    int nc=0;
    for (auto i=0;i<wtv.size();i++)
    {
        vector<int> nepisodes=wtv[i]->getEpisodesPerSeason();
        total=0;
        for (int j=0;j<(int)nepisodes.size();j++)
        {
            total+=nepisodes[j];
        }
        if (total>etv[i]){
            nc++;
        }
    }
    if (nc>2) {
        lt.push_back(root->user);
    }

    lt.insert(lt.end(),ltleft.begin(),ltleft.end());
    lt.insert(lt.end(),ltright.begin(),ltright.end());

    return lt;        
}

vector<int> UserManagementTree::usersCategoryStatistics(NodeUser* root,string cat,int perc) {
    vector<int> v(3);
   
    if (root==nullptr || cat.empty() || perc<0 || perc>100){
    return v;
    }
 
    vector<TVSeries*> wtv=root->user->getWatchedSeries();
    vector<int> etv=root->user->getEpisodesWatched();
    int total=0;
 
    for (auto i=0;i<wtv.size();i++)
    {
        if ((wtv[i]->getGenre()==cat) && (etv[i]>=1)) {
            
            v[0]=1;
            vector<int> nepisodes=wtv[i]->getEpisodesPerSeason();
            total=0;
            for (int j=0;j<(int)nepisodes.size();j++)
            {
                total+=nepisodes[j];
            }
            if(etv[i]*100/total>=perc){
                v[1]=1;
                vector<string> fg=root->user->getFavoriteGenres();
                auto it=find(fg.begin(),fg.end(),cat);
                if (it!=fg.end()){
                    v[2]=1;
                }
            }
        }
    }    
    vector<int> vleft;
    vleft= usersCategoryStatistics(root->left,cat,perc);
    vector<int> vright;
    vright= usersCategoryStatistics(root->right,cat,perc);
    for (int i=0;i<3;i++){
    v[i]+=vleft[i]+vright[i];
    }
    return v;
}

HashTable::HashTable(int ts)
{
    if (ts>0)
    {
    tableSize = ts;
    totalCountryStats=0;
    table.resize(ts,nullptr);
  
    } else delete this;
}

/* DESTRUTOR */

HashTable::~HashTable()
{

   for (int i=0;i<tableSize;i++)
   {
       
        delete (table[i]);
            
   } 
 
}

int HashTable::getTableSize() const
{
    
    return tableSize;
}
int HashTable::getTotalCountryStats() const
{
    
    return totalCountryStats;
}
vector<CountryStats*> HashTable::getTable() const
{
    return table;
}

int HashTable::hashFunction(string key)
{
    if (!key.empty())
    {
    int h = 7; 
    for(int i = 0; key[i]; i++)
    {
        h += (int)key[i];
    }

    return h % tableSize;
    } else return -1;
}


int HashTable::probingFunction(string key,int i)
{
    if (!key.empty())
    {
    int h = hashFunction(key); 
   
        h += 23*i*i;
 

    return h % tableSize;
    } else return -1;
}

int HashTable::searchCountryStats(string country) 
{
            
    if (country.empty())
    {
        return -1;
    }
   
    int index = hashFunction(country);
    if (table[index]==nullptr) return -1;
    if (table[index]->country==country)
    {
        
        return index;
    } else 
    {
        int i=1;
        
        while((table[index]->country!=country))
        {
            
            index=probingFunction(country,i);
            if (table[index]==nullptr) return -1;
            if (table[index]->country==country)
            {
                return index;
            } 
            i++;
            
        }
    }
    return -1;        
}

int HashTable::deleteAccountStats(string country)
{       
    if (country.empty())
    {
        return -1;
    }
    int index = hashFunction(country);
    if (table[index]->country==country)
    {
        delete(table[index]);
        totalCountryStats--;
        CountryStats *as=new CountryStats("apagado",0,0,0.0,{0,0,0,0,0});
        table[index]=as;
        return 0;
    } else 
    {
        int i=1;
        while((table[index]!=nullptr))
        {
            index=probingFunction(country,i);
            if (table[index]->country==country)
            {
                delete(table[index]);
                totalCountryStats--;
                CountryStats *as=new CountryStats("apagado",0,0,0.0,{0,0,0,0,0});
                table[index]=as;
                return 0;
            } 
            i++;
        }
    }
    return -1; 

}     


void HashTable::show(void)      
{
    for(int i=0;i<tableSize;i++)
    {
        if (table[i]!=nullptr)
        {cout << i << "->" << table[i]->country << "-" <<table[i]->nUsers<< "-" <<table[i]->nTVSeries<<"-" <<table[i]->averageTVseries ;
        for (int j=0;j<N_GENRES; j++)
            {
            cout<<"-"<<vGenres[j]<<"("<<table[i]->nGenre[j]<<")"<<endl;
            } 
        }else
        cout << i << endl;
    }
}


UserManagementGraph::UserManagementGraph()
{
    totalUsers = 0;
    userNodes.clear();
    network.clear();
}

size_t UserManagementGraph::getTotal() const
{
    return totalUsers;
}

vector<User*> UserManagementGraph::getUserNodes() const
{
    return userNodes;
}

vector<list<User*>> UserManagementGraph::getNetwork() const
{
    return network;
}

int UserManagementGraph::addUserNode(User* userPtr)
{
    if (!userPtr) return -1;

    if (userNodePosition(userPtr) >= 0) return 1; // User already exists in the graph
    
    userNodes.push_back(userPtr);
    network.resize(userNodes.size());
    totalUsers = userNodes.size();
    return 0;
}

int UserManagementGraph::userNodePosition(User* userPtr)
{
    if (!userPtr) return -2;

    auto it = find(userNodes.begin(), userNodes.end(), userPtr);
    if (it == userNodes.end()) return -1; // Node does not exist

    return it - userNodes.begin();
}

int UserManagementGraph::addFollower(User* userA, User* userB)
{
    if (!userA || !userB) return -1;

    int posA = userNodePosition(userA), posB = userNodePosition(userB);

    if (posA == -2 || posB == -2) return -1; // Error

    // Check if the nodes exist
    if (posA == -1) {
        addUserNode(userA); // Add userA
        posA = userNodePosition(userA); // Update posA with userA position
    }
    if (posB == -1) {
        addUserNode(userB); // Add userB
        posB = userNodePosition(userB); // Update posB with userB position
    }

    // Check if the edge already exists
    if (find(network.at(posA).begin(), network.at(posA).end(), userB) != network.at(posA).end()) return 1;

    network.at(posA).push_back(userB);
    return 0;
}

int UserManagementGraph::removeFollower(User* userA, User* userB)
{
    if (!userA || !userB) return -1;

    int posA = userNodePosition(userA), posB = userNodePosition(userB);

    if (posA == -1 || posB == -1 || posA == -2 || posB == -2) return -1; // Error

    // Check if the edge does not exist
    if (find(network.at(posA).begin(), network.at(posA).end(), userB) == network.at(posA).end()) return 1;

    network.at(posA).remove(userB);
    return 0;
}

void UserManagementGraph::printGraph()
{
    for (int i = 0; i < (int) totalUsers; i++) {
        cout << "(" << i << ") " << userNodes.at(i)->getUsername() << " -> ";

        size_t j = 0;
        for (auto u_follow : network.at(i)){
            cout << u_follow->getUsername();
            j++;
            if (j != network.at(i).size()) cout << " | ";
        }
        cout << endl;
    }
    cout << endl;
} 

struct CompareP {
    bool operator () (User *user1, User *user2)
    {

        return user1->getLength() > user2->getLength();
    }
};









/**************************/
/*     A implementar      */
/**************************/









vector<User*> UserManagementGraph::mostFollowing()
{
// question 1
    vector<User*> vMostUsers;   //vector to be returned
    size_t max = 0;             //max amount of Users followed by an User (the one(s) in vMostUsers)

    if (totalUsers == 0) return vMostUsers; //if network is empty: return empty vector
    
    for(size_t i = 0; i < totalUsers; i++)  //check if all Nodes have valid User pointers
    {
        if(userNodes[i] == nullptr) return vMostUsers;  //if not: return empty vector
    }

    for(size_t i = 0; i < totalUsers; i++)  //for all Users:
    {
        if(network[i].size() == max)    //if they follow the same amount of Users than the User(s) with the current max amount:
        {
            vMostUsers.push_back(userNodes[i]); //push it into vMostUsers
        }
        else if(network[i].size() > max)    //if they follow more Users than the User(s) with the current max amount:
        {
            max = network[i].size();            //update the max amount
            vMostUsers.clear();                 //clear vMostUsers
            vMostUsers.push_back(userNodes[i]); //and push the new User into vMostUsers
        }
    }

    return vMostUsers;  //return our filled vector
}







TVSeries* UserManagementGraph::followingMostWatchedSeries(User* userPtr)
{
// question 2
    TVSeries* vMostViewed=nullptr;

    if(userPtr == nullptr) return vMostViewed;  //check for faulty parameter

//create the variables needed to the operation
    vector<TVSeries*> viewed;   //vector to keep track of the series watched by the multiple Users followed by User pointed by userPtr
    vector<int> eps, viewers;   //vectors to keep track of the total number of episodes watched by the same multiple Users for each
    //TVSeries in viewed and also how many of those Users have seen each one of those TVSeries
    list<User*>::iterator net = network[userNodePosition(userPtr)].begin();

//get the TVSeries into viewed and respective nº of episodes watched to eps and viewers to viewers
    for(size_t i = 0; i < network[userNodePosition(userPtr)].size(); i++)
    {
        vector<TVSeries*> watchedseries = (*net)->getWatchedSeries();   //accessible copy of each User's watchedSeries
        vector<int> epswatched = (*net)->getEpisodesWatched();          //accessible copy of each User's episodesWatched

        for(size_t j = 0; j < watchedseries.size(); j++)
        {
            auto it = find(viewed.begin(), viewed.end(), watchedseries[j]); //search for each TVSeries in viewed
            if(it == viewed.end())  //if not found:
            {
                viewed.push_back(watchedseries[j]); //add TVSeries (pointer) to viewed
                eps.push_back(epswatched[j]);       //add the number of episodes watched by this User
                viewers.push_back(1);               //add the first viewer for this TVSeries
            }
            else    //if found:
            {
                eps[distance(viewed.begin(), it)] += epswatched[j]; //update the total number of episodes watched for this TVSeries
                viewers[distance(viewed.begin(), it)]++;            //increment the number of viewers for this TVSeries
            }
        }

        net++;  //increment network iterator
    }

//filter the TVSeries to be returned
    int max_eps = 0, max_viewers = 0;   //create max variables

    for(size_t i = 0; i < viewed.size(); i++)   //for each TVSeries in viewed:
    {
        if(eps[i] > max_eps)    //if it has more episodes watched:
        {
            max_eps = eps[i];           //update max_eps
            max_viewers = viewers[i];   //update max_viewers
            vMostViewed = viewed[i];    //update TVSeries (pointer) to be returned
        }
        else if(eps[i] == max_eps)  //if it has the same nº of episodes watched:
        {
            if(viewers[i] > max_viewers)    //but it has more viewers:
            {
                max_viewers = viewers[i];   //update max_viewers
                vMostViewed = viewed[i];    //update TVSeries (pointer) to be returned
            }
            else if(viewers[i] == max_viewers)  //and the same nº of viewers:
            {
                if(viewed[i]->getTitle() < vMostViewed->getTitle()) //if it is first in alphabetical order:
                {
                    vMostViewed = viewed[i];    //update TVSeries (pointer) to be returned
                }
            }
        }
    }

    return vMostViewed; //return our TVSeries (pointer)
}







int UserManagementGraph::shortestPaths(User* userSrc, User* userDst)
{
    int d = 0;
    list<User*> vizinhos;
    
    
    if(userSrc == nullptr || userDst == nullptr) return -1;
    
    for (auto node : userNodes){ //Iterate through all the nodes
        if (node == userSrc) node->setLength(0); //Set distance of userSrc to 0
        else node->setLength(std::numeric_limits<int>::max()); //Set distance of other nodes to max (infinity)
    }
    
    priority_queue<User*, vector<User*>, CompareP> queue;
    queue.push(userSrc);
    
    while (!queue.empty()) {
        User* temp = queue.top();
        queue.pop();
        if (temp == userDst) break;
        
        for(int i = 0; i < (int) totalUsers; i++){
            if(userNodes.at(i) == temp){
                for (auto user : network.at(i)){
                    vizinhos.push_back(user);
                }
            }
        }
        
        for (auto vizinho : vizinhos){
            d = temp->getLength() + 1;
            
            // Update distance if shorter path is found
            if(d < vizinho->getLength()) {
                vizinho->setLength(d);
                queue.push(vizinho);
            }
        }
    }
    
    if (userDst->getLength() == std::numeric_limits<int>::max()) return -2;
    
    return userDst->getLength();
}







int HashTable::insertCountryStats(CountryStats &countryS)
{
    int index = 0;
    string country = countryS.country;
    
    if(country.empty()) return -1;
    
    index = hashFunction(countryS.country);

    int c = 1;
    while(table[index] != nullptr){
        index = probingFunction(country, c++);
    }
    
    table[index] = &countryS;
    
    totalCountryStats++;
    
    //cout<<"Indice da chave \"apagado\" : "<<hashFunction(countryS.country)<<endl;
    
    //show();
    
    return index;
}







int HashTable::importFromVector(UserManagement &userManager)      
{
// question 5

//create a vector with a vector for each country's CountryStats
    //(for this, we'll use the "index", this way, CountryStats position is the same in both the table and seriesCStats)
//each one of those index vectors have all the DIFFERENT TVSeries watched by the Users of their indexes' countries
    //this will be specially useful when there's need to update a CountryStats' nTVSeries and nGenre attributes
    vector<vector<TVSeries*>> seriesCStat;

//set seriesCStat size to maximum (the same size as table) each country
    seriesCStat.resize(tableSize);

    for(User* user: userManager.getVectorUsers())   //for each User pointed by the pointers "user" in userManager's vectorUsers:
    {//begin importFromVector

        if(user == nullptr) return -1;  //check for nullptrs

        vector<TVSeries*>& watchS = user->getWatchedSeries();   //shortcut alias to User's watchedSeries
        int index = searchCountryStats(user->getCountry());     //save User's country's CountryStats position in the table for later usage
        vector<int> vGen(N_GENRES, 0);                          //create/reset vector to use as payload to nGenre attribute

    //index == -1 means CountryStats does not exist
        if(index == -1) //if CountryStats for this User's country doesn't exist: CS CREATION PROCESS
        {//begin CS CREATION PROCESS

        //update vGen
            for(size_t i = 0; i < watchS.size(); i++)   //for each TVSeries in User's watchedSeries:
            {
                for(size_t j = 0; j < N_GENRES; j++)    //for each Genre:
                {//compare TVSeries' Genre with each Genre
                    if(watchS[i]->getGenre() == vGenres[j]) //whenever a correspondence is found:
                    {
                        vGen[j]++;  //update vGen count of corresponding Genre
                    }
                }
            }

        //create new CountryStats
            CountryStats *CStat = new CountryStats(user->getCountry(), 1, watchS.size(), watchS.size(), vGen);
        //insert new CountryStats into the table and get its index
            index = insertCountryStats(*CStat);

        //fill the new CountryStats' vector in seriesCStat
            for(size_t i = 0; i < watchS.size(); i++)   //for each TVSeries in User's watchedSeries:
            {
                seriesCStat[index].push_back(watchS[i]);   //push it into the vector
            }

        }//end CS CREATION PROCESS

        else    //if CountryStats already exists: CS UPDATE PROCESS
        {//begin CS UPDATE PROCESS

            table[index]->nUsers++; //update nUsers

        //update seriesCStat
            for(size_t i = 0; i < watchS.size(); i++)   //for each TVSeries in User's watchedSeries:
            {//search TVSeries within seriesCStat[index]
                auto it = find(seriesCStat[index].begin(), seriesCStat[index].end(), watchS[i]);
                if(it == seriesCStat[index].end())  //if TVSeries is not within seriesCStat[index]:
                {
                    seriesCStat[index].push_back(watchS[i]);    //push it into the vector
                }
            }

            table[index]->nTVSeries = seriesCStat[index].size();    //updated nTVSeries
            
        //update averageTVseries
            table[index]->averageTVseries *= (table[index]->nUsers - 1);    //multiply by nUsers-1 in order to get previous sum
            table[index]->averageTVseries += watchS.size();                 //update sum by adding the new parcel
            table[index]->averageTVseries /= (float)table[index]->nUsers;   //divide (the sum) by nUsers to get average
            
        //update vGen
            for(size_t i = 0; i < seriesCStat[index].size(); i++)
            {
                for(size_t j = 0; j < N_GENRES; j++)    //for each Genre:
                {//compare TVSeries' Genre with each Genre
                    if(seriesCStat[index][i]->getGenre() == vGenres[j])  //whenever a correspondence is found:
                    {
                        vGen[j]++;  //update vGen count of corresponding Genre
                    }
                }
            }

            table[index]->nGenre = vGen;    //update nGenre

        }//end CS UPDATE PROCESS
    
    }//end importFromVector

    return 0;   //return success code
}
