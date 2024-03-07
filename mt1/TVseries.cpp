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

    os<<"Displaying user info:"<<endl;
    os<<"-----Username: "<<username<<endl;  //display username
    os<<"-----Name: "<<name<<endl;          //display name
    os<<"-----Country: "<<country<<endl;    //display country
//display favorite genres
    os<<"-----Favorite Genres:"<<endl;
    for(size_t i=0;i<favoriteGenres.size();++i) //Iterate through the array
    {                                           //displaying all favorite genres
        os<<"------ "<<favoriteGenres[i]<<endl;
    }
//display watched series w/ repective number of watched episodes 
    os<<"-----Watched Series:"<<endl;
    for(size_t i=0;i<watchedSeries.size();++i)  //Iterate through the array
    {                                           //displaying all watched series w/ respective number of episodes watched
        os<<"------ "<<watchedSeries[i]->getTitle()<<", Episodes Watched: "<<episodesWatched[i]<<endl;
    }
}

int User::addRating(TVSeries* series, float rating)
{
//answer 2

//verificar parâmetros; if invalid (series pointer is null or rating value is out of bounds (under 0)): return -1
    if(series == nullptr || rating < 0) return -1;
//procurar a série na lista de séries já vistas
    vector<TVSeries*>::iterator it = find(watchedSeries.begin(), watchedSeries.end(), series);
//verificar se a série já foi vista; ifnot: return -2
    if(it == watchedSeries.end()) return -2;
//atribuir o rating na posição correspondente à série
    ratings[distance(watchedSeries.begin(), it)] = rating;
//código de retorno: bem sucedido
    return 0;
}

float TVSeries::updateRating(const vector<User*>& vectorUser)
{
//answer 3
  
    float sum = 0;  //Inicialization of sum
    int n = 0;      //Inicialization of number of matches (ratings) found
  
  
    for(size_t i=0;i<vectorUser.size();++i) //Iterate through all the users (i)
    {
    if(vectorUser[i] == nullptr) return -1; //And find any nullptr's (meaning that vectorUser has a faulty element(i))
    }
  
    for(size_t i=0;i<vectorUser.size();++i) //Iterate through all the users (i)
    {
        vector<TVSeries*> series = vectorUser[i]->getWatchedSeries();   //Series watched by a single user (for each one of them)
    
        for(size_t j=0;j<series.size();++j) //Iterate through all the series watched (j)
        {
            if(series[j]->getTitle() == title)  //If match found (meaning that series' been watched by User)
            {
                vector<int> ratings = vectorUser[i]->getRatings();  //Ratings of all the series watched by an user
                sum+=ratings[j];    //Increment sum w/ the corresponding rating
                n+=1;               //Increment number of matches found
            }
        }
    }
    if(n==0) return 0;  //Return 0, if no user has seen the series
  
    rating=(sum/n); //calculate new rating
    return rating;  //Return new rating
}

int TVSeriesManagement::TVSeriesInsert(TVSeries* series)
{
//answer 4

    if(series == nullptr) return -1;    //Find a nullptr (faulty parameter)

//verificar se a série já existe; ifyes: return 1
auto it = find(vectorTVSeries.begin(), vectorTVSeries.end(), series);
if(it != vectorTVSeries.end()) return 1;
    
//adicionar a série à lista
if(it == vectorTVSeries.end())
{
  vectorTVSeries.insert(vectorTVSeries.end(), series);
}
return 0;//código de retorno: bem sucedido
}

int UserManagement::updateWatched(string filename, TVSeriesManagement& manager)
{
//answer 5


//verificar os parâmetros; if invalid (filename empty): return -1;
    if(filename == "") return -1;

//abrir ficheiro de texto
    ifstream fin(filename);

//verificar abertura bem sucedida do ficheiro; ifnot: return -1
    if(!fin) return -1;

//ler dados em ficheiro
    string title, uname, nepsw_str;
    while(getline(fin, title, ',') && getline(fin, uname, ',') && getline(fin, nepsw_str))
    {   //enquanto houver dados:


//TVSERIES



    //verificar existência de TVSeries; iffalse: return -2 //processo muito longo porque title é privado de TVSeries e vectorTVSeries é privado de TVSeriesManagement

        vector<TVSeries*> vtvs = manager.getVectorTVSeries();    //vtvs é uma cópia acessível de manager.vectorTVSeries (privado de TVSeriesManagement)
        int sz = vtvs.size();    //nº de elementos de manager.vectorTVSeries
        bool exists = 0;    //se existe a TVSeries em questão
        int itvs;   //posição da TVSeries em manager.vectorTVSeries

        for(int i = 0; i < sz; i++) //pesquisar TVSeries em manager.vectorTVSeries
        {   //i é cada TVSeries no manager.vectorTVSeries

        //comparar o title com o title de cada TVSeries no manager.vectorTVSeries
            if(title == vtvs[i]->getTitle())
            {   //se TVSeries é encontrada:
            
                exists = 1;   //atualizar existência da TVSeries em questão
                itvs = i;   //registar a sua posição no manager.vectorTVSeries
                break;  //terminar pesquisa da TVSeries

            }//fim comparação TVSeries

        }//fim pesquisa TVSeries

    //(Finalmente) verificar existência de TVSeries; iffalse: return -2
        if(!exists) return -2;
        
        

//USER


        
        else
        {
        //verificar existência de User  //processo longo porque username é privado de User

            sz = vectorUsers.size();    //reutilizar a variável sz; nº de elementos de vectorUsers
            exists = 0; //reutilizar a variável; se existe o User em questão
            int iu; //posição do User em vectorUsers

            for(int i = 0; i < sz; i++) //pesquisar User em vectorUsers
            {   //i é cada User no vectorUsers

            //comparar o username com o username de cada User no vectorUsers
                if(uname == vectorUsers[i]->getUsername())
                {   //se User é encontrado:

                    exists = 1;   //atualizar existência do User em questão
                    iu = i; //registar a sua posição no vectorUsers
                    break;  //terminar pesquisa do User

                }//fim comparação User

            }//fim pesquisa User

        //(Finalmente) verificar existência de User
            if(!exists)
            {   //iffalse: NEW-USER-PROTOCOL

            //criar newUser
                vector<string> fav;
                User newUser(uname, "Unknown", "Unknown", fav);

            //criar apontador para o newUser
                User* nUser = &newUser; 

            //adicionar newUser a vectorUsers
                addUser(nUser);

            //e registar a sua posição no vectorUsers
                iu = sz;    //!apesar do tamanho de vectorUsers ter aumentado, sz não foi atualizado!
                
            }//fim NEW-USER-PROTOCOL


            
//watchedSeries



        //agora que sabemos que temos o user e a série e sabemos as posições de ambos nos respetivos vetores:

        //verificar/adicionar TVSeries a watchedSeries do User em questão (User é vectorUsers[iu]; o seu watchedSeries é vectorUsers[iu].watchedSeries)
            int ret = vectorUsers[iu]->addWatchedSeries(vtvs[itvs]); //addWatchedSeries retorna: 0 para nova adição com sucesso, 1 para série já vista e -1 para erro
        
            if(ret == -1)
            {   //código de erro: return -1
                return -1;
            }
            else
            {   //reto == 0 || ret == 1: adicionar/atualizar episodesWatched
                int nepsw = stoi(nepsw_str);    //nº de episodesWatched em int
            //adicionar/atualizar episodesWatched
                int out = vectorUsers[iu]->addEpisodesWatched(vtvs[itvs],nepsw);   //addEpisodesWatched retorna: 0 para adição bem sucedida, -1 para parâmetros inválidos e -2 para série não existente (em watchedSeries)
                if(out) //out == -1 || out == -2
                {   //código de erro: return -1
                    return -1;
                }
                //else; out == 0  //código de sucesso: prosseguir (não fazer nada)
                
            }//fim adicionar/atualizar episodesWatched

        }//fim else(if(TVSeries existe))

    }//fim while(leitura)

//fechar ficheiro de texto
    fin.close();
    
//código de retorno: bem sucedido
    return 0;
}
