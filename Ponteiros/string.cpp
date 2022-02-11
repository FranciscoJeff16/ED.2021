#include <iostream>
#include <cstring>

using namespace std;

//função para ordenar strings
void ordenando(int quanti, char *vet[]);

int main(){
    int quanti,tam;
    cin >> quanti;
   char **vet = new (nothrow) char*[quanti];
    if(vet == nullptr){
        cout << "erro de programa" << endl;
        return 0;
    }
    
    for(int i = 0;i < quanti;i++){
        cin >> tam;
        vet[i] = new (nothrow) char [tam+1]; 
        if(vet[i] == nullptr){
            cout << "erro de programa" << endl;
            return 0;
        }
        cin.ignore();
        cin.get(vet[i],tam+2);
    }
   
    ordenando(quanti,vet);
    
    for(int i = 0; i < quanti;i++){
        cout << vet[i] << endl;
    }
    
    delete[] vet;
    return 0;
}

void ordenando(int quanti, char *vet[]){
     for(int i = 0;i < quanti;i++){
        for(int j = 0;j < quanti - 1;j++){
            if(strcmp(vet[j],vet[j+1]) > 0){
            char *temp = vet[j+1];
            vet[j+1] = vet[j];
            vet[j] = temp;
            }
        }
    }    
}