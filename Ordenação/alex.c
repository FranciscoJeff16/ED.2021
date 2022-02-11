#include <stdio.h>

int main(){
    int tam;
    scanf("%d", tam);
    int vet[tam];
    char nomes[100];
    float notas[3];
    for (int i = 0; i < tam;i++){
        fgets(nomes, 100, stdin);
        for (int j = 0; j < 3;i++){
            scanf("%d",notas[j]);
        }
    }
}   