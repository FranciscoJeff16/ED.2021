#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
// para comparar as strings;
vector<int> matchingStrings(int tamanho1, string entrada[], int tamanho2, string testador[]);
// para imprimir o vetor resultante
void print(vector<int> result); 

int main(void){
    int tamanho1, tamanho2, i = 0, j = 0;
    //Primeira string
    cin >> tamanho1;
    string entrada[tamanho1];
     for(int i = 0; i < tamanho1;i++){
         cin >> entrada[i];
         cin.ignore();
     }
    //Segunda string
    cin >> tamanho2;
    string testador[tamanho2];
     for(int i = 0; i < tamanho2;i++){
         cin >> testador[i];
         cin.ignore();
     }
    print(matchingStrings(tamanho1,entrada,tamanho2,testador));
}
vector<int> matchingStrings(int tamanho1, string entrada[], int tamanho2, string testador[]){
    short aux = 0;
    vector<int> result;
    for(int i = 0;i < tamanho2;i++){
        for(int j = 0;j < tamanho1;j++){
            if(testador[i] == entrada[j]){
                aux++;
            }
        }
         result.push_back(aux);
         aux = 0;
    }
    return result;
}
void print(vector<int> result){
    int aux = result.size();
    cout << "[ ";
    for(int i = 0;i < aux;i++){
        cout << result[i] << " ";
    }
    cout << "]";
}