#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;


class Car
{
  private:
  string brand;
  string model;
  float price;
  vector<string> colors;
  
  public:
  /*constructor*/
  Car(string brand, string model, float price);
  
  /*Get Methods*/
  string getBrand() const;
  string getModel() const;
  float getPrice() const;
  vector<string> getColors() const;
  
  /*Other Methods*/
  void setPrice(float euros);
  void addColors(string color);
};

Car::Car(string brand, string model, float price)
{
  this->brand = brand;
  this->model = model;
  if(price>=0) this->price = price;
  else this->price = 0;
}

string Car::getBrand() const {return brand;}

string Car::getModel() const {return model;}

float Car::getPrice() const {return price;}

vector<string> Car::getColors() const {return colors;}

void Car::setPrice(float euros)
{
  if(euros >= 0) price = (float)euros;
}

void Car::addColors(string color)
{
  if(!color.empty()) colors.push_back(color);
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
    Car b1(ISBN,quantity,title,author,price);

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