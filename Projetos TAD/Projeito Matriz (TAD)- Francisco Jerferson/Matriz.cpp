// Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"

// Aloca espaco para matriz n por m
Matriz::Matriz(int n, int m) {
// TODO
	this->lin = n;
	this->col = m;
	matriz = new int*[n];
	for(int i = 0;i < lin;i++){
		matriz[i] = new int[m];
}
}   

// Destrutor: Libera a memoria da matriz
Matriz::~Matriz() {
// TODO
	for(int i = 0;i < lin;i++){
		delete[] matriz[i];
	}
	delete[] matriz;
	std::cout << "matriz liberada \n";
}     

// Retorna o valor do elemento [i][j]
int Matriz::valor(int i, int j) {
// TODO
	return this->matriz[i][j];
} 

// Atribui valor ao elemento [i][j]
void Matriz::atribui(int valor, int i, int j) {
// TODO
	matriz[i][j] = valor;
}

// Retorna o numero de linhas da matriz
int Matriz::linhas() {
// TODO
	return this->lin;
} 

// Retorna o numero de colunas da matriz
int Matriz::colunas() { 
// TODO
	return this->col;
}

// Imprime matriz --- Ja esta codificado 
void Matriz::imprime(int largura) {
	for (int linha = 0; linha < lin; linha++) {
		for (int coluna = 0; coluna < col; coluna++) {
			std::cout << std::setw(largura) << matriz[linha][coluna];
		}
		std::cout << std::endl;
	}
} 

// Soma matrizes
Matriz *Matriz::soma(Matriz *B) {
// TODO
	int  l = this->lin, c = this->col;
	//criando matriz resultante
	Matriz* NovaMatriz = new Matriz(l,c);
	int Matriz1, Matriz2;
	if(this->lin == B->lin && this->col == B->col){
		for(int i = 0;i < l;i++){
			for(int j = 0;j < c;j++){
				int soma = this->matriz[i][j] + B->matriz[i][j];
				NovaMatriz->atribui(soma, i, j);
			}
		}
		return NovaMatriz;
	}else{
		return nullptr;
	}
}

// Multiplica matrizes
Matriz *Matriz::multiplica(Matriz *B) {
// TODO
	int l =this->lin, c = this->lin;
		//criando matriz resultante
	Matriz* NovaMatriz = new Matriz(l,c);
		if(this->lin == B->col){
		for(int i = 0;i < lin;i++){
			for(int j = 0;j < col;j++){
				int sm = 0;
				for(int z = 0;z < lin;z++){
					sm += this->matriz[i][z] * B->matriz[z][j]; 
				}	
					NovaMatriz->matriz[i][j] = sm;
					sm = 0;
			}
		}
			return NovaMatriz;
	}else{
		return nullptr;
	}
}
