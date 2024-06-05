#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;

class HashTable
{
    private:
                
       
        int tableSize;

        /**
         *  Tabela de dispersão (array de apontadores para strings).
         */
        vector<string> table;

    public:
        
        /**
         *  Número de contas (número efetivo de elementos) na tabela de dispersão.
         */
        int totalStrings;


        /* CONSTRUTOR */

        /**
         *  Construtor (parametrizado).
         */
        HashTable(int ts);

        /* MÉTODOS GET */

        /**
         *   Obter o tamanho da tabela de dispersão.
         */
        int getTableSize() const;

        /**
        */
        vector<string> getTable() const;
        

        /* OUTROS MÉTODOS */

        /**
         *  Determinar o índice de determinada chave.
         *   Função de dispersão: devolve a hash (h) -> somatório de h(i-1)+key[i], com i>=0 e i<key.length() (h(-1)=7).
         */
        int hashFunction(string key);

        /**
         *  Determinar o índice de determinada chave para resolução de colisões.
            Função de sondagem quadrática: devolve a hash (h) -> h+23*i^2.
        */
        int probingFunction(string key, int i);
        
        /**
         * Inserir uma nova string na tabela de dispersão.
           */
        int insertString(string st);

        /**
         *  Remover um elemento da tabela de dispersão.
         * 
         */
        int deleteString(string st);



        /**
         *   Mostrar o conteúdo da tabela de dispersão.
       
         */
        void show();
};


HashTable::HashTable(int ts)
{

    if (ts>0)
    {
    this->tableSize = ts;
    totalStrings=0;
    table.resize(ts);
    for (int i=0; i<ts; i++)
    {
        table[i]="";
    }
    } else delete this;
}

int HashTable::getTableSize() const
{

    return tableSize;
}
vector<string> HashTable::getTable() const
{
    return table;
}

int HashTable::hashFunction(string key)
{
    if (!key.empty())
    {
    int h = 7; 
    for(int i = 0; key[i]; i++)
    {
        h += (int)key[i];
    }

    return h % tableSize;
    } else return -1;
}


int HashTable::probingFunction(string key,int i)
{
    if (!key.empty())
    {
    int h = hashFunction(key); 
   
        h += 23*i*i;
 

    return h % tableSize;
    } else return -1;
}
        
int HashTable::insertString(string st)
{      
        int index = hashFunction(st);
        
        if (table[index]=="")
        {
           
            table[index]=st;
            totalStrings++;
            return index;
        } else {
            if(table[index]=="apagado")
            {table[index]=st;
            totalStrings++;
            return index;
            }
            int i=1;
            
            while(table[index]!="")
            {

                index=probingFunction(st,i);
            
                if (table[index]=="")
                {
                    table[index]=st;
                    totalStrings++;
                    return index;
                } else
                {
                    if(table[index]=="apagado")
                    {
                        table[index]=st;
                        totalStrings++;
                        return index;
                    }
                }
                i++;
            }
        }
        return -1;
}
int HashTable::deleteString(string st)
{    
    if (st.empty())
    {
        return -1;
    }
    int index = hashFunction(st);
    if (table[index]==st)
    {
        table[index]="apagado";
        totalStrings--;
        return 0;
    } else 
    {
        int i=1;
        while((table[index]!=""))
        {
            index=probingFunction(st,i);
            if (table[index]==st)
            {
                table[index]="apagado";
                totalStrings--;
                return 0;
            } 
            i++;
        }
    }
    return -1; 

}     

void HashTable::show()
{
    cout << "Tabela de dispersão: "<<endl;
    vector<string> tab=getTable();
    for (int i=0;i<(int)getTableSize();i++)
    {
        cout << "["<<i<<"]:";
        if (tab[i]!="")
        {
            cout <<tab[i] <<endl;
        } else cout <<endl;

    }
}

string maxCollisions(HashTable &ht, vector<string> &v)
{
    if(v.empty() || ht.getTableSize() <= 0) return "";
    
    string maxString;
    int max = -1;

    for (const string &str : v){
        int collisions = 0;

        for (int i = 0; i < ht.getTableSize(); i++){
            int pos = ht.probingFunction(str, i);
            if (ht.getTable()[pos] == str || ht.getTable()[pos] == "") break;
            collisions++;
        }

        if (collisions > max){
            max = collisions;
            maxString = str;
        }
    }

    return maxString;
}

void showVector(vector<string> ve)
 {
     cout << "vector: ";

    for (int i=0;i<(int)ve.size();i++)
    {
        cout <<" - "<<ve[i] ;
    }
    cout <<endl;
 }

int main()
{
    HashTable ht(17);
    ht.insertString("Ana");
    ht.insertString("Vitor");
    ht.insertString("Luis");
    ht.insertString("Duarte");
    ht.insertString("Anabela");
    ht.insertString("Marta");
    ht.insertString("Susana");
    ht.insertString("Sofia");
    ht.insertString("Bruno");
    ht.insertString("Paulo");
    ht.insertString("Bernardo");
    ht.insertString("Carlos");
    ht.insertString("Francisco");
    ht.show();

      cout << "\n++ Exercício 3 ++\n\n";

    // Teste 1
    vector<string>  v1;
    v1.push_back("Paulo");
    v1.push_back("Carlos");
    v1.push_back("Bernardo");
    string res1=maxCollisions(ht,v1);
    if (!res1.empty())
    cout << "resultado: "<< res1 <<endl;
    else cout<<"resultado vazio"<<endl;

    // Teste 2
    vector<string>  v2;
    string res2=maxCollisions(ht,v2);
    if (!res2.empty())
    cout << "resultado: "<< res2 <<endl;
    else cout<<"resultado vazio"<<endl;


}