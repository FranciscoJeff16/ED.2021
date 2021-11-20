#include <iostream>
using namespace std;

//Função  fazer as mudanças
void Hanoi_4_Pinos(int discos, char comeco, char aux_1, char aux_2, char fim);

int main(){
	int n;
	cin >> n;
    Hanoi_4_Pinos(n, 'A', 'B', 'C', 'D');

    return 0;
}
void Hanoi_4_Pinos(int discos, char comeco, char aux_1, char aux_2, char fim){
   // Caso só tenho um disco a mudança será só  A -> B
    if ( discos == 1 ){
        cout << comeco << " -> " << fim << endl;
   // Caso tenha dois discos a mudanã será  A -> B, A -> D e B -> D    
    }else if ( discos == 2 ){
        cout << comeco << " -> " << aux_1 << endl;
        cout << comeco << " -> " << fim << endl;
        cout << aux_1 << " -> " << fim << endl;
    //Caso sejam mais que 2 discos
    }else {
        Hanoi_4_Pinos(discos - 2, comeco, aux_2, fim, aux_1);
        cout << comeco << " -> " << aux_2 << endl;
        cout << comeco << " -> " << fim << endl;
        cout << aux_2 << " -> " << fim << endl;
        Hanoi_4_Pinos(discos - 2, aux_1, comeco, aux_2, fim);
    }
}