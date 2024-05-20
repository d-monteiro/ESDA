#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

void testLargestPosElementString(string orig, int k, string result);
void testSmallestPosElementVector(vector<int> orig, int k, int result);

/**
 *  @brief Função de comparação para ordenar uma max-heap cujos elementos são strings.
 *  @note  Os elementos são ordenados por tamanho decrescente. Para tamanhos iguais, os elementos são ordenados por ordem alfabética.
 */
struct compareMax
{
    bool operator() (const string &s1, const string &s2) const {
        return s1.length() == s2.length() ? s1 > s2 : s1.length() < s2.length();
    }
};

/** 
 *  @brief  Encontrar o k-ésimo menor elemento de um vetor de inteiros.
 *  @param  vec vetor a analisar
 *  @param  k k-ésima posição
 *  @return k-ésimo menor elemento do vetor || 9999 em caso de erro
 *  @note   Recorrer ao uso de uma fila de prioridade para ordenar o vetor.
 *  @note   Validar o valor dos argumentos. k deve ser um número positivo.
 */
int smallestPosElementVector(vector<int> vec, int k)
{
    /* Implementar 2a) */
}


/** 
 *  @brief  Encontrar o k-ésimo maior elemento (palavra) de uma string (frase).
 *  @param  text string a analisar
 *  @param  k k-ésima posição
 *  @return k-ésimo maior elemento da string
 *  @note   Recorrer ao uso de uma stringstream e de uma fila de prioridade para ordenar as palavras da string.
 *  @note   Validar o valor dos argumentos. k deve ser um número positivo.
 */
string largestPosElementString(string text, int k)
{
    /* Implementar 2b) */
}



/* ----------------------------- */
/* -------- NÃO ALTERAR -------- */
/* ----------------------------- */

int main()
{
    string s1, s2, s3, s4, s5, s_result;
    vector<int> v1, v2, v3, v4, v5;
    int v_result = 9999;

    s2 = "when there is smoke there is fire";
    s3 = "better safe than sorry";
    s4 = "blood is thicker than water";
    s5 = "river";
    v2 = {4, 5, 6, 6, 10, 9, 7, 2, 6, 1};
    v3 = {-35, 95, 63, 58, 63, 3};
    v4 = {87, -58, -21};
    v5 = {77};

    cout << "\n++ Exercício 2a) ++\n\n";

    v_result = smallestPosElementVector(v2, 11); // k is above the limit
    testSmallestPosElementVector(v2, 11, v_result);

    v_result = smallestPosElementVector(v2, 4);
    testSmallestPosElementVector(v2, 4, v_result);

    v_result = smallestPosElementVector(v3, 2);
    testSmallestPosElementVector(v3, 2, v_result);
    
    v_result = smallestPosElementVector(v4, 1);
    testSmallestPosElementVector(v4, 1, v_result);

    cout << "\n++ Exercício 2b) ++\n\n";
    
    s_result = largestPosElementString(s2, 8); // k is above the limit
    testLargestPosElementString(s2, 8, s_result);

    s_result = largestPosElementString(s2, 4);
    testLargestPosElementString(s2, 4, s_result);

    s_result = largestPosElementString(s3, 3);
    testLargestPosElementString(s3, 3, s_result);
    
    s_result = largestPosElementString(s4, 1);
    testLargestPosElementString(s4, 1, s_result);

  

    return 0;
}

/* +++ Funções utilitárias +++ */

/**
 *  @brief  Função de teste da função 'largestPosElementString'.
 *  @param  orig string original
 *  @param  k posição
 *  @param  result retorno da função 'largestPosElementString'
 *  @return void
 */
void testLargestPosElementString(string orig, int k, string result)
{
    if (result.empty()) cout << "largestPosElementString(): ERRO\n\n";
    else {
        cout << "largestPosElementString(): OK\n";
        cout << "   String original: " << orig << endl;
        cout << "   String: (k = " << k << "): " << result << endl << endl;
    }
}

/**
 *  @brief  Função de teste da função 'smallestPosElementVector'.
 *  @param  orig vetor
 *  @param  k posição
 *  @param  result retorno da função 'smallestPosElementVector'
 *  @return void
 */
void testSmallestPosElementVector(vector<int> orig, int k, int result)
{
    if (result == 9999) cout << "smallestPosElementVector(): ERRO\n\n";
    else {
        cout << "smallestPosElementVector(): OK\n";
        cout << "   Vetor: ";
        for (int i = 0; i < (int)orig.size(); i++) cout << orig[i] << " ";
        cout << "\n   Elemento (k = " << k << "): " << result << endl << endl;
    }
}