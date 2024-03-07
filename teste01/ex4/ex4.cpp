#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;


class Car{
 // questão 2 a)

};


Car::Car(string brand, string model, float price){
    // questão 2 b)
}

string Car::getbrand() const{
     // questão 2 c)
}

string Car::getmodel() const{
     // questão 2 c)
}


float Book::getPrice() const{
    // questão 2 c)
}

vector<string> Book::getcolors() const{
  // // questão 2 c)
}


void Book::setPrice(float euros){
   // questão 2 d)

void Book::addcolors(string color){
    // questão 2 e)
}



void print_vector( vector<string> vec, string sep=" ")
{
    for(auto elem : vec)
    {
        cout<<elem<< sep;
    }
    cout << endl;
  
}

int main()
{
   
    cout << "Beginning Tests\n\n" << endl;

    int ISBN = 1236574; 
    int quantity = 78; 
    string title = "The Hobbit";
    string author = "J. R. R. Tolkien"; 
    float price = 9.98; 
    Book b1(ISBN,quantity,title,author,price);

    cout << "O atributo ISBN é " << b1.getISBN() << endl;
    cout << "O atributo availability é " << b1.getAvailable() << endl;
    cout << "O atributo quantity é " << b1.getQuantity() << endl;
    cout << "O atributo title é " << b1.getTitle() << endl; 
    cout << "O atributo author é " << b1.getAuthor() << endl;
    cout << "O atributo price é " << b1.getPrice() << endl;
    cout << "O tamanho do atributo genres é " << b1.getGenres().size() << endl;

    //Setter
    b1.setPrice(7.2);
      cout << "O atributo price é " << b1.getPrice() << endl;

    //Other methods
    b1.addGenres("High Fantasy"); 
    cout << "Os elementos do atributo genres são:";
    print_vector(b1.getGenres()); 





}