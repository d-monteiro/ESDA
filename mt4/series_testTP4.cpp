#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <list>
#include <queue>
#include <math.h> 
#include "TVseries.hpp"




using namespace std;

int verifica_mostFollowing(UserManagementGraph& g)
{
    int er = 0;
    UserManagementGraph g1;

    /*Teste 1*/
    vector<User*> vector_following = g1.mostFollowing();
    if (!vector_following.empty())
    {
        cout << "...verifica_mostFollowing: (Grafo vazio) - retorno não é um vetor vazio (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_mostFollowing: (Grafo vazio) - retorno é um vetor vazio (ok)" << endl;
    

    /*Teste 2*/
    vector_following = g.mostFollowing();
   
    if (vector_following.size()!=3)
    {
        cout << "...verifica_mostFollowing: (Grafo preenchido) Tamanho do vetor (="<<vector_following.size()<<") e' diferente do esperado (=3) (ERRO)" << endl;
          er++;
    }
    else
        cout << "...verifica_mostFollowing: (Grafo preenchido) Tamanho do vetor (="<<vector_following.size()<<") e' o esperado (ok)" << endl;
    

    /*Teste 3*/
    bool ok=true;
    string str="";
    //string s1="john_doe";
    string s2="mia_davis";
    string s3="rodrigo8";
    string s4="emily_c";
    
    
    if (!vector_following.empty())
    {
        for(auto i=0;i<vector_following.size();i++)
        {
            str+=vector_following[i]->getUsername()+" - ";
            if ( (vector_following[i]->getUsername()!=s2) && (vector_following[i]->getUsername()!=s3) && (vector_following[i]->getUsername()!=s4)) 
            {
                ok=false;
            }

        }
        str.pop_back();
        str.pop_back();
        str.pop_back();
    } else {ok=false;}
 

    
    if (!ok)
    {
        cout << "...verifica_mostFollowing: (Grafo preenchido) Os elementos (="<<str<<") são diferentes do esperado (="<<s2<<","<<s3<<","<<s4<<") (ERRO)" <<endl;
          er++;
    }
    else
        cout << "...verifica_mostFollowing: (Grafo preenchido) Os elementos  (="<<str<<") são os esperados (ok)" << endl;

    
    return er;
}

int verifica_followingMostWatchedSeries(UserManagementGraph& g,User& us1,User& us4)
{
    int er = 0;

    //Teste 1
    User* us=nullptr;
    TVSeries* mostwatched = g.followingMostWatchedSeries(us);

    if (mostwatched!=nullptr)
    {
        cout << "...verifica_followingMostWatchedSeries: (User não existe) retorno não é Null (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_followingMostWatchedSeries: (User não existe) retorno é Null (ok)" << endl;
    
    //Teste 2
    
    mostwatched = g.followingMostWatchedSeries(&us4);

    if (mostwatched!=nullptr)
    {
    if (mostwatched->getTitle()!="The Office")
    {
        cout << "...verifica_followingMostWatchedSeries: (User existe) A serie (="<<mostwatched->getTitle()<<") e' diferente do esperado (=The Office) (ERRO)" << endl;
         er++;  
    }
    else
        cout << "...verifica_followingMostWatchedSeries: (User existe),  A serie (="<<mostwatched->getTitle()<<") e' o esperado (ok)" << endl;
    } else 
    {
        cout << "...verifica_followingMostWatchedSeries: (User existe), Serie nula (ERRO)" << endl;
         er++;  
    }
   
    //Teste 3

      mostwatched = g.followingMostWatchedSeries(&us1);
     if (mostwatched!=nullptr)
    {
    if (mostwatched->getTitle()!="Stranger Things")
    {
        cout << "...verifica_followingMostWatchedSeries: (User existe-empate entre series) A serie (="<<mostwatched->getTitle()<<") e' diferente do esperado (=Stranger Things) (ERRO)" << endl;
         er++;  
    }
    else
        cout << "...verifica_followingMostWatchedSeries: (User existe-empate entre series),  A serie (="<<mostwatched->getTitle()<<") e' o esperado (ok)" << endl;
    } else 
    {
        cout << "...verifica_followingMostWatchedSeries: (User existe), Serie nula (ERRO)" << endl;
         er++;  
    }
   
    return er;
}

int verifica_shortestPaths(UserManagementGraph& g,User& us1,User& us6,User& us7)
{
    int er = 0;
 
    //Teste 1

    User* no=nullptr;
    int res=g.shortestPaths(&us1,no);
    if (res!=-1)
    {
        cout << "...verifica_shortestPaths: (Nó não existe) o retorno (="<<res<<") é diferente do esperado  (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_shortestPaths: (Nó não existe) o retorno é o esperado (="<<res<<")  (ok)" << endl;
    
    //Teste 2
    
    res=g.shortestPaths(&us1,&us6);
    
    if (res!=3)
    {
        cout << "...verifica_shortestPaths: (Nó existe), Distancia (="<<res<<") e' diferente do esperado (=3) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_shortestPaths: (Nó existe), Distancia (="<<res<<") (ok)" << endl;
    
    //Teste 3
    res=g.shortestPaths(&us7,&us6);
    
    if (res!=-2)
    {
        cout << "...verifica_shortestPaths: (Caminho não existe), Retorno (="<<res<<") e' diferente do esperado (=-2) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_shortestPaths: (Caminho não existe), Retorno (="<<res<<") (ok)" << endl;
    

    return er;
}


int verifica_insertCountryStats(HashTable& ht)
{
    int er = 0;
    
    //Teste 1
    int res;
    CountryStats* cs=new CountryStats("Portugal",1,1,1.0,{0,1,0,0,0});
    res=ht.insertCountryStats(*cs);
    if (res!=6)
    {
        cout << "...verifica_insertCountryStats: (1º Insersão 'Portugal' numa tabela de tamanho 11) campo onde foi inserido (="<<res<<") e' diferente do esperado (=6) (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_insertCountryStats: (1º Insersão 'Portugal' numa tabela de tamanho 11) campo onde foi inserido (="<<res<<") (ok)" << endl;
    
    //Teste 2
    

   CountryStats* cs2=new CountryStats("Espanha",1,1,1.0,{0,1,0,0,0});
    res=ht.insertCountryStats(*cs2);
    CountryStats* cs3=new CountryStats("França",1,1,1.0,{0,1,0,0,0});
    res=ht.insertCountryStats(*cs3);
    CountryStats* cs4=new CountryStats("Alemanha",1,1,1.0,{0,1,0,0,0});
    res=ht.insertCountryStats(*cs4);
    if (res!=10)
    {
        cout << "...verifica_insertCountryStats: (Inserir (Espanha,França e Alemanha)), campo onde a Alemanha foi inserido (="<<res<<") e' diferente do esperado (=10) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_insertCountryStats: (Nó existe), campo onde a Alemanha foi inserido (="<<res<<") (ok)" << endl;
    
    //Teste 3



 
    return er;
}

int verifica_importFromVector(HashTable& ht, UserManagement &userManager)
{
    int er = 0;
    
    //Teste 1

   int res=ht.importFromVector(userManager);
    
 
    if ((int)ht.getTotalCountryStats()!=7) {
        cout << "...verifica_importFromVector: (Importar o vetor) numeros de elementos inseridos (="<<(int)ht.getTotalCountryStats()<<") e' diferente do esperado (=6) (ERRO)"<< endl ;
           er++;
        } else 
         cout << "...verifica_importFromVector: (Importar o vetor) numeros de elementos inseridos (="<<(int)ht.getTotalCountryStats()<<") (ok)"<< endl ;
       
    //Teste 2
    
    res=ht.searchCountryStats("Portugal");
  
   if (res>=0 && res<11)
    {
        cout << "...verifica_importFromVector: (Importar o vetor) Portugal foi encontrado (ok)"<< endl ;
        
    if (ht.getTable()[res]!=nullptr)
    {
          if (ht.getTable()[res]->nUsers!=13) {
        cout << "...verifica_importFromVector: (Importar o vetor) numero de utilizadores em Portugal (="<<ht.getTable()[res]->nUsers<<") e' diferente do esperado (=13) (ERRO)"<< endl ;
           er++;
        } else 
         cout << "...verifica_importFromVector: (Importar o vetor) numero de utilizadores em Portugal (="<<ht.getTable()[res]->nUsers<<") (ok)"<< endl ;
      
    }
    else {
        cout << "...verifica_importFromVector: (Importar o vetor) Portugal não foi encontrado (ERRO)"  << endl;
         er++;
    }
    
     //Teste 4
   
      if (ht.getTable()[res]!=nullptr)
    {
          if (ht.getTable()[res]->nTVSeries!=17) {
        cout << "...verifica_importFromVector: (Importar o vetor) numero de series vistas em Portugal (="<<ht.getTable()[res]->nTVSeries<<") e' diferente do esperado (=17) (ERRO)"<< endl ;
           er++;
        } else 
         cout << "...verifica_importFromVector: (Importar o vetor) numero de series vistas em Portugal (="<<ht.getTable()[res]->nTVSeries<<") (ok)"<< endl ;
      
    }
    else {
        cout << "...verifica_importFromVector: (Importar o vetor) Portugal não foi encontrado (ERRO)"  << endl;
         er++;
    }
    
      //Teste 5
          if (ht.getTable()[res]!=nullptr)
    {
          if (fabs(ht.getTable()[res]->averageTVseries-2.23077)>0.0001) {
        cout << "...verifica_importFromVector: (Importar o vetor) média de series vistas por utilizador em Portugal (="<<ht.getTable()[res]->averageTVseries<<") e' diferente do esperado (=2.23077) (ERRO)"<< endl ;
           er++;
        } else 
         cout << "...verifica_importFromVector: (Importar o vetor) média de series vistas por utilizador em Portugal (="<<ht.getTable()[res]->averageTVseries<<") (ok)"<< endl ;
      
    }
    else {
        cout << "...verifica_importFromVector: (Importar o vetor) Portugal não foi encontrado (ERRO)"  << endl;
         er++;
    }

    //Teste 6
          if (ht.getTable()[res]!=nullptr)
    {
          if (ht.getTable()[res]->nGenre[0]!=2) {
        cout << "...verifica_importFromVector: (Importar o vetor) numero de series de Action vistas em Portugal (="<<ht.getTable()[res]->nGenre[0]<<") e' diferente do esperado (=2) (ERRO)"<< endl ;
           er++;
        } else 
         cout << "...verifica_importFromVector: (Importar o vetor) numero de series de Action vistas em Portugal (="<<ht.getTable()[res]->nGenre[0]<<") (ok)"<< endl ;
      
    }
    else {
        cout << "...verifica_importFromVector: (Importar o vetor) Portugal não foi encontrado (ERRO)"  << endl;
         er++;
    }
    }
    else {
        cout << "...verifica_importFromVector: (Importar o vetor) Portugal não foi encontrado (ERRO)"  << endl;
         er++;
    }
    //Teste 3
   
    return er;
}
int updatelist(string f,TVSeriesManagementList& tvSeriesManagerList)
{
    ifstream file(f);
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
        tvSeriesManagerList.TVSeriesInsert(series);
        //cout << series->getTitle()<< endl;
    }
    // Close the file
    
    file.close();
    return 0;
}

int updatelistUser(string f,UserManagement& userManager)
{
    ifstream file(f);
    if (!file.is_open()) {
        cout << "Error: Unable to open series.txt file." << endl;
        return -1;
    }

    string line;
    User* users;
    // Read each line from the file
    while (getline(file, line)) {
        // Parse the line to extract series information
        string username, name, country,genreStr;
    
       
        vector<string> vgenre;
     
    
        stringstream ss;
        ss.clear();
        ss << line; 
        getline(ss, username, ',');
        getline(ss, name, ',');
        getline(ss, country, ',');
        
        while (getline(ss, genreStr, ',')) {
            vgenre.push_back(genreStr);
        }
     
      
        // Create a new user object
        users = new User(username, name, country, vgenre);

        // Add the user to the manager
        userManager.addUser(users);
        
    }
    // Close the file
    
    file.close();
    return 0;
}



int main()
{

     int errorCount = 0, error;

    cout << "INICIO DOS TESTES\n\n" << endl;
    // Create users for testing
    // Create a TV series manager object
    TVSeriesManagementList tvSeriesManagerList;


    
    User user1("john_doe", "John", "USA", {vGenres[0], vGenres[1], vGenres[2]}); 
    User user2("mia_davis", "Milena", "Luxembourg", {vGenres[1], vGenres[3], vGenres[4]}); 
    User user3("rodrigo8", "Rodrigo", "Portugal", {vGenres[2], vGenres[4]});
    User user4("mike124", "Michael", "USA", {vGenres[0], vGenres[1]});
    User user5("teresa_santos", "Teresa", "Portugal", {vGenres[4]});
    User user6("emily_c", "Emily", "USA", {vGenres[2], vGenres[1], vGenres[2]});
    User user7("carlitos", "Carlos", "Spain", {vGenres[0], vGenres[1]});

    UserManagement userManager1;
    userManager1.addUser(&user1);
    userManager1.addUser(&user2);
    userManager1.addUser(&user3);
    userManager1.addUser(&user4);
    userManager1.addUser(&user5);
    userManager1.addUser(&user6);
    userManager1.addUser(&user7);
    
    TVSeriesManagementList tvSeriesManagerList1;
    int up2=updatelist("series.txt",tvSeriesManagerList1);
    if(up2==-1)
    return 0;

    string filename2="user_updateWateched1.txt";

    userManager1.updateWatched(filename2, tvSeriesManagerList1);
 /* 
for (int i=0;i<(int)userManager1.getVectorUsers().size();i++)
{
    cout <<userManager1.getVectorUsers()[i]->getUsername()<<"-";
    for (int j=0;j<(int)userManager1.getVectorUsers()[i]->getEpisodesWatched().size();j++)

    cout <<userManager1.getVectorUsers()[i]->getWatchedSeries()[j]->getTitle()<<"("<<userManager1.getVectorUsers()[i]->getEpisodesWatched()[j]<<")-";
    cout<<endl;
}
cout <<endl;
*/
    UserManagementGraph graph;
    graph.addUserNode(&user1);
    graph.addUserNode(&user2);
    graph.addUserNode(&user3);
    graph.addUserNode(&user4);
    graph.addUserNode(&user5);
    graph.addUserNode(&user6);
    graph.addUserNode(&user7);

    graph.addFollower(&user1, &user2);
    graph.addFollower(&user1, &user4);
    graph.addFollower(&user2, &user3);
    graph.addFollower(&user2, &user4);
    graph.addFollower(&user2, &user5);
    graph.addFollower(&user4, &user1);
    graph.addFollower(&user4, &user5);
    graph.addFollower(&user6, &user1);
    graph.addFollower(&user6, &user7);
    graph.addFollower(&user6, &user5);
    graph.addFollower(&user3, &user6);
    graph.addFollower(&user3, &user1);
    graph.addFollower(&user3, &user2);

       
    
    
   
    UserManagement userManager;
    int up=updatelistUser("users.txt",userManager);
    up=updatelist("series.txt",tvSeriesManagerList);
    string filename="user_updateWateched.txt";
    userManager.updateWatched(filename,tvSeriesManagerList);
    if(up==-1)
    return 0;

    error = verifica_mostFollowing(graph);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_mostFollowing\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_mostFollowing passou\n\n" << endl;
    }  

    //2ª verificação
   
    error = verifica_followingMostWatchedSeries(graph,user1,user4);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_followingMostWatchedSeries\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_followingMostWatchedSeries passou\n\n" << endl;
    } 

    //3ª verificação

    
        error = verifica_shortestPaths(graph,user1,user6,user7);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_shortestPaths\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_shortestPaths passou\n\n" << endl;
    } 


    //4ª verificação
  HashTable ht(11); // tabela de 11 campos



    error = verifica_insertCountryStats(ht);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_insertCountryStats\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_insertCountryStats passou\n\n" << endl;
    } 

    //5ª verificação
    HashTable ht1(11);
    

    error = verifica_importFromVector(ht1,userManager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_importFromVector\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_importFromVector passou\n\n" << endl;
    } 


     if (errorCount == 0)
        cout << "FIM DOS TESTES: Todos os testes passaram\n" << endl;
    else
        cout << "FIM DOS TESTES: Foram encontrados "<< errorCount << " ERROS no total\n" << endl;

    return 0;
}