#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;


class Book{
  private:
    /*Atributes*/
    int ISBN;
    int quantity;
    bool available;
    string title;
    string author;
    float price;
    vector<string> genres;
    
  public:
    /*Constructor*/
    Book(int ISBN, int quantity, string title, string author, float price);
    
    /*Get Methods*/
    int getISBN() const;
    int getQuantity() const;
    bool getAvailable() const;
    string getTitle() const;
    string getAuthor() const;
    float getPrice() const;
    vector<string> getGenres() const;
    
    /*Other Methods*/
    void setPrice(float euros);
    void addGenres(string genrs);
    
};


Book::Book(int ISBN, int quantity, string title, string author, float price)
{
  if(ISBN>0) this->ISBN = ISBN;
  if(quantity>0){
    this->quantity = quantity; 
    this->available = 1;
  }
  else{
    this->quantity = 0; 
    this->available = 0; 
  }
  if(!title.empty()) this->title = title;
  if(!author.empty()) this->author = author;
  if(price>=0) this->price = price;
  else this->price = 0;
}

int Book::getISBN() const {return ISBN;}

int Book::getQuantity() const {return quantity;}

bool Book::getAvailable() const {return available;}

string Book::getTitle() const {return title;}

string Book::getAuthor() const {return author;}

float Book::getPrice() const {return price;}

vector<string> Book::getGenres() const {return genres;}

void Book::setPrice(float euros)
{
  if(euros >= 0) price = (float)euros;
}

void Book::addGenres(string genrs)
{
  if(!genrs.empty()) genres.push_back(genrs);
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