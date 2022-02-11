#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

typedef int Item;
// Fila a partir de duas pilhas
class Fila{
    private:
    stack<Item> deposito;
    stack<Item> prate;

    public:
    void enfileirar(Item n){
        //n vai para o topo da fila;
        deposito.push(n);
    }
    void retira(){
        //verificando se a listas estão vazias
        if(deposito.empty() && prate.empty()){
             throw std::underflow_error("fila vazia");
        }
        //invertendo posições nas filas 
        if (prate.empty()){
            while (!deposito.empty()) {
                prate.push(deposito.top());// 4 3 2 1 - 1 2 3 4
                deposito.pop();
            }
        }
        if(prate.size() > 0){
            prate.pop();
        }

    }
    void print(){
        if (prate.empty()){
            while (!deposito.empty()) {
                prate.push(deposito.top());
                deposito.pop();
            }
        }
        cout << prate.top()<< endl;
    }
};

int main(){
    // Quantidade de buscas
    Item qBusca;
    Fila arm;
    cin >> qBusca;
    int testador;
    Item paraFila;
    for(int i = 0;i < qBusca;i++){
        cin >> testador;
        switch(testador){
            case 1: // coloca o elemnto paraFila no topo da pilha
            cin >> paraFila;
            arm.enfileirar(paraFila);
            break;
            case 2:// retira o elemento do topo da pilha
            arm.retira();
            break;
            case 3:// imprime o elemento que está no topp
            arm.print();
            break;
        }
    }
    return 0;
}
