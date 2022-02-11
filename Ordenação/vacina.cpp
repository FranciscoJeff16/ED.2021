#include <iostream>
#include <vector>

using namespace std;

int main(){
    int quant, aux, aux1, i = 0;
    cin >> quant;
    vector<int> vacinas;
    vector<int> pacientes;
    while(quant > i){
        cin >> aux;
        vacinas.push_back(aux);
        i++;
    }
    int w = 0;
    while(quant > w){
        cin >> aux1;
        pacientes.push_back(aux1);
        w++;
    }
    int cont = 0; // contador;
    for (int j = 0; j < quant;j++){
        if(vacinas[j] > pacientes[j]){
            cont++;
        }
    }
    if(cont == quant){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}