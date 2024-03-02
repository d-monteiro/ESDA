#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "TVseries.hpp"




using namespace std;

int verifica_displayUserInfo(User& us1, User& us2)
{
    int er = 0;
 
    stringstream ss;
    string str,strtotal="",str1;
    str1="Displaying user info:\n-----Username: john_doe\n-----Name: John\n-----Country: USA\n-----Favorite Genres:\n------ Action\n------ Comedy\n------ Drama\n-----Watched Series:\n------ Dark, Episodes Watched: 0\n------ Echo, Episodes Watched: 0";
    us1.displayUserInfo(ss);
   
    while(getline(ss,str))
    {
            strtotal += str+"\n";
    }
      
    if (!strtotal.empty()) strtotal.pop_back();
    
    /*Teste 1*/
    if (strtotal!=str1)
    {
        cout << "...verifica_displayUserInfo: Informação do User1 está incorreta - " << endl<< strtotal <<endl << "Devia aparecer:" << endl << str1;
           er++;
    }
    else
        cout << "...verifica_displayUserInfo: Informação do User1 está correta (ok)" << endl;
    
    ss.clear();
    str1="Displaying user info:\n-----Username: rodrigo8\n-----Name: Rodrigo\n-----Country: Portugal\n-----Favorite Genres:\n------ Drama\n------ Crime\n-----Watched Series:\n------ Echo, Episodes Watched: 0";
    us2.displayUserInfo(ss);
    strtotal="";
    while(getline(ss,str))
    {
            strtotal += str+"\n";
    }
    if (!strtotal.empty()) strtotal.pop_back();
    /*Teste 2*/
    if (strtotal!=str1)
    {
        cout << "...verifica_displayUserInfo: Informação do User3 está incorreta - " << endl<< strtotal <<endl << "Devia aparecer:" << endl << str1;
          er++;
    }
    else
        cout << "...verifica_displayUserInfo: Informação do User3 está correta (ok)" << endl;

    
    return er;
}

int verifica_addRating(User& us1,TVSeries &serie)
{
    
    int er = 0;
    TVSeries serie1("Dark3", 1,{2},"Drama", 2,1);
    int res=us1.addRating(&serie1,4);
    if (res!=-2)
    {
        cout << "...verifica_addRating: Serie não existe, retorno(="<<res<<") e' diferente do esperado (=-2) (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_addRating: Serie não existe, retorno =-2 (ok)" << endl;
    
    res=us1.addRating(&serie,4);
    if (res!=0)
    {
        cout << "...verifica_addRating: Serie existe, retorno(="<<res<<") e' diferente do esperado (=0) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_addRating: Serie existe, retorno =0 (ok)" << endl;
    
    if (us1.getRatings()[1]!=4)
    {
        cout << "...verifica_addRating: Rating da serie ="<<res<<") e' diferente do esperado (=4) (ERRO)"<< endl ;
         er++; 
    }
    else
        cout << "...verifica_addRating: Rating da serie =4 (ok)" << endl;
    
   
    return er;
}

int verifica_updateRating(TVSeries &serie, const vector<User*>& vectorUser)
{
    int er = 0;
    TVSeries serie1("Dark3", 1,{2},"Drama", 2,1);
    float res=serie1.updateRating(vectorUser);
    if (res!=0)
    {
        cout << "...verifica_updateRating: Ninguém viu esta serie, retorno(="<<res<<") e' diferente do esperado (=0) (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_updateRating: Ninguém viu esta serie, retorno =0 (ok)" << endl;
    
    res=serie.updateRating(vectorUser);
    
    cout <<fixed << setprecision(2);
    if (res!=6.25)
    {
        cout << "...verifica_updateRating: retorno de updateRating="<<res<<") e' diferente do esperado (=6.25) (ERRO)"<< endl ;
         er++; 
    }
    else
        cout << "...verifica_updateRating: retorno de updateRating=="<<res<<" (ok)" << endl;
       if (serie.getRating()!=6.25)
    {
        cout << "...verifica_updateRating: series_echo->getRating()="<<serie.getRating()<<") e' diferente do esperado (=6.25) (ERRO)"<< endl ;
         er++; 
    }
    else
        cout << "...verifica_updateRating: series_echo->getRating()="<<serie.getRating()<<" (ok)" << endl;
    
   
    return er;
}

int verifica_TVSeriesInsert(TVSeries &serie, TVSeriesManagement& tvSeriesManager)
{
    int er = 0;

    int res=tvSeriesManager.TVSeriesInsert(NULL);
    if (res!=-1)
    {
        cout << "...verifica_TVSeriesInsert: Serie não existe, retorno(="<<res<<") e' diferente do esperado (=-1) (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_TVSeriesInsert: Serie não existe, retorno =-1 (ok)" << endl;
    
    res=tvSeriesManager.TVSeriesInsert(&serie);
    if (res!=0)
    {
        cout << "...verifica_TVSeriesInsert: Inserir Serie, retorno(="<<res<<") e' diferente do esperado (=0) (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_TVSeriesInsert: Inserir Serie, retorno =0 (ok)" << endl;
    if (tvSeriesManager.getVectorTVSeries().size()>0)
    if (tvSeriesManager.getVectorTVSeries()[tvSeriesManager.getVectorTVSeries().size()-1]->getTitle()!=serie.getTitle())
    {
        cout << "...verifica_TVSeriesInsert: Serie não foi inserida na ultima posicao do vetor tvseriesManager  (ERRO)"<< endl ;
         er++; 
    }
    else
        cout << "...verifica_TVSeriesInsert: Serie foi inserida com sucesso na ultima posicao do vetor tvseriesManager (ok)" << endl;
    
   
    return er;
}


int verifica_updateWatched(string& name_file, TVSeriesManagement& tvSeriesManager,UserManagement &UserM )
{
    int er = 0;
  
    int res=UserM.updateWatched("",tvSeriesManager);
    if (res!=-1)
    {
        cout << "...verifica_updateWatched: Ficheiro não existe, retorno(="<<res<<") e' diferente do esperado (=-1) (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_updateWatched: Ficheiro não existe, retorno =-1 (ok)" << endl;
    
    res=UserM.updateWatched(name_file,tvSeriesManager);
    if (res!=0)
    {
        cout << "...verifica_updateWatched: Ficheiro existe , retorno(="<<res<<") e' diferente do esperado (=0) (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_updateWatched: Inserir Serie, retorno =0 (ok)" << endl;
 if (UserM.getVectorUsers().size()>0)
{if (UserM.getVectorUsers().size()<7) return er;
if (UserM.getVectorUsers()[5]->getEpisodesWatched().size()==0) return er;
    if (UserM.getVectorUsers()[5]->getEpisodesWatched()[0]!=24)
    {
        cout << "...verifica_updateWatched: Numero de episodios do user emily_c não foi inserido corretamente(="<<UserM.getVectorUsers()[6]->getEpisodesWatched()[0]<<") e' diferente do esperado (=24) (ERRO)"<< endl ;
         er++; 
    }
    else
        cout << "...verifica_updateWatched: Numero de episodios do user emily_c foi inserido corretamente =24 (ok)" << endl;
    
   if (UserM.getVectorUsers()[6]->getEpisodesWatched()[0]!=10)
    {
        cout << "...verifica_updateWatched: Numero de episodios do user carlitos não foi inserido corretamente(="<<UserM.getVectorUsers()[6]->getEpisodesWatched()[0]<<") e' diferente do esperado (=10) (ERRO)"<< endl ;
         er++; 
    }
    else
        cout << "...verifica_updateWatched: Numero de episodios do user carlitos foi inserido corretamente =10 (ok)" << endl;
}   
   
    return er;
}

int main()
{

     int errorCount = 0, error;

    cout << "INICIO DOS TESTES\n\n" << endl;
    // Create users for testing
    // Create a TV series manager object
    TVSeriesManagement tvSeriesManager;

    User user1("john_doe", "John", "USA", {vGenres[0], vGenres[1], vGenres[2]}); // user1 with favorite genres Action, Comedy, Drama
    User user2("mia_davis", "Milena", "Luxembourg", {vGenres[1], vGenres[3], vGenres[4]}); 
    User user3("rodrigo8", "Rodrigo", "Portugal", {vGenres[2], vGenres[4]});
    User user4("mike124", "Michael", "USA", {vGenres[0], vGenres[1]});
    User user5("teresa_santos", "Teresa", "Portugal", {vGenres[3]});
    User user6("emily_c", "", "Emily", {vGenres[2], vGenres[1], vGenres[2]});
    User user7("carlitos", "Carlos", "Spain", {vGenres[0], vGenres[1]});
    
    TVSeries* series_dark = new TVSeries("Dark", 3,{8,8,8},"Drama", 8.8,1);
    tvSeriesManager.TVSeriesInsert(series_dark);
    TVSeries* series_echo = new TVSeries("Echo", 1,{5},"Action", 0.0,0);
    tvSeriesManager.TVSeriesInsert(series_echo);
    TVSeries* series_dark5 = new TVSeries("Dark5", 3,{8,8,8},"Drama", 8.8,1);

    user1.addWatchedSeries(series_dark); 
    user1.addWatchedSeries(series_echo); 
   // user2.addWatchedSeries(nullptr);  
    
    // Test the display method
  


   

    
  

    //Open the file "series.txt"
    ifstream file("series_small.txt");
    if (!file.is_open()) {
        cout << "Error: Unable to open series.txt file." << endl;
        return -1;
    }

    string line;
    TVSeries* series;
    // Read each line from the file
    while (getline(file, line)) {
        // Parse the line to extract series information
        string title, genre, n, episodesStr,finishedstr, ratingstr;
        char finishedchar;
        int numberOfSeasons;
        vector<int> episodesPerSeason;
        float rating;
        bool finished;
        stringstream ss;
        ss.clear();
        ss << line; 
        getline(ss, title, ',');
        getline(ss, n, ',');
        numberOfSeasons = stoi(n);
        getline(ss, episodesStr, ',');
        
        stringstream episodesStream(episodesStr);
        string episode;
        while (getline(episodesStream, episode, ' ')) {
            episodesPerSeason.push_back(stoi(episode));
        }
        getline(ss, genre, ','); 
        getline(ss, ratingstr, ',');
        rating = stof(ratingstr);
        getline(ss, finishedstr);
        finishedchar = finishedstr[0];
        finished = (finishedchar != '0');
     
        // Create a new TV series object
        series = new TVSeries(title, numberOfSeasons, episodesPerSeason, genre, rating, finished);

        // Add the TV series to the manager
        tvSeriesManager.TVSeriesInsert(series);
    }
    // Close the file
    file.close();

    // Print the TVSeries titles to verify the content of the vector
 /*   cout << "TVSeries titles in tvseries manager:" << endl;
    for (const TVSeries* seriesPtr : tvSeriesManager.getVectorTVSeries()) {
        seriesPtr->displaySeriesInfo();
    } */
    

    // Create a user management object
    UserManagement userManager;
    userManager.addUser(&user1);
    userManager.addUser(&user2);
    userManager.addUser(&user3);
    userManager.addUser(&user4);
    userManager.addUser(&user5);
    userManager.addUser(&user6);
    userManager.addUser(&user7);
    user3.addWatchedSeries(series_echo); 
    user4.addWatchedSeries(series_echo); 
    user5.addWatchedSeries(series_echo); 
    user3.addRating(series_echo,6);
    user4.addRating(series_echo,8);
    user5.addRating(series_echo,7);
    
//
 


      error = verifica_displayUserInfo(user1,user3);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_displayUserInfo\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_displayUserInfo passou\n\n" << endl;
    }  


        error = verifica_addRating(user1,*series_echo);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_addRating\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_addRating passou\n\n" << endl;
    } 

  
        error = verifica_updateRating(*series_echo,userManager.getVectorUsers());
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_updateRating\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_updateRating passou\n\n" << endl;
    } 

          error = verifica_TVSeriesInsert(*series_dark5,tvSeriesManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_TVSeriesInsert\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_TVSeriesInsert passou\n\n" << endl;
    } 
    string file1="user_updateWateched.txt";
              error = verifica_updateWatched(file1,tvSeriesManager,userManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_updateWatched\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_updateWatched passou\n\n" << endl;
    } 


     if (errorCount == 0)
        cout << "FIM DOS TESTES: Todos os testes passaram\n" << endl;
    else
        cout << "FIM DOS TESTES: Foram encontrados "<< errorCount << " ERROS no total\n" << endl;

    return 0;
}