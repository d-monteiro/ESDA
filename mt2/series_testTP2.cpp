#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <list>
#include <queue>
#include "TVSeries.hpp"




using namespace std;

int verifica_seriesByCategory(TVSeriesManagementList& tvMaList)
{
    int er = 0;
    list<TVSeries*> lst;
    lst=tvMaList.seriesByCategory("");
     
    /*Teste 1*/
    if (!lst.empty())
    {
        cout << "...verifica_seriesByCategory: (Categoria incorreta) - retorno não é uma lista vazia (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_seriesByCategory: (Categoria incorreta) - retorno é uma lista vazia (ok)" << endl;
    

    /*Teste 2*/
    lst=tvMaList.seriesByCategory("Comedy");
    if (lst.size()!=3)
    {
        cout << "...verifica_seriesByCategory: (Series da categoria comedia) Tamanho da lista (="<<lst.size()<<") e' diferente do esperado (=3) (ERRO)" << endl;
          er++;
    }
    else
        cout << "...verifica_seriesByCategory: (Series da categoria comedia) Tamanho da lista (="<<lst.size()<<") e' o esperado (ok)" << endl;
    

    /*Teste 3*/
    bool ok=true;
    string str="";
    string s1="The Office";
    string s2="Friends";
    string s3="The Big Bang Theory";
    if (!lst.empty())
    {
        for(auto it=lst.begin();it!=lst.end();it++)
        {
            str+=(*it)->getTitle()+" - ";
            if (((*it)->getTitle()!=s1) && ((*it)->getTitle()!=s2) && ((*it)->getTitle()!=s3)) 
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
        cout << "...verifica_seriesByCategory: (Series da categoria comedia) Lista das series (="<<str<<") e' diferente do esperado (="<<s1<<" - "<<s2<<" - "<<s3<<") (ERRO)" <<endl;
          er++;
    }
    else
        cout << "...verifica_seriesByCategory: (Series da categoria comedia) Lista das series  (="<<str<<") e' o esperado (ok)" << endl;

    
    return er;
}

int verifica_seeAll(UserManagementList& uml,TVSeries* serie)
{
    int er = 0;
    list<User*> lst;
    /*Teste 1*/

    TVSeries serie1("Dark3", 1,{2},"Drama", 2,1);
    lst=uml.seeAll(&serie1);
    
    if (!lst.empty())
    {
        cout << "...verifica_seeAll: (Serie não existe) retorno não é uma lista vazia (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_seeAll: (Serie não existe) retorno é uma lista vazia (ok)" << endl;
    
    /*Teste 2*/
    
    lst=uml.seeAll(serie);
    
    if (lst.size()!=2)
    {
        cout << "...verifica_seeAll: (Serie existe), Tamanho da lista (="<<lst.size()<<") e' diferente do esperado (=2) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_seeAll: (Serie existe), Tamanho da lista (="<<lst.size()<<") (ok)" << endl;
    
    /*Teste 3*/
     bool ok=true;
    string str="";
    string u1="mia_davis";
    string u2="mike124";

    if (!lst.empty())
    {
        for(auto it=lst.begin();it!=lst.end();it++)
        {
            str+=(*it)->getUsername()+" - ";
            if (((*it)->getUsername()!=u1) && ((*it)->getUsername()!=u2) ) 
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
        cout << "...verifica_seeAll: (Serie exite) Lista dos utilizadores (="<<str<<") e' diferente do esperado (="<<u1<<" - "<<u2<<") (ERRO)" <<endl;
         er++; 
    }
    else
        cout << "...verifica_seeAll: (Serie exite) Lista das series  (="<<str<<") e' o esperado (ok)" << endl;
    
   
    return er;
}
int verifica_numberOfEpisodesToSee(User& us,list<TVSeries*>& ltvs)
{
    int er = 0;
     int res;
    /*Teste 1*/

 
    res=us.numberOfEpisodesToSee("",ltvs);
    if (res!=-1)
    {
        cout << "...verifica_numberOfEpisodesToSee: (Serie não existe) retorno=("<<res<<") e' diferente do esperado (=-1) (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_numberOfEpisodesToSee: (Serie não existe) retorno=("<<res<<") (ok)" << endl;
    
    /*Teste 2*/
    
    res=us.numberOfEpisodesToSee("Sherlock",ltvs);
    
    if (res!=512)
    {
        cout << "...verifica_numberOfEpisodesToSee: (Serie Sherlock), retorno(="<<res<<") e' diferente do esperado (=512) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_numberOfEpisodesToSee: (Serie Sherlock), retorno(=(="<<res<<") (ok)" << endl;
    
    return er;
}


int verifica_TVSeriesDelete(TVSeriesManagementList& tvMaList,User& us,UserManagementList& UMaLi)
{
    int er = 0;
    int res;
    /*Teste 1*/

   
    res=tvMaList.TVSeriesDelete("",UMaLi);
    if (res!=-1)
    {
        cout << "...verifica_TVSeriesDelete: (Serie não existe)  retorno=("<<res<<") e' diferente do esperado (=-1) (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_TVSeriesDelete: (Serie não existe) retorno=("<<res<<") (ok)"  << endl;
    
    /*Teste 2*/
    
    res=tvMaList.TVSeriesDelete("Dark",UMaLi);
    list<TVSeries*> ltv=tvMaList.getListTVSeries();
    if (ltv.size()!=16)
    {
        cout << "...verifica_TVSeriesDelete: (Serie existe), Tamanho da lista (="<<ltv.size()<<") e' diferente do esperado (=16) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_TVSeriesDelete: (Serie existe), Tamanho da lista (="<<ltv.size()<<") (ok)" << endl;
    
    /*Teste 3*/
     bool ok=true;
    string str="Dark";
    

    if (!ltv.empty())
    {
      for (auto it=ltv.begin();it!=ltv.end();it++)
      {
        if((*it)->getTitle()==str)
        {ok=false;}
      }
       
    } else {ok=false;}


    if (!ok)
    {
        cout << "...verifica_TVSeriesDelete: (Serie existe) Não foi apagada da lista (ERRO)" <<endl;
         er++; 
    }
    else
        cout << "...verifica_TVSeriesDelete: (Serie existe) Foi apagada da lista (ok)" << endl;
    
    /*Teste 4*/
    ok=true;
    str="Dark";
    vector<TVSeries*> vtv=us.getWatchedSeries();

    if (!vtv.empty())
    {
      
        if(vtv[0]->getTitle()==str)
        {ok=false;}
     
       
    } 


    if (!ok)
    {
        cout << "...verifica_TVSeriesDelete: (Serie existe) Não foi apagada do vetor de wateched de um utilizador (ERRO)" <<endl;
         er++; 
    }
    else
        cout << "...verifica_TVSeriesDelete: (Serie existe) Foi apagada do vetor de wateched de um utilizador (ok)" << endl;
    
   
   
    return er;
}


int verifica_suggestsSeries(TVSeriesManagementList& tvMaList,UserManagementList& UMaLi)
{
    int er = 0;
    list<TVSeries*> lst;
    /*Teste 1*/
    list<User*> ulst=UMaLi.getListUsers();
    lst=tvMaList.suggestsSeries("teresa_santos","",ulst);
    bool ok=true;
    string str="";
    string s1="Money Heist";
    string s2="Narcos";
    string s3="Sherlock";
    string s4="Peaky Blinders";

    if (!lst.empty())
    {
        for(auto it=lst.begin();it!=lst.end();it++)
        {
            str+=(*it)->getTitle()+" - ";
            if (((*it)->getTitle()!=s1) && ((*it)->getTitle()!=s2) && ((*it)->getTitle()!=s3)&& ((*it)->getTitle()!=s4)) 
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
        cout << "...verifica_suggestsSeries: (Utlizador sugestor não exite) Lista de series sugeridas (="<<str<<") e' diferente do esperado (="<<s1<<" - "<<s2<<" - "<<s3<<" - "<<s4<<") (ERRO)" <<endl;
         er++; 
    }
    else
        cout << "...verifica_suggestsSeries: (Utlizador sugestor não exite) Lista de series sugeridas  (="<<str<<") e' o esperado (ok)" << endl;
    
    /*Teste 2*/
    
    lst=tvMaList.suggestsSeries("teresa_santos","emily_c",ulst);
    ok=true;
    str="";
    s1="Money Heist";
    s2="Narcos";
    
    
    if (!lst.empty())
    {
        for(auto it=lst.begin();it!=lst.end();it++)
        {
            str+=(*it)->getTitle()+" - ";
            if (((*it)->getTitle()!=s1) && ((*it)->getTitle()!=s2) ) 
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
        cout << "...verifica_suggestsSeries: (Utlizador sugestor exite) Lista de series sugeridas (="<<str<<") e' diferente do esperado (="<<s1<<" - "<<s2<<") (ERRO)" <<endl;
         er++; 
    }
    else
        cout << "...verifica_suggestsSeries: (Utlizador sugestor exite) Lista de series sugeridas  (="<<str<<") e' o esperado (ok)" << endl;
 
   
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
    User user6("emily_c", "", "Emily", {vGenres[2], vGenres[1], vGenres[2]});
    User user7("carlitos", "Carlos", "Spain", {vGenres[0], vGenres[1]});

    UserManagementList userManagerList;
    userManagerList.addUser(&user1);
    userManagerList.addUser(&user2);
    userManagerList.addUser(&user3);
    userManagerList.addUser(&user4);
    userManagerList.addUser(&user5);
    userManagerList.addUser(&user6);
    userManagerList.addUser(&user7);
    
    int up=updatelist("series.txt",tvSeriesManagerList);
    if(up==-1)
    return 0;
      //1ª verificação

      error = verifica_seriesByCategory(tvSeriesManagerList);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_seriesByCategory\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_seriesByCategory passou\n\n" << endl;
    }  

    //2ª verificação
    list<TVSeries*> ltsm=tvSeriesManagerList.getListTVSeries();
    auto it=ltsm.begin();
    it++;
    user2.addWatchedSeries(*it);
    user4.addWatchedSeries(*it);  
    user1.addWatchedSeries(*it); 
    user1.addEpisodesWatched(*it,10);
    user2.addEpisodesWatched(*it,62);
    user4.addEpisodesWatched(*it,62);
    
    error = verifica_seeAll(userManagerList,*it);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_seeAll\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_seeAll passou\n\n" << endl;
    } 

    //3ª verificação
    it=ltsm.begin();
    
    user3.addWishSeries(*it);
    it++;
    user3.addWishSeries(*it);
    it++;
    user3.addWishSeries(*it);
    for (int i=0;i<9;i++)
    it++;
    user3.addWishSeries(*it);
    list<TVSeries*> lstm=tvSeriesManagerList.getListTVSeries();
        error = verifica_numberOfEpisodesToSee(user3,lstm);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_numberOfEpisodesToSee\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_numberOfEpisodesToSee passou\n\n" << endl;
    } 


    //4ª verificação
     it=ltsm.begin();
    if (ltsm.size()>16)
    {
       for (int i=0;i<15;i++)
    it++;
   }
    user5.addWatchedSeries(*it);

    error = verifica_TVSeriesDelete(tvSeriesManagerList, user5,userManagerList);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_TVSeriesDelete\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_TVSeriesDelete passou\n\n" << endl;
    } 
 
    //5ª verificação
    it=ltsm.begin();
    if (ltsm.size()>9)
    {
    for (int i=0;i<5;i++)
    it++;
   
    user6.addWatchedSeries(*it);
    for (int i=0;i<2;i++)
    it++;
    }
    user6.addWatchedSeries(*it);
 
    error = verifica_suggestsSeries(tvSeriesManagerList, userManagerList);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_suggestsSeries\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_suggestsSeries passou\n\n" << endl;
    } 


     if (errorCount == 0)
        cout << "FIM DOS TESTES: Todos os testes passaram\n" << endl;
    else
        cout << "FIM DOS TESTES: Foram encontrados "<< errorCount << " ERROS no total\n" << endl;

    return 0;
}