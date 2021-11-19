#include <iostream>
using namespace std;
int fn(int n);

int main(){
    int n;
    cout << "Qual o número que você quer saber o enésimo termo na sequeência de Fibonacci? " << endl;
    cin >> n;
    cout << "O enésimo termo é: " << fn(n) << endl;
    return 0;
}
 
int fn(int n){
int aux_1=0, aux_2=1, temp=0;
 for(int i = 1;i < n; i++){
        temp = aux_1 + aux_2;
        aux_1 = aux_2;
        aux_2 = temp;
    }
    return temp;
}