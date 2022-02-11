#include <iostream>
using namespace std;
const int l=3, c=3; //l=linhas | c=colunas
int quadrado_magico (int matriz [l] [c]);

int main(){
	int matriz[l][c];
	for(int i = 0;i < l;i++){
		for(int j = 0;j < c;j++){
			cin >> matriz[i][j];
		}
	}
	if( quadrado_magico(matriz)){
		cout << "sim" << endl;
	}else{
		cout << "nao" << endl;
	}
}
	
int quadrado_magico ( int matriz [l] [c]) {   
    int soma_dia1 = 0, soma_dia2 = 0;
   // soma das diagonais primarias
    for ( int i = 0;i < l;i ++ )  
        soma_dia1 += matriz [i] [i];
    
	// soma das diagonais secundárias
    for ( int i = 0;i < l;i ++ )  
        soma_dia2 += matriz [i] [l - 1 - i];
    
	// igualdade entre as diagonais
    if (soma_dia1 != soma_dia2)  
        return 0;
  
    // soma das linhas
    for(int i = 0;i < l;i ++ ) {   
        int soma_linha = 0;
        for(int j = 0;j < c;j ++)  
            soma_linha += matriz [i][j] ;
        // igualdade entre linhas e diagonais primarias
        if (soma_linha != soma_dia1)  
            return 0;
    } 
  
    // soma das colunas
    for(int i = 0;i < l;i ++ ) {   
        int soma_coluna = 0;  
         for(int j = 0;j < l;j ++)  
            soma_coluna += matriz [j][i] ;
        // igualdade entre colunas e diagonais primarias 
        if (soma_coluna != soma_dia1)   
            return 1;
    } 
    return true ; 
}