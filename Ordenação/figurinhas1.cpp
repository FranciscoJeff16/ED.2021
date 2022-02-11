#include <iostream>
#include <vector>

using namespace std;

  void verif(vector<int> vet1, vector<int> vet2, int quant);

int main(){
    int quant, aux, aux1, i = 0;
    cin >> quant;
    vector<int> figB;
    vector<int> figG;
    while(quant > i){
        cin >> aux;
        figB.push_back(aux);
        i++;
    }
    int w = 0;
    while(quant > w){
        cin >> aux1;
        figG.push_back(aux1);
        w++;
    }
    verif(figB,figG, quant);
    return 0;
}

void verif(vector<int> vet1, vector<int> vet2, int quant){
    int cont = 0; // contador;
    for (int j = 0; j < quant;j++){
        for(int m = 0;m < quant; m++)
            if(vet1[j] == vet2[m]){
                cont++;
        }
    }
    if(cont == quant){
        cout << "1" << endl;
    }else{
        cout << "0" << endl;
    }
}