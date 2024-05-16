#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "TVseries.hpp"


//#1

int verifica_getUniquePrincipals5(TVSeriesAPP& app)
{
    int er = 0;
   

    /*Teste 1*/
    string tc="tt0383158";
    vector <string> uniqprinc = app.getUniquePrincipals(tc);
    string str="";
   for (auto un : uniqprinc){
        str+=un+", ";
    } 
  string res="Chris Woerts, Danny Vera, Gertjan Verbeek, Hans Kraay Jr., Jan Boskamp, Johan Derksen, Johnny de Mol, Marcel van Roosmalen, René van der Gijp, Roelof Luinge, Ronald Koeman, Sensi Lowe, Simon Zijlemans, Valentijn Driessen, Walter Trout, Wilfred Genee, Willem Feenstra, Wim Kieft, ";
   if (str!=res)
    {
        cout << "...verifica_getUniquePrincipals5: (Serie - Voetbal Inside) - Os elementos (="<<str<<") são diferentes do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_getUniquePrincipals5: (Serie - Voetbal Inside) - Os elementos  (="<<res<<") são os esperados (ok)" << endl;
    

    /*Teste 2*/
    tc="tt10003494";
   
    uniqprinc = app.getUniquePrincipals(tc);
    str="";
     for (auto un : uniqprinc){
        str+=un+", ";
    }
    res="Albert Cerný, Antonín Hrabal, Jeroným Subrt, Victor Sotberg, ";
    if (str!=res)
    {
        cout << "...verifica_getUniquePrincipals5: (Serie - Weird Norwegian) - Os elementos (="<<str<<") são diferentes do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_getUniquePrincipals5: (Serie - Weird Norwegian) - Os elementos  (="<<res<<") são os esperados (ok)" << endl;
    
    
    return er;
}

int verifica_getUniquePrincipals(TVSeriesAPP& app)
{
    int er = 0;
   

    /*Teste 1*/
    string tc="tt11663058";
    vector <string> uniqprinc = app.getUniquePrincipals(tc);
    string str="";
   for (auto un : uniqprinc){
        str+=un+", ";
    } 
  string res="Alex Butcher, Andrew Katz, Anthony Rosario, Brett Smith, Curtis Maloney, Dan Kelly, David Kern, Emily Dunlop, Jack Dalton, Jack Moynihan, Jenna Phelan, John DiSabito, John O'Connor, Katelyn Johnson, Leo Dibbern, Mahak Kanjolia, Matt O'Brien, Rachel Michaelson, Rose Stella, Ryan Imelio, Sammie Dibbern, ";
   if (str!=res)
    {
        cout << "...verifica_getUniquePrincipals: (Serie - Corruption) - Os elementos (="<<str<<") são diferentes do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_getUniquePrincipals: (Serie - Corruption) - Os elementos  (="<<res<<") são os esperados (ok)" << endl;
    

   
    
    return er;
}


//#2

int verifica_getMostSeriesGenre5(TVSeriesAPP& app)
{
    int er = 0;
   
    
  
    /*Teste 1*/
    string mostseriesgenre = app.getMostSeriesGenre();
  
    string res="Talk-Show";
    if (mostseriesgenre!=res)
    {
        cout << "...verifica_getMostSeriesGenre5: (Genero com mais series) - A serie (="<<mostseriesgenre<<") é diferente do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_getMostSeriesGenre5: (Genero com mais series) - A serie  (="<<res<<") é o esperado (ok)" << endl;
    
   
    return er;
}

int verifica_getMostSeriesGenre(TVSeriesAPP& app)
{
    int er = 0;
   
    
  
    /*Teste 1*/
    string mostseriesgenre = app.getMostSeriesGenre();
  
    string res="Comedy";
    if (mostseriesgenre!=res)
    {
        cout << "...verifica_getMostSeriesGenre: (Genero com mais series) - A serie (="<<mostseriesgenre<<") é diferente do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_getMostSeriesGenre: (Genero com mais series) - A serie  (="<<res<<") é o esperado (ok)" << endl;
    
   
    return er;
}


//#6

int verifica_getPrincipalFromCharacter5(TVSeriesAPP& app)
{
    int er = 0;
   
    
  
    /*Teste 1*/
    
    string mostfreqprincchar = app.getPrincipalFromCharacter("Self"); 
  
  
    string res="Johan Derksen";
    if (mostfreqprincchar!=res)
    {
        cout << "...verifica_getPrincipalFromCharacter5: (Pessoa que interpetou de 'Self' mais vezes) - A pessoa (="<<mostfreqprincchar<<") é diferente do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_getPrincipalFromCharacter5: (Pessoa que interpetou de 'Self' mais vezes) - A pessoa  (="<<res<<") é o esperado (ok)" << endl;
    
    /*Teste 2*/
    
    mostfreqprincchar = app.getPrincipalFromCharacter("Raul"); 
  
  
    res="Kristof Garcia";
    if (mostfreqprincchar!=res)
    {
        cout << "...verifica_getPrincipalFromCharacter5: (Pessoa que interpetou de 'Raul' mais vezes) - A pessoa (="<<mostfreqprincchar<<") é diferente do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_getPrincipalFromCharacter5: (Pessoa que interpetou de 'Raul' mais vezes) - A pessoa  (="<<res<<") é o esperado (ok)" << endl;
    


    return er;
}

int verifica_getPrincipalFromCharacter(TVSeriesAPP& app)
{
    int er = 0;
   
    
  
    /*Teste 1*/
    
    string mostfreqprincchar = app.getPrincipalFromCharacter("Self"); 
  
  
    string res="Aaron Elliott";
    if (mostfreqprincchar!=res)
    {
        cout << "...verifica_getPrincipalFromCharacter: (Pessoa que interpetou de 'Self' mais vezes) - A pessoa (="<<mostfreqprincchar<<") é diferente do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_getPrincipalFromCharacter: (Pessoa que interpetou de 'Self' mais vezes) - A pessoa  (="<<res<<") é o esperado (ok)" << endl;
    
    /*Teste 2*/
    
    mostfreqprincchar = app.getPrincipalFromCharacter("Judy"); 
  
  
    res="Elora Españo";
    if (mostfreqprincchar!=res)
    {
        cout << "...verifica_getPrincipalFromCharacter: (Pessoa que interpetou de 'Judy' mais vezes) - A pessoa (="<<mostfreqprincchar<<") é diferente do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_getPrincipalFromCharacter: (Pessoa que interpetou de 'Judy' mais vezes) - A pessoa  (="<<res<<") é o esperado (ok)" << endl;
    


    return er;
}


//#3

int verifica_principalsWithMultipleCategories5(TVSeriesAPP& app)
{
   int er = 0;
   
    
    /*Teste 1*/
    string tc="tt0383158";
    vector<string> people = app.principalsWithMultipleCategories(tc);
   
    string str="";
     for (auto un : people){
        str+=un+", ";
    }
    
    string res="";
    if (str!=res)
    {
        cout << "...verifica_principalsWithMultipleCategories5: (Serie 'Voetbal Inside') - As pessoas (="<<str<<") são diferentes do esperado (='não existe nenhuma pessoa') (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_principalsWithMultipleCategories5: (Serie 'Voetbal Inside') - Não existe nenhuma pessoa (ok)" << endl;
    
    /*Teste 2*/
    tc="tt0400059";
    people = app.principalsWithMultipleCategories(tc);
   
    str="";
     for (auto un : people){
        str+=un+", ";
    }
    
    res="Jeffrey Hidalgo, ";
    if (str!=res)
    {
        cout << "...verifica_principalsWithMultipleCategories5: (Serie 'Wish ko lang') - As pessoas (="<<str<<") são diferente do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_principalsWithMultipleCategories5: (Serie 'Wish ko lang') - As pessoas (="<<str<<") são o esperado (ok)" << endl;
    
   

    return er;
}

int verifica_principalsWithMultipleCategories(TVSeriesAPP& app)
{
   int er = 0;
   
    
    /*Teste 1*/
    string tc="tt11368680";
    vector<string> people = app.principalsWithMultipleCategories(tc);
   
    string str="";
     for (auto un : people){
        str+=un+", ";
    }
    
    string res="";
    if (str!=res)
    {
        cout << "...verifica_principalsWithMultipleCategories: (Serie Ted and Johnny) - As pessoas (="<<str<<") são diferentes do esperado (='não existe nenhuma pessoa') (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_principalsWithMultipleCategories: (Serie Ted and Johnny) - Não existe nenhuma pessoa (ok)" << endl;
    
    /*Teste 2*/
    tc="tt10058722";
    people = app.principalsWithMultipleCategories(tc);
   
    str="";
     for (auto un : people){
        str+=un+", ";
    }
    
    res="Chris Greenwood, Dave Baines, David Foulkes, Di Evans, Donnovan Harris, Joseph Hassell, Laura Balfour, Matt Ward, ";
    if (str!=res)
    {
        cout << "...verifica_principalsWithMultipleCategories: (Serie 'Call Me Katie') - As pessoas (="<<str<<") são diferente do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_principalsWithMultipleCategories: (Serie 'Call Me Katie') - As pessoas (="<<str<<") são o esperado (ok)" << endl;
    
   

    return er;
}


//#5

int verifica_principalInMultipleGenres5(TVSeriesAPP& app)
{
   int er = 0;


    
    /*Teste 1*/
   vector<string> vg;
   vg.push_back("Sport");
   vg.push_back("Talk-Show");
   int total = app.principalInMultipleGenres(vg);
     
    int res=18;
    if (total!=res)
    {
        cout << "...verifica_principalInMultipleGenres5: (Genero: Sport , Talk-Show) - O total (="<<total<<") é diferente do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_principalInMultipleGenres5: (Genero: Sport , Talk-Show) - O total  (="<<total<<") são o esperado (ok)" << endl;
    
    /*Teste 2*/
    vg.clear();
    vg.push_back("Crime");
    vg.push_back("Documentary");
    vg.push_back("Drama");
     
    total = app.principalInMultipleGenres(vg);
    res=175;
    if (total!=res)
    {
        cout << "...verifica_principalInMultipleGenres5: (Genero: Crime, Documentary, Drama) - O total (="<<total<<") é diferente do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_principalInMultipleGenres5: (Genero: Crime, Documentary, Drama) - O total  (="<<total<<") são o esperado (ok)" << endl;
    

    return er;
}

int verifica_principalInMultipleGenres(TVSeriesAPP& app)
{
   int er = 0;


    
    /*Teste 1*/
   vector<string> vg;
   vg.push_back("Drama");
   vg.push_back("Comedy");
   
   int total = app.principalInMultipleGenres(vg);
     
    int res=52;
    if (total!=res)
    {
        cout << "...verifica_principalInMultipleGenres: (Genero: Sport , Talk-Show) - O total (="<<total<<") é diferente do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_principalInMultipleGenres: (Genero: Sport , Talk-Show) - O total  (="<<total<<") são o esperado (ok)" << endl;
    
    /*Teste 2*/
    vg.clear();
    vg.push_back("Crime");
    vg.push_back("Comedy");
     
    total = app.principalInMultipleGenres(vg);
    res=97;
    if (total!=res)
    {
        cout << "...verifica_principalInMultipleGenres: (Genero: Crime, Documentary, Drama) - O total (="<<total<<") é diferente do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_principalInMultipleGenres: (Genero: Crime, Documentary, Drama) - O total  (="<<total<<") são o esperado (ok)" << endl;
    

    return er;
}


//#4

int verifica_principalsInAllEpisodes5(TVSeriesAPP& app)
{
   int er = 0;



    /*Teste 1*/
    string tc="tt0383158";
    vector<string> prin_ceps = app.principalsInAllEpisodes(tc);
   
   
    string str="";
     for (auto un : prin_ceps){
        str+=un+", ";
    }
    
    string res="Johan Derksen, René van der Gijp, Wilfred Genee, ";

    if (str!=res)
    {
        cout << "...verifica_principalsInAllEpisodes5: (Serie: Voetbal Inside) - As pessoas (="<<str<<") são diferentes do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_principalsInAllEpisodes5: (Serie: Voetbal Inside) - As pessoas (="<<str<<") são o esperado (ok)" << endl;
    
    /*Teste 2*/
    tc="tt0400059";
    prin_ceps = app.principalsInAllEpisodes(tc);
   
   
    str="";
     for (auto un : prin_ceps){
        str+=un+", ";
    }
    
    res="";

    if (str!=res)
    {
        cout << "...verifica_principalsInAllEpisodes5: (Serie: Wish ko lang) - As pessoas (="<<str<<") são diferentes do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_principalsInAllEpisodes5: (Serie: Wish ko lang) - As pessoas (="<<str<<") são o esperado (ok)" << endl;
    

    return er;
}

int verifica_principalsInAllEpisodes(TVSeriesAPP& app)
{
   int er = 0;



    /*Teste 1*/
    string tc="tt10270950";
    vector<string> prin_ceps = app.principalsInAllEpisodes(tc);
   
   
    string str="";
     for (auto un : prin_ceps){
        str+=un+", ";
    }
    
    string res="S. Sekilar, Saran Rajesh, Suresh Krishna, Vani Bhojan, ";

    if (str!=res)
    {
        cout << "...verifica_principalsInAllEpisodes: (Serie: Lakshmi Vanthachu) - As pessoas (="<<str<<") são diferentes do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_principalsInAllEpisodes: (Serie: Lakshmi Vanthachu) - As pessoas (="<<str<<") são o esperado (ok)" << endl;
    
    /*Teste 2*/
    tc="tt10468280";
    prin_ceps = app.principalsInAllEpisodes(tc);
   
   
    str="";
     for (auto un : prin_ceps){
        str+=un+", ";
    }
    
    res="Divya Aggarwal, ";

    if (str!=res)
    {
        cout << "...verifica_principalsInAllEpisodes: (Serie: Secret Diaries) - As pessoas (="<<str<<") são diferentes do esperado (="<<res<<") (ERRO)" << endl ;
           er++;
    }
    else
        cout << "...verifica_principalsInAllEpisodes: (Serie: Secret Diaries) - As pessoas (="<<str<<") são o esperado (ok)" << endl;
    

    return er;
}


//Parsing functions

// Function to parse TitleBasics from a TSV file
int parseTitleBasics(const string& filename,TVSeriesAPP& Tree) {
 //   vector<TitleBasics> titles;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return -1;
    }

    string line;
    // Skip header line
    getline(file, line);
    while (getline(file, line)) {
        istringstream iss(line);
        TitleBasics title;
        string genre;
        getline(iss, title.tconst, '\t');
        getline(iss, title.titleType, '\t');
        getline(iss, title.primaryTitle, '\t');
        getline(iss, title.originalTitle, '\t');
        string isAdultStr;
        getline(iss, isAdultStr, '\t');
        title.isAdult = (isAdultStr == "1");
        string startYearStr;
        getline(iss, startYearStr, '\t');
        if (startYearStr != "\\N") {
            title.startYear = stoi(startYearStr);
        } else {
            title.startYear = 0;
        }
        string endYearStr;
        getline(iss, endYearStr, '\t');
        if (endYearStr != "\\N") {
            title.endYear = stoi(endYearStr);
        } else {
            title.endYear = 0;
        }
        string runtimeMinutesStr;
        getline(iss, runtimeMinutesStr, '\t');
        if (runtimeMinutesStr != "\\N") {
            title.runtimeMinutes = stoi(runtimeMinutesStr);
        } else {
            title.runtimeMinutes = 0;
        }
        while (getline(iss, genre, ',')) {
            title.genres.push_back(genre);
        }
        Tree.addTitleBasics(title);
    }

    file.close();
    return 0;
}

// Function to parse TitleEpisode from a TSV file
int parseTitleEpisodes(const string& filename,TVSeriesAPP& Tree) {
 //   vector<TitleEpisode> episodes;
 
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return -1;
    }

    string line;
    // Skip header line
    getline(file, line);
    while (getline(file, line)) {
        istringstream iss(line);
        TitleEpisode episode;
        getline(iss, episode.tconst, '\t');
        getline(iss, episode.parentTconst, '\t');
        iss >> episode.seasonNumber;
        iss.ignore(); // Ignore the tab
        iss >> episode.episodeNumber;
        Tree.addTitleEpisodes(episode);
       
    }

    file.close();
    return 0;
}

// Function to parse TitlePrincipals from TSV file
int parseTitlePrincipals(const string& filename,TVSeriesAPP& Tree) {
    vector<TitlePrincipals> principals;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return -1;
    }

    string line;
    // Skip header line
    getline(file, line);
    while (getline(file, line)) {
        istringstream iss(line);
        TitlePrincipals principal;
        string genre;
        getline(iss, principal.tconst, '\t');
        
        string ordering;
        getline(iss, ordering, '\t');
        if (ordering != "\\N") {
            principal.ordering = stoi(ordering);
        } else {
            principal.ordering = 0;
        }

        getline(iss, principal.nconst, '\t');
        getline(iss, principal.primaryName, '\t');

        string birthYear;
        getline(iss, birthYear, '\t');
         
        if (birthYear != "\\N") {
            principal.birthYear = stoi(birthYear);
        } else {
            principal.birthYear = 0;
        }
       
        string category;
       
        getline(iss, category, '\t');
        if (category != "\\N") {
            principal.category = category;
        } else {
            principal.category = "";
        }
        string job;
        getline(iss, job, '\t');
        if (job != "\\N") {
            principal.job = job;
        } else {
            principal.job = "";
        }

        string characters;
        while (getline(iss, characters, ',')) {
            if(characters[0] == '['){
                characters.erase(0, 1);
            }
            if(characters[characters.size()-1] == ']'){
                characters.erase(characters.size() - 1);
            }
            principal.characters.push_back(characters);
        }
         
        Tree.addTitlePrincipal(principal);
      
    }

    file.close();
    return 0;
}


int main() {
    int errorCount = 0, error;

    cout << "INICIO DOS TESTES\n\n" << endl;
    cout << "Base de dados pequena (5 series) \n\n" << endl;
    // Parse data from TSV files

    TVSeriesAPP tvSeriesApp5;
    int res = parseTitleBasics("series5.basics.tsv",tvSeriesApp5);

    res = parseTitleEpisodes("series5.episode.tsv", tvSeriesApp5);
    res = parseTitlePrincipals("series5.principals.names.tsv",tvSeriesApp5);



    //PERGUNTA 1
      error = verifica_getUniquePrincipals5(tvSeriesApp5);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_getUniquePrincipals5\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_getUniquePrincipals5 passou\n\n" << endl;
    }  


    //PERGUNTA 2
        error = verifica_getMostSeriesGenre5(tvSeriesApp5);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_getMostSeriesGenre5\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_getMostSeriesGenre5 passou\n\n" << endl;
    }  


    //PERGUNTA 3
      error = verifica_principalsWithMultipleCategories5(tvSeriesApp5);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_principalsWithMultipleCategories5\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_principalsWithMultipleCategories5 passou\n\n" << endl;
    }  


   //PERGUNTA 4
         error = verifica_principalsInAllEpisodes5(tvSeriesApp5);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_principalsInAllEpisodes5\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_principalsInAllEpisodes5 passou\n\n" << endl;
    } 


   //PERGUNTA 5
       error = verifica_principalInMultipleGenres5(tvSeriesApp5);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_principalInMultipleGenres5\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_principalInMultipleGenres5 passou\n\n" << endl;
    }


    //PERGUNTA 6
     error = verifica_getPrincipalFromCharacter5(tvSeriesApp5);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_getPrincipalFromCharacter5\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_getPrincipalFromCharacter5 passou\n\n" << endl;
    }  

     cout << "Fim dos testes da base de dados pequena \n" << endl;
    

//inicio do comentário
    
    cout << "Base de dados grande \n" << endl;

    TVSeriesAPP tvSeriesApp;
    res = parseTitleBasics("series1000.basics.tsv",tvSeriesApp);


    res = parseTitleEpisodes("series1000.episode.tsv", tvSeriesApp);


    res = parseTitlePrincipals("series1000.principals.names.tsv",tvSeriesApp);



    clock_t beg, end;
    double time;
    beg = clock();


    //PERGUNTA 1
      error = verifica_getUniquePrincipals(tvSeriesApp);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_getUniquePrincipals\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_getUniquePrincipals passou\n\n" << endl;
    }  


    //PERGUNTA 2
        error = verifica_getMostSeriesGenre(tvSeriesApp);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_getMostSeriesGenre\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_getMostSeriesGenre passou\n\n" << endl;
    }  


   //PERGUNTA 3
      error = verifica_principalsWithMultipleCategories(tvSeriesApp);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_principalsWithMultipleCategories\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_principalsWithMultipleCategories passou\n\n" << endl;
    }


        //PERGUNTA 4
         error = verifica_principalsInAllEpisodes(tvSeriesApp);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_principalsInAllEpisodes\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_principalsInAllEpisodes passou\n\n" << endl;
    } 


    //PERGUNTA 5
       error = verifica_principalInMultipleGenres(tvSeriesApp);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_principalInMultipleGenres\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_principalInMultipleGenres passou\n\n" << endl;
    }

    //PERGUNTA 6
     error = verifica_getPrincipalFromCharacter(tvSeriesApp);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_getPrincipalFromCharacter\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_getPrincipalFromCharacter passou\n\n" << endl;
    }



    end = clock();
    time = (double)(end - beg) / CLOCKS_PER_SEC;
    cout << "Tempo para responder às 6 questões: "<< time << endl;

// fim do comentário

if (errorCount == 0)
        cout << "FIM DOS TESTES: Todos os testes passaram\n" << endl;
    else
        cout << "FIM DOS TESTES: Foram encontrados "<< errorCount << " ERROS no total\n" << endl;

    return 0;
}
