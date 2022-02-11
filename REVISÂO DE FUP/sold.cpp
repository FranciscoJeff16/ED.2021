#include <iostream>

using namespace std;
const int l=3, c=3; //l=linhas | c=colunas

int main(){
	int matriz[l][c],contador = 0;
	for(int i = 0;i < l;i++){
		for(int j = 0;j < c;j++){
			cin >> matriz[i][j];
		}
	}
//calculando quantos números menores estão atrás dos maiores
 for (int i = 0;i < (l - 1);i++){
        for (int j = 0;j < c;j++){
            if(matriz[i][j] > matriz[i + 1][j]){
                contador++;
            }
        }
    }
cout << contador << endl;
return 0;
}
