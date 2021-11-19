#include <iostream>

using namespace std;

bool checando(int vet[], int n);

int main(){
	int vet[]={1,6,8,14,33,46,90};
	int n;
	n=sizeof(vet)/sizeof(vet[0]);
	if (checando(vet, n))
		cout << "Esta ordenado\n";
	else
		cout << "Nao esta ordenado\n";
}

bool checando(int vet[], int n){
	if (n == 0 || n == 1){//caso o vetor não tenha elementos ou seja somente de 1 elemento
		return true;
	}
	for (int i = 0; i < n-1; i++){
		if (vet[i] > vet[i+1]){
			return false;
			break;
		}
	}
	return true;
}