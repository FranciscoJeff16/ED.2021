#include <stdlib.h>
#include <stdio.h>

  
// Protótipos de Funções
// Protótipo de Função que escanear vetor bidimensional e soma seus elementos.
int quadrado_magico (int l/*linhas*/,int c/*Colunas*/, int[l][c]/*Matriz*/);


int main (void) {
    int l,c;

    scanf("%d %d",&l,&c);
    int QUADRADO[l][c], i, j;

    i= -1;
    while (l > ++i) {
        j= -1;
        while (c > ++j) scanf(" %d",QUADRADO[i]+j);
        }

    printf("%ceh MAGICO.\n", quadrado_magico(l, c, QUADRADO)? '\b':'~');
    return 0;
    }

// Função que retorna 1-verdadeiro ou 0-falso para quadrado mágico.
int quadrado_magico (int l, int c, int q[l][c]) {
    int i, j, slinhas,scolunas,sdigprincipal,sdigsegundaria;


    sdigprincipal = sdigsegundaria = 0;
    i = -1;
    while (l > ++i) {
        slinhas = scolunas = 0;
        j = -1;
        while (c > ++j) {
            // Diagonal principal.
            if (i == j) sdigprincipal = q[i][j] + sdigprincipal;

            // Diagonal segundaria
            if ((i+j) == (l-1)) sdigsegundaria = q[i][j] + sdigsegundaria;

            // Linhas
            slinhas =  q[i][j] + slinhas;

            // Colunas
            scolunas=  q[j][i] + scolunas;
            }
      	if (scolunas != slinhas) return 0;
        }
    return(sdigprincipal == sdigsegundaria);
    }