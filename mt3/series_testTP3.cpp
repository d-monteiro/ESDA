#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <list>
#include <queue>
#include "TVseries.hpp"




using namespace std;

int verifica_queueTVSeriesCategory(UserManagement& UserManager,priority_queue<TVSeries> pq)
{
    int er = 0;
    priority_queue<TVSeries> pqnew;
    pqnew=UserManager.queueTVSeriesCategory(pq,"");
     
    /*Teste 1*/
    if (!pqnew.empty())
    {
        cout << "...verifica_queueTVSeriesCategory: (Categoria incorreta) - retorno não é uma fila de prioridade vazia (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_queueTVSeriesCategory: (Categoria incorreta) - retorno é uma fila de prioridade vazia (ok)" << endl;
    

    /*Teste 2*/
       pqnew=UserManager.queueTVSeriesCategory(pq,"Comedy");
    if (pqnew.size()!=3)
    {
        cout << "...verifica_queueTVSeriesCategory: (Series da categoria comedia) Tamanho da fila de prioridade (="<<pqnew.size()<<") e' diferente do esperado (=3) (ERRO)" << endl;
          er++;
    }
    else
        cout << "...verifica_queueTVSeriesCategory: (Series da categoria comedia) Tamanho da fila de prioridade (="<<pqnew.size()<<") e' o esperado (ok)" << endl;
    

    /*Teste 3*/
    bool ok=false;
    string str="";
    string s1="Friends";
    
    if (!pqnew.empty())
    {
      str=pqnew.top().getTitle();
      if (pqnew.top().getTitle()==s1) {
            
            ok=true;
        }

    }
    if (!ok)
    {
        cout << "...verifica_queueTVSeriesCategory: (Series da categoria comedia) 1º elemento da fila de prioridade (="<<str<<") e' diferente do esperado (="<<s1<<") (ERRO)" <<endl;
          er++;
    }
    else
        cout << "...verifica_queueTVSeriesCategory: (Series da categoria comedia) 1º elemento da fila de prioridade  (="<<str<<") e' o esperado (ok)" << endl;

    
    return er;
}

int verifica_queueTVSeries(UserManagement& UserManager,list<TVSeries*> listTV)
{
    int er = 0;
    priority_queue<TVSeries> pqnew;
    //Teste 1
    list<TVSeries*> lt;
    pqnew=UserManager.queueTVSeries(lt,1);
    if (!pqnew.empty())
    {
        cout << "...verifica_queueTVSeries: (lista de series vazia) retorno não é uma lista vazia (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_queueTVSeries: (lista de series vazia) retorno é uma lista vazia (ok)" << endl;
    
    //Teste 2
    
    pqnew=UserManager.queueTVSeries(listTV,3);
    
    if (pqnew.size()!=5)
    {
        cout << "...verifica_queueTVSeries: (Lista de Series existe),Tamanho da fila de prioridade (="<<pqnew.size()<<") e' diferente do esperado (=5) (ERRO)" << endl;
         er++;  
    }
    else
        cout << "...verifica_queueTVSeries: (Lista de Series existe),  Tamanho da fila de prioridade (="<<pqnew.size()<<") e' o esperado (ok)" << endl;
    
    //Teste 3
    bool ok=false;
    string str="";
    string s1="Stranger Things";
    
    if (!pqnew.empty())
    {
      str=pqnew.top().getTitle();
      if (pqnew.top().getTitle()==s1) {
            
            ok=true;
        }

    }


    if (!ok)
    {
        cout << "...verifica_queueTVSeries: (Lista de Series existe) 1º elemento da fila de prioridade (="<<str<<") e' diferente do esperado (="<<s1<<") (ERRO)" <<endl;
         er++; 
    }
    else
        cout << "...verifica_queueTVSeries: (Lista de Series existe) 1º elemento da fila de prioridade  (="<<str<<") e' o esperado (ok)" << endl;
    
   
    return er;
}

int verifica_usersInitialLetter(UserManagementTree& umt)
{
    int er = 0;
     vector<User*> res;
    //Teste 1

    NodeUser* no=nullptr;
    res=umt.usersInitialLetter(no,'m');
    if (!res.empty())
    {
        cout << "...verifica_usersInitialLetter: (Nó não existe) o vetor de retorno não é vazio (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_usersInitialLetter: (Nó não existe) o vetor de retorno é vazio  (ok)" << endl;
    
    //Teste 2
    
    res=umt.usersInitialLetter(umt.getRoot(),'m');
    
    if (res.size()!=2)
    {
        cout << "...verifica_usersInitialLetter: (Nó existe), retorno(="<<res.size()<<") e' diferente do esperado (=2) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_usersInitialLetter: (Nó existe), retorno(="<<res.size()<<") (ok)" << endl;
    
    //Teste 3
    bool ok=true;
    string str="";
    string s1="mia_davis";
    string s2="mike124";


    if (!res.empty())
    {
        for(auto i=0;i<res.size();i++)
        {
            str+=res[i]->getUsername()+" - ";
            if ((res[i]->getUsername()!=s1) && (res[i]->getUsername()!=s2) ) 
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
        cout << "...verifica_usersInitialLetter: (Nó existe) Vetor de utlizadores como a carater inicial de m (="<<str<<") e' diferente do esperado (="<<s1<<" - "<<s2<<") (ERRO)" <<endl;
         er++; 
    }
    else
        cout << "...verifica_usersInitialLetter: (Nó existe) Vetor de utlizadores como a carater inicial de m (="<<str<<") e' o esperado (ok)" << endl;
    

    return er;
}


int verifica_usersNotFan(UserManagementTree& umt)
{
    int er = 0;
    
    //Teste 1
    list<User*> res;
    NodeUser* no=nullptr;
    res=umt.usersNotFan(no);
    if (!res.empty())
    {
        cout << "...verifica_usersNotFan: (Nó não existe) a lista de retorno não é vazia (ERRO)"<< endl ;
           er++;
    }
    else
        cout << "...verifica_usersNotFan: (Nó não existe) a lista de retorno é vazia  (ok)"  << endl;
    
    //Teste 2
    
   res=umt.usersNotFan(umt.getRoot());
 
    if (res.size()!=4)
    {
        cout << "...verifica_usersNotFan: (Nó existe), Tamanho da lista (="<<res.size()<<") e' diferente do esperado (=4) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_usersNotFan: (Nó existe), Tamanho da lista (="<<res.size()<<") (ok)" << endl;
    
    //Teste 3
 bool ok=true;
    string str="";
    string s1="emily_c";
    string s2="carlitos";
    string s3="teresa_santos";
    string s4="rodrigo8";

    if (!res.empty())
    {
        for(auto it=res.begin();it!=res.end();it++)
        {
            str+=(*it)->getUsername()+" - ";
            if (((*it)->getUsername()!=s1) && ((*it)->getUsername()!=s2) && ((*it)->getUsername()!=s3)&& ((*it)->getUsername()!=s4)) 
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
        cout << "...verifica_usersNotFan: (Nó existe) Lista de utilizadores que não são fans (="<<str<<") e' diferente do esperado (="<<s1<<" - "<<s2<<" - "<<s3<<" - "<<s4<<") (ERRO)" <<endl;
         er++; 
    }
    else
        cout << "...verifica_usersNotFan: (Nó existe) Lista de utilizadores que não são fans (="<<str<<") e' o esperado (ok)" << endl;
    
   
    return er;
}

int verifica_usersCategoryStatistics(UserManagementTree& umt)
{
    int er = 0;
    vector<int> v;
    //Teste 1
    NodeUser* no=nullptr;
    v=umt.usersCategoryStatistics(no,"comedia",50);
       int soma=0;
    for (auto i=0;i<v.size();i++)
    {
        soma+=v[i];
    }
   if (!v.empty())
    {
        if (soma!=0) {
        cout << "...verifica_usersCategoryStatistics: (Nó não existe) o vetor de estatistica não tem todas as posicoes a zero (ERRO)"<< endl ;
           er++;
        } else 
         cout << "...verifica_usersCategoryStatistics: (Nó não existe) o vetor de estatistica tem todas as posicoes a zero (ok)"<< endl ;
       
    }
    else {
        cout << "...verifica_usersCategoryStatistics: (Nó não existe) o vetor de estatistica é vazio (ERRO)"  << endl;
         er++;
    }
   
    //Teste 2
    
    v=umt.usersCategoryStatistics(umt.getRoot(),"comedia",500);
    soma=0;
    for (auto i=0;i<v.size();i++)
    {
        soma+=v[i];
    }
   if (!v.empty())
    {
          if (soma!=0) {
        cout << "...verifica_usersCategoryStatistics: (Percentagem fora dos limites) o vetor de estatistica não tem todas as posicoes a zero (ERRO)"<< endl ;
           er++;
        } else 
         cout << "...verifica_usersCategoryStatistics: (Percentagem fora dos limites) o vetor de estatistica tem todas as posicoes a zero (ok)"<< endl ;
      
    }
    else {
        cout << "...verifica_usersCategoryStatistics: (Percentagem fora dos limites) o vetor de estatistica é vazio (ERRO)"  << endl;
         er++;
    }
    //Teste 3
    v=umt.usersCategoryStatistics(umt.getRoot(),"Drama",50);
    if (!v.empty()){
        
     if (v[0]!=6)
    {
        cout << "...verifica_usersCategoryStatistics: (Parametros ok), número de utlizadores que assistiram a pelo menos uma série de uma categoria (="<<v[0]<<") e' diferente do esperado (=6) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_usersCategoryStatistics: (Parametros ok), número de utlizadores que assistiram a pelo menos uma série de uma categoria  (="<<v[0]<<") (ok)" << endl;
    } else {
       cout << "...verifica_usersCategoryStatistics: (Parametros ok) o vetor de estatistica é vazio (ERRO)"  << endl;
         er++;
    }
     //Teste 4
  
    if (v.size()>1){
        
     if (v[1]!=4)
    {
        cout << "...verifica_usersCategoryStatistics: (Parametros ok), número de utilizadores que assistiram a uma determinada numero de episodios de pelo menos uma série de uma categoria (="<<v[1]<<") e' diferente do esperado (=4) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_usersCategoryStatistics: (Parametros ok), número de utilizadores que assistiram a uma determinada numero de episodios de pelo menos uma série de uma categoria (="<<v[1]<<") (ok)" << endl;
    } else { 
       cout << "...verifica_usersCategoryStatistics: (Parametros ok) o vetor de estatistica é vazio (ERRO)"  << endl;
     er++;
    }
      //Teste 5
  
    if (v.size()>2){
        
     if (v[2]!=1)
    {
        cout << "...verifica_usersCategoryStatistics: (Parametros ok), número de utilizadores que assistiram a uma determinada numero de episodios de pelo menos uma série de uma categoria que gostam (="<<v[2]<<") e' diferente do esperado (=1) (ERRO)"<< endl ;
         er++;  
    }
    else
        cout << "...verifica_usersCategoryStatistics: (Parametros ok), número de utilizadores que assistiram a uma determinada numero de episodios de pelo menos uma série de uma categoria que gostam (="<<v[2]<<") (ok)" << endl;
    } else {
       cout << "...verifica_usersCategoryStatistics: (Parametros ok) o vetor de estatistica é vazio (ERRO)"  << endl;
        er++;
    }

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
    User user6("emily_c", "Emily", "USA", {vGenres[2], vGenres[1], vGenres[2]});
    User user7("carlitos", "Carlos", "Spain", {vGenres[0], vGenres[1]});

    UserManagement userManager;
    userManager.addUser(&user1);
    userManager.addUser(&user2);
    userManager.addUser(&user3);
    userManager.addUser(&user4);
    userManager.addUser(&user5);
    userManager.addUser(&user6);
    userManager.addUser(&user7);
    
    int up=updatelist("series.txt",tvSeriesManagerList);
    if(up==-1)
    return 0;

    priority_queue<TVSeries> pq;
      //1ª verificação
    list<TVSeries*> listmanager=tvSeriesManagerList.getListTVSeries();
    for (auto it=listmanager.begin();it!=listmanager.end();it++) {
        pq.push(**it);
    }
 

      error = verifica_queueTVSeriesCategory(userManager,pq);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_queueTVSeriesCategory\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_queueTVSeriesCategory passou\n\n" << endl;
    }  

    //2ª verificação
   /* list<TVSeries*> ltsm=tvSeriesManagerList.getListTVSeries();
    auto it=ltsm.begin();
    it++;
    user2.addWatchedSeries(*it);
    user4.addWatchedSeries(*it);  
    user1.addWatchedSeries(*it); 
    user1.addEpisodesWatched(*it,10);
    user2.addEpisodesWatched(*it,62);
    user4.addEpisodesWatched(*it,62); */
    string filename="user_updateWateched.txt";
   userManager.updateWatched(filename,tvSeriesManagerList);
    
    error = verifica_queueTVSeries(userManager,listmanager);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_queueTVSeries\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_queueTVSeries passou\n\n" << endl;
    } 

    //3ª verificação
   UserManagementTree userManagerTree;
    userManagerTree.addUser(&user1);
    userManagerTree.addUser(&user2);
    userManagerTree.addUser(&user3);
    userManagerTree.addUser(&user4);
    userManagerTree.addUser(&user5);
    userManagerTree.addUser(&user6);
    userManagerTree.addUser(&user7);
    
        error = verifica_usersInitialLetter(userManagerTree);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_usersInitialLetter\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_usersInitialLetter passou\n\n" << endl;
    } 


    //4ª verificação
  

    error = verifica_usersNotFan(userManagerTree);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_usersNotFan\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_usersNotFan passou\n\n" << endl;
    } 

    //5ª verificação
  
    error = verifica_usersCategoryStatistics(userManagerTree);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_usersCategoryStatistics\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_usersCategoryStatistics passou\n\n" << endl;
    } 


     if (errorCount == 0)
        cout << "FIM DOS TESTES: Todos os testes passaram\n" << endl;
    else
        cout << "FIM DOS TESTES: Foram encontrados "<< errorCount << " ERROS no total\n" << endl;

    return 0;
}