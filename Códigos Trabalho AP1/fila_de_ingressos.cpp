#include <iostream>

using namespace std;

//função para tirar as fila da fila e imprimir;
void saiu(int tamanho1, int fila[], int tamanho2, int saindo[]);

int main(){

    int tamanhoFila, QSaiu; // tamanho da fila e quantidade pessoas que saíram da fila
    cin >> tamanhoFila;
    int fila[tamanhoFila];
    for(int i = 0;i < tamanhoFila;i++){
        cin >> fila[i];
    }
    cin >> QSaiu;
    int sairam[QSaiu];
    for(int i = 0;i < QSaiu;i++){
        cin >> sairam[i];
    }
    saiu(tamanhoFila,fila,QSaiu,sairam);
    return 0;
}

//função para tirar as fila da fila e imprimir;
void saiu(int tamanho1, int fila[], int tamanho2, int saindo[]){
   /*Toda vida que tiver um elemento igual na fila, faço com que o vetor na posição do elemento igual *
    *receba -1, assim na impressão eu imprimo todos os elementos maiores ou iguais a 0;               */
    int negativando = -1,i = 0;
    while(i<tamanho2){
        for(int j = 0;j < tamanho1;j++){
            if(saindo[i] == fila[j]){
                fila[j] = negativando;
            }
        }
        i++;
    }
    for(int i = 0;i < tamanho1; i++){
        if(fila[i] >= 0){
            cout << fila[i] << " ";
        }
    }
}