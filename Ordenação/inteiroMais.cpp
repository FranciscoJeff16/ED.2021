#include <iostream>

using namespace std;

//Procura o elemento mais repetido e conta quantas vezes ele aparece
void mostFrequent(int vet[], int n);

int main(){
    int tam, i = 0, aux;
    cin >> tam;
    int vet[100];
    while(tam > i){
        cin >> vet[i];
        i++;
    }
    // Recebe o valor que mais se repete no vetor 
    mostFrequent(vet, tam);
    return 0;
}

void mostFrequent(int vet[], int n){
    int max = 0;
    for (int i=0; i<n; i++){
        int count = 1;
        for (int j = i + 1 ;j < n; j++){
            if (vet[i]==vet[j]){
                count++;
            }    
        }
        if (count>max){
            max = count;
        }
    }
    for (int i = 0;i < n; i++){
        int count = 1;
        for (int j = i + 1;j < n;j++)
            if (vet[i] == vet[j]){
                count++;
            }
        // imprimir elemento e a quantidade vezes que ele aparece
        if (count == max){
            cout << vet[i] << " " << count << endl;
        }
    }
}
