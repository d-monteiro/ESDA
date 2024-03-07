#include <iostream>
#include <vector>

using namespace std;


int insert_several(vector<int>& v, int n)
{
  if(n<0) return -1;
  
  for(int i=1;i<=n;++i){
    v.push_back(2*i);
  }
  return 0;
}


int insert_pos(vector<int>& v, int pos, int value)
{
  if((int)v.size() < pos || pos<0) return -1;
  
  auto i = v.begin()+pos;
  v.insert(i, value);
  return 0;
}


// Utility function to print the vector
void print_vec(vector<int>& v){
    cout << "Vector elements: " << endl;
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl; 
}
    

int main(){
    

    vector<int> numbers;
    cout << "Return Value: " << insert_several(numbers,10) << endl;
    print_vec(numbers);

    int pos = 3;
    int value = 4;
    cout << "Return Value: " << insert_pos(numbers, pos, value)<< endl;
    print_vec(numbers);


}