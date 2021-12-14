#include <iostream>
#include <vector>

using namespace std;

//função para leitura do vetor rotacionado 
void show(vector<int> &vet);
//função para realizar a rotação n vezes
void right_rotation(vector<int>& vet, int nrot);

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    right_rotation(vet, nrot);
    show(vet);
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}
//função para realizar a rotação n vezes
void right_rotation(vector<int>& vet, int nrot){
    nrot = nrot % vet.size();
    for(int i = 0;i < nrot;i++){
        // aux recebe o último elemento do vetor
        int aux = vet[vet.size() - 1];
        for(int j = vet.size() - 1;j >= 0; j--){
            if(j != 0){  
                vet[j] = vet[j-1];
            }else{
                vet[0] = aux;
            }
        }
    }
}
