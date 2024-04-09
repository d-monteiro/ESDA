#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int adicionar(priority_queue<string, vector<string>, greater<string> > *pq, string file_name)
{
    
    if(pq == nullptr || file_name.empty()) return -1;
    
    ifstream file(file_name);
    if(!file) return -1;

    string line;

    while(getline(file,line)) pq->push(line);
    
    return pq->size();
}

void imprimir(priority_queue<string, vector<string>, greater<string> > *pq, int n)
{
    cout<<"Primeiros 10 pilotos:\n";
    for(int i=1; i<=n; i++){
        cout<<"#"<<i<<": "<<pq->top()<<"\n";
        pq->pop();
    }
}


int main()
{

  // alínea a)

  // alínea b)

  // alínea c)

  return 0;
}

